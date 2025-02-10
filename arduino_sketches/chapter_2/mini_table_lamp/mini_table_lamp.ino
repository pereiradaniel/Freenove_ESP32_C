// Objective: Learn how to debounce a push button switch.

#define LED 2
#define BUTTON 13

void setup() {
    pinMode(LED,    OUTPUT);
    pinMode(BUTTON, INPUT);
}

void loop(){
  // Judge the push button state:
  //    - If detected as pressed down, wait for a time to detect again, to eleminate effect of bounce.
  if (digitalRead(BUTTON) == LOW) {
      delay(20);
      if (digitalRead(BUTTON) == LOW) {
          // When confirmed, flip the LED on or off:
          reverseGPIO(LED);
      }
      // Wait for button to be released, with a delay to eleminate the effect of bounce after release:
      while (digitalRead(BUTTON) == LOW);
      delay(20);
  }
}

// Reads the state value of specified pin, then sets it to the reverse:
void reverseGPIO(int pin) {
    digitalWrite(pin, !digitalRead(pin));
}
