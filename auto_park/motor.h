#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "servo.h"

// Motor Pin Setting
const byte LEFT1 = 3; // IN1
const byte LEFT2 = 4; // IN2
const byte LEFT_PWM = 2; //ENA

const byte RIGHT1 = 5; // IN3
const byte RIGHT2 = 6; //IN4
const byte RIGHT_PWM = 7; //ENB

// 設定 PWM 輸出值, You need exactly 12 voltages to get right speed!
const int speed = 150;
const int slow_speed = 150;

// int current_angle;
// int angle = ;
// int slow_angle = ;

void stop();
void forward();
void backward();
void turnLeft();
void turnRight();
void strt2LEFT();
void strt2RIGHT();
void RIGHT2strt();
void LEFT2strt();
int joy();

#endif