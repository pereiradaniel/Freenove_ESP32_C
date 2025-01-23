// Objective: Combine PWM with flowing LED bar.

// LED pins:
const byte ledPins[]  = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23};

// PWM channels:
const byte channels[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// PWM dutys, 30 pulse width values:
const int  dutys[]    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        1023, 512, 256, 128, 64, 32, 16, 8, 4, 2,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// LED index/num of LEDs:
int ledCounts = sizeof(ledPins);

// Flow speed:
int delayTimes = 50;

void setup() {
    // Sets up PWM channels at 1000Hz with bit accuracy of 0 bits, max pulse width 1023:
    for (int i = 0; i < ledCounts; ++i)
        ledcAttachChannel(ledPins[i], 1000, 10, channels[i]);
}

void loop() {
    // Flow in one direction:
    for (int i =0; i < 20; ++i) {
        for (int j = 0; j < ledCounts; ++j)
            ledcWrite(ledPins[j], dutys[i+j]);
        delay(delayTimes);
    }

    // Flow in the other direction:
    for (int i = 0; i < 20; ++i) {
        for (int j = ledCounts - 1; j > -1; --j)
            ledcWrite(ledPins[j], dutys[i + (ledCounts - 1 - j)]);
        delay(delayTimes);
    }
}
