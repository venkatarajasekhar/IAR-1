#ifndef DISTANCESENSORS_H_
#define DISTANCESENSORS_H_

#include <stdio.h>
#include <phidget21.h>
#include <time.h>

extern int sensorReadings [8];
extern int inputReadings [8];
extern timespec inputTime[8];
void initDistanceSensors();
void closeDistanceSensors();

#endif /* DISTANCESENSORS_H_ */
