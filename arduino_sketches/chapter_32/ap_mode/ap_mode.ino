// Project 32.2

#include <WiFi.h>

const char *ssid_AP     = "";
const char *password_AP = "";

IPAddress local_IP(192,168,1,100);  // Set the IP address of ESP32 itself
IPAddress gateway(192,168,1,10);    // Set the gateway of ESP32 itself
IPAddress subnet(255,255,255,0);    // Set the subnet mask for ESP32 itself

void setup(){
    Serial.begin(115200);
    delay(2000);

    Serial.println("Setting soft-AP configuration ... ");
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
    Serial.println("Setting soft-AP ... ");
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