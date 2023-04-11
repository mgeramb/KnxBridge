#pragma once
#include "component.h"

class KnxBridgeDevice;

class IBridgeInterface
{
    public:
    virtual void initialize(KnxBridgeDevice* brigdeDevice) = 0;
    virtual void loop() = 0;
};

class KnxBridgeDevice : Component
{
    private:
        IBridgeInterface* bridgeInterface;
    public:
        char ssid[32 + 1]; // One more then chars for ending 0
        char password[64 + 1]; // One more then chars for ending 0

        char deviceName[30 + 1]; // One more then chars for ending 0
        KnxBridgeDevice(IBridgeInterface* bridgeInterface, uint16_t& goOffset, uint32_t& parameterAddress);

   protected:
        virtual void loop(unsigned long now, bool initalize);
 
};
