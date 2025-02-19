// Project 32.1: WiFi Station.
// This project sets up an ESP32 in WiFi station mode.

#include <WiFi.h>

// WiFi Router and password variables:  
const char *ssid_Router     = ""; //Enter the router name
const char *password_Router = ""; //Enter the router password

void setup(){
    // Initialize serial connection with ESP32 via USB:
    Serial.begin(115200);

    //Add some delay:
    delay(2000);

    // Print a message to the console notifying 
    Serial.println("Setup start");

    // Initialize WIFI connection:
    WiFi.begin(ssid_Router, password_Router);
    Serial.println(String("Connecting to ")+ssid_Router);
    
    // Display counter as connection is processed:
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
  
    // After WIFI connection is established:

    // Display connection message and IP address: 
    Serial.println("\nConnected with IP address: ");
    Serial.println(WiFi.localIP());

    // Display completion message: 
    Serial.println("WiFi setup completed.");
}
 
void loop() {
}
