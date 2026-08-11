#ifndef MQTT_H
#define MQTT_H
#include "includes.h"
#include "mqtt_client.h"
void mqtt_setup(void);
static void mqtt_event_handler(void* event_handler_arg,
                                    esp_event_base_t event_base,
                                    int32_t event_id,
                                    void* event_data);
#endif