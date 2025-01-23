// Objective: Use PWM to create a breathing LED on GPIO 2.

#define LED     2       // LED will be on GPIO 2
#define CHN     0       // PWM channel
#define FRQ     1000    // PWM frequency
#define PWM_BIT 8       // PWM precision

void setup() {
    // Attaches LED pin to PWM channel, setting frequency and precision:
    ledcAttachChannel(LED, FRQ, PWM_BIT, CHN);
}

void loop() {

    // Increase PWM from 0 to 100%.
    for (int i = 0; i < 255; ++i)
    {
        ledcWrite(LED, i);
        delay(5);
    }

    // Decrease PWM from 100% to 0.
    for (int i = 255; i > -1; --i)
    {
        ledcWrite(LED, i);
        delay(5);
    }
}
