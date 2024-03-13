#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "PumpClass.h"
#include "ScaleClass.h"
#include "TemperatureClass.h"

// make object sensors
DS18B20Sensor suhu(2);
ScaleClass basaScale(3, 4, 8000);
ScaleClass asamScale(6, 7, 9000);
PumpClass pump(10);
// make object lcd
LiquidCrystal_I2C lcd(0x27, 20, 4);

// make variable for value sensors
int phValue = 0;
int suhuValue = 0;
float basaValue = 0;
float asamValue = 0;

void displaySensorsValue(int coloum, int row, float value)
{
  lcd.setCursor(coloum, row);
  lcd.print(value);
}

// make function for postion display sensors
void displaySensors()
{
  // display ph
  lcd.setCursor(6, 0);
  lcd.print("PH   : ");
  displaySensorsValue(7, 0, phValue);

  // display suhu
  lcd.setCursor(6, 1);
  lcd.print("Suhu : ");
  displaySensorsValue(7, 1, suhuValue);

  // display basa scale
  lcd.setCursor(6, 2);
  lcd.print("Basa : ");
  displaySensorsValue(7, 2, basaValue);

  // display basa scale
  lcd.setCursor(6, 2);
  lcd.print("Asam : ");
  displaySensorsValue(7, 3, asamValue);
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
    displaySensorsValue(7, 1, suhuValue)
  }
  else
  {
    displaySensorError("suhu");
  }
}

void executeBasa()
{
  if (basaScale.checkSensor())
  {
    basaValue = basaScale.getValue();
    displaySensorsValue(7, 2, basaValue)
  }
  else
  {
    displaySensorError("Basa");
  }
}

void executeAsam()
{
  if (asamScale.checkSensor())
  {
    asamValue = asamScale.getValue();
    displaySensorsValue(7, 2, asamValue)
  }
  else
  {
    displaySensorError("asamScale");
  }
}

void setup()
{
  Serial.begin(9600);
  // for initialize
  suhu.initialize();
  // for initialize scale
  basaScale.initialize();
  asamScale.initialize();
  // for pump
  pump.initialize();
  // lcd
  lcd.init();
  lcd.backlight();
  displaySensors();
}

void loop()
{
  executeSuhu();
  executeBasa();
  executeAsam();
}
