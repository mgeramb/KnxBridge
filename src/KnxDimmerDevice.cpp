#include <knx.h>
#include "KnxDimmerDevice.h"

#define GO_SWITCH 0, "Switch", DPT_Switch
#define GO_SWITCH_FEEDBACK 1, "Switch Feedback", DPT_Switch
#define GO_DIMMER 2, "Dimmer", DPT_Scaling
#define GO_DIMMER_FEEDBACK 3, "Dimmer Feedback", DPT_Scaling
#define NUMBER_OF_GOS 4



KnxDimmerDevice::KnxDimmerDevice(IDimmerInterface* dimmerInterface, uint16_t &goOffset, uint32_t &parameterAddress)
    : Component((const char *)"", goOffset),
    dimmerInterface(dimmerInterface)
{
    readKnxParameterString("DeviceName", parameterAddress, deviceName, sizeof(deviceName));
    goOffset += NUMBER_OF_GOS;

    dimmerInterface->initialize(this);
}

void KnxDimmerDevice::deviceChanged()
{
    Serial.print(name);
    Serial.println(" device receive changed");
    float percentValue = dimmerInterface->getBrightness();
    Serial.print("Brightness: ");
    Serial.println(percentValue);
    bool power = dimmerInterface->getPower();
    if (!power)
        percentValue = 0;
    Serial.print("Power: ");
    Serial.println(power);
    uint8_t knxValue = percentValue;
    goSet(GO_DIMMER, knxValue, true);
    goSet(GO_SWITCH, knxValue > 0, true);
}

void KnxDimmerDevice::loop(unsigned long now, bool initalize)
{
    if (initalize)
    {
        goSetWithoutSend(GO_SWITCH, 0);
        goSetWithoutSend(GO_DIMMER, 0);
        goSetWithoutSend(GO_SWITCH_FEEDBACK, 0);
        goSetWithoutSend(GO_DIMMER_FEEDBACK, 0);
        goSendReadRequest(GO_SWITCH_FEEDBACK);
        goSendReadRequest(GO_DIMMER_FEEDBACK);
    }
}

void KnxDimmerDevice::received(GroupObject &groupObject)
{
    if (isGo(groupObject, GO_SWITCH_FEEDBACK))
    {
        bool switchValue = goGet(GO_SWITCH_FEEDBACK);
        goSetWithoutSend(GO_SWITCH, switchValue);
        dimmerInterface->setPower(switchValue);
    }
    if (isGo(groupObject, GO_DIMMER_FEEDBACK))
    {
        uint8_t dimmerValue = goGet(GO_DIMMER_FEEDBACK);
        goSetWithoutSend(GO_DIMMER, dimmerValue);
        dimmerInterface->setBrightness(dimmerValue);
    }
}
