#include <Arduino.h>

struct Led {
  uint32_t interval;
  uint32_t lastToggle;
  uint8_t pin;
  bool enabled;
};

Led redLed    = {200,  0, 16, false};
Led yellowLed = {500,  0, 17, false};
Led greenLed  = {1000, 0, 18, false};

void update_led(Led& led) {
    uint32_t now = millis();

    if (now - led.lastToggle >= led.interval) {
        led.enabled = !led.enabled;
        led.lastToggle = now;
        digitalWrite(led.pin, led.enabled ? LOW : HIGH);
    }
}

void setup() {
  pinMode(redLed.pin, OUTPUT);
  pinMode(yellowLed.pin, OUTPUT);
  pinMode(greenLed.pin, OUTPUT);
}

void loop() {
  update_led(redLed);
  update_led(yellowLed);
  update_led(greenLed);
}
