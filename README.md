# Battery Monitor

An embedded voltage monitoring system built on the STM32F103 microcontroller. Displays real-time voltage readings on an SSD1306 OLED display with button-controlled UI and UART data logging.

## Features

- Real-time voltage measurement using a 10kΩ/3kΩ resistor voltage divider
- SSD1306 128x64 OLED display over I2C
- Button-toggled UI: intro screen ↔ voltage measurement screen
- LED indicator — on when monitoring, blinks when battery is low
- Low battery warning at configurable threshold (default 3.50V)
- UART data logging at 115200 baud (`timestamp_ms,voltage` format)
- Modular code architecture (adc_voltage, ui, button modules)

## Hardware

| Component | Pin |
|-----------|-----|
| Voltage input (via divider) | PA0 |
| LED | PA1 |
| OLED SDA | PB9 |
| OLED SCL | PB8 |
| Button | PC13 |
| UART TX (to ST-Link) | PA2 |

## Voltage Divider

```
VIN+ ── 10kΩ ── PA0 ── 3kΩ ── GND
```

Safe input range: 0–14V. STM32 ADC sees max 3.3V.

## Getting Started

1. Clone the repo and open in STM32CubeIDE
2. Build and flash to STM32F103 board
3. Press the button to switch from intro screen to voltage display
4. Open a serial terminal at 115200 baud to view UART voltage logs

## Project Structure

```
Core/
  Inc/
    adc_voltage.h   — ADC voltage reading interface
    button.h        — Button debounce interface
    ui.h            — OLED display interface
  Src/
    adc_voltage.c   — ADC read + voltage scaling
    button.c        — Button edge detection + debounce
    ui.c            — OLED screen rendering
    main.c          — Main application loop
```

## Tools & Technologies

- STM32CubeIDE / STM32CubeMX
- STM32 HAL Library
- C (embedded)
- I2C, ADC, UART, GPIO peripherals
- SSD1306 OLED library (afiskon/stm32-ssd1306)
