// Project 13.1: Thermometer using thermistor.

// GPIO 4 will be thermistor pin:
#define PIN_ANALOG_IN 4

void setup() {
    // Initialize serial connection with ESP32:
    Serial.begin(115200);   // Baud rate: 11500
}

void loop() {
    // Use analogRead() to get raw ADC value from thermistor's GPIO:
    int adcValue = analogRead(PIN_ANALOG_IN);

    // Calculate voltage:
    double voltage = (float)adcValue / 4095.0 * 3.3;

    // Calculate resistance value of the thermistor:
    double Rt = 10 * voltage / (3.3 - voltage);

    // Calculate temperature:
        // KELVIN:
            double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0);
        // CELSIUS:
            double tempC = tempK - 273.15;
    
    // Print a message to the console:
    Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC\n", adcValue, voltage, tempC);

    // Add some delay:
    delay(1000);
}