#include "./LegBuilder.h"

LegBuilder::LegBuilder()
{

}

LegBuilder::~LegBuilder()
{

}

const Leg* LegBuilder::getLegG()
{
    BlockedMotor::BlockedMotorInitializer genouGInit= this-> getMotorInit(5,1,0,160,160);
    BlockedMotor::BlockedMotorInitializer cuisseGInit= this-> getMotorInit(4,1,0,200,150);
    BlockedMotor::BlockedMotorInitializer hancheGRotInit= this-> getMotorInit(2,-1,30,170,100);
    BlockedMotor::BlockedMotorInitializer hancheGEccartInit= this-> getMotorInit(3,-1,40,160,80);
    return new Leg(hancheGRotInit, hancheGEccartInit, cuisseGInit, genouGInit);
}

const Leg* LegBuilder::getLegD()
{
    BlockedMotor::BlockedMotorInitializer genouDInit= this-> getMotorInit(6,1,0,200,30);
    BlockedMotor::BlockedMotorInitializer cuisseDInit= this-> getMotorInit(7,1,0,180,20);
    BlockedMotor::BlockedMotorInitializer hancheDRotInit= this-> getMotorInit(14,-1,30,160,80);
    BlockedMotor::BlockedMotorInitializer hancheDEccartInit= this-> getMotorInit(15,-1,50,150,80);
    return new Leg(hancheDEccartInit, hancheDRotInit, cuisseDInit, genouDInit);
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
