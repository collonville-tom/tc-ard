#ifndef _BLOCKEDMOTOR_H_
#define _BLOCKEDMOTOR_H_

#include <Servo.h>

class BlockedMotor
{
    public:
        typedef struct {
            int spin;
            int pin;
            int min;
            int max;
            int position;
        } BlockedMotorInitializer;

    private:
        Servo servo;
        int spin;
        int min;
        int max;
        int position;

    public:
        BlockedMotor(const BlockedMotorInitializer& blockedMotorInitializer);
        BlockedMotor(const int& pin,const int& spin,const int& min,const int& max,const int& initPosition);
        ~BlockedMotor();
        void setPosition(const int& value);
        int getPosition();
        void add(const int& value);
        void remove(const int& value);
        int targetFilter(const int& target);
       
};

#endif
