// Project 21.2: Ultrasonic Ranging using the library

// Import the Ultrasonic Sensor library:
#include <UltrasonicSensor.h>

// Define an ultrasonic object and the pins:
// Trigger pin: 13
//    Echo pin: 14
UltrasonicSensor ultrasonic(13, 14);

void setup() {
  // Initialize a serial connection with the ESP32:
  Serial.begin(115200);
  
  // Set temperature variable:
  int temperature = 22;

  // Update the module with the temperature to produce more accurate results:
  ultrasonic.setTemperature(temperature);
}

void loop() {
    // Use the distanceInCentimeters() function to get the distance in cm:
    int distance = ultrasonic.distanceInCentimeters();
  
    // Prints a message to the serial monitor including the distance measured:
    Serial.printf("Distance: %dcm\n",distance);
  
    // Add some delay:
    delay(300);
}