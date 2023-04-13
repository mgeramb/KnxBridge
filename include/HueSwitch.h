#pragma once
#include "HueBridge.h"
#include "KnxSwitchDevice.h"

class HueSwitch : public ISwitchInterface
{
    KnxSwitchDevice *SwitchDevice;
    HueBridge* hueBridge;
    EspalexaDevice* espalexaDevice;

public:
    HueSwitch(HueBridge* bridge);
    void initialize(KnxSwitchDevice *SwitchDevice);

    boolean update();
    virtual bool getPower();
    virtual void setPower(bool value);
};