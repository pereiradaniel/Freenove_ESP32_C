#define PIN_BUZZER 13   // GPIO pin for passive buzzer
#define PIN_BUTTON 4    // GPIO pin for button control
#define CHN        0    // PWM channel

void setup() {
    // Sets up the button to receive input from pin GPIO pin 4:
    pinMode(PIN_BUTTON, INPUT);
    
    // Attaches the LED pin to the PWM channel:
    ledcAttachChannel(PIN_BUZZER, 1, 10, CHN);
    
    // Sound at 2KHz for 0.3 seconds:
    ledcWriteTone(PIN_BUZZER, 2000);
    delay(300);
}

void loop() {
    if (digitalRead(PIN_BUTTON) == LOW) {
        // If button is pressed, sound alarm:
        alert();
    } else {
        // If button is released, no buzzer:
        ledcWriteTone(PIN_BUZZER, 0);
    }
}

void alert() {
    float   sinVal;     // Sine variable.
    int     toneVal;    // Tone value of sine.

    // X from 0 to 360 degrees:
    for (int x = 0; x < 360; x += 10) {
        // Calculate the sine of x:
        sinVal = sin(x * (PI / 180));

        // Calculate sound frequency according to the sine of x
        toneVal = 2000 + sinVal * 500;
        ledcWriteTone(PIN_BUZZER, toneVal);
        
        delay(10);
    }
}