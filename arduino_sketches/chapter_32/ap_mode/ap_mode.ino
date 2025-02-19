// Project 32.2: ESP32 as an Accesss Point (AP)

// This project requires the WiFi library header file for the ESP32:
#include <WiFi.h>

// Name of WiFi hotspot and password:
const char *ssid_AP = "";
const char *password_AP = "";

// Set the IP address of ESP32 itself:
IPAddress local_IP(192,168,1,100);

// Set the gateway of ESP32 itself:
IPAddress gateway(192,168,1,10);

// Set the subnet mask for ESP32 itself:
IPAddress subnet(255,255,255,0);

void setup(){
  // Initialize serial connection between ESP32 via USB:
  Serial.begin(115200);
  
  // Add some delay:
  delay(2000);

  // Prints message to serial monitor notifying that set up is beginning:
  Serial.println("Initializing soft-AP configuration...");
  
  // Disconnect any existing WiFi first:
  WiFi.disconnect();
  
  // Sets WiFi mode:
  WiFi.mode(WIFI_AP);
  
  // Print a message to the serial monitor with WiFi connection settings and print ready message ELSE notify of failure:
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  // Print message to serial monitor notifying that AP set up is beginning:
  Serial.println("Setting soft-AP...");


  boolean result = WiFi.softAP(ssid_AP, password_AP);
  
  if (result) {
    Serial.println("Ready");
    Serial.println(String("Soft-AP IP address = ") + WiFi.softAPIP().toString());
    Serial.println(String("MAC address = ") + WiFi.softAPmacAddress().c_str());
  } else {  
  Serial.println("Failed!");
}

Serial.println("Setup End");
}
 
void loop() {
}