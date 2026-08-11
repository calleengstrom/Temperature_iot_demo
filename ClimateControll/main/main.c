#include "../include/config.h"
#include "../include/rgb.h"
#include "../include/wifi_connect.h"
#include "../include/mqtt_sub.h"


void app_main(void)
{

    rgb_init();
    wifi_connect();
    mqtt_setup();
    
}
