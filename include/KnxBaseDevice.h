#pragma once
#include "component.h"

class KnxBaseDevice : public Component
{
    protected:
        const int NUMBER_OF_GOS = 4;
    public:
        char deviceName[25 + 1]; // One more then chars for ending 0
         KnxBaseDevice(uint16_t& goOffset, uint32_t& parameterAddress);
};