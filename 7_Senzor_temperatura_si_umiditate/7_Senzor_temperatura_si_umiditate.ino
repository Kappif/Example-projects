
#include <dht.h>

dht DHT;

#define DHT11_PIN 38 //Ataseaza senzorul de pinul 7


void setup(){
  //Serial Port begin
  Serial.begin(9600);
  // configurați numărul de coloane și rânduri ale ecranului LCD:
  lcd.begin(16, 2);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperatura = ");
  // Afiseaza temperatura prin portul serial
  Serial.println(DHT.temperature);
  Serial.print("Umiditate = ");
   // Afiseaza umiditatea prin portul serial
  Serial.println(DHT.humidity);
  delay(1500);
}
