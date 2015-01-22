#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motor1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	eraseDisplay();
	nMotorEncoder[motor1] = 0;
	nMotorEncoder[motor2] = 0;

	while (true) {
		//nMotorEncoder[motor1] = 0;
		//nMotorEncoder[motor2] = 0;
		nxtDisplayCenteredBigTextLine(2, "%d", nMotorEncoder[motor1]);
		nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[motor2]);
		while(nNxtButtonPressed == 1)
		{
			motor[motor1] = 100;
			motor[motor2] = -100;
			nxtDisplayCenteredBigTextLine(2, "%d", nMotorEncoder[motor1]);
			nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[motor2]);
		}
		while(nNxtButtonPressed == 2)
		{
			motor[motor1] = -100;
			motor[motor2] = 100;
			nxtDisplayCenteredBigTextLine(2, "%d", nMotorEncoder[motor1]);
			nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[motor2]);
		}
		motor[motor1] = 0;
		motor[motor2] = 0;
	}
}
