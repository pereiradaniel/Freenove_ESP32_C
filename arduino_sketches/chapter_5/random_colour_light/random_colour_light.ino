// Defines PWM channels and associates them with the pins on an RGB LED:
const byte rgbPins[] = {4, 2, 5};   // GPIO pins for RGB LED
const byte chans[]   = {0, 1, 2};   // PWM channels

// Defines variables to hold colour values:
int red, green, blue;

void setup() {
    // Set up PWM channels: 1Khz, 8-bit.
    for (int i=0; i<3; ++i)
        ledcAttachChannel(rgbPins[i], 1000, 8, chans[i]);
}

void loop() {
    // Generate three random numbers for RGB values:
    red   = random(0, 256);
    green = random(0, 256);
    blue  = random(0, 256);

    // Set RGB LED to randomized colour values:
    setColour(red, green, blue);

    // Control speed of colour change using delay():
    delay(200);
}

// Uses function parameters to set the colour of the RGB LED:
void setColour(byte r, byte g, byte b) {
    // Low level turns on LED
    ledcWrite(chans[0], 255 -r);
    ledcWrite(chans[1], 255 -g);
    ledcWrite(chans[2], 255 -b);
}