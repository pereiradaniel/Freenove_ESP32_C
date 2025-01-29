#define LED       2   // LED is on GPIO 2

// A value close to 0 indicates that a touch has been detected:
#define PRESS     14  // Touch threshold.
#define RELEASE   25  // Release threshold

// Initializes a boolean which is used to indicate whether a touch or release has been processed:
bool isProcessed = false;

void setup() {
    // Initializes a serial connection with ESP32:
    Serial.begin(115200);

    // Set the LED on GPIO 2 to OUTPUT:
    pinMode(LED, OUTPUT);
}

void loop() {
    // Determines if touch has been detected:
    if (touchRead(T0) < PRESS) {
        if (!isProcessed) {
            // Flip state of boolean so that this process is not repeated:
            isProcessed = true;
            // Print a message to the console:
            Serial.printf("Touch detected! Value: %d\n", touchRead(T0));
            // Reverse the state of the LED (on or off):
            reverseGPIO(LED);
        }
    }

    // Determines if touch has been released:
    if (touchRead(T0) > RELEASE) {
        if (isProcessed) {
            // Flip state of boolean so that this process is not repeated:
            isProcessed = false;
            // Print a message to the console:
            Serial.printf("Released! Value: %d\n", touchRead(T0));
        }
    }
}

// Reverses the state of the LED pin:
void reverseGPIO(int pin) {
  // Writes to the pin the opposite of its current state:
  digitalWrite(pin, !digitalRead(pin));
}
