#include <Servo.h>

#define PIN_SERVO_COMMAND 9

Servo myServo;

void setup() {
  myServo.attach(PIN_SERVO_COMMAND);
}

void servoSlow(Servo num, int delayTime, int startPosition, int endPosition) {
  num.write(startPosition);

  for(int i = startPosition; i <= endPosition; i++) {
    num.write(i);
    delay(delayTime);
  }
}

void loop() {
  servoSlow(myServo, 20, 30, 180);
}
