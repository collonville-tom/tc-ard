#include "./LegBuilder.h"

LegBuilder::LegBuilder()
{

}

LegBuilder::~LegBuilder()
{

}
const Leg* LegBuilder::getLegD()
{
  BlockedMotor::BlockedMotorInitializer cuisseDInit= this-> getMotorInit("cd",7,1,0,180,90);
    BlockedMotor::BlockedMotorInitializer genouDInit= this-> getMotorInit("gd",6,1,0,200,110);
    BlockedMotor::BlockedMotorInitializer hancheDRotInit= this-> getMotorInit("rd",15,-1,30,160,90);
    BlockedMotor::BlockedMotorInitializer hancheDEccartInit= this-> getMotorInit("ed",14,-1,50,150,75);
    return new Leg(hancheDRotInit,hancheDEccartInit, cuisseDInit, genouDInit);
}

const Leg* LegBuilder::getLegG()
{
    BlockedMotor::BlockedMotorInitializer cuisseGInit= this-> getMotorInit("cg",4,1,0,200,90);
    BlockedMotor::BlockedMotorInitializer genouGInit= this-> getMotorInit("gg",5,-1,0,160,90);
    BlockedMotor::BlockedMotorInitializer hancheGRotInit= this-> getMotorInit("gr",2,1,30,170,100);
    BlockedMotor::BlockedMotorInitializer hancheGEccartInit= this-> getMotorInit("eg",3,1,40,160,70);
    return new Leg(hancheGRotInit, hancheGEccartInit, cuisseGInit, genouGInit);
}




BlockedMotor::BlockedMotorInitializer LegBuilder::getMotorInit(const String& tag,const int& pin,const int& spin,const int& minPosition,const int& maxPosition,const int& initPosition)
{
    BlockedMotor::BlockedMotorInitializer motorInit;
    motorInit.spin = spin;
    motorInit.pin = pin;
    motorInit.minPosition = minPosition;
    motorInit.maxPosition = maxPosition;
    motorInit.position = initPosition;
    motorInit.tag=tag;
    return motorInit;
}
