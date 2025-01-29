#define PIN_ANALOG_IN 4
#define PIN_LED       25
#define CHAN          0

void setup() {
    Serial.begin(115200);

    // Setup LEDC pin with frequency, resolution, and channel:
    //      LEDC pin:                       PIN_LED (GPIO 25)
    //      Frequency of PWM:               1000
    //      Resolution for LEDC channel:    12 bits
    //      Channel:                        CHAN (0)
    ledcAttachChannel(PIN_LED, 1000, 12, CHAN);

    // Print a message to the console with initialilzation data:
    Serial.printf("Analog in: %d\nLED pin: %d\nChannel: %d\n", PIN_ANALOG_IN, PIN_LED, CHAN);
}

void loop() {
    // analogRead():
    //      Gets ADC raw value for a given pin/ADC channel.
    int adc = analogRead(PIN_ANALOG_IN);

    // Re-map adc to pwm:
    int pwm = adc;

    // Set the LEDC duty to the pulse width of pwm:
    // ledcWrite():
    //      Used to set duty for the LEDC pin.
    //      LEDC pin:   PIN_LED (GPIO 25)
    //      LEDC duty:  pwm (read from PIN_ANALOG_IN (GPIO 4))
    ledcWrite(PIN_LED, pwm);
    
    // Print a message to the console:
    Serial.printf("PWM/LEDC duty: %d\n", pwm);
    
    // Add some delay:
    delay(10);
}
