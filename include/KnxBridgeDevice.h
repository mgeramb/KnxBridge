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
        std::list<IBridgeInterface *> *bridgeInterfaces;
    public:
        char ssid[32 + 1]; // One more then chars for ending 0
        char password[64 + 1]; // One more then chars for ending 0

        char deviceName[20 + 1]; // One more then chars for ending 0
        char pairingCode[8 + 1]; // One more then chars for ending 0
        KnxBridgeDevice(std::list<IBridgeInterface *> *bridgeInterfaces, uint16_t& goOffset, uint32_t& parameterAddress);

   protected:
        virtual void loop(unsigned long now, bool initalize);
 
};
