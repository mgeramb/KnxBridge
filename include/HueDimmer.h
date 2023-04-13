#pragma once
#include "HueBridge.h"
#include "KnxDimmerDevice.h"

class HueDimmer : public IDimmerInterface
{
    KnxDimmerDevice *dimmerDevice;
    HueBridge* hueBridge;
    EspalexaDevice* espalexaDevice;

public:
    HueDimmer(HueBridge* bridge);
    void initialize(KnxDimmerDevice *dimmerDevice);

    boolean update();
    virtual bool getPower();
    virtual void setPower(bool value);
    virtual int getBrightness();
    virtual void setBrightness(int brightness);
};