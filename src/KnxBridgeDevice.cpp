#include <knx.h>
#include "KnxBridgeDevice.h"

#define GO_WLAN_STATE 0, "WLAN Connected", DPT_Switch
#define NUMBER_OF_GOS 1

#include "KnxBridgeDevice.h"

KnxBridgeDevice::KnxBridgeDevice(uint16_t &goOffset, uint32_t &parameterAddress)
    : Component((const char *)deviceName, goOffset)
{
    readKnxParameterString("Bridge", "BridgeName", parameterAddress, deviceName, sizeof(deviceName));
    mode = (Mode) readKnxParameterUInt8("Mode", parameterAddress);
    readKnxParameterString("Bridge", "SSID", parameterAddress, ssid, sizeof(ssid));
    readKnxParameterString("Bridge", "Password", parameterAddress, password, sizeof(password));
    readKnxParameterString("Bridge", "PairingCode", parameterAddress, pairingCode, sizeof(pairingCode));
 
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    goOffset += NUMBER_OF_GOS;

}

void KnxBridgeDevice::initialize(std::list<IBridgeInterface *> *bridgeInterfaces)
{
    this->bridgeInterfaces = bridgeInterfaces;
    for (std::list<IBridgeInterface *>::iterator it = bridgeInterfaces->begin(); it != bridgeInterfaces->end(); ++it)
    (*it)->initialize(this);
}

void KnxBridgeDevice::loop(unsigned long now, bool initalize)
{       
    goSet(GO_WLAN_STATE, WiFi.status() == WL_CONNECTED, initalize);

    for (std::list<IBridgeInterface *>::iterator it = bridgeInterfaces->begin(); it != bridgeInterfaces->end(); ++it)
        (*it)->loop();    
}
