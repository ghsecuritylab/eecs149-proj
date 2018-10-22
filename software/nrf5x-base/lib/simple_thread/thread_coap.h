#pragma once

#include <stdint.h>

#include <openthread/openthread.h>
#include <openthread/coap.h>

void thread_coap_client_init(otInstance* instance);
void thread_coap_send(otInstance* instance, otCoapCode req, otCoapType type, otIp6Address* dest, const char* path, const uint8_t* data, size_t len);
