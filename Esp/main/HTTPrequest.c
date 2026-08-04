#include "esp_http_client.h"
#include "esp_log.h"
#include "../include/HTTPrequest.h"
#include "../include/data_t.h"
#include "../include/config.h"
static const char *TAG = "HTTP_CLIENT";

// ==================== SKICKA DATA ====================
void send_temperature_data(DATA_T data)
{
    char url[256];
    char json_string[128];

    snprintf(url, sizeof(url),
             WEB_API);

    snprintf(json_string, sizeof(json_string),
             "{\"temp\":%d.%d,\"hum\":%d.%d,\"room\":\"%s\"}",
             data.temp / 10, data.temp % 10,
             data.hum / 10, data.hum % 10,
             data.room);

    esp_http_client_config_t config = {
        .url = url,
        .method = HTTP_METHOD_POST,
        .timeout_ms = 5000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_header(client, "Content-Type", "application/json");

    esp_http_client_set_post_field(
        client,
        json_string,
        strlen(json_string));

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        int status = esp_http_client_get_status_code(client);
        ESP_LOGI(TAG, "Data skickad! Status = %d", status);
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET misslyckades: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
}

void clear_temperature_data()
{
    char url[256];

    snprintf(url, sizeof(url),
             "http://%s:%s/Temp/Delete",
             WEB_HOST, WEB_PORT);

    esp_http_client_config_t config = {
        .url = url,
        .method = HTTP_METHOD_GET,
        .timeout_ms = 5000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        int status = esp_http_client_get_status_code(client);
        ESP_LOGI(TAG, "Data rensad! Status = %d", status);
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET misslyckades: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
}