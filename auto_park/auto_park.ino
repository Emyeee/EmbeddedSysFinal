#include "servo.h"
#include "ultrasonic.h"
#include "ir_track.h"
#include "motor.h"
#include"main.h"
#include"obstacle.h"

static struct App Flags;

Servo myservo;
ultrasonic My_ultrasonic;
ir My_ir;
ob My_ob;

void setup() {
  Serial.begin(9600);
  My_ultrasonic = ultrasonic();
  My_ir = ir();
  My_ob = ob();
  myservo.attach(11);
}

static void Auto_park(){
  unsigned char ParkDist = 0;
	unsigned short Count = 0;
	Flags.Parked = false;
  Serial.println("Auto Park begins.");
  forward();
  while(++Count < ITERATIONS) {
		if (My_ultrasonic.get_distance() > PARKING_DEPTH) {
			if(++ParkDist > PARKING_DISTANCE) {
				ParkVehicle();
				Flags.Parked = true;
				return 1;
			}
			delayMicroseconds(100);
		} else
			ParkDist = 0;
	}
  stop();
  delayMicroseconds(1000);
}

static void ParkVehicle(void) {
	unsigned char i;
	forward();
	delayMicroseconds(4000);
	stop();
	Flags.Back = true;
  while(TurnL(myservo)==0){
    turnLeft();
  }
	backward();
	i = 0;
	while (i < 100) {
		if (My_ob.detect_ob()==1) {
			backward(); 
			i++;
		} else
			stop();
		delayMicroseconds(55);
	}
	LEFT2strt();
	strt2RIGHT();
	i = 0;
	while (i < 100) {
		if (My_ob.detect_ob()==1) {
			backward();
			i++;
		} else
		stop();
		delayMicroseconds(55);
	}
	stop();
	RIGHT2strt();
	// Mot1Aclk(Myservo); !!!
	delayMicroseconds(750);
	stop();
	Flags.Back = false;
	delayMicroseconds(2000);
}

void loop() {
	if (1) {
		if (Flags.Parked){
      // Unpark();
      Auto_park();
      Serial.println("here");
    }
		else
			Auto_park();
		Flags.AutoPark = false;
	}
}
