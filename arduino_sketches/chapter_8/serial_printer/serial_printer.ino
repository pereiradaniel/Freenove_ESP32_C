void setup() {
    // Initiallizes the serial port:
    //   Baud rate: 115200
    Serial.begin(115200);

    // Print message to the serial port:
    Serial.println("ESP32 initialization completed!");
}

void loop() {
    // Print message to the serial port using the same method as printing in C:
    Serial.printf("Running time : %.1f s\n", millis() / 1000.0f);

    delay(1000);
}
