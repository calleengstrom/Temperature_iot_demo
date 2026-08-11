#include "../include/config.h"
#include "../include/rgb.h"
#include "../include/wifi_connect.h"
#include "../include/mqtt_sub.h"
void climate_task(void *args){
    while (1)
    {
       
        
        vTaskDelay(pdMS_TO_TICKS(2000));
        red_on();
        vTaskDelay(pdMS_TO_TICKS(2000));
        green_on();
        vTaskDelay(pdMS_TO_TICKS(2000));
        blue_on();
        vTaskDelay(pdMS_TO_TICKS(2000));
        magneta_on();
        vTaskDelay(pdMS_TO_TICKS(2000));
    } 
}

void app_main(void)
{

    rgb_init();
    wifi_connect();
    mqtt_setup();
    //xTaskCreatePinnedToCore(climate_task,"climate_task",8192,NULL,22,NULL,0);
}
