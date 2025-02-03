// GPIO Pin Setup:

    // Relay pin set to GPIO 13
    int relayPin = 13;
    // Push button pin set to GPIO 15
    int buttonPin = 15;

// Set up variables for storing values:

    // Value for storing button state (default set to HIGH):
    int buttonState = HIGH;
    // Value for storing the relay state (default set to LOW):
    int relayState = LOW;
    // Value for last button state recorded:
    int lastButtonState = HIGH;
    // Button change time point value:
    long lastChangeTime = 0;

void setup() {
    // Set push button to input mode:
    pinMode(buttonPin, INPUT_PULLUP);
    
    // Set relay pin to output mode:
    pinMode(relayPin, OUTPUT);

    // Set relay initial state to OFF:
    digitalWrite(relayPin, relayState);
}
void loop() {
    // Reads current state of button:
    int nowButtonState = digitalRead(buttonPin);
  
    // Records the time point if button state has changed:
    if (nowButtonState != lastButtonState) {
        lastChangeTime = millis();
    }
  
    // ANTI-BOUNCE!
    // Button state has changed, remained stable, past the bounce area:
    if (millis() - lastChangeTime > 10) {
        // Confirms button state has changed:
        if (buttonState != nowButtonState) {
        
            buttonState = nowButtonState;
      
            // LOW = button is pressed:
            if (buttonState == LOW) {
        
            // Reverses relay state:
            relayState = !relayState;

            // Updates relay state by writing to pin:
            digitalWrite(relayPin, relayState);
            }
        }
    }
    // Saves state of last button:
    lastButtonState = nowButtonState;
}