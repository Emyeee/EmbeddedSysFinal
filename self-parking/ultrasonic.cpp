#include "ultrasonic.h"
#include <Arduino.h>
#define TRIG_PIN 6
#define ECHO_PIN 7

ultrasonic::ultrasonic()
{
  duration = 0;
  distance = 0;
  pinMode(TRIG_PIN, INPUT);
  pinMode(ECHO_PIN, OUTPUT);
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