#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <EEPROM.h>

#define relay 0 //relay connected to  GPIO0

char ssid[] = "SUPERONLINE_WiFi_8875";
char pass[] = "HPVATVJU77PA";
char auth[] = "W6790nsoiVeFDaMqAP5yO0ITdDYLkPOc";

int EEaddress = 0; //EEPROM Address
bool bulb_status = false;

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  
  if(pinValue)
  {
    bulb_status = true;
    digitalWrite(relay, HIGH);
    EEPROM.write(EEaddress, bulb_status);
  }
  else
  {
    bulb_status = false;
    digitalWrite(relay, LOW);
    EEPROM.write(EEaddress, bulb_status);
  }
  
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(relay, OUTPUT);
  bulb_status = EEPROM.read(EEaddress);
}

void loop()
{
  Blynk.run();
}
