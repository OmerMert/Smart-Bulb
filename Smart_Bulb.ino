#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define relay 0 //relay connected to  GPIO0

char ssid[] = ".........."; //wifi name
char pass[] = ".........."; //wifi password
char auth[] = ".........."; //Blynk token


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  
  if(pinValue)
    digitalWrite(relay, HIGH);
  else
    digitalWrite(relay, LOW);
  
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(relay, OUTPUT
}

void loop()
{
  Blynk.run();
}
