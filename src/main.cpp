#include <knx.h>
#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include "KnxBridgeDevice.h"
#include "KnxSwitchDevice.h"
#include "KnxDimmerDevice.h"

#include "HomeKitBridge.h"
#include "HomeKitSwitch.h"
#include "HomeKitDimmer.h"

#include "HueBridge.h"
#include "HueSwitch.h"
#include "HueDimmer.h"

u_int8_t startTimeInMilliseconds = 0;

void progLedOn()
{
  Serial.println("Prog LED ON");
#if LED_BUILTIN == 1 // GPIO1 is used for serial TX, to turn on the LED, the serial communication must be stopped
  Serial.flush(true);
  Serial.end(true);
  pinMode(LED_BUILTIN, OUTPUT);
#endif
  digitalWrite(LED_BUILTIN, false);
}

void progLedOff()
{
  digitalWrite(LED_BUILTIN, true);
#if LED_BUILTIN == 1 // GPIO1 is used for serial TX, it can be used now again for serial communication
  Serial.begin(115200);
  Serial.println();
#endif
  Serial.println("Prog LED Off");
}

ICACHE_RAM_ATTR void programButtonPressed()
{
  // Debounce
  static uint32_t lastpressed = 0;
  if (millis() - lastpressed > 200)
  {
    knx.toggleProgMode();
    lastpressed = millis();
  }
}

void setup()
{
  Serial.begin(115200);

  ArduinoPlatform::SerialDebug = &Serial;
  knx.platform().knxUart(&Serial2);
  Serial2.end(); // needed, because knxUart calls begin, but this causes a failure in the start

  knx.setProgLedOffCallback(progLedOff);
  knx.setProgLedOnCallback(progLedOn);

  knx.buttonPin(0);
  knx.setButtonISRFunction(programButtonPressed);
  knx.readMemory();

  if (knx.configured())
  {
    GroupObject::classCallback(Component::receiveAll);
    Serial.println("Initialize group objects and sensors");

    uint16_t goOffset = 1;
    uint32_t parameterAddress = 0;
    startTimeInMilliseconds = knx.paramInt(parameterAddress) * 1000;
    Serial.print("Start time ");
    Serial.println(startTimeInMilliseconds);
    parameterAddress += 4;
    
    HueBridge* hueBridge = new HueBridge();
    std::list<IBridgeInterface *> *bridgeInterfaces = new std::list<IBridgeInterface *>();
    bridgeInterfaces->push_back(new HomeKitBridge());
    bridgeInterfaces->push_back(hueBridge);
    new KnxBridgeDevice(bridgeInterfaces, goOffset, parameterAddress);

    // Start loop with 2, because device 1 is the bridge
    int devices = 25;
    int start = 2;
    for (int device = start; device < start + devices; device++)
    {

      uint8_t deviceType = knx.paramByte(parameterAddress);
      parameterAddress += 1;
      Serial.print("Device ");
      Serial.print(device - start + 1);
      Serial.print(": ");

      switch (deviceType)
      {
      case 1:
      {
        Serial.println("Switch");
        std::list<ISwitchInterface *> *switchInterfaces = new std::list<ISwitchInterface *>();
        switchInterfaces->push_back(new HomeKitSwitch(device));
        switchInterfaces->push_back(new HueSwitch(hueBridge));
        new KnxSwitchDevice(switchInterfaces, goOffset, parameterAddress);
        break;
      }
      case 2:
      {
        Serial.println("Dimmer");
        std::list<IDimmerInterface *> *dimmerInterfaces = new std::list<IDimmerInterface *>();
        dimmerInterfaces->push_back(new HomeKitDimmer(device));
        dimmerInterfaces->push_back(new HueDimmer(hueBridge));
        new KnxDimmerDevice(dimmerInterfaces, goOffset, parameterAddress);
        break;
      }
      default:
      {
        Serial.println("Inactive");
        new KnxBaseDevice(goOffset, parameterAddress);
        break;
      }
      } 
    }
  }
  Serial.println("Start KNX framework");
  knx.start();
  Serial.println("KNX framework started");
}

bool initializeHue = true;
bool initalizeKnx = true;

void loop()
{
  unsigned long now = millis();
  if (now == 0)
    now = 1; // Never use 0, it's used for marker

  knx.loop();

  if (!knx.configured())
    return;
  if (knx.progMode())
    return;

  if (startTimeInMilliseconds != 0)
  {
    if (now < startTimeInMilliseconds)
      return;
    startTimeInMilliseconds = 0;
    Serial.println("Start device");
    Serial.println(initalizeKnx);
  }
  Component::loopAll(now, initalizeKnx);

  initalizeKnx = false;
}
