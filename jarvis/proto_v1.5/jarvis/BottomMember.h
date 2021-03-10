#ifndef _BOTTOMMEMBER_H_
#define _BOTTOMMEMBER_H_

#include "./Leg.h"

class BottomMember
{
    private:
        Leg legD;
        Leg legG;
    public:
        BottomMember(const Leg& legD,const Leg& legG);
        ~BottomMember();

        DynamicJsonDocument getPosition();
        void moveTo(Messaging* messaging);
};

#endif
