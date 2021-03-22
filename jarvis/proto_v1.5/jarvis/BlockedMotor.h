#ifndef _BLOCKEDMOTOR_H_
#define _BLOCKEDMOTOR_H_

#include <Servo.h>
#include <WString.h>
#include "./Messaging.h"

class BlockedMotor
{
    public:
        typedef struct {
            int pin;
            int minPosition;
            int maxPosition;
            int position;
            String tag;
        } BlockedMotorInitializer;

    private:
        Servo servo;
        int minPosition;
        int maxPosition;
        int position;
        String tag;

    public:
        BlockedMotor(const BlockedMotorInitializer& blockedMotorInitializer);
        BlockedMotor(const String& tag,const int& pin,const int& minPosition,const int& maxPosition,const int& initPosition);
        ~BlockedMotor();
        void setPosition(const int& value);
        int getPosition();
        void add(const int& value);
        void remove(const int& value);
        int adaptTarget(Messaging* messaging);
        bool isTargetReached(int target);
        String getTag();
       
};

#endif
