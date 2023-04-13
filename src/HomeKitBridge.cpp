#include "HomeKitBridge.h"

void HomeKitBridge::initialize(KnxBridgeDevice *bridgeDevice)
{
    homeSpan.setWifiCredentials(bridgeDevice->ssid, bridgeDevice->password);
    homeSpan.setPairingCode(bridgeDevice->pairingCode);
    homeSpan.setPortNum(8080);
    homeSpan.begin(Category::Bridges, bridgeDevice->deviceName);
    new SpanAccessory();
    new Service::AccessoryInformation();
    new Characteristic::Identify();
}

void HomeKitBridge::loop()
{
    homeSpan.poll();
}


