#include <SoftwareSerial.h> // 引用「軟體序列埠」程式庫
#include "motor.h"
#include "servo.h"

char command; // 接收序列埠值的變數
boolean run = false;
int xPin = 0;  //X軸 接類比A0
int yPin = 1;  //Y軸 接類比A1
int zPin = 2;  //Z軸 接類比A2
  
int xval=0;    //Ｘ軸變數
int yval=0;    //Ｙ軸變數
int zval=0;    //Ｚ軸變數

int temp_speed;

void stop() { // 馬達停止
  analogWrite(LEFT_PWM, 0); // 馬達 A 的 PWM 輸出
  analogWrite(RIGHT_PWM, 0); 
}
void forward() {	// 馬達轉向：前進
  // joy();
  Serial.println("forwarding");
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(LEFT_PWM, speed);
  analogWrite(RIGHT_PWM, speed);
}

void backward() {	// 馬達轉向：後退
  //joy();
  Serial.println("backwarding");
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);
  analogWrite(LEFT_PWM, speed);
  analogWrite(RIGHT_PWM, speed);
}

void turnLeft() {
// 左不動，右動
  Serial.println("turning left");
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, speed);
}

void turnRight() {
// 右不動，左動
  Serial.println("turning right");
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, speed);
  analogWrite(RIGHT_PWM, 0);
}

void strt2LEFT(){
  Serial.println("straight to left");
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, slow_speed);

}

void strt2RIGHT() {
  Serial.println("straight to right");
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, slow_speed);
  analogWrite(RIGHT_PWM, 0);
}

void RIGHT2strt() {
  Serial.println("right to straight");
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, slow_speed);
  analogWrite(RIGHT_PWM, 0);
}

void LEFT2strt(){
  //joy();
  Serial.println("left to straight");
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(RIGHT_PWM, slow_speed);
  analogWrite(LEFT_PWM, 0);


}

int joy(){
  xval = analogRead(xPin);   //讀取X軸數值到xval變數
  yval = analogRead(yPin);   //讀取Y軸數值到yval變數
  zval = analogRead(zPin);   //讀取Z軸數值到zval變數

  return xval;
}
