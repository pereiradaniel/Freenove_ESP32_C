// Objective: Reads a touch sensor value from T0 (GPIO 4)

void setup() {
    // Initializes a serial connection with the ESP32:
    Serial.begin(115200);
}

void loop() {
    // Prints the touch value to the serial monitor:
    // touchRead():
    //  - Reads the touch sensor value at specified pin. 
    //  - A value close to 0 means that a touch has been detected.
    Serial.printf("Touch value: %d \n", touchRead(T0));
    delay(1000);
}