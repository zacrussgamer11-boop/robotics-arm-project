#include <Servo.h>
#include <IRremote.hpp>

Servo myServo;

int angle = 90;

void setup() {
  Serial.begin(9600);

  myServo.attach(9);
  IrReceiver.begin(8);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command);

    if (IrReceiver.decodedIRData.command == 96) {
      angle = angle - 10;
    }

    if (IrReceiver.decodedIRData.command == 97) {
      angle = angle + 10;
    }

    angle = constrain(angle, 20, 160);
    myServo.write(angle);

    IrReceiver.resume();
  }
}