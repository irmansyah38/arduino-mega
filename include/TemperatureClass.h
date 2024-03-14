#ifndef TEMPERATURECLASS_H
#define TEMPERATURECLASS_H

#include <OneWire.h>
#include <DallasTemperature.h>

class DS18B20Sensor
{
private:
  OneWire oneWire;
  DallasTemperature sensors;
  DeviceAddress sensorAddress;

public:
  DS18B20Sensor(int pin);
  void initialize();
  float getValue();
};

#endif