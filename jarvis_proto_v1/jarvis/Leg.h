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

    void adjustGenou(int targetGenou);
    void adjustCuisse(int targetCuisse);
    void adjustRot(int targetRot);
    void adjustEccart(int targetEccart);
    void moveTo(Messaging* messaging);
    DynamicJsonDocument getPosition();


  private:
    bool checkTarget(int targetGenou,int targetCuisse, int targetRot, int targetEccart);
};

#endif
