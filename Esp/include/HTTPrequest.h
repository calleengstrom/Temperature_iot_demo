#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define WEB_HOST "192.168.0.192"
#define WEB_PORT "8080"
#define WEB_PATH "/"
#include "./data_t.h"
void send_temperature_data(DATA_T data);
void clear_temperature_data(void);
#endif