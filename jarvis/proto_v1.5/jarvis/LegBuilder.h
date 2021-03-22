#ifndef _LEGBUILDER_H_
#define _LEGBUILDER_H_

#include "./Leg.h"

class LegBuilder
{
    public:
        LegBuilder();
        ~LegBuilder();

        const Leg* getLegD();
        const Leg* getLegG();

    private:
        BlockedMotor::BlockedMotorInitializer getMotorInit(const String& value,const int& pin,const int& minPosition,const int& maxPosition,const int& initPosition);
};

#endif
