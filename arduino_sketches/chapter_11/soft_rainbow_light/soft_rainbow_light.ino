// PROJECT 11.3
// Include WS2812 lib for ESP32:
// This is an Arduino library for controlling ws2812 led on ESP32!
#include "Freenove_WS2812_Lib_for_ESP32.h"

#define PIN_POT     13  // Analog input pins.
#define LEDS_COUNT  8   // Number of LEDs.
#define LEDS_PIN    2   // GPIO pin for LED module.
#define CHANNEL     0   // Channel for RMT module.
#define BRIGHTNESS  100 // Value range is from 0 to 255.

// Create a strip object:
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
    // Initialize LED strip:
    strip.setBrightness(BRIGHTNESS);
    
    // LED strip ready:
    strip.begin();
}

void loop() {
    // Initialize colour data:
    //      - Use analogRead() to get raw ADC value from potentiometer.
    //      - Calculate colour data using a scale of 0-255.
    int colourPos = map(analogRead(PIN_POT), 0, 4095, 0, 255);

    for (int i=0; i < LEDS_COUNT; ++i) {
        // Set the colour data:
        strip.setLedColorData(i,strip.Wheel(colourPos + i * 255 / 8));
    }

    // Send colour data to the LED strip and display:
    strip.show();
    delay(10);
}