#ifndef CLIMATE_PROTCOL_H
#define CLIMATE_PROTCOL_H
#include "./includes.h"


typedef enum{
    NORMAL,
    HEATING,
    COOLING,
    UNKNOWN_CMD
}climate_mode_t;


climate_mode_t mqtt_protocol(char *mqtt_msg);

#endif