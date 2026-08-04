#include <stdio.h>
#include <stdbool.h>
#include <driver/gpio.h>
#include <esp_err.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"

#define RED_GPIO GPIO_NUM_32
void app_main(void)
{
    while(1){
    gpio_set_direction(RED_GPIO,GPIO_MODE_DEF_OUTPUT);

    gpio_set_level(RED_GPIO, 1);

    vTaskDelay(pdMS_TO_TICKS(2000));
    
    gpio_set_level(RED_GPIO, 0);

    vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
