
#include "./BlockedMotor.h"
#include "./Leg.h"
#include "./Messaging.h"

#include <ArduinoJson.h>

int cycle_base = 1000;

Messaging* messaging;
Leg* leg;

void setup() {
  messaging = new Messaging();
  messaging->sendJson("Init system");

  BlockedMotor::BlockedMotorInitializer genouInit;
  genouInit.spin = 1;
  genouInit.pin = 5;
  genouInit.min = 0;
  genouInit.max = 200;
  genouInit.position = 100;

  BlockedMotor::BlockedMotorInitializer cuisseInit;
  cuisseInit.spin = 1;
  cuisseInit.pin = 4;
  cuisseInit.min = 0;
  cuisseInit.max = 200;
  cuisseInit.position = 100;

  BlockedMotor::BlockedMotorInitializer hancheRotInit;
  hancheRotInit.spin = -1;
  hancheRotInit.pin = 2;
  hancheRotInit.min = 20;
  hancheRotInit.max = 100;
  hancheRotInit.position = 60;

  BlockedMotor::BlockedMotorInitializer hancheEccartInit;
  hancheEccartInit.spin = -1;
  hancheEccartInit.pin = 3;
  hancheEccartInit.min = 100;
  hancheEccartInit.max = 160;
  hancheEccartInit.position = 130;

  leg = new Leg(hancheRotInit, hancheEccartInit, cuisseInit, genouInit);
  messaging->sendJson(leg->getPosition());
  messaging->sendJson("Init Done");
}

void loop() {
  if (messaging->hasNewCommand())
  {
    leg->moveTo(messaging);
    
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
  }
  if (payload != "") {
    messaging->readCommands(payload);
  }

}
