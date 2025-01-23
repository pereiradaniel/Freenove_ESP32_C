// Objective: Learn how to use the push button switch to control an LED.

// Step 1: Read the state of the switch.
// Step 2: Determine whether to turn the LED on.

#define LED     2       // Set LED to GPIO 2
#define BUTTON  13      // Set Push Button Pin to GPIO 13

void setup()
{
    // Initializes LED as an output:
    pinMode(LED, OUTPUT);

    // Initializes BUTTON as an input:
    pinMode(BUTTON, INPUT);
}

void loop()
{
    if (digitalRead(BUTTON) == LOW)   // button is pressed
        digitalWrite(LED, LOW);       // LED on
    else                              // button is not pressed
        digitalWrite(LED, HIGH);      // LED off
}
