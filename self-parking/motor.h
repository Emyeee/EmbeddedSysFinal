#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>


// Motor Pin Setting
const byte LEFT1 = 10;
const byte LEFT2 = 9;
const byte LEFT_PWM = 5;

// 設定 PWM 輸出值, You need exactly 12 voltages to get right speed!
const byte speed = 100;
const byte slow_speed = 40;

void stop();
void forward();
void backward();
void turnLeft();
void turnRight();

#endif
