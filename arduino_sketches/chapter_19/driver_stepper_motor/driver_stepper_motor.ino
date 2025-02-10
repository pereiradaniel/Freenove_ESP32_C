// Project 19.1

// Stepper motor ports:
int outPorts[] = {14, 27, 26, 25};

void setup() {
  // Set motor ports to output:
  for (int i = 0; i < 4; i++)
    pinMode(outPorts[i], OUTPUT);
}

void loop()
{
    // MOVEMENT:
    // The rotor will rotate fully one direction, then the other.

    // Phase 1:
    // Rotates a full turn:
    // Stepper motor needs 32*64 steps for one full rotation!
    moveSteps(true, 32 * 64, 3);
    // Delay 1 second:
    delay(1000);

    // Phase 2:
    // Rotates a full turn:
    // Stepper motor needs 32*64 steps for one full rotation!
    moveSteps(false, 32 * 64, 3);
    // Delay second:
    delay(1000);
}

// Speed of rotation is determined by ms.
// The value of ms should be between 3-20. Larger value is slower.
void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    // Rotates one step:
    moveOneStep(dir);
    
    // Controls the speed:
    delay(constrain(ms,3,20));
  }
}

// Used to drive the stepper motor to rotate clockwise or counter clockwise:
//  dir indicates direction of rotation.
//  if dir returns true, motor rotates clockwise.
//  else rotates counter-clockwise
void moveOneStep(bool dir) {
  // Four low bits to indicate state of the port:
  static byte out = 0x01;

  // Decide the shift direction according to the rotation direction:

  // Left:
  if (dir)
    out != 0x08 ? out = out << 1 : out = 0x01;
  // Right:
  else
    out != 0x01 ? out = out >> 1 : out = 0x08;
  
  // Output signal to each port:
  for (int i = 0; i < 4; i++)
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
}

void moveAround(bool dir, int turns, byte ms) {
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}
void moveAngle(bool dir, int angle, byte ms) {
  moveSteps(dir,(angle*32*64/360),ms);
}