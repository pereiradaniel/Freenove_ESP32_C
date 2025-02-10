// Include the IR receiver library:
#include "Freenove_IR_Lib_for_ESP32.h"

// GPIO pin 15 is connected to IR receiver:
const uint16_t recvPin = 15;

// Initialize a class object for the IR receiver:
Freenove_ESP32_IR_Recv ir_recv(recvPin);

// Initializes GPIO pin for LED:
int ledPin = 14;

// Initializes GPIO pin for the buzzer:
int buzzerPin = 13;

void setup(){
    // Sets: frequency, solution_bits, GPIO channel.
    ledcAttachChannel(ledPin, 1000, 8, 0);
    
    // Set buzzer pin to OUTPUT mode:
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    // Receive IR data:
    ir_recv.task();
  
    // Check NEC protocol:
    if(ir_recv.nec_available()) {
        // Handle the commands from the remote control:
        handleControl(ir_recv.data());
    }
}

void handleControl(unsigned long value) {
  // Make a beep when the button press is received:
  digitalWrite(buzzerPin, HIGH);
  
  // Length of buzzer sound:
  delay(100);

  digitalWrite(buzzerPin, LOW);
  
    switch (value) {
        // Button pressed: 0
        case 0xff6897:
            // Turn off LED:
            ledcWrite(ledPin, 0);
        break;

        // Button pressed: 1
        case 0xff30cf:
            // Lowest brightness:
            ledcWrite(ledPin, 7);
        break;

        // Button pressed: 2
        case 0xff18e7:
            // Medium brightness:
            ledcWrite(ledPin, 63);
        break;

        // Button pressed: 3
        case 0xff7a85:
            // Strongest bightness:
            ledcWrite(ledPin, 255);
        break;
    }
}