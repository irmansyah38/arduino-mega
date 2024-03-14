#include "ScaleClass.h"

ScaleClass::ScaleClass(int doutPin, int clkPin, float calFactor)
    : scale(doutPin, clkPin), calibration_factor(calFactor) {}

void ScaleClass::initialize()
{

  scale.set_scale();
  scale.tare();
}

float ScaleClass::getWeight()
{
  scale.set_scale(calibration_factor);
  int GRAM = scale.get_units();
  return GRAM;
}
