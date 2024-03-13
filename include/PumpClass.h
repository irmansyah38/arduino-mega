#ifndef PumpClass_H
#define PumpClass_H

#include <Arduino.h>

class PumpClass
{

public:
  int pin;

private:
  PumpClass(int p);
  void initialize();
  void onAndOffPump(int timer);
};

#endif