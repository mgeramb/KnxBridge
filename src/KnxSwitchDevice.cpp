#include <knx.h>
#include "KnxSwitchDevice.h"

#define GO_SWITCH 0, "Switch", DPT_Switch
#define GO_SWITCH_FEEDBACK 1, "Switch Feedback", DPT_Switch
// Not used: #define GO_Switch 2, "Switch", DPT_Scaling
// Not used: #define GO_Switch_FEEDBACK 3, "Switch Feedback", DPT_Scaling

KnxSwitchDevice::KnxSwitchDevice(std::list<ISwitchInterface *> *switchInterfaces, uint16_t &goOffset, uint32_t &parameterAddress)
    : KnxBaseDevice(goOffset, parameterAddress),
      switchInterfaces(switchInterfaces)
{
    for (std::list<ISwitchInterface *>::iterator it = switchInterfaces->begin(); it != switchInterfaces->end(); ++it)
        (*it)->initialize(this);
}

void KnxSwitchDevice::deviceChanged(ISwitchInterface *switchInterface)
{
    Serial.print(name);
    Serial.println(" device receive changed");
    bool power = switchInterface->getPower();
    Serial.print("Power: ");
    Serial.println(power);
    goSet(GO_SWITCH, power, true);
    for (std::list<ISwitchInterface *>::iterator it = switchInterfaces->begin(); it != switchInterfaces->end(); ++it)
    {
        if ((*it) != switchInterface)
            (*it)->setPower(power);
    }
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
        bool power = goGet(GO_SWITCH_FEEDBACK);
        goSetWithoutSend(GO_SWITCH, power);
        for (std::list<ISwitchInterface *>::iterator it = switchInterfaces->begin(); it != switchInterfaces->end(); ++it)
        {
            (*it)->setPower(power);
        }
    }
}