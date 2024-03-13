#include "TemperatureClass.h"
DS18B20Sensor ::DS18B20Sensor(int pin) : oneWire(pin), sensors(&oneWire)
{
}
void DS18B20Sensor::initialize()
{
  sensors.begin();
}

float DS18B20Sensor::getValue()
{
  // Minta pembacaan suhu
  sensors.requestTemperatures();

  // Baca suhu dalam Celsius
  float temperatureCelsius = sensors.getTempC(sensorAddress);

  return temperatureCelsius;
}

bool DS18B20Sensor::checkSensor()
{
  return sensors.isConnected();
}