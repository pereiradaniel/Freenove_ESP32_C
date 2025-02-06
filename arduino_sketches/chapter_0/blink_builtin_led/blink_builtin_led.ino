// Set BOARD_LED to GPIO pin 2, which is the pin for the builtin LED on the ESP32 board.
#define GPIO_2 2

void setup()
{
        // Initializes GPIO_2 as an OUTPUT so that it can be set to HIGH or LOW.
        pinMode(GPIO_2, OUTPUT);
}

void loop()
{
    // Setting GPIO pin 2 to HIGH turns the LED OFF:
    digitalWrite(GPIO_2, HIGH);
    
    // Delay in milliseconds:
    delay(500);

    // Setting GPIO pin 2 to LOW tuns the LED ON:
    digitalWrite(GPIO_2, LOW);

    // Delay in milliseconds:
    delay(500);
}
