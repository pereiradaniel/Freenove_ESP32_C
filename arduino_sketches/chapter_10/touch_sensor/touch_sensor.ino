// Objective: Reads a touch sensor value from T0 (GPIO 4)

void setup() {
    // Initializes a serial connection with the ESP32:
    Serial.begin(115200);
}

void loop() {
    // Prints the touch value to the serial monitor:
    Serial.printf("Touch value: %d \n", touchRead(T0));
    delay(1000);
}