#define PIN_ANALOG_IN   4       // Analog pin for photoresistor.
#define PIN_LED         12      // GPIO pin for LED.
#define CHANNEL         0       // LEDC Channel
#define LIGHT_MIN       372     // Value for min light.
#define LIGHT_MAX       2048    // Value for max light.

void setup() {
    // Setup LEDC pin:
    //      PIN:            PINLED (GPIO 12)
    //      Frequency:      1000
    //      Resolution:     12 bits
    //      LEDC Channel:   CHANNEL (0)
    ledcAttachChannel(PIN_LED, 1000, 12, CHANNEL);
}

void loop() {
    // Get raw ADC value from photoresistor:
    int adcValue = analogRead(PIN_ANALOG_IN);

    // Calculate pwm value and constrain between LIGHT_MIN and LIGHT_MAX:
    int pwmValue = map(constrain(adcValue, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0, 4095);

    // Set the duty for the LED:
    ledcWrite(PIN_LED, pwmValue);

    // Add some delay:
    delay(10);
}
