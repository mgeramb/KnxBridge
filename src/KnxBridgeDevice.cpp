#include <knx.h>
#include "KnxBridgeDevice.h"

#define NUMBER_OF_GOS 0

#include "KnxBridgeDevice.h"

KnxBridgeDevice::KnxBridgeDevice(IBridgeInterface* bridgeInterface, uint16_t &goOffset, uint32_t &parameterAddress)
    : Component((const char *)deviceName, goOffset),
    bridgeInterface(bridgeInterface)
{
    readKnxParameterString("Global", "BridgeName", parameterAddress, deviceName, sizeof(deviceName));
    readKnxParameterString("Global", "PairingCode", parameterAddress, pairingCode, sizeof(pairingCode));
    readKnxParameterString("Global", "SSID", parameterAddress, ssid, sizeof(ssid));
    readKnxParameterString("Global", "Password", parameterAddress, password, sizeof(password));

    goOffset += NUMBER_OF_GOS;

    bridgeInterface->initialize(this);
}

void KnxBridgeDevice::loop(unsigned long now, bool initalize)
{
    bridgeInterface->loop();
}

