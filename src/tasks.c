#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

typedef struct {
    uint32_t interval_ms;
    gpio_num_t pin;
} led_config_t;

static led_config_t red_led = {
    .interval_ms = 200,
    .pin = GPIO_NUM_16,
};

static led_config_t yellow_led = {
    .interval_ms = 500,
    .pin = GPIO_NUM_17,
};

static led_config_t green_led = {
    .interval_ms = 1000,
    .pin = GPIO_NUM_18,
};

static void led_task(void *arg)
{
    led_config_t *led = (led_config_t *)arg;

    bool enabled = false;

    while (1) {
        enabled = !enabled;

        gpio_set_level(
            led->pin,
            enabled ? 0 : 1
        );

        vTaskDelay(pdMS_TO_TICKS(led->interval_ms));
    }
}

void app_main(void)
{
    gpio_config_t io_conf = {
        .pin_bit_mask =
            (1ULL << red_led.pin) |
            (1ULL << yellow_led.pin) |
            (1ULL << green_led.pin),

        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&io_conf);

    gpio_set_level(red_led.pin, 1);
    gpio_set_level(yellow_led.pin, 1);
    gpio_set_level(green_led.pin, 1);

    xTaskCreate(
        led_task,
        "red_led_task",
        2048,
        &red_led,
        5,
        NULL
    );

    xTaskCreate(
        led_task,
        "yellow_led_task",
        2048,
        &yellow_led,
        5,
        NULL
    );

    xTaskCreate(
        led_task,
        "green_led_task",
        2048,
        &green_led,
        5,
        NULL
    );
}