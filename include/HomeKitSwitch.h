#pragma once
#include "HomeSpan.h"
#include "KnxSwitchDevice.h"

class HomeKitSwitch : public ISwitchInterface
{
    int device;
    KnxSwitchDevice *switchDevice;
    Characteristic::On *power;
    class ServiceImplementation : Service::LightBulb
    {
        HomeKitSwitch* parent;
        bool update()
        {
            return parent->update();
        }
    public:
        ServiceImplementation(HomeKitSwitch* parent) : parent(parent)
        {
        }
    };
public:
    HomeKitSwitch(int device);
    void initialize(KnxSwitchDevice *switchDevice);

    boolean update();
    virtual bool getPower();
    virtual void setPower(bool value);
};