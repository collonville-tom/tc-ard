
#include "./BlockedMotor.h"
#include "./Leg.h"
#include "./BottomMember.h"
#include "./LegBuilder.h"
#include "./Messaging.h"

#include <ArduinoJson.h>

int cycle_base = 1000;

Messaging* messaging;
BottomMember* bottomMember;

void setup() {
  messaging = new Messaging();
  messaging->sendJson("Init system");

  LegBuilder legBuilder;
  bottomMember= new BottomMember(legBuilder.getLegD(),legBuilder.getLegG());


  messaging->sendJson(bottomMember->getPosition());
  messaging->sendJson("Init Done");
}

void loop() {
  if (messaging->hasNewCommand())
  {
    bottomMember->moveTo(messaging);
    
    messaging->unFlag();
  }

  delay(100);
  receiveEvent();
}

void receiveEvent()
{
  String payload = "";
  boolean loading = false;
  while (Serial.available())
  {
    char incoming = (char)Serial.read();
    if (incoming == messaging->stop_bit)
    {
      loading = false;
    }
    if (loading)
    {
      payload.concat(incoming);
    }
    if (incoming == messaging->start_bit)
    {
      loading = true;
    }
    delay(10);
  }
  if (payload != "") {
    messaging->readCommands(payload);
  }

}
