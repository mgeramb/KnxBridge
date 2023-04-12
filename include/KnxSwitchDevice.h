#pragma once
#include "component.h"

class KnxSwitchDevice;

class ISwitchInterface
{
    public:
    virtual void initialize(KnxSwitchDevice* SwitchDevice) = 0;
    virtual void setPower(bool on) = 0;
    virtual bool getPower() = 0; 
};

class KnxSwitchDevice : Component
{
    public:
        char deviceName[20 + 1]; // One more then chars for ending 0
        ISwitchInterface* switchInterface;
        KnxSwitchDevice(ISwitchInterface* switchInterface, uint16_t& goOffset, uint32_t& parameterAddress);
    protected:
        virtual void loop(unsigned long now, bool initalize);
        virtual void received(GroupObject& groupObject);

        public:
            void deviceChanged();
};
