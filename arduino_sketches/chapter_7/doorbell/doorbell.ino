// Objective: Operate an active buzzer with a push button.
#define PIN_BUZZER 13   // GPIO pin to buzzer.
#define PIN_BUTTON 4    // GPIO pin to button.

void setup() {
    // Set GPIO pins for either OUTPUT or INPUT:
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_BUZZER,HIGH);
  }else{
    digitalWrite(PIN_BUZZER,LOW);
  }
}