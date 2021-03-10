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
        BlockedMotor::BlockedMotorInitializer getMotorInit(const int& pin,const int& spin,const int& min,const int& max,const int& initPosition);
};

#endif
