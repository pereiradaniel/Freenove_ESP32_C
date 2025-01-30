// Project 15.1: Flowing water light using 74HC595

// Objective: Control LED bar using 74HC595 chip in order to preserve GPIO on the ESP32.

int latchPin = 12;  // ST_CP of 74HC595 (Pin12)
int clockPin = 13;  // SH_CP of 74HC595 (Pin11)
int dataPin  = 14;  // DS    of 74HC595 (Pin14)

void setup() {
    // Set up pins for output:
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop() {
    // One-byte variable uses 8 bits to represent the state of 8 LEDs:
    // 0x01 indicates only one LED light is on.
    byte x = 0x01; // 0b 0000 0001

    // Let the LED light up from right to left:
    for (int j = 0; j < 8; ++j) {
        writeTo595(LSBFIRST, x);
        x <<= 1; // Make variable move one bit to left once.
        delay(50);
    }
    delay(100);
    x = 0x80;   // 0b 1000 0000

    // Let the LED light up from left to right:
    for (int j = 0; j < 8; ++j) {
        writeTo595(LSBFIRST, x);
        x >>= 1;
        delay(50);
    }
    delay(100);
}

void writeTo595(int order, byte _data) {
    // Output LOW level to latchPin:
    digitalWrite(latchPin, LOW);

    // Send serial data to 74HC595 with shiftOut():
    // dataPin:     The pin on which to output each bit.
    // clockPin:    The pin to toggle once the dataPin has been set to the correct value.
    // bitOrder:    Which order to shift out the bits:
    //                  MSBFIRST (most significant bit)
    //                  LSBFIRST (least significant bit)
    // _data:       The data to shift out.
    shiftOut(dataPin, clockPin, order, _data);
    
    // Output high level to latchPin, and 74HC595 will update the data to the parallel output:
    digitalWrite(latchPin, HIGH);
}
