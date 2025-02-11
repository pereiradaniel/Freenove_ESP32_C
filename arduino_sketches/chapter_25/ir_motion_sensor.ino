// Project 25.1: Infrared Motion Sensor
// Objective: Lights up LED whenever motion is detected from the IR module.

// IR sensor is connected to GPIO 14:
int sensorPin = 14;

// LED is connected to GPIO 13:
int ledPin = 13;

void setup() {
    // Initializes sensor pin as an input:
    pinMode(sensorPin, INPUT);

    // Initializes LED pin as an output:
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Turn LED ON or OFF according to Infrared Motion Sensor:
    digitalWrite(ledPin, digitalRead(sensorPin));
    
    // Interval between IR sensor readings:
    delay(1000);
}