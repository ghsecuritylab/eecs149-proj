// testing flex sensors

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_error.h"
#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_serial.h"
#include "nrfx_gpiote.h"
#include "nrfx_saadc.h"

#include "buckler.h"
#include "pin_assignments.h"

#define SENSOR_0_ADC_CHANNEL 0
#define SENSOR_1_ADC_CHANNEL 1
#define SENSOR_2_ADC_CHANNEL 2
#define SENSOR_3_ADC_CHANNEL 3
#define SENSOR_4_ADC_CHANNEL 4

#define ADC_SCALING_FACTOR 1137.778 // See page 358 of nRF52832 Product Specification for details
// ADC_OUTPUT =  [V(P) – V(N)] * GAIN/REFERENCE * 2^(RESOLUTION - m)
// ADC_OUTPUT = V * 1137.778

#define DIVIDER_RESISTANCE 47000
// Resistor value used in every resistive divider with the flex sensors

#define NUMBER_OF_SENSORS 5

// callback for SAADC events
void saadc_callback(nrfx_saadc_evt_t const * p_event) {
    // don't care about adc callbacks
}

// sample a particular analog channel in blocking mode
nrf_saadc_value_t sample_value(uint8_t channel) {
    nrf_saadc_value_t val;
    ret_code_t error_code = nrfx_saadc_sample_convert(channel, &val);
    APP_ERROR_CHECK(error_code);
    return val;
}

void update_flex_sensor_readings(nrf_saadc_value_t* readings) {
    readings[0] = sample_value(SENSOR_0_ADC_CHANNEL);
    readings[1] = sample_value(SENSOR_1_ADC_CHANNEL);
    readings[2] = sample_value(SENSOR_2_ADC_CHANNEL);
    readings[3] = sample_value(SENSOR_3_ADC_CHANNEL);
    readings[4] = sample_value(SENSOR_4_ADC_CHANNEL);
}

ret_code_t initialize_rtt() {
    ret_code_t error_code = NRF_LOG_INIT(NULL);
    NRF_LOG_DEFAULT_BACKENDS_INIT();
    return error_code;
}

ret_code_t initialize_adc() {
    nrfx_saadc_config_t saadc_config = NRFX_SAADC_DEFAULT_CONFIG;
    saadc_config.resolution = NRF_SAADC_RESOLUTION_12BIT;
    ret_code_t error_code = nrfx_saadc_init(&saadc_config, saadc_callback);
    return error_code;
}

ret_code_t initialize_adc_channel(nrf_saadc_input_t pin, uint8_t channel, nrf_saadc_channel_config_t channel_config) {
    // initialize ADC channel 0 with pin AIN0
    channel_config.pin_p = pin;
    ret_code_t error_code = nrfx_saadc_channel_init(channel, &channel_config);
    return error_code;
}

float adc_input_voltage(nrf_saadc_value_t adc_reading) {
    return adc_reading / ADC_SCALING_FACTOR;
}

float flex_resistance_kohms(float voltage) {
    // Supply voltage = 5 V. That's where the magic number 5 comes from.
    return (DIVIDER_RESISTANCE/5 * voltage)/(1 - voltage/5)/1000;
}

void display_readings(nrf_saadc_value_t* readings) {
    int i;
    float voltage;
    float resistance;
    for (i = 0; i < NUMBER_OF_SENSORS; i++) {
        voltage = adc_input_voltage(readings[i]);
        resistance = flex_resistance_kohms(voltage);
        printf("sample %d: %d | %f V | %f kOhms\n", i, readings[i], voltage, resistance);

    }
}

nrf_saadc_value_t get_sensor_threshold(int sensor_number, nrf_saadc_value_t* readings) {
    int i;
    int16_t sum = 0;
    int16_t count = 5;
    printf("Calibrating sensor %d...\n", sensor_number);
    printf("Bend corresponding finger in approx. 90 degree angle\n");
    nrf_delay_ms(2000);
    for (i = 0; i < count; i++) {
        printf("Reading from sensor %d...\n", sensor_number);
        update_flex_sensor_readings(readings);
        display_readings(readings);
        sum += readings[sensor_number];
        nrf_delay_ms(5000);
    }
    return (nrf_saadc_value_t) (sum/count);
}

void update_sensor_thresholds(nrf_saadc_value_t* readings, nrf_saadc_value_t* thresholds) {
    int i;
    int j;
    int32_t sums[NUMBER_OF_SENSORS];
    for (i = 0; i < NUMBER_OF_SENSORS; i++) {
        sums[i] = 0;
    }
    int32_t count = 10; // number of samples to take
    printf("Preparing to calibrate sensors. Please bend all fingers.\n");
    nrf_delay_ms(2000);
    printf("Calibrating...\n");
    for (i = 0; i < count; i++) {
        update_flex_sensor_readings(readings);
        for (j = 0; j < NUMBER_OF_SENSORS; j++) {
            sums[j] += readings[j];
            nrf_delay_ms(10);
        }
    }
    for (i = 0; i < NUMBER_OF_SENSORS; i++) {
        printf("SUMS[%d], = %d\n", i, sums[i]);
        thresholds[i] = (nrf_saadc_value_t) (sums[i]/count);
    }
    printf("Calibration complete.\n");
    for (i = 0; i < NUMBER_OF_SENSORS; i++) {
        printf("Sensor %d threshold: %d\n", i, thresholds[i]);
    }
}

bool is_flexed(int sensor_number, nrf_saadc_value_t* readings, nrf_saadc_value_t* thresholds) {
    // Returns true if the ADC reading off the sensor is within 20% of the sensor's calibrated threshold value.
    return 0.8 * thresholds[sensor_number] <= readings[sensor_number] && readings[sensor_number] < 1.2 * thresholds[sensor_number];
}


int main() {
    //----------Initialization stuff--------------------------------------------------------------------------------
    ret_code_t error_code = NRF_SUCCESS;

    // initialize RTT library
    error_code = initialize_rtt();
    APP_ERROR_CHECK(error_code);

    // initialize ADC
    error_code = initialize_adc();
    APP_ERROR_CHECK(error_code);

    // initialize analog inputs
    nrf_saadc_channel_config_t channel_config = NRFX_SAADC_DEFAULT_CHANNEL_CONFIG_SE(0);
    channel_config.gain = NRF_SAADC_GAIN1_6; // GAIN = 1.6
    channel_config.reference = NRF_SAADC_REFERENCE_INTERNAL; // REFERENCE = 0.6

    error_code = initialize_adc_channel(SENSOR_0_INPUT_PIN, SENSOR_0_ADC_CHANNEL, channel_config);
    APP_ERROR_CHECK(error_code);
    error_code = initialize_adc_channel(SENSOR_1_INPUT_PIN, SENSOR_1_ADC_CHANNEL, channel_config);
    APP_ERROR_CHECK(error_code);
    error_code = initialize_adc_channel(SENSOR_2_INPUT_PIN, SENSOR_2_ADC_CHANNEL, channel_config);
    APP_ERROR_CHECK(error_code);
    error_code = initialize_adc_channel(SENSOR_3_INPUT_PIN, SENSOR_3_ADC_CHANNEL, channel_config);
    APP_ERROR_CHECK(error_code);
    error_code = initialize_adc_channel(SENSOR_4_INPUT_PIN, SENSOR_4_ADC_CHANNEL, channel_config);
    APP_ERROR_CHECK(error_code);
    //----------End initialization stuff-----------------------------------------------------------------------------

    // Initialize readings / thresholds holder arrays
    nrf_saadc_value_t flex_sensor_readings[NUMBER_OF_SENSORS];
    nrf_saadc_value_t flex_sensor_thresholds[NUMBER_OF_SENSORS];
    int i;

    nrf_delay_ms(2000);
    printf("RTT working...\n");

    // Calibrate sensors
    update_sensor_thresholds(flex_sensor_readings, flex_sensor_thresholds);

    nrf_delay_ms(5000);

    while (1) {
        printf("Sampling...\n");
        update_flex_sensor_readings(flex_sensor_readings);
        display_readings(flex_sensor_readings);
        for (i = 0; i < NUMBER_OF_SENSORS; i++) {
            if (is_flexed(i, flex_sensor_readings, flex_sensor_thresholds)) {
                printf("%d 1\n", i); // Indicate which sensors are flexed
            } else {
                printf("%d 0\n", i);
            }
        }

        nrf_delay_ms(1000);
    }

}
