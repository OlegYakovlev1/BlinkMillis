# Multi LED Blinking with `millis()` on ESP32

This project demonstrates how to control multiple independent processes inside a single `loop()` without blocking execution.

Three LEDs blink simultaneously with different intervals:

- LED1 — every 200 ms
- LED2 — every 500 ms
- LED3 — every 1000 ms

The project uses the `millis()` function instead of `delay()`, allowing all LEDs to work independently and continuously.

---

## Features

- Non-blocking programming approach
- Multiple independent timers
- Uses `struct` to organize LED data
- Clean and reusable update function
- Compatible with ESP32 and Arduino framework

---

## Hardware

- ESP32
- 3 LEDs
- 3 resistors (220Ω recommended)
- Breadboard and jumper wires

---

## GPIO Pins

| LED | GPIO |
|------|------|
| Red LED | 16 |
| Yellow LED | 17 |
| Green LED | 18 |

---

## How It Works

Each LED stores:

- blink interval
- last toggle timestamp
- GPIO pin
- current state

Inside `loop()`, the program continuously checks whether enough time has passed using `millis()`.

If the interval is reached, the LED state is toggled without stopping the execution of other tasks.

This approach is commonly used in embedded systems for cooperative multitasking and responsive applications.

---

## Concepts Used

- `millis()`
- Non-blocking timing
- `struct`
- Functions with references
- GPIO output control
- Superloop architecture

---

## Result

All three LEDs blink independently at different speeds while the ESP32 continues executing the main loop without blocking.
