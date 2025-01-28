#define PIN_ANALOG_IN  4    // Potentiometer

void setup() {
  // Initialize serial port with baud rate 115200:
  Serial.begin(115200);
}

void loop() {
  // Obtain ADC value using analogRead():
  // analogRead() reads the value from the specified analog pin.
  // Return the analog reading on the pin.
  // (0-4095 for 12 bits)
  int adcVal = analogRead(PIN_ANALOG_IN);

  // Convert ADC vaue into 8-bit precision DAC value using map():
  // map() re-maps a number from one range to another.
  int dacVal = map(adcVal, 0, 4095, 0, 255);

  double voltage = adcVal / 4095.0 * 3.3;
  
  // Output the value using dacWrite();
  // dacWrite() writes the given value to the supplied analog pin.
  dacWrite(DAC1, dacVal);

  // Print message to the serial console:
  Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  delay(200);
}
