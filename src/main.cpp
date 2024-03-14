#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// make object lcd
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{

  lcd.init();
  lcd.backlight();
  displaySensors();
}

void loop()
{
}
