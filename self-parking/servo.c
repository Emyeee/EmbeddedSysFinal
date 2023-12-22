#include <Servo.h>
#include "servo.h"

// Create a Servo object
// I created in the main.ino

void TurnRight(Servo& servo) {
  Strt2Right();
  delay(TURN_RDELAY);
  Right2Strt();
}

void TurnLeft(Servo& servo) {
  Strt2Left();
  delay(TURN_LDELAY);
  Left2Strt();
}

void Strt2Right(Servo& servo) {
  while (servo.read() < RIGHT_EXTM) {
    servo.write(servo.read() + DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
}

void Right2Strt(Servo& servo) {
  while (servo.read() > ZERO_DEGREE) {
    servo.write(servo.read() - DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
}

void Strt2Left(Servo& servo) {
  while (servo.read() > LEFT_EXTM) {
    servo.write(servo.read() - DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
}

void Left2Strt(Servo& servo) {
  while (servo.read() < ZERO_DEGREE) {
    servo.write(servo.read() + DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
}
