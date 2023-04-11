#pragma once
#include "component.h"

class KnxDimmerDevice;

class IDimmerInterface
{
    public:
    virtual void initialize(KnxDimmerDevice* dimmerDevice) = 0;
    virtual void setBrightness(int brightness) = 0;
    virtual void setPower(bool on) = 0;
    virtual bool getPower() = 0; 
    virtual int getBrightness() = 0;  
};

class KnxDimmerDevice : Component
{
    public:
        char deviceName[30 + 1]; // One more then chars for ending 0
        IDimmerInterface* dimmerInterface;
        KnxDimmerDevice(IDimmerInterface* dimmerInterface, uint16_t& goOffset, uint32_t& parameterAddress);
    protected:
        virtual void loop(unsigned long now, bool initalize);
        virtual void received(GroupObject& groupObject);

        public:
            void deviceChanged();
};
