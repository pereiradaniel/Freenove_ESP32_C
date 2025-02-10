// Project 20.1: LCD1602 Hello World

// Include the I2C library for LCD1602:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14

// LC1602 uses PCF8574t: I2C address = 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Attach the I2C pin:
    Wire.begin(SDA, SCL);

    if (!i2CAddrTest(0x27)) {
        lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    }

    // lcd driver initialization:
    lcd.init();
    
    // Turns on the backlight:
    lcd.backlight();
    
    // Move the cursor to row 0, column 0:
    lcd.setCursor(0,0);

    // Print message to the LCD screen:
    lcd.print("Ciao mondo.");
}

void loop() {
    // Move cursor to row 1, column 0:
    lcd.setCursor(0,1);

    // Print message to the LCD screen:
    lcd.print("Contatore: ");

    // Count will be displayed every second:
    lcd.print(millis() / 1000);
    
    // Add one second delay:
    delay(1000);
}

// Function that checks whether the I2C address exists:
bool i2CAddrTest(uint8_t addr) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
        return true;
    }
    return false;
}
