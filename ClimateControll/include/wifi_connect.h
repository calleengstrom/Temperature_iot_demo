#ifndef WIFI_CONNECT_H
#define WIFI_CONNECT_H
#include "./includes.h"



#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK
#define ESP_WIFI_SAE_MODE WPA3_SAE_PWE_BOTH
#define EXAMPLE_H2E_IDENTIFIER ""

void wifi_init_sta(void);
bool wifi_connect(void);
void wifi_stop(void);

#endif