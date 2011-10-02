#include "control.h"
#include "motorControl.h"
#include <unistd.h>

double LEFT_MOTOR_MODIFIER = 1;
double RIGHT_MOTOR_MODIFIER = 1;

double remaining;

void initControl() {
	initMotors();
}

void move(double distance) {
	double modifier = 1;
	if (distance < 0)
		modifier = -1;

	setAcceleration(0, LEFT_MOTOR_MODIFIER * 100.00);
	setVelocity(0, -1 * LEFT_MOTOR_MODIFIER * modifier * 100.00);
	setAcceleration(1, RIGHT_MOTOR_MODIFIER * 100.00);
	setVelocity(1, RIGHT_MOTOR_MODIFIER * modifier * 100.00);
	remaining = (modifier * distance) / 10;
}

//degrees relative to current direction
void turn(double degrees) {
	double modifier = 1;
	if (degrees < 0)
		modifier = -1;

	setAcceleration(0, LEFT_MOTOR_MODIFIER * 100.00);
	setVelocity(0, LEFT_MOTOR_MODIFIER * 100.00 * modifier);
	setAcceleration(1, RIGHT_MOTOR_MODIFIER * 100.00);
	setVelocity(1, RIGHT_MOTOR_MODIFIER * 100.00 * modifier);
	remaining = (degrees * modifier) / 500;
}

void stop() {
	setAcceleration(0, LEFT_MOTOR_MODIFIER * 100.00);
	setVelocity(0, 0.00);
	setAcceleration(1, RIGHT_MOTOR_MODIFIER * 100.00);
	setVelocity(1, 0.00);
}

void releaseControl() {
	closeMotors();
}

void controlTick(double diff) {
	remaining -= diff;
	if (remaining < 0) {
		stop();
	}
}
