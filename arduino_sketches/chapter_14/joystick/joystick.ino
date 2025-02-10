// Project 14.1: Joystick

// Define GPIO pins for:
//      x:  13
//      y:  12
//      z:  14
int xyzPins[] = {13, 12, 14};

void setup() {
    // Initialize connection with ESP32:
    Serial.begin(115200);

    // Set up z axis pin as a button:
    pinMode(xyzPins[2], INPUT_PULLUP);
}

void loop() {
    // Use analogRead() to read the value from the pins:
    int xValue = analogRead(xyzPins[0]);
    int yValue = analogRead(xyzPins[1]);
    int zValue = analogRead(xyzPins[2]);

    // Print a message to the console:
    Serial.printf("X, Y, Z; %d,\t%d,\t%d\n", xValue, yValue, zValue);

    // Add some delay:
    delay(500);
}
