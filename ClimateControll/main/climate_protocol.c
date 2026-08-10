#include "../include/climate_protocol.h"

climate_mode_t mqtt_protocol(char* mqtt_msg)
{
    if (strncmp(mqtt_msg,"NORMAL",sizeof("NORMAL")))
    {
        return NORMAL;
    }
    if (strncmp(mqtt_msg,"COOLING",sizeof("COOLING")))
    {
        return COOLING;
    }
    if (strncmp(mqtt_msg,"HEATING",sizeof("HEATING")))
    {
        return HEATING;
    }

    return UNKNOWN_CMD;
}
