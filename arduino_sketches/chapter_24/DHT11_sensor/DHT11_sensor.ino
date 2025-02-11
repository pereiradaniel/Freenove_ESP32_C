// Project 24.1: DHT11 Temperature and Humidity Sensor
// Objective: Read the temperature and humidity from the sensor and display on the terminal.

// DHT11 module requires this library:
#include "DHTesp.h"

// Create a class object for the DHT11:
DHTesp dht;

// GPIO connected to the DHT11:
int dhtPin = 13;

void setup() {
    // Initialize the DHT11 obejct and GPIO:
    dht.setup(dhtPin, DHTesp::DHT11);
  
    // Initialize a serial connection over usb with the ESP32:
    Serial.begin(115200);
}

void loop() {
    // Gets the Temperature and humidity from the DHT11:
    flag:TempAndHumidity newValues = dht.getTempAndHumidity();
  
    // Catches incorrect values and returns to flag to try again:
    if (dht.getStatus() != 0)
        goto flag;

    // Prints a message to the serial monitor with the temperature and humidity values:
    Serial.println(" Temperature:" + String(newValues.temperature) + 
    " Humidity:" + String(newValues.humidity));
    
    // Delay for 2 seconds before re-reading temperature and humidity again:
    delay(2000);
}