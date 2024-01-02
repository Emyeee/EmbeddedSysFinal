#include <Servo.h>
#include "servo.h"

// Create a Servo object
// I created in the main.ino

int TurnR(Servo& servo) {
  Strt2Right();
  delay(TURN_RDELAY);
  Right2Strt();
  return 1;
}

int TurnL(Servo& servo) {
  Strt2Left();
  delay(TURN_LDELAY);
  Left2Strt();
  return 1;
}

int Strt2R(Servo& servo) {
  while (servo.read() < RIGHT_EXTM) {
    servo.write(servo.read() + DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
  return 1;
}

int R2Strt(Servo& servo) {
  while (servo.read() > ZERO_DEGREE) {
    servo.write(servo.read() - DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
  return 1;
}

int Strt2L(Servo& servo) {
  while (servo.read() > LEFT_EXTM) {
    servo.write(servo.read() - DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
  return 1;
}

int L2Strt(Servo& servo) {
  while (servo.read() < ZERO_DEGREE) {
    servo.write(servo.read() + DELTA_ANGLE);
    delay(DELTA_SPEED);
  }
  return 1;
}