#include <knx.h>
#include "KnxDimmerDevice.h"

#define GO_SWITCH 0, "Switch", DPT_Switch 
#define GO_SWITCH_FEEDBACK 1, "Switch Feedback", DPT_Switch 
#define GO_DIMMER 2, "Dimmer", DPT_Scaling 
#define GO_DIMMER_FEEDBACK 3, "Dimmer Feedback", DPT_Scaling 
#define NUMBER_OF_GOS 4

std::list<DimmerDevice*> DimmerDevice::deviceInstances = {};

DimmerDevice::DimmerDevice(Espalexa& espalexa, uint16_t& goOffset, uint32_t& parameterAddress)
: Component((const char*) "", goOffset)
{
    deviceInstances.push_back(this);
    readKnxParameterString("DeviceName", parameterAddress, deviceName, sizeof(deviceName));
    goOffset += NUMBER_OF_GOS;
    espAlexaDevice = new EspalexaDevice("Light 1", anyDeviceChanged, EspalexaDeviceType::dimmable); 
    // Define your devices here. 
    espalexa.addDevice(espAlexaDevice); //simplest definition, default state off
}

void DimmerDevice::anyDeviceChanged(EspalexaDevice* changedDevice)
{
    for (std::list<DimmerDevice*>::iterator it=deviceInstances.begin(); it != deviceInstances.end(); ++it)
    {
        DimmerDevice* device = (*it);
        if (device->espAlexaDevice == changedDevice)
            device->deviceChanged();
    }
}

void DimmerDevice::deviceChanged()
{
    Serial.print(name);
    Serial.println(" device receive changed");
    float percent = ((float) espAlexaDevice->getValue() / 2.55f);
    if (percent > 100)
        percent = 100;
    uint8_t bytePercent = (uint8_t) percent;
    goSet(GO_DIMMER, bytePercent, true);
    goSet(GO_SWITCH, bytePercent > 0, true);
}

DimmerDevice::~DimmerDevice()
{
    // espalexa does not support remove device, so delete espAlexaDevice makes no sense
    deviceInstances.remove(this);
}

void DimmerDevice::loop(unsigned long now, bool initalize)
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


void DimmerDevice::received(GroupObject& groupObject)
{
    if (isGo(groupObject, GO_SWITCH_FEEDBACK))
    {
        bool switchValue = goGet(GO_SWITCH_FEEDBACK);
        goSetWithoutSend(GO_SWITCH, switchValue);
        espAlexaDevice->setState(switchValue);
    }
    if (isGo(groupObject, GO_DIMMER_FEEDBACK))
    {
        goSetWithoutSend(GO_DIMMER, goGet(GO_DIMMER_FEEDBACK));
        float dimmerValue = goGet(GO_DIMMER_FEEDBACK);
        float value = dimmerValue * 2.55f;
        if (value > 100)
            value = 100;
        espAlexaDevice->setValue(value);
    }
}
