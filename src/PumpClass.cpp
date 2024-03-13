#include "PumpClass.h"

PumpClass::PumpClass(int p) : pin(pin) {}

void PumpClass::initialize()
{
  pinMode(pin, OUTPUT);
}

void PumpClass::onAndOffPump(int timer)
{
  digitalWrite(pin, HIGH);
  delay(timer);
  digitalWrite(pin, LOW);
}