#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTAC,           sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C2_1,     chassisL,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     chassisR,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     scissorL,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     scissorR,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     bucketL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     bucketR,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_4,    trailerServo,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    gateServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_1,    bucketServoL,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    bucketServoR,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-accelerometer.h"
#include "JoystickDriver.c"

int readAxis(int avg)
{
	int avgX = 0;
	int _x_axis, _y_axis, _z_axis;
	for(int i = 0; i < avg; i++)
	{
		if (!HTACreadAllAxes(HTAC, _x_axis, _y_axis, _z_axis))
		{
			nxtDisplayTextLine(4, "ERROR!!");
			wait1Msec(1000);
			StopAllTasks();
		}
		avgX += _x_axis;
	}
	return(avgX/avg*0.44444+100);
}

void go(int l, int r, float t)
{
	motor[chassisR] = l;
	motor[chassisL] = -r;
	wait1Msec(t);
	motor[chassisR] = 0;
	motor[chassisL] = 0;
}

//eraseDisplay();
//nxtDisplayCenteredBigTextLine(1,"X=%3d",x);

task main()
{
  waitForStart();
  //go(20,20,3000);
  PlaySound(soundBeepBeep);
  /*go(-25,25,900);			//Turn towards field

  wait1Msec(1000);
  PlaySound(soundBeepBeep);
  go(100,100,900);			//Ram into pole

  go(40,-40,900);
  go(100,100,1000);
  wait1Msec(1000);
  PlaySound(soundBeepBeep);

  go(50,-50,1000);
  go(100,100,1000);
  */
}
