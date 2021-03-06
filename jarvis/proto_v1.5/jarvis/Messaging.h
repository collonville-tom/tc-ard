#ifndef _MESSAGING_H_
#define _MESSAGING_H_

#include <ArduinoJson.h>

class Messaging
{
  public:
    const char start_bit = '$';
    const char stop_bit = '#';
    const int doc_size=100;

  private:
    DynamicJsonDocument command;
    boolean docAvailable = false;
  public:
    Messaging();
    ~Messaging();

    void sendJson(DynamicJsonDocument message);
    void sendJson(const String& message);
    void readCommands(const String payload );
    void unFlag();
    boolean hasNewCommand();
    DynamicJsonDocument getCommand();
};

#endif
