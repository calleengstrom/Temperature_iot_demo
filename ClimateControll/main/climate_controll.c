#include "../include/mqtt_sub.h"
#include "../include/includes.h"
#include "../include/config.h"
#include "../include/rgb.h"
#include "../include/climate_protocol.h"

static const char *TAG = "Climate controller : ";

void climate_controller(esp_mqtt_event_handle_t event)
{
    char mqtt_msg[64];

    if (event->data_len >= sizeof(mqtt_msg))
    {
        ESP_LOGW(TAG, "Message too long!");
        return;
    }

    memcpy(mqtt_msg, event->data, event->data_len);
    mqtt_msg[event->data_len] = '\0';

    ESP_LOGI(TAG, "Message %s", mqtt_msg);

    switch (mqtt_protocol(mqtt_msg))
    {
    case NORMAL:
        green_on();
        break;
    case HEATING:
        red_on();
        break;
    case COOLING:
        blue_on();
        break;

    default:
        break;
    }

}
