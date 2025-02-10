// ESP32Servo library is required in this project:
#include <ESP32Servo.h>

// Create a Servo class object:
Servo myservo;

// Initialize variables:
int posVal = 0;  // servo position
int servoPin = 15;  // servo motor pin

void setup() {
    // Standard 50 hz servo:
    myservo.setPeriodHertz(50);
  
    // Attach pin to the Servo object:
    // myservo.attach():
    //      pin: Port connected to servo signal line.
    //      low: Time of high level corresponding to 0 degrees.
    //      high: Time of high level corresponding to 180 degrees.
    myservo.attach(servoPin, 500, 2500);
}

void loop() {
    // MOVEMENT:
    //  Movement infinitely loops, and takes place in two phases:
    //      Phase 1:
    //          - Servo arm moves from 0 to 180 degrees.
    //      Phase 2:
    //          - Servo arm moves from 180 to 0 degrees.

    // Phase 1:
    for (posVal = 0; posVal <= 180; posVal += 1) {
        // Servo goes to position posVal:
        myservo.write(posVal);
        // Wait 15 ms for servo to reach end position:
        delay(15);
    }

    // Phase 2:
    for (posVal = 180; posVal >= 0; posVal -= 1) { 
        // Servo goes to position posVal:
        myservo.write(posVal);
        // Wait 15 ms for servo to reach end position:
        delay(15);
    }
}