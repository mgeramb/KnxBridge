#pragma once
#include "KnxBaseDevice.h"

class KnxSwitchDevice;

class ISwitchInterface
{
    public:
    virtual void initialize(KnxSwitchDevice* switchDevice) = 0;
    virtual void setPower(bool on) = 0;
    virtual bool getPower() = 0; 
};

class KnxSwitchDevice : public KnxBaseDevice
{
    public:
        std::list<ISwitchInterface*>* switchInterfaces; 
        KnxSwitchDevice(std::list<ISwitchInterface*>* switchInterfaces, uint16_t& goOffset, uint32_t& parameterAddress);
    protected:
        virtual void loop(unsigned long now, bool initalize);
        virtual void received(GroupObject& groupObject);

        public:
            void deviceChanged(ISwitchInterface* switchInterface);
};
