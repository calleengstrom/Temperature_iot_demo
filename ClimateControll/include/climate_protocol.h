#ifndef CLIMATE_PROTCOL_H
#define CLIMATE_PROTCOL_H
#include "./includes.h"

#define CLIMATE_PROTOCOL_NORMAL "NORMAL"
#define CLIMATE_PROTOCOL_HEATING "HEATING"
#define CLIMATE_PROTOCOL_COOLING "COOLING"


typedef enum{
    NORMAL,
    HEATING,
    COOLING,
    UNKNOWN_CMD
}climate_mode_t;


climate_mode_t mqtt_protocol(char *mqtt_msg);

#endif