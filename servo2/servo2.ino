#include <Servo.h>

#define PIN_SERVO_COMMAND 9

Servo myServo;

void setup() {
  myServo.attach(PIN_SERVO_COMMAND);
}

void loop() {
  myServo.write(0);
  delay(500);
  myServo.write(60);
  delay(500);
  myServo.write(120);
  delay(500);
  myServo.write(180);
  delay(500);
}
