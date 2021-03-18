#include "./LegBuilder.h"

LegBuilder::LegBuilder()
{

}

LegBuilder::~LegBuilder()
{

}
const Leg* LegBuilder::getLegD()
{
  BlockedMotor::BlockedMotorInitializer cuisseDInit= this-> getMotorInit(7,1,0,180,90);
    BlockedMotor::BlockedMotorInitializer genouDInit= this-> getMotorInit(6,1,0,200,110);
    BlockedMotor::BlockedMotorInitializer hancheDRotInit= this-> getMotorInit(15,-1,30,160,90);
    BlockedMotor::BlockedMotorInitializer hancheDEccartInit= this-> getMotorInit(14,-1,50,150,75);
    return new Leg(hancheDRotInit,hancheDEccartInit, cuisseDInit, genouDInit);
}

const Leg* LegBuilder::getLegG()
{
    BlockedMotor::BlockedMotorInitializer cuisseGInit= this-> getMotorInit(4,1,0,200,90);
    BlockedMotor::BlockedMotorInitializer genouGInit= this-> getMotorInit(5,-1,0,160,90);
    BlockedMotor::BlockedMotorInitializer hancheGRotInit= this-> getMotorInit(2,1,30,170,100);
    BlockedMotor::BlockedMotorInitializer hancheGEccartInit= this-> getMotorInit(3,1,40,160,70);
    return new Leg(hancheGRotInit, hancheGEccartInit, cuisseGInit, genouGInit);
}




BlockedMotor::BlockedMotorInitializer LegBuilder::getMotorInit(const int& pin,const int& spin,const int& min,const int& max,const int& initPosition)
{
    BlockedMotor::BlockedMotorInitializer motorInit;
    motorInit.spin = spin;
    motorInit.pin = pin;
    motorInit.min = min;
    motorInit.max = max;
    motorInit.position = initPosition;
    return motorInit;
}
