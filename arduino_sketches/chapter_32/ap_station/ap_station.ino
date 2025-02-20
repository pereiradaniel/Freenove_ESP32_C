// Project 32.3: AP + Station Mode

#include <WiFi.h>

// The name and password of the internet router that the ESP32 will be connecting to for an internet connection:
const char *ssid_Router     =  "********";
const char *password_Router =  "********";

// The name and password of the Access Point that will be set up by the ESP32:
const char *ssid_AP         =  "ESP32HOTSPOT";
const char *password_AP     =  "ESP32HOTSPOT";

void setup(){
  Serial.begin(115200);
  Serial.println("Setting up ESP32 Access Point...");
  
  // Disconnect from anything that might be connected:
  WiFi.disconnect();
  
  // Put the ESP32 into WiFi Access Point mode:
  WiFi.mode(WIFI_AP);

  Serial.println("Setting soft-AP ... ");

  // Attempt to start ESP32 Access Point:
  boolean result = WiFi.softAP(ssid_AP, password_AP);

  if(result){
    Serial.println("Success! ESP32 Access Point available.");
    Serial.println(String("IP address = ") + WiFi.softAPIP().toString());
    Serial.println(String("MAC address = ") + WiFi.softAPmacAddress().c_str());
  }else{
    Serial.println("Failed! ESP32 Access Point not available.");
  }
  
  // Begin to put the ESP32 in Station mode to connect with internet router:
  Serial.println("\nSetting up Station mode...");
  
  // Attempt to connect with internet router using name and password:
  WiFi.begin(ssid_Router, password_Router);
  
  // Display connection message on the serial monitor:
  Serial.println(String("Connecting to ")+ ssid_Router);
  
  // Print output to the serial monitor while connection is established:
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  // Print successful connection message:
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());

  // Print message notifying that setup is complete:
  Serial.println("Setup End");
}

void loop() {
}