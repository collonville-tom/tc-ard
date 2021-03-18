#ifndef _LEG_H_
#define _LEG_H_

#include "./BlockedMotor.h"
#include <ArduinoJson.h>
#include "./Messaging.h"

class Leg
{
  private:
    BlockedMotor cuisse;
    BlockedMotor genou;
    BlockedMotor hancheRot;
    BlockedMotor hancheEccart;
  public:
    Leg(const BlockedMotor::BlockedMotorInitializer& hanche_rot,
        const BlockedMotor::BlockedMotorInitializer& hanche_eccart,
        const BlockedMotor::BlockedMotorInitializer& cuisse,
        const BlockedMotor::BlockedMotorInitializer& genou);
    ~Leg();

    void moveTo(const int targetGenou,const int targetCuisse,const int targetRot,const int targetEccart);
    bool isTargetReached(int targetGenou,int targetCuisse, int targetRot, int targetEccart);

    BlockedMotor getCuisse();
    BlockedMotor getGenou();
    BlockedMotor getHancheRot();
    BlockedMotor getHancheEccart();

  private:
    void adjust(const BlockedMotor& articulation,int targetRot);
    
};

#endif
