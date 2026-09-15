#include <Servo.h>

Servo myServo;

int previousAngle = 0;

void setup() {
  myServo.attach(9);
  pinMode(12, OUTPUT);
}

void loop() {
  int potValue = analogRead(A0);
  
  int angle = map(potValue, 0, 1023, 0, 180);

  if (abs(angle - previousAngle) > 2) {
    digitalWrite(12, HIGH);
    previousAngle = angle;
  } else {
    digitalWrite(12, LOW);
  }

  myServo.write(angle);

  delay(15);
}