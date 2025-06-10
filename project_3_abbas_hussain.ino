#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 6  

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {

  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }


  float hif = dht.computeHeatIndex(f, h);

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(f, 2);  
  lcd.print("F ");
  lcd.print(h, 0);
  lcd.print("% hum");

  lcd.setCursor(0, 1);
  lcd.print("Heat Ind ");
  lcd.print(hif, 2);
  lcd.print("F");
}
