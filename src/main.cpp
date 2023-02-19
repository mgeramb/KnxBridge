#include <knx.h>
#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include "KnxDimmerDevice.h"

u_int8_t startTimeInMilliseconds = 0;
// prototypes


char ssid[32 + 1]; // One more then chars for ending 0
char password[64 + 1]; // One more then chars for ending 0

boolean wifiConnected = false;

Espalexa espalexa;


void progLedOn()
{
  Serial.println("Prog LED ON");
#if LED_BUILTIN == 1  // GPIO1 is used for serial TX, to turn on the LED, the serial communication must be stopped
  Serial.flush(true);
  Serial.end(true);
  pinMode (LED_BUILTIN, OUTPUT);
#endif
  digitalWrite(LED_BUILTIN, false);
}

void progLedOff()
{
  digitalWrite(LED_BUILTIN, true);
#if LED_BUILTIN == 1  // GPIO1 is used for serial TX, it can be used now again for serial communication
  Serial.begin(115200);
  Serial.println();
#endif
  Serial.println("Prog LED Off");
}

ICACHE_RAM_ATTR void programButtonPressed()
{
    // Debounce
    static uint32_t lastpressed=0;
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

    Component::readKnxParameterString("Global", "SSID", parameterAddress, ssid, sizeof(ssid));
    Component::readKnxParameterString("Global", "Password", parameterAddress, password, sizeof(password));

    uint8_t deviceType = knx.paramByte(parameterAddress);
    parameterAddress +=1;
    new DimmerDevice(espalexa, goOffset, parameterAddress);
   
  }

  Serial.println("Start KNX framework");
  knx.start();
  Serial.println("KNX framework started"); 

  if (knx.configured())
  {
    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ");
    Serial.print(ssid);
    Serial.println("...");
  }
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

  if (WiFi.status() == WL_CONNECTED) 
  {
    if (initializeHue)
    {
      initializeHue = false;
      Serial.print("WiFi connected to ");
      Serial.println(ssid);
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());

      espalexa.begin();
    } 
    espalexa.loop();
  }

 
}

