#include "../include/climate_protocol.h"
static const char *TAG = "PROTOCOL : ";
climate_mode_t mqtt_protocol(char* mqtt_msg)
{
    if (strncmp(mqtt_msg,CLIMATE_PROTOCOL_NORMAL,sizeof(CLIMATE_PROTOCOL_NORMAL)))
    {
        ESP_LOGI(TAG,"Normal");
        return NORMAL;
    }
    if (strncmp(mqtt_msg,CLIMATE_PROTOCOL_COOLING,sizeof(CLIMATE_PROTOCOL_COOLING)))
    {
        ESP_LOGI(TAG,"Cooling");
        return COOLING;
    }
    if (strncmp(mqtt_msg,CLIMATE_PROTOCOL_HEATING,sizeof(CLIMATE_PROTOCOL_HEATING)))
    {
        ESP_LOGI(TAG,"heating");
        return HEATING;
    }
    ESP_LOGI(TAG,"unknown");
    return UNKNOWN_CMD;
}
