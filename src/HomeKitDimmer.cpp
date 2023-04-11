#include "HomeKitDimmer.h"

void HomeKitDimmer::initialize(KnxDimmerDevice *dimmerDevice)
{
    this->dimmerDevice = dimmerDevice;
    new SpanAccessory();
        new Service::AccessoryInformation();
        new Characteristic::Identify();
        new Characteristic::Name(dimmerDevice->deviceName);
    new ServiceImplementation(this);
       power = new Characteristic::On();
    level = new Characteristic::Brightness(100);
    level->setRange(1, 100, 1);
}

boolean HomeKitDimmer::update()
{
    dimmerDevice->deviceChanged();
    return (true);
}

bool HomeKitDimmer::getPower()
{
    return power->getNewVal();
}

void HomeKitDimmer::setPower(bool value)
{
    power->setVal(value);
}

int HomeKitDimmer::getBrightness()
{
    return level->getNewVal();
}

void HomeKitDimmer::setBrightness(int brightness)
{
    if (brightness == 0)
    {
        power->setVal(false);
    }
    else
    {
        level->setVal(brightness);
        power->setVal(true);
    }
}
