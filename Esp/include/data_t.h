#ifndef DATA_T_H
#define DATA_T_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

typedef struct
{
    char *room;
    int16_t temp;
    int16_t hum;
    
} DATA_T;

#endif