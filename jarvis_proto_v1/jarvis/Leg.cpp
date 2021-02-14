#include "./Leg.h"



Leg::Leg(const BlockedMotor::BlockedMotorInitializer& hanche_rot_init, const BlockedMotor::BlockedMotorInitializer& hanche_eccart_init,
         const BlockedMotor::BlockedMotorInitializer& cuisse_init,const BlockedMotor::BlockedMotorInitializer& genou_init):
cuisse(cuisse_init),genou(genou_init),hancheRot(hanche_rot_init),hancheEccart(hanche_eccart_init)
{
}

Leg::~Leg()
{
}

bool Leg::checkTarget(int targetGenou,int targetCuisse, int targetRot, int targetEccart)
{
  return genou.getPosition()!=targetGenou || cuisse.getPosition()!= targetCuisse || hancheRot.getPosition() != targetRot || hancheEccart.getPosition() != targetEccart;
}
/*
13:41:45: b'${}#${"g":100,"c":100,"r":60,"e":130}#${}#'
13:43:33: Receive command:{'gt': 150, 'ct': 150, 'rt': 145, 'et': 80}
13:50:10: b'${"g":150,"c":150,"r":100,"e":100}#'
13:50:11: b'${"g":150,"c":150,"r":100,"e":100}#'

*/
void Leg::adjustGenou(int targetGenou)
{
  if(targetGenou < genou.getPosition())
    genou.remove(1);
  if(targetGenou > genou.getPosition())
    genou.add(1);
}

void Leg::adjustCuisse(int targetCuisse)
{
  if(targetCuisse < cuisse.getPosition())
    cuisse.remove(1);
  if(targetCuisse > cuisse.getPosition())
    cuisse.add(1);
}

void Leg::adjustRot(int targetRot)
{
  if(targetRot > hancheRot.getPosition())
    hancheRot.remove(1);
  if(targetRot < hancheRot.getPosition())
    hancheRot.add(1);
}

void Leg::adjustEccart(int targetEccart)
{
  if(targetEccart > hancheEccart.getPosition())
    hancheEccart.remove(1);
  if(targetEccart < hancheEccart.getPosition())
    hancheEccart.add(1);
}

DynamicJsonDocument Leg::getPosition(){
  DynamicJsonDocument response(512);
  response["g"] = genou.getPosition();
  response["c"] = cuisse.getPosition();
  response["r"] = hancheRot.getPosition();
  response["e"] = hancheEccart.getPosition();
  return response;
}

void Leg::moveTo(Messaging* messaging)
{
  int targetGenou=genou.targetFilter(messaging->getCommand()["gt"]);
  int targetCuisse=cuisse.targetFilter(messaging->getCommand()["ct"]);
  int targetRot=hancheRot.targetFilter(messaging->getCommand()["rt"]);
  int targetEccart=hancheEccart.targetFilter(messaging->getCommand()["et"]);

  while(checkTarget(targetGenou,targetCuisse, targetRot, targetEccart) )
  {
    adjustGenou(targetGenou);
    adjustCuisse(targetCuisse);
    adjustRot(targetRot);
    adjustEccart(targetEccart);
    messaging->sendJson(this->getPosition());
    delay(10);
  }
}
