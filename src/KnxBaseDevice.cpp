#include "KnxBaseDevice.h"

KnxBaseDevice::KnxBaseDevice(uint16_t &goOffset, uint32_t &parameterAddress)
    : Component((const char *)deviceName, goOffset)
{
    readKnxParameterString("DeviceName", parameterAddress, deviceName, sizeof(deviceName));
    goOffset += NUMBER_OF_GOS;
}