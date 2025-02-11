// Project 26.1: Acceleratio Detection with MPU6050

// Import library for MPU6050 module:
#include <MPU6050_tockn.h>
#include <Wire.h>

#define SDA 13
#define SCL 14

// Attach I2C:
MPU6050 mpu6050(Wire);

// Defines acceleration values of 3 axes:
int16_t ax,ay,az;

//define variables to save the values in 3 axes of gyroscope
int16_t gx,gy,gz;

long timer = 0;

void setup() {
    // Initialize serial connection with ESP32 via USB:
    Serial.begin(115200);
    
    // Attach I2C pin:
    Wire.begin(SDA, SCL);

    // Initializes MPU6050:
    mpu6050.begin();
  
    // Get the offsets value:
    mpu6050.calcGyroOffsets(true);
}

void loop() {
    // Run this block each second:
    if(millis() - timer > 1000){
        // Update the MPU6050:
        mpu6050.update();

        // Update the acceleration and gyroscope values:
        getMotion6();

        // Prints the data to the serial monitor:
        Serial.print("\na/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t\t");
        Serial.print(gy); Serial.print("\t\t");
        Serial.println(gz);
        Serial.print("a/g:\t");
        Serial.print((float)ax / 16384); Serial.print("g\t");
        Serial.print((float)ay / 16384); Serial.print("g\t");
        Serial.print((float)az / 16384); Serial.print("g\t");
        Serial.print((float)gx / 131); Serial.print("d/s \t");
        Serial.print((float)gy / 131); Serial.print("d/s \t");
        Serial.print((float)gz / 131); Serial.print("d/s \n");
        timer = millis();
    }
}

// Function that updates the acceleration and gyroscope values:
void getMotion6(void) {
    
    // ACCELERATION RAW DATA:
        // X axis:
        ax=mpu6050.getRawAccX();
        
        // Y axis:
        ay=mpu6050.getRawAccY();
        
        // Z axis:
        az=mpu6050.getRawAccZ();

    // GYROSCOPE RAW DATA:
        // X axis:
        gx=mpu6050.getRawGyroX();
    
        // Y axis:
        gy=mpu6050.getRawGyroX();
    
        // Z axis:
        gz=mpu6050.getRawGyroX();
}