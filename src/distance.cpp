#include <time.h>

#include "distance.h"
#include "interfaceKit.h"


void initDistance()
{
    initDistanceSensors();
}

void closeDistance()
{
    closeDistanceSensors();
}

int getDistance(int sensor)
{
    return 4080 / (sensorReadings[sensor] - 20);
}

int getLeftDistance()
{
    return getDistance(1);
}

int getRightDistance()
{
    return getDistance(2);
}

bool getWhisker(int sensor) {
    timespec now, then;
    clock_gettime(CLOCK_MONOTONIC, &now);
    
    then = inputTime[sensor];
    
    double diff = (now.tv_sec - then.tv_sec) + ((now.tv_nsec - then.tv_nsec) / NANOSECONDS_PER_SECOND);
    
    if (diff < 0.2) {
	return false;
    } else {
	return inputReadings[sensor] == 1;
    }
}

bool getFrontWhisker()
{
    return getWhisker(1);
}

bool getBackWhisker()
{
    return getWhisker(0);
}