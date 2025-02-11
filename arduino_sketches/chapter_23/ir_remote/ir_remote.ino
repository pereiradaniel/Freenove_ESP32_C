// Project 23.1: LED controlled by IR remote.
// Objective: Control an LED using the IR remote. The LED should be capable of three brightness settings, of of being turned either off or on.

#include "Freenove_IR_Lib_for_ESP32.h"

// GPIO Pin 15 is connected to IR reciever:
const uint16_t recvPin = 15;

// Create IR receiver class object:
Freenove_ESP32_IR_Recv ir_recv(recvPin);

void setup() {
    // Initialize ESP32 with serial connection:
    Serial.begin(115200);
  
    // Send message to terminal to notify when IR receiver is waiting for a signal from the remote:
    Serial.print("IR receiver is waiting for IR message. ");
  
    // Print the IR receiver pin output to the serial monitor:
    Serial.println(recvPin);
}

void loop() {
    // Gets IR received data:
    ir_recv.task();
  
    // Check NEC protocol:
    if(ir_recv.nec_available()){
      // Prints the code received from the IR remote:
      Serial.printf("IR Code:  %#x\r\n", ir_recv.data());
    }
}

// Codes for LONG and SHORT button presses:
//      A long press will result in 0xffffffff following the code for the button that was pressed.
//      A short press will simply display the code for the button.