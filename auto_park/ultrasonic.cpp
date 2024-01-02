#include "ultrasonic.h"
#include <Arduino.h>
#define TRIG_PIN 9
#define ECHO_PIN 8

ultrasonic::ultrasonic()
{
  duration = 0;
  distance = 0;
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

double ultrasonic::get_distance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2)/29.4;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}