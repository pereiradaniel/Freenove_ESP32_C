// Project 24.2: DHT11 Hygrothermograph with LCD Display.
// Objective: Read temperature and humidity from the DHT11 module and display the results on the LCD display.

// Import libraries:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHTesp.h"

// Define the GPIO in connections with the DHT11:
#define SDA 13
#define SCL 14

// Create class object for the DHT11:
DHTesp dht;

// Set GPIO pin for the DHT module:
int dhtPin = 18;

// Initialize LCD:
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
    // Attach the I2C pin:
    Wire.begin(SDA, SCL);

    if (!i2CAddrTest(0x27))
        lcd = LiquidCrystal_I2C(0x3F, 16, 2);

    // Initialize LCD driver:
    lcd.init();
  
    // Turn on the backlight:
    lcd.backlight();
  
    // Attach and initialize DHT pin:
    dht.setup(dhtPin, DHTesp::DHT11);
}

void loop() {
    // Reads data from the DHT11 and saves it: 
    flag:TempAndHumidity DHT = dht.getTempAndHumidity();

    // Catches bad read and returns back to flag to try again:
    if (dht.getStatus() != 0)
        goto flag;

    // Prints the temperature on Line 1:
        // Sends cursor to column 0, line 1:
        lcd.setCursor(0, 0);

        // Prints the temperature to the LCD:
        lcd.print("Temperature:");
        lcd.print(DHT.temperature);

    // Prints the humidity on line 2:
        // Sends the cursor to column 0, line 2: 
        lcd.setCursor(0, 1);
    
        // Prints the humidity to the LCD:
        lcd.print("Humidity   :");
        lcd.print(DHT.humidity);

    // Wait for two seconds before re-reading and displaying the data:
    delay(2000);
}

bool i2CAddrTest(uint8_t addr) {
 
  Wire.beginTransmission(addr);
 
  if (Wire.endTransmission() == 0)
    return true;

  return false;
}