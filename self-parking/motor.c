#include <SoftwareSerial.h> // 引用「軟體序列埠」程式庫
#include "motor.h"

char command; // 接收序列埠值的變數
boolean run = false;

void stop() { // 馬達停止
  analogWrite(LEFT_PWM, 0); // 馬達 A 的 PWM 輸出
}
void forward() {	// 馬達轉向：前進
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
}

void backward() {	// 馬達轉向：後退
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
}

void turnLeft() {	// 馬達轉向：左轉, but we only have one motor, so we let it go forward slowly
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
}

void turnRight() {	// 馬達轉向：右轉, but we only have one motor, so we let it go forward slowly
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
}

// void loop() {
//   if (Serial.available() > 0) {
//     cmd = Serial.read();
    
//     switch (cmd) {
//       case 'w':		// 接收到'w'，前進。
//         forward();
//         run = true;	// 啟動馬達
//         break;
//       case 'x':		// 接收到'x'，後退。
//         backward();
//         run = true;	// 啟動馬達
//         break;
//       case 'a':		// 接收到'a'，左轉。
//         turnLeft();
//         run = true;	// 啟動馬達
//         break;
//       case 'd':		// 接收到'd'，右轉。
//         turnRight();
//         run = true;	// 啟動馬達
//         break;
//       case 's':
//         run = false;	// 停止馬達
//         break;
//     }
//   }
  
//   if (run) {	
//     // 如果要啟動馬達… 向馬達輸出指定的類比電壓值
//     if(cmd == 'a' or cmd == 'd')
//       analogWrite(LEFT_PWM, slow_speed);
//     else
//       analogWrite(LEFT_PWM, speed);
//   } else {
//     // 否則…將馬達的電壓值設定成0
//     analogWrite(LEFT_PWM, 0);
//   }
// }
