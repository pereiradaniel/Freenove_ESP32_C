// Project 27.1: Bluetooth Passthrough

// Include the Bluetooth Serial library:
#include "BluetoothSerial.h"

// Instantiate a BluetoothSerial object to work with:
BluetoothSerial SerialBT;

// Create a String buffer to handle text:
String buffer;

void setup() {
    // Initialize a serial connection with the ESP32 over USB:
    Serial.begin(115200);
  
    // Initialize the BluetoothSerial device with a name:
    SerialBT.begin("Daniel's ESP32-WROVER"); //Bluetooth device name
  
    Serial.println("\nDevice started, and ready to pair with Bluetooth.");
}

void loop() {
    // Check if Serial has a message, and then write it to the Bluetooth device:
    if (Serial.available())
        SerialBT.write(Serial.read());

    // Check if Bluetooth has a message, and then write it to the serial monitor:
    if (SerialBT.available())
        Serial.write(SerialBT.read());
    
    // Add 20 ms for delay:
    delay(20);
}