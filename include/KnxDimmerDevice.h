#pragma once
#include "component.h"
#include <Espalexa.h>

class DimmerDevice : Component
{
    public:
        static std::list<DimmerDevice*> deviceInstances;   
        char deviceName[30 + 1]; // One more then chars for ending 0
        EspalexaDevice* espAlexaDevice;
        DimmerDevice(Espalexa& espalexa, uint16_t& goOffset, uint32_t& parameterAddress);
        ~DimmerDevice();
    protected:
        virtual void loop(unsigned long now, bool initalize);
        virtual void received(GroupObject& groupObject);

        //callback functions
        static void anyDeviceChanged(EspalexaDevice* changedDevice);
        void deviceChanged();
};
