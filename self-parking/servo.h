#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <Servo.h>


const int16_t ZERO_DEGREE = 1500; // Adjust as needed

const int16_t DELTA_ANGLE = 25;   // Adjust as needed
const int16_t DELTA_SPEED = 25;   // Adjust as needed

const int16_t RIGHT_EXTM = 2000;   // Adjust as needed
const int16_t LEFT_EXTM = 1025;      // Adjust as needed

const int16_t TURN_RDELAY = 2000;  // Adjust as needed
const int16_t TURN_LDELAY = 5000;  // Adjust as needed

void TurnRight(Servo& servo);
void TurnLeft(Servo& servo);
void Strt2Right(Servo& servo);
void Right2Strt(Servo& servo);
void Strt2Left(Servo& servo);
void Left2Strt(Servo& servo);

#endif
