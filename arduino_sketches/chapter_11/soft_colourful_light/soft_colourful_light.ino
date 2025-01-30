// PROJECT 11.2
// Define LED pins for RGB light:
const byte ledPins[] = {15, 2, 4};

// Define PWM channels:
const byte pwmChans[] = {0, 1, 2};

// Define ADC channels for potentiometers:
const byte adcChans[] = {13, 12, 14};

// RGB values:
int colours[] = {0, 0, 0};

void setup() {
    // Setup PWM channels:
    // ledcAttachChannel():
    //      Setup LEDC pin with given frequency, resolution, and channel.
    for (int i = 0; i < 3; i++)
        ledcAttachChannel(ledPins[i], 1000, 8, pwmChans[i]);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    // Calculate current colour value:
    // analogRead():
    //      Used to get the ADC raw value for a given pin/ADC channel.
    colours[i] = map(analogRead(adcChans[i]), 0, 4096, 0, 255);

    // Set the current colour:
    // ledcWrite():
    //      Used to set duty for the LEDC pin.
    ledcWrite(ledPins[i], 256 - colours[i]);
  }
  delay(10);
}