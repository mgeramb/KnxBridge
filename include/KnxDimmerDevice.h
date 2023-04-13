#pragma once
#include "KnxBaseDevice.h"

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

class KnxDimmerDevice : public KnxBaseDevice
{
    public:
        std::list<IDimmerInterface *> *dimmerInterfaces;
        KnxDimmerDevice(std::list<IDimmerInterface *> *dimmerInterfaces, uint16_t& goOffset, uint32_t& parameterAddress);
    protected:
        virtual void loop(unsigned long now, bool initalize);
        virtual void received(GroupObject& groupObject);

        public:
            void deviceChanged(IDimmerInterface* dimmerInterface);
};
