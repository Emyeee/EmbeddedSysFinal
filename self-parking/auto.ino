#include "servo.h"
#include "ultrasonic.h"
#include "ir_track.h"
#include "motor.h"
#include "servo.h"
#include"main.h"

static struct App Flags;

Servo Myservo;
ultrasonic My_ultrasonic;
ir My_ir;

void setup() {
  My_ultrasonic = ultrasonic();
  My_ir = ir();
  Myservo.attach(9); // Attach the servo to pin 9
}

static void Auto_park(){
  int8u ParkDist = 0;
	int16u Count = 0;
	Flags.Parked = FALSE;
  Serial.println("Auto Park begins.");
  parked = false;
  forward();
  while(++Count < ITERATIONS) {
		if (My_ultrasonic.get_distance() > PARKING_DEPTH) {
			if(++ParkDist > PARKING_DISTANCE) {
				ParkVehicle();
				Flags.Parked = TRUE;
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
	int8u i;
	forward();
	delayMicroseconds(4000);
	stop();
	Flags.Back = TRUE;
	Strt2Left(Myservo);
	backward();
	i = 0;
	while (i < 100) {
		if (!Flags.Obstacle) {
			backward(); 
			i++;
		} else
			stop();
		delayMicroseconds(55);
	}
	Left2Strt(Myservo);
	Strt2Right(Myservo);
	i = 0;
	while (i < 100) {
		if (!Flags.Obstacle) {
			backward();
			i++;
		} else
		stop();
		delayMicroseconds(55);
	}
	stop();
	Right2Strt(Myservo);
	// Mot1Aclk(Myservo); !!!
	delayMicroseconds(750);
	stop();
	Flags.Back = FALSE;
	delayMicroseconds(2000);
}

void loop() {
	if (Flags.AutoPark) {
		if (Flags.Parked)
			// Unpark();
		else
			AutoPark();
		Flags.AutoPark = FALSE;
	}
}
