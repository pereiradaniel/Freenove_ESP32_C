// Project 16.1: 7-Segment Display

// Set up pins for use with 74HC595:
int dataPin = 15;          // DS    of 74HC595（Pin14）
int latchPin = 2;          // ST_CP of 74HC595（Pin12）
int clockPin = 4;          // SH_CP of 74HC595（Pin11）

// Define the encoding of characters 0-F for the common-anode 7-Segment Display
byte num[] = {
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
  0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e
};

void setup() {
  // Set up 3 pins for use with 74HC595:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // Iterate from 0 to F in Hexadecimal and display:
  for (int i = 0; i < 16; i++) {
    // Send data to 74HC595:
    writeData(num[i]);
    
    // Delay for 1 second:
    delay(1000);
    
    // Clear the display.
    writeData(0xff);
  }
}

// Function that writes to the pin outputs and uses shiftOut to bit shift:
void writeData(int value) {
  // Set latchPin to LOW level:
  digitalWrite(latchPin, LOW);
 
  // Send serial data to 74HC595:
  shiftOut(dataPin, clockPin, LSBFIRST, value);
 
  // Set latchPin to HIGH, 74HC595 will update the data to parallel output:
  digitalWrite(latchPin, HIGH);
}
