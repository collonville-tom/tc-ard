#include "./LegBuilder.h"

LegBuilder::LegBuilder()
{

}

LegBuilder::~LegBuilder()
{

}
const Leg* LegBuilder::getLegD()
{
  // 0 arriere,180 avant
  BlockedMotor::BlockedMotorInitializer cuisseDInit= this-> getMotorInit("cd",7,0,180,90);
  // 0 avant,180 arriere
  BlockedMotor::BlockedMotorInitializer genouDInit= this-> getMotorInit("gd",6,0,180,110);
  // 0 interieur,180 exterieur
  BlockedMotor::BlockedMotorInitializer hancheDRotInit= this-> getMotorInit("rd",15,0,180,90);
  // 0 arriere,180 avant
  BlockedMotor::BlockedMotorInitializer hancheDEccartInit= this-> getMotorInit("ed",14,0,180,70);
  return new Leg(hancheDRotInit,hancheDEccartInit, cuisseDInit, genouDInit);
}

const Leg* LegBuilder::getLegG()
{ 
  // 0 avant,180 arriere
  BlockedMotor::BlockedMotorInitializer cuisseGInit= this-> getMotorInit("cg",4,0,180,85);
  // 0 arriere,180 avant
  BlockedMotor::BlockedMotorInitializer genouGInit= this-> getMotorInit("gg",5,0,180,90);
  // 0 exterieur,180 interieur
  BlockedMotor::BlockedMotorInitializer hancheGRotInit= this-> getMotorInit("rg",2,0,180,100);
  // 0 avant,180 arriere
  BlockedMotor::BlockedMotorInitializer hancheGEccartInit= this-> getMotorInit("eg",3,0,180,70);
  return new Leg(hancheGRotInit, hancheGEccartInit, cuisseGInit, genouGInit);
}




BlockedMotor::BlockedMotorInitializer LegBuilder::getMotorInit(const String& tag,const int& pin,const int& minPosition,const int& maxPosition,const int& initPosition)
{
    BlockedMotor::BlockedMotorInitializer motorInit;
    motorInit.pin = pin;
    motorInit.minPosition = minPosition;
    motorInit.maxPosition = maxPosition;
    motorInit.position = initPosition;
    motorInit.tag=tag;
    return motorInit;
}
