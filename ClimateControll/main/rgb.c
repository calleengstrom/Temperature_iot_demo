
#include "../include/rgb.h"
#include "../include/includes.h"

void all_off()
{
    gpio_set_level(RED_RGB, 0);
    gpio_set_level(GREEN_RGB, 0);
    gpio_set_level(BLUE_RGB, 0);
}
void rgb_init(void)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << RED_RGB) | (1ULL << GREEN_RGB) | (1ULL << BLUE_RGB),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE};

    if (gpio_config(&io_conf) == ESP_OK)
    {
        ESP_LOGI("RGB INIT : ", "RGB GIPOS INIT OK !");
    }
    else
    {
        ESP_LOGI("RGB INIT : ", "RGB GIPOS INIT FAILED !");
    }
    all_off();
}

void red_on(void)
{
    all_off();
    gpio_set_level(RED_RGB, 1);
}

void green_on(void)
{
    all_off();
    gpio_set_level(GREEN_RGB, 1);
}

void blue_on(void)
{
    all_off();
    gpio_set_level(BLUE_RGB, 1);
}

void magneta_on(void)
{
    all_off();
    gpio_set_level(RED_RGB, 1);
    gpio_set_level(BLUE_RGB, 1);
}
