#include "ir_track.h"
#include <Arduino.h>
#define IR_1_PIN 3
#define IR_2_PIN 2

ir::ir()
{
  obstacle_1 = false;
  obstacle_2 = false;
  pinMode(IR_1_PIN, OUTPUT);
  pinMode(IR_2_PIN, OUTPUT);
}

bool ir::obstacle_detect_1()
{
  obstacle_1 = digitalRead(IR_1_PIN);
  Serial.print("IR_1 detection: ");
  Serial.println(obstacle_1);
  return obstacle_1;
}

bool ir::obstacle_detect_2()
{
  obstacle_2 = digitalRead(IR_2_PIN);
  Serial.print("IR_2 detection: ");
  Serial.println(obstacle_2);
  return obstacle_2;
}