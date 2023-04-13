#include <knx.h>
#include "KnxBridgeDevice.h"

#define GO_WLAN_STATE 0, "WLAN Connected", DPT_Switch
#define NUMBER_OF_GOS 1

#include "KnxBridgeDevice.h"

KnxBridgeDevice::KnxBridgeDevice(std::list<IBridgeInterface *> *bridgeInterfaces, uint16_t &goOffset, uint32_t &parameterAddress)
    : Component((const char *)deviceName, goOffset),
      bridgeInterfaces(bridgeInterfaces)
{
    readKnxParameterString("Global", "BridgeName", parameterAddress, deviceName, sizeof(deviceName));
    readKnxParameterString("Global", "PairingCode", parameterAddress, pairingCode, sizeof(pairingCode));
    readKnxParameterString("Global", "SSID", parameterAddress, ssid, sizeof(ssid));
    readKnxParameterString("Global", "Password", parameterAddress, password, sizeof(password));

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    goOffset += NUMBER_OF_GOS;

    for (std::list<IBridgeInterface *>::iterator it = bridgeInterfaces->begin(); it != bridgeInterfaces->end(); ++it)
        (*it)->initialize(this);
}

void KnxBridgeDevice::loop(unsigned long now, bool initalize)
{       
    goSet(GO_WLAN_STATE, WiFi.status() == WL_CONNECTED, initalize);

    for (std::list<IBridgeInterface *>::iterator it = bridgeInterfaces->begin(); it != bridgeInterfaces->end(); ++it)
        (*it)->loop();    
}
