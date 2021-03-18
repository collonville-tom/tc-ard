#include "./Leg.h"



Leg::Leg(const BlockedMotor::BlockedMotorInitializer& hanche_rot_init, const BlockedMotor::BlockedMotorInitializer& hanche_eccart_init,
         const BlockedMotor::BlockedMotorInitializer& cuisse_init,const BlockedMotor::BlockedMotorInitializer& genou_init):
cuisse(cuisse_init),genou(genou_init),hancheRot(hanche_rot_init),hancheEccart(hanche_eccart_init)
{
}

Leg::~Leg()
{
}

bool Leg::isTargetReached(int targetGenou,int targetCuisse, int targetRot, int targetEccart)
{
  return genou.isTargetReached(targetGenou) && cuisse.isTargetReached(targetCuisse) && hancheRot.isTargetReached(targetRot) && hancheEccart.isTargetReached(targetEccart);
}


void Leg::adjust(const BlockedMotor& articulation, int target)
{
  if(target > articulation.getPosition())
    articulation.remove(1);
  if(target < articulation.getPosition())
    articulation.add(1);
}


void Leg::moveTo(const int targetGenou,const int targetCuisse,const int targetRot,const int targetEccart)
{
  adjust(genou,targetGenou);
  adjust(cuisse,targetCuisse);
  adjust(hancheRot,targetRot);
  adjust(hancheEccart,targetEccart);
}

BlockedMotor Leg::getCuisse(){
  return cuisse;
}

BlockedMotor Leg::getGenou(){
  return genou;
}

BlockedMotor Leg::getHancheRot(){
  return hancheRot;
}

BlockedMotor Leg::getHancheEccart(){
  return hancheEccart;
}
