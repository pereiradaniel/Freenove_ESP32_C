// Objective: Turn on LEDs in an LED bar so that the light bounces back and forth.

// Array of GPIO pins for LEDs:
byte LEDpins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23};

// Sets value of LEDcounter to number of pins listed in LEDpins:
int LEDcounter = sizeof(LEDpins);

void setup()
{
    // Iterate through LEDpins and set them all to OUTPUT:
    for (int i = 0; i < LEDcounter; ++i)
      pinMode(LEDpins[i], OUTPUT);
}

void loop() {

  // Turns on LEDs in ascending order:
  for (int i = 0; i < LEDcounter; ++i) {
    digitalWrite(LEDpins[i], HIGH);
    delay(100);
    digitalWrite(LEDpins[i], LOW);
  }

  // Turns on LEDs in descending order:
  for (int i = LEDcounter - 1; i > -1; --i) {
    digitalWrite(LEDpins[i], HIGH);
    delay(100);
    digitalWrite(LEDpins[i], LOW);
  }
}
