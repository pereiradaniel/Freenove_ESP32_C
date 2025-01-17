// Set BOARD_LED to GPIO pin 2, which is the pin for the builtin LED on the ESP32 board.
# define BOARD_LED 2

void setup()
{
        // Initializes BOARD_LED as an OUTPUT so that it can be set to HIGH or LOW.
        pinMode(BOARD_LED, OUTPUT);
}

void loop()
{
    // Setting GPIO pin 2 to HIGH turns the LED OFF:
    digitalWrite(BOARD_LED, HIGH);
    
    // Delay in milliseconds:
    delay(500);

    // Setting GPIO pin 2 to LOW tuns the LED ON:
    digitalWrite(BOARD_LED, LOW);

    // Delay in milliseconds:
    delay(500);
}