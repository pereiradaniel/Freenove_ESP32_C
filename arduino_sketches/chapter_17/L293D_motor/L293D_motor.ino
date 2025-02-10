// Project 17.2: DC motor control with L293D.

// Channel 1, L293D:
int in1Pin = 12;
// Channel 2, L293D:
int in2Pin = 14;
// Enable 1 pin, L293D:
int enable1Pin = 13;
int channel = 0;

// Boolean that saves state of motor rotation direction: 
boolean rotationDir;
// Variable for the motor's rotation speed:
int rotationSpeed;

/*
Determining the direction of the motor:
  The ADC of the ESP32 has a 12-bit accuracy:
                Range: 0-4095
      Mid-range point: 2048
  The mid-range point is what determines which way the motor rotates.

Determining the speed of the motor:
  Take the absolute value of the result of subtracting 2048 from the ADC value of the potentiometer.
*/

void driveMotor(boolean dir, int spd) {
  // Controls motor rotation direction:
  if (dir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  // Controls motor rotation speed:
  ledcWrite(enable1Pin, spd);
}

void setup() {
  // Initialize pins::
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  // Set PWM: 11 bits, range 0-2047
  ledcAttachChannel(enable1Pin,1000,11,channel);
}

void loop() {
    // Converts voltage of the rotary potentiometer into digital:
    int potenVal = analogRead(A0);
  
    // DETERMINE CLOCKWISE OR COUNTER-CLOCKWISE:
    // if > 2048, clockwise. Else: counter-clockwise:
    rotationSpeed = potenVal - 2048;

    if (potenVal > 2048)
        rotationDir = true;
    else
        rotationDir = false;
  
    // Calculates motor speed:
    rotationSpeed = abs(potenVal - 2048);
  
    // Controls steering and speed of the motor:
    driveMotor(rotationDir, constrain(rotationSpeed,0,2048));
}
