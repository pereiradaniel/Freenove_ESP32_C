// Project 22.1: 4x4 Matrix Keypad

#include <Keypad.h>

// Define keypad matrix:
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect row pins of the keypad:
byte rowPins[4] = {14, 27, 26, 25};

// Connect column pins of the keypad:
byte colPins[4] = {13, 21, 22, 23};

// Initialize an instance of class NewKeypad:
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
    // Open serial connection with ESP32 over USB:
  Serial.begin(115200);

  // Print ready message to the serial monitor:
  Serial.println("ESP32 is ready!");
}

void loop() {
  // Get input:
  char keyPressed = myKeypad.getKey();

  // If a key is pressed, send output to the serial monitor:
  if (keyPressed)
    Serial.println(keyPressed);
}
