// Project 22.2: Keypad Door

// Required libraries:
//      Keypad
//      ESP32 Servo
#include <Keypad.h>
#include <ESP32Servo.h>

// Define keypad symbols:
char keys[4][4] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect rows and columns of the keypad:
byte rowPins[4] = {14, 27, 26, 25};
byte colPins[4] = {13, 21, 22, 23};

// Initialize an instance of class NewKeypad:
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

// Initialize a Servo object and its pins:
Servo  myservo;
int servoPin = 19;
int buzzerPin = 18;

// The correct password:
char passWord[] = {"1234"};

void setup() {
    // Initialize standard 50Hz servo:
    myservo.setPeriodHertz(50);
    
    // Attach servo pins to the servo object:
    myservo.attach(servoPin, 500, 2500);

    // Set starting position of servo:
    myservo.write(0);
  
    // Initialize buzzer pin:
    pinMode(buzzerPin, OUTPUT);

    // Start with buzzer OFF:
    digitalWrite(buzzerPin, HIGH);
  
    // Initialize a serial connection with the ESP32 using USB:
    Serial.begin(115200);
}

void loop() {
  
    // Stores the input character:
    static char keyIn[4];

    // Stores the number of input characters (counter):
    static byte keyInNum = 0; // Save the the number of input characters
  
    // Gets the character input:
    char keyPressed = myKeypad.getKey();

    // Handles input characters:
    if (keyPressed) {
        // Sound a beep each time a key is pressed;
        // Buzzer ON:
        digitalWrite(buzzerPin, LOW);
        // Delay for 100ms:
        delay(100);
        // Buzzer OFF:
        digitalWrite(buzzerPin, HIGH);

        // Save the input characters:
        keyIn[keyInNum++] = keyPressed;
        
        // After 4 characters have been input, th passWord gets evaluated:
        if (keyInNum == 4) {
            // Password begins as true:
            bool isRight = true;

            // Evaluate password and set to false if it fails:
            for (int i = 0; i < 4; i++)
                if (keyIn[i] != passWord[i])
                    isRight = false;

            // Accept or Deny entry:
            if (isRight) {
                // CORRECT PASSWORD:

                // Move the servo (open the door):
                myservo.write(90);
                
                // Delay for 2 seconds:
                delay(2000);
                
                // Return the servo to starting position (close the door):
                myservo.write(0);             // Close the switch
                
                // Prints a message to the serial monitor:
                Serial.println("Password correct: Door opened.");
            }
            else {
                // WRONG PASSWORD:

                // Loud error BEEP for 1 second:
                
                // Buzzer ON:
                digitalWrite(buzzerPin, LOW);
                
                // Delay for 1 second:
                delay(1000);
                
                // Buzzer OFF
                digitalWrite(buzzerPin, HIGH);
                
                // Prints a message to the serial monitor:
                Serial.println("Password incorrect: Entry denied.");
            }
            // Reset number of keys pressed to zero:
            keyInNum = 0;
        }
    }
}
