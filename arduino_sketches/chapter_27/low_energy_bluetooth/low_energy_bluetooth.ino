// Project 27.2: Low Energy Bluetooth

// Objective:
//      Establish a serial connection with the ESP32 over USB.
//      Connect the ESP32 with a mobile device via Bluetooth.
//      Transmit text messages between the serial monitor and the mobile device using the serial and Bluetooth connections.

#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEUtils.h"
#include "BLE2902.h"

// Instantiate a BLECharacteristic: 
BLECharacteristic *pCharacteristic;

// Boolean that informs the program whether a device is connected: 
bool deviceConnected = false;
 
// Tracks time since last message received:
long lastMsg = 0;

// Initializes message rx buffer with text:
String rxload="Test\n";
 
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" 
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"
 
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        deviceConnected = true;
    };
    
    void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
        
        //pServer->getAdvertising()->start();  //Reopen the pServer and wait for the connection.
    }
};
 
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
        String rxValue = pCharacteristic->getValue();
      
        if (rxValue.length() > 0) {
            rxload="";
        
            for (int i = 0; i < rxValue.length(); i++)
                rxload +=(char)rxValue[i];
        }
    }
};
 
void setupBLE(String BLEName){
    // 1. Create a BLE Server:
    const char *ble_name=BLEName.c_str();
    
    BLEDevice::init(ble_name);
    
    BLEServer *pServer = BLEDevice::createServer();
    
    pServer->setCallbacks(new MyServerCallbacks());
  
    // 2. Create a BLE Service:
    BLEService *pService = pServer->createService(SERVICE_UUID);

    // 3. Create a BLE Characteristic on the Service:
    pCharacteristic= pService->createCharacteristic(CHARACTERISTIC_UUID_TX,BLECharacteristic::PROPERTY_NOTIFY);
    
    // 4. Create a BLE Descriptor on the Charactersitic:
    pCharacteristic->addDescriptor(new BLE2902());
    
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX,BLECharacteristic::PROPERTY_WRITE);
    
    pCharacteristic->setCallbacks(new MyCallbacks()); 
    
    // 5. Start the Service:
    pService->start();
    
    // 6. Start the advertising:
    pServer->getAdvertising()->start();
    
    // Prints a waiting message to the serial monitor:
    Serial.println("Waiting for a client connection to notify...");
}

void setup() {
    // Initialize a serial connection with the ESP32 over usb:
    Serial.begin(115200);

    // Start BLE and give it a name:
    setupBLE("Daniel's ESP32 Bluetooth");
}
 
void loop() {
    long now = millis();
    if (now - lastMsg > 100) {
        // Check if there is a message from the BT device and print:
        if (deviceConnected&&rxload.length()>0) {
            Serial.println(rxload);
            
            // Reset the message rx buffer:
            rxload="";
        }

        if(Serial.available()>0){
            String str=Serial.readString();
            
            const char *newValue=str.c_str();
            
            pCharacteristic->setValue(newValue);
            
            pCharacteristic->notify();
        }
        // Reset the timer since the last message to right now:
        lastMsg = now;
    }
}
