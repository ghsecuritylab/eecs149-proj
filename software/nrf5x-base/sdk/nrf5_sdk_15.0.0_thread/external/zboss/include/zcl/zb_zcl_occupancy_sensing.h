/**
 * ZBOSS Zigbee 3.0
 * 
 * Copyright (c) 2012-2018 DSR Corporation, Denver CO, USA.
 * http://www.dsr-zboss.com
 * http://www.dsr-corporation.com
 * 
 * All rights reserved.
 * 
 * 
 * Use in source and binary forms, redistribution in binary form only, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 2. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 3. This software, with or without modification, must only be used with a Nordic
 *    Semiconductor ASA integrated circuit.
 * 
 * 4. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * PURPOSE: Occupancy Sensing definitoins
*/

#if ! defined ZB_ZCL_OCCUPANCY_SENSING_H
#define ZB_ZCL_OCCUPANCY_SENSING_H

#include "zcl/zb_zcl_common.h"
#include "zcl/zb_zcl_commands.h"

/** @cond DOXYGEN_ZCL_SECTION */

/** @addtogroup ZB_ZCL_OOSC
 *  @{
 *    @details
 *    Occupancy Sensing cluster has no cluster-specific command support. Cluster
 *    attributes can be queried with @ref ZB_ZCL_COMMANDS "common commands".
 */

/*! @name Occupancy Sensing cluster attributes
    @{
*/

/*! @brief Occupancy Sensing cluster attribute identifiers
    @see ZCL spec, subclause 4.8.2.2
*/
enum zb_zcl_occupancy_sensing_attr_e
{
  /*! Occupancy attribute identifier */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_ID              = 0x0000,
  /*! Occupancy Sensor Type attribute identifier */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ID  = 0x0001,
  /*! PIROccupiedToUnoccupiedDelay identifier */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_PIR_OCC_TO_UNOCC_DELAY_ID = 0x0010,
  /*! PIRUnoccupiedToOccupiedDelay identifier */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_PIR_UNOCC_TO_OCC_DELAY_ID = 0x0011,
  /*! PIRUnoccupiedToOccupiedThreshold identifier */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_PIR_UNOCC_TO_OCC_THRESHOLD_ID = 0x0012,

  /* Parking Sensor, Attributes for device Configuration, 2.5.1 */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_REPORTING_MODE_ID                                   = 0x8001,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_DEBUG_MODE_ID                                       = 0x8002,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_SENSING_INTERVAL_ID                                 = 0x8003,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_MAX_NBR_CONFIRM_PINGS_ID                            = 0x8004,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_CONFIRM_PING_DELAY_ID                               = 0x8005,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_NBR_CONFIRM_PINGS_TO_VALID_ID                       = 0x8006,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_LOCAL_TEMPERATURE_OVERRIDE_ID                       = 0x8007,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_REMOTE_TEMPERATURE_VALUE_ID                         = 0x8008,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_HUMIDITY_COMPENSATION_ID                            = 0x800A,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_TRANDUCER_SENSITIVITY_CALIBRATION_SOURCE_ID         = 0x800B,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_TRANDUCER_SENSITIVITY_CALIBRATION_OVERRIDE_VALUE_ID = 0x800C,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_SENSOR_TIME_VS_GAIN_LUT_ID                          = 0x800D,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_LEARN_ID                                            = 0x800E,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_RINGDOWN_DISTANCE_ID                                = 0x800F,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_REFERENCE_FLOOR_DISTANCE_ID                         = 0x8010,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_DETECTION_ALGORITHM_SELECTOR_ID                     = 0x8011,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_FLOOR_DEADBAND_ID                                   = 0x8012,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_MAIN_OBJECT_DEADBAND_ID                             = 0x8013,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_DETECTION_THRESHOLD_ID                              = 0x8014,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_FORCE_REPORT_ID                                     = 0x801C,

  /* Parking Sensor, Reportable Attributes, 2.5.2 */
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_LOCAL_TEMPERATURE_VALUE_ID              = 0x8009,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_CONFIDENCE_ID                           = 0x8015,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_ECHO_RETURN_ARRAY_ID                    = 0x8017,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_RX_SAMPLES_ARRAY_1_ID                   = 0x8018,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_RX_SAMPLES_ARRAY_2_ID                   = 0x8019,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_RX_SAMPLES_ARRAY_3_ID                   = 0x801A,
  ZB_ZCL_ATTR_OCCUPANCY_SENSING_CUSTOM_RX_SAMPLES_ARRAY_4_ID                   = 0x801B
};

/*! @brief Permissible values for Occupancy attribute
    @see ZCL spec, subclause 4.8.2.2.1.1
*/
enum zb_zcl_occupancy_sensing_occupancy_e
{
  /*! Occupied value */
  ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_OCCUPIED   = 0,
  /*! Unoccupied value */
  ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_UNOCCUPIED = 1
};

/* Custom Attributes values */

/*! @brief Maximal value for switch type attribute */
#define ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_MAX_VALUE \
  (ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_UNOCCUPIED)

/* Switch type attribute has no default value */

/*! @brief Permissible values for Occupancy Sensor Type attribute
    @see ZCL spec, subclause 4.8.2.2.1.2
*/
enum zb_zcl_occupancy_sensing_occupancy_sensor_type_e
{
  /*! PIR value */
  ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PIR                = 0,
  /*! Ultrasonic value */
  ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ULTRASONIC         = 1,
  /*! PIR and Ultrasonic value */
  ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PIR_AND_ULTRASONIC = 2,
  /*! Reserved value */
  ZB_ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_RESERVED           = 3
};


enum zb_zcl_custom_reporting_mode_type_e
{
  ZB_ZCL_CUSTOM_OCCUPANCY_SENSING_REPORING_MODE_TYPE_REGULAR_REPORTING                = 0,
  ZB_ZCL_CUSTOM_OCCUPANCY_SENSING_REPORING_MODE_TYPE_LOW_POWER_REPORTING              = 1
};


enum zb_zcl_custom_debug_mode_type_e
{
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_DEBUG_MODE_TYPE_SHORT                = 0,
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_DEBUG_MODE_TYPE_ENHANCED             = 1,
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_DEBUG_MODE_TYPE_DEBUG                = 2
};

enum zb_zcl_custom_learn_type_e
{
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_LEARN_NOT_YET_PERFORMED       = 0,
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_LEARN_IN_PROGRESS             = 1,
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_LEARN_FINISHED_WITH_A_FAILURE = 2,
  ZB_ZCL_OCCUPANCY_SENSING_CUSTOM_LEARN_FINISHED_SUCCSESSFULLY  = 3
};


#define ZB_SET_ATTR_DESCR_WITH_ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_ID(data_ptr) \
  {                                                                                 \
    ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_ID,                                     \
    ZB_ZCL_ATTR_TYPE_8BITMAP,                                                       \
    ZB_ZCL_ATTR_ACCESS_READ_ONLY | ZB_ZCL_ATTR_ACCESS_REPORTING,                    \
    (zb_voidp_t) data_ptr                                                           \
  }

#define ZB_SET_ATTR_DESCR_WITH_ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ID(data_ptr) \
  {                                                                                             \
    ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ID,                                     \
    ZB_ZCL_ATTR_TYPE_8BIT_ENUM,                                                                 \
    ZB_ZCL_ATTR_ACCESS_READ_ONLY,                                                               \
    (zb_voidp_t) data_ptr                                                                       \
  }

/** @internal @brief Declare attribute list for Occupancy Sensing cluster
    @param attr_list - attribure list name
    @param switch_type - pointer to variable to store switch type attribute value
    @param switch_actions - pointer to variable to store switch action attribute value
*/
#define ZB_ZCL_DECLARE_OCCUPANCY_SENSING_ATTRIB_LIST(attr_list, occupancy, occupancy_sensor_type)       \
  ZB_ZCL_START_DECLARE_ATTRIB_LIST(attr_list)                                                           \
  ZB_ZCL_SET_ATTR_DESC(ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_ID, (occupancy))                         \
  ZB_ZCL_SET_ATTR_DESC(ZB_ZCL_ATTR_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ID, (occupancy_sensor_type)) \
  ZB_ZCL_FINISH_DECLARE_ATTRIB_LIST

/** @internal Number of attributes mandatory for reporting on Occupancy Sensing cluster */
#define ZB_ZCL_OCCUPANCY_SENSING_REPORT_ATTR_COUNT 1

/*! @} */ /* Occupancy Sensing cluster attribute structures */

/*! @} */ /* ZCL Occupancy Sensing cluster definitions */

/** @endcond */ /* DOXYGEN_ZCL_SECTION */

#define ZB_ZCL_CLUSTER_ID_OCCUPANCY_SENSING_SERVER_ROLE_INIT (zb_zcl_cluster_init_t)NULL
#define ZB_ZCL_CLUSTER_ID_OCCUPANCY_SENSING_CLIENT_ROLE_INIT (zb_zcl_cluster_init_t)NULL

#endif /* ! defined ZB_ZCL_OCCUPANCY_SENSING_H */
