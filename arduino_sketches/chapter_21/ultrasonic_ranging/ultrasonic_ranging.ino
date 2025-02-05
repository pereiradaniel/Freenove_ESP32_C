// Project 20.1: Ultrasonic Ranging.

// Initialize pins:
    // Trigger pin:
    #define trigPin 13

    // Echo pin:
    #define echoPin 14

// Sensor has a maximum distance rated at 400-500cm:
#define MAX_DISTANCE 700

// Define length of time before time out:
float timeOut = MAX_DISTANCE * 60;

// Define sound speed: 340 ms (the speed of sound through air). 
int soundVelocity = 340;

void setup() {
    // Trigger pin must be set to OUTPUT:
    pinMode(trigPin, OUTPUT);

    // Echo pin must be set to INPUT:
    pinMode(echoPin, INPUT);

    // Begin serial monitor with ESP32 at baud rate:
    Serial.begin(115200);
}

void loop() {
    // Wait 100ms between pings (20 pings/second).
    delay(100);
    Serial.print("Distance: ");
    
    // Send ping:
    Serial.print(getSonar());
    
    // Print a message to the serial monitor with the distance:
    Serial.println("cm");
}

// Function that sends out a ping and receives response, returns distance in cm as a float:
float getSonar() {
    unsigned long pingTime;
    float distance;

    // Make trigPin output high level lasting for 10us to trigger module:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Wait:
    pingTime = pulseIn(echoPin, HIGH, timeout);

    // Calculate the distance according to the time:
    distance = (float)pingTime * soundVelocity / 2 / 10000;
    return distance;
}