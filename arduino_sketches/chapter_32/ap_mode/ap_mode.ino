// Project 32.2: ESP32 as an Accesss Point (AP)

// Objective: Puts the ESP32 into WiFi Access Point mode, and setting up an access point that you can connect to.

// This project requires the WiFi library header file for the ESP32:
#include <WiFi.h>

// Name of WiFi hotspot and password that will be created with the ESP32:
const char *ssid_AP = "esp32wifiap";
const char *password_AP = "esp32wifiap";

// Sets the IP address of ESP32:
IPAddress local_IP(192,168,1,100);

// Sets the gateway of ESP32:
IPAddress gateway(192,168,1,10);

// Sets the subnet mask for ESP32:
IPAddress subnet(255,255,255,0);

void setup(){
  // Initialize serial connection between ESP32 via USB:
  Serial.begin(115200);
  
  // Add some delay:
  delay(2000);

  // Prints message to serial monitor notifying that set up is beginning:
  Serial.println("Initializing WiFi configuration...");
  
  // Disconnect any existing WiFi first:
  WiFi.disconnect();
  
  // Puts ESP32 into AP (Access Point) WiFi mode:
  WiFi.mode(WIFI_AP);
  
  // Configures IP address, gateway, and subnet mask for the ESP32, and prints either success or failure message to the serial monitor:
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  // Print message to serial monitor notifying that AP set up is beginning:
  Serial.println("Beginning softAP set-up...");

  // Start the Wi-Fi as an Access Point:
  boolean result = WiFi.softAP(ssid_AP, password_AP);
  
  if (result) {
    Serial.println("Success! Access Point is ready.");
    Serial.println(String("IP address = ") + WiFi.softAPIP().toString());
    Serial.println(String("MAC address = ") + WiFi.softAPmacAddress().c_str());
  } else {  
  Serial.println("Failed! Access Point is not available.");
  }

  Serial.println("Finished.");
}
 
void loop() {
}
