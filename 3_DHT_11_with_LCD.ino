/*
  The purpose of this program is to continue our knowledge on how an lcd works, and use it with a temperature and humidity sensor DHT11.
  This program provides the ability to read the temperature (celsius or fahrenheit) and humidity values,
  which is then displayed on the lcd determining the sensors value.
*/

#include <DHT.h>
#define Type DHT11
#include <LiquidCrystal.h>

// define pins between lcd and ardunio uno
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

// sensor setup
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int dt = 1000;

// lcd pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// the loop function runs over and over again forever
void setup()
{

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  HT.begin(); // establishes a connection with using sensor DHT11
  delay(setTime); // wait time (setime = 500ms)
  lcd.begin(16, 2); // set up the LCD's number of columns and rows

}

// the loop function runs over and over again forever
void loop()
{

  humidity = HT.readHumidity();
  tempC = HT.readTemperature(true); // Celsius is set as the unit of temperature to be used
  tempF = HT.readTemperature(); // Fahrenheit can be set as the unit of temperature if set to true

  lcd.setCursor(0, 0); // position of text on lcd (will show on 1st colomn)
  lcd.print("Temp C = "); // print text on lcd
  lcd.print(tempC); // print temperature value in celsius on lcd

  lcd.setCursor(0, 1); // position of text on lcd (will show on 2nd colomn)
  lcd.print("Humidity = "); // print text on lcd
  lcd.print(humidity); // print humidity value on lcd
  lcd.print(" %"); // print text on lcd
  delay(setTime); // wait time (setime = 500ms)
  lcd.clear();

  Serial.print("Humidity: "); // print text in serial monitor
  Serial.print(humidity); // print humidity value in serial monitor
  Serial.print("% Temperature "); // print text in serial monitor

  Serial.print(tempC); // print celsius value in serial monitor
  Serial.print(" C "); // print text in serial monitor

  Serial.print(tempF); // print fahrenheit value in serial monitor
  Serial.println(" F "); // print text in serial monitor

}
