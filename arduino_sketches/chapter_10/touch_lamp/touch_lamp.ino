#define LED       2   // LED is on GPIO 2

// A value close to 0 indicates that a touch has been detected:
#define PRESS     14  // Touch threshold.
#define RELEASE   25  // Release threshold

bool isProcessed = false;

void setup() {
    // Initializes a serial connection with ESP32:
    Serial.begin(115200);

    // Set the LED on GPIO 2 to OUTPUT:
    pinMode(LED, OUTPUT);
}

void loop() {
    if (touchRead(T0) < PRESS) {
        if (!isProcessed) {
            isProcessed = true;
            Serial.println("Touch detected! Value: %d\n", touchRead(T0));
            reverseGPIO(LED);
        }
    }

    if (touchRead(T0) > RELEASE) {
        if (isProcessed) {
            isProcessed = false;
            Serial.println("Released! Value: %d\n", touchRead(T0));
        }
    }
}