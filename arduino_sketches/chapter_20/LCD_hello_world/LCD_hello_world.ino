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

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Ciao mondo.");
}

void loop() {
    lcd.setCursor(0,1);
    lcd.print("Contatore: ");
    lcd.print(millis() / 1000);
    delay(1000);
}

bool i2CAddrTest(uint8_t addr) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
        return true;
    }
    return false;
}
