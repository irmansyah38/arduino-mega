#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "TemperatureClass.h"

// make object sensors
DS18B20Sensor suhu(2);

// make object lcd
LiquidCrystal_I2C lcd(0x27, 20, 4);

// make variable for value sensors
int suhuValue = 0;

void displaySensorsValue(int coloum, int row, float value)
{
  lcd.setCursor(coloum, row);
  lcd.print(value);
}

// make function for postion display sensors
void displaySensors()
{

  // display suhu
  lcd.setCursor(6, 1);
  lcd.print("Suhu : ");
  displaySensorsValue(7, 1, suhuValue);
}

// display sensors value for example suhu,ph dan lain lain
void displaySensorError(char sensor)
{
  lcd.clear();
  lcd.print("Sensor " + sensor + " error");
  delay(2000);
  lcd.clear();
  displaySensors();
}

// make function for ph sensor
void executeSuhu()
{
  if (suhu.checkSensor())
  {
    suhuValue = suhu.getValue();
    displaySensorsValue(7, 1, suhuValue);
  }
  else
  {
    displaySensorError("suhu");
  }
}

void setup()
{
  Serial.begin(9600);
  // for initialize
  suhu.initialize();
  // for initialize scale

  // for pump
  // lcd
  lcd.init();
  lcd.backlight();
  displaySensors();
}

void loop()
{
  executeSuhu();
}
