// Project 27.3: LED controlled through Bluetooth.

#include "BluetoothSerial.h"
#include "string.h"

// GPIO for LED:
#define LED 2

// Instantiate BluetoothSerial object to work with:
BluetoothSerial SerialBT;

char buffer[20];

static int count = 0;

void setup() {
    // Set LED pin to OUTPUT:
    pinMode(LED, OUTPUT);

    // Start Bluetooth device and give it a name:
    SerialBT.begin("Daniel's ESP32 LED controller.");

    // Start a serial connection with the ESP32 over usb:
    Serial.begin(115200);

    // Send ready message to serial monitor:
    Serial.println("\nDevice started, ready to be paired over Bluetooth.");
}

void loop() {
    while(SerialBT.available())
    {
        buffer[count] = SerialBT.read();
        ++count;
    }
    if(count>0){
        Serial.print(buffer);
        
        if(strncmp(buffer,"led_on",6)==0)
            digitalWrite(LED,HIGH);

        if(strncmp(buffer,"led_off",7)==0)
            digitalWrite(LED,LOW);

        // Reset counter:
        count=0;

        memset(buffer,0,20);
    }
}