#include <Servo.h>

Servo myServo;
Servo myServo2; 
int servoPin = 10;
int servoPin2 = 11;
String servoPos;
int pos;

void setup() {
    Serial.begin(115200);
    myServo.attach(servoPin);
    myServo2.attach(servoPin2); 
    myServo.write(90);
    myServo2.write(90); 
}

void loop() {
    if (Serial.available() > 0) {
        servoPos = Serial.readStringUntil('\r');
        pos = servoPos.toInt();
        myServo.write(pos);   
        delay(50);
        
        if (Serial.available() > 0) {
            servoPos = Serial.readStringUntil('\r');
            pos = servoPos.toInt();
            myServo2.write(pos); 
            delay(50);
        }
    }
}