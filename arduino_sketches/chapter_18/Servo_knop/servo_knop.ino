// Project 18.2: Servo Knop

#include <ESP32Servo.h> 
// Default ADC max value on ESP32 with 12 bit accuracy:
#define ADC_Max 4095

// Create Servo object:
Servo myservo;

// Servo pin out:
int servoPin = 15;
// Potentiometer analong in:
int potPin = 34;
// Variable to store state of potentiometer:
int potVal;

void setup()
{
    // Standard 50hz servo:
    myservo.setPeriodHertz(50);
    
    // Attach pin to the Servo object:
    // myservo.attach():
    //      pin: Port connected to servo signal line.
    //      low: Time of high level corresponding to 0 degrees.
    //      high: Time of high level corresponding to 180 degrees.
    myservo.attach(servoPin, 500, 2500);   
  
    // Initialize serial connection with baud rate:
    Serial.begin(115200);
}

void loop() {
  // Read potentiometer and store its state in potVal:
  potVal = analogRead(potPin);
  
  // Display a message on the console:
  Serial.printf("potVal_1: %d\t",potVal);
  
  // Use map() to scale the values to 0-180 degrees:
  potVal = map(potVal, 0, ADC_Max, 0, 180); 

  // Move the servo to the value at potVal:
  myservo.write(potVal);                  
  
  // Print a message to the console:
  Serial.printf("potVal_2: %d\n",potVal);
  
  // Wait 15ms for the servo to arrive at the position:
  delay(15);
}