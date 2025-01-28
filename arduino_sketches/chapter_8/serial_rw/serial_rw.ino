// Create a String for storing incoming data:
String inputString = "";

// Indicates if string is complete or not:
bool stringComplete = false;

void setup() {
    // Initialize serial port using baud rate 115200:
    Serial.begin(115200);

    Serial.println(String("\nESP32 initialization complete!\n")
                + String("Please input some characters,\n")
                + String("select \"Newline\" below and click send button. \n"));
}

void loop() {
    // Detect if data has been received:
    if (Serial.available()) {
        // Read one character:
        char inChar = Serial.read();
        inputString += inChar;
        
        // Check for \n to detect if at the end of the newline:
        if (inChar == '\n')
            stringComplete = true;  // Completes the string
    }

    // Detect if the string is complete:
    if (stringComplete) {
        // Print the completed string to the terminal:
        Serial.printf("inputString: %s \n", inputString);
        
        // Reset the string and its boolean:
        inputString = "";
        stringComplete = false;
    }
}