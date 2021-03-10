
#include "./BlockedMotor.h"
#include "./Leg.h"
#include "./Messaging.h"

#include <ArduinoJson.h>

int cycle_base = 1000;

Messaging* messaging;
Leg* gauche;
Leg* droite;

void setup() {
  messaging = new Messaging();
  messaging->sendJson("Init system");

  BlockedMotor::BlockedMotorInitializer genouDInit;
  genouDInit.spin = 1;
  genouDInit.pin = 6;
  genouDInit.min = 0;
  genouDInit.max = 200;
  genouDInit.position = 100;

  BlockedMotor::BlockedMotorInitializer cuisseDInit;
  cuisseDInit.spin = 1;
  cuisseDInit.pin = 7;
  cuisseDInit.min = 0;
  cuisseDInit.max = 180;
  cuisseDInit.position = 100;

  BlockedMotor::BlockedMotorInitializer hancheDRotInit;
  hancheDRotInit.spin = -1;
  hancheDRotInit.pin = 14;
  hancheDRotInit.min = 30;
  hancheDRotInit.max = 160;
  hancheDRotInit.position = 90;

  BlockedMotor::BlockedMotorInitializer hancheDEccartInit;
  hancheDEccartInit.spin = -1;
  hancheDEccartInit.pin = 15;
  hancheDEccartInit.min = 50;
  hancheDEccartInit.max = 150;
  hancheDEccartInit.position = 80;

  droite = new Leg(hancheDEccartInit, hancheDRotInit, cuisseDInit, genouDInit);


  BlockedMotor::BlockedMotorInitializer genouGInit;
  genouGInit.spin = 1;
  genouGInit.pin = 5;
  genouGInit.min = 0;
  genouGInit.max = 160;
  genouGInit.position = 50;

  BlockedMotor::BlockedMotorInitializer cuisseGInit;
  cuisseGInit.spin = 1;
  cuisseGInit.pin = 4;
  cuisseGInit.min = 0;
  cuisseGInit.max = 200;
  cuisseGInit.position = 50;

  BlockedMotor::BlockedMotorInitializer hancheGRotInit;
  hancheGRotInit.spin = -1;
  hancheGRotInit.pin = 2;
  hancheGRotInit.min = 30;
  hancheGRotInit.max = 170;
  hancheGRotInit.position = 100;

  BlockedMotor::BlockedMotorInitializer hancheGEccartInit;
  hancheGEccartInit.spin = -1;
  hancheGEccartInit.pin = 3;
  hancheGEccartInit.min = 40;
  hancheGEccartInit.max = 160;
  hancheGEccartInit.position = 100;

  gauche = new Leg(hancheGRotInit, hancheGEccartInit, cuisseGInit, genouGInit);

  messaging->sendJson(gauche->getPosition());
  messaging->sendJson(droite->getPosition());
  messaging->sendJson("Init Done");
}

void loop() {
  if (messaging->hasNewCommand())
  {
    gauche->moveTo(messaging);
    
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
