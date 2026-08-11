#include "../include/mqtt_sub.h"
#include "../include/includes.h"
#include "../include/config.h"
#include "../include/rgb.h"
#include "../include/climate_protocol.h"
static const char *TAG = "MQTT : ";

static void mqtt_event_handler(void *event_handler_arg,
                               esp_event_base_t event_base,
                               int32_t event_id,
                               void *event_data)
{

    esp_mqtt_event_handle_t event = event_data;

    switch (event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "Connected");
        esp_mqtt_client_subscribe(event->client, "climate/office", 1);
        break;
    case MQTT_EVENT_DATA:
        char mqtt_msg[64];

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

        break;
    default:
        break;
    }
};

void mqtt_setup(void)
{

    const esp_mqtt_client_config_t mqtt_conf = {
        .broker.address.uri = MY_MQTT_BROKER_URI,
        .credentials.username = MY_MQTT_BROKER_USERNAME,
        .credentials.authentication.password = MY_MQTT_BROKER_PASSOWRD,
    };
    esp_mqtt_client_handle_t mqtt_client = esp_mqtt_client_init(&mqtt_conf);
    esp_mqtt_client_register_event(mqtt_client, ESP_EVENT_ANY_ID, mqtt_event_handler, mqtt_client);
    esp_mqtt_client_start(mqtt_client);
}
