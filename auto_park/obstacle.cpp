#include"obstacle.h"
#include <Arduino.h>
#define OB_PIN 10

ob::ob(){
  Serial.begin(9600);
  pinMode(INPUT, OB_PIN);
}

int ob::detect_ob(){
  int val;
  val = digitalRead(OB_PIN);
  if(val==1){
    Serial.println("obstacle detected");
  }
  return val;
}