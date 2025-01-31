// Project 16.2: 4-digit 7-segment display.

int latchPin = 2;   // ST_CP of 74HC595（Pin12）
int clockPin = 4;   // SH_CP of 74HC595（Pin11）
int dataPin = 15;   // DS    of 74HC595（Pin14）

// Common pin (anode) of 4 digit 7-segment display:
int comPin[] = {25,26,27,14};

// Define the encoding of characters 0-F of the common-anode 7-Segment Display:
byte num[] = {
    0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
    0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e
};
              
void setup() {
    // Pins connected tp 74HC595:
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    // Pins connected to 4-digit 7-segment display:
    for (int i = 0; i < 4; i++)
        pinMode(comPin[i], OUTPUT);
}

void loop() {
    for (int i = 0; i < 4; i++) {
        // Select a single 7-segment display:
        selectDigitalDisplay (i);

        // Send data to 74HC595:
        writeData(num[i]);
        delay(5);

        // Clear the display content:
        writeData(0xff);
    }
}

// Function that chooses the 7-segment display module from the 4-digit module:
void selectDigitalDisplay(byte com) {
    // Setting the pin to high will allow the 7-segment display to be selected for use!

    // First, close all the 7-segment displays:
    for (int i = 0; i < 4; i++)
        digitalWrite(comPin[i], LOW);

    // Select the proper 7-segment display com:
    digitalWrite(comPin[com], HIGH);
}

void writeData(int value) {
    // Set latchPin output low level:
    digitalWrite(latchPin, LOW);

    // Send serial data to 74HC595:
    shiftOut(dataPin, clockPin, LSBFIRST, value);

    // Setting latchPin output to HIGH, updating data to parallel output:
    digitalWrite(latchPin, HIGH);
}
