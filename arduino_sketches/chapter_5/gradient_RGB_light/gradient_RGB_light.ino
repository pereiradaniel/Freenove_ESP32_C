// Defines RGB LED pins:
const byte rgbPins[] = {4, 2, 15};   // GPIO pins for RGB LED

// Defines PWM channels:
const byte chans[]   = {0, 1, 2};

void setup() {
    // Set up PWM channels: 1Khz, 8-bit.
    for (int i = 0; i < 3; ++i)
        ledcAttachChannel(rgbPins[i], 1000, 8, chans[i]);
}

void loop() {
  for (int i = 0; i < 256; ++i)
    {
      setColour(wheel(i));
      delay(20);
    }
}

void setColour(long rgb) {
    ledcWrite(rgbPins[0], 255 - (rgb >> 16) & 0xFF);
    ledcWrite(rgbPins[1], 255 - (rgb >>  8) & 0xFF);
    ledcWrite(rgbPins[2], 255 - (rgb >>  0) & 0xFF);
}

long wheel(int pos) {
    long WheelPos = pos % 0xff;

    if (WheelPos < 85) {
        return ((255 - WheelPos * 3) << 16) | ((WheelPos *3) << 8);
    } else if (WheelPos < 170) {
        WheelPos -= 85;
        return (((255 - WheelPos * 3) << 8) | (WheelPos * 3));
    } else {
        WheelPos -= 170;
        return ((WheelPos * 3) << 16 | (255 - WheelPos * 3));
    }
}
