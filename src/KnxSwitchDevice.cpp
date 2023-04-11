#include <knx.h>
#include "KnxSwitchDevice.h"

#define GO_SWITCH 0, "Switch", DPT_Switch
#define GO_SWITCH_FEEDBACK 1, "Switch Feedback", DPT_Switch
// Not used: #define GO_Switch 2, "Switch", DPT_Scaling
// Not used: #define GO_Switch_FEEDBACK 3, "Switch Feedback", DPT_Scaling
#define NUMBER_OF_GOS 4


KnxSwitchDevice::KnxSwitchDevice(ISwitchInterface* switchInterface, uint16_t &goOffset, uint32_t &parameterAddress)
    : Component((const char *)deviceName, goOffset),
    switchInterface(switchInterface)
{
    readKnxParameterString("DeviceName", parameterAddress, deviceName, sizeof(deviceName));
    goOffset += NUMBER_OF_GOS;

    switchInterface->initialize(this);
}

void KnxSwitchDevice::deviceChanged()
{
    Serial.print(name);
    Serial.println(" device receive changed");
    bool power = switchInterface->getPower();
    Serial.print("Power: ");
    Serial.println(power);
    goSet(GO_SWITCH, power, false);
}

void KnxSwitchDevice::loop(unsigned long now, bool initalize)
{
    if (initalize)
    {
        goSetWithoutSend(GO_SWITCH, 0);
        goSetWithoutSend(GO_SWITCH_FEEDBACK, 0);
        goSendReadRequest(GO_SWITCH_FEEDBACK);
    }
}

void KnxSwitchDevice::received(GroupObject &groupObject)
{
    if (isGo(groupObject, GO_SWITCH_FEEDBACK))
    {
        bool switchValue = goGet(GO_SWITCH_FEEDBACK);
        goSetWithoutSend(GO_SWITCH, switchValue);
        switchInterface->setPower(switchValue);
    }
}
