#include <stdio.h>
#include "phidget.h"

int AttachHandler(CPhidgetHandle MC, void *userptr)
{
    int serialNo;
    const char *name;

    CPhidget_getDeviceName(MC, &name);
    CPhidget_getSerialNumber(MC, &serialNo);
    #ifndef SILENT
    printf("%s %10d attached!\n", name, serialNo);
    #endif
    
    return 0;
}

int DetachHandler(CPhidgetHandle MC, void *userptr)
{
    int serialNo;
    const char *name;

    CPhidget_getDeviceName(MC, &name);
    CPhidget_getSerialNumber(MC, &serialNo);
    
    #ifndef SILENT
    printf("%s %10d detached!\n", name, serialNo);
    #endif
    
    return 0;
}

int ErrorHandler(CPhidgetHandle MC, void *userptr, int ErrorCode, const char *Description)
{
    printf("Error handled. %d - %s\n", ErrorCode, Description);
    return 0;
}
