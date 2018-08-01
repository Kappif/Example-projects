
//Include biblioteca ecranului si a senzorului de uimiditate
#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 38 //Ataseaza senzorul de pinul 7


// inițializați biblioteca prin asocierea oricărui pin de interfață LCD necesar
// cu numarul pinului arduino la care este conectat
const int rs=PL2, EN=PL3, D4=PL4, D5=PL5, D6=PL6, D7=PL7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
  //Serial Port begin
  Serial.begin(9600);
  // configurați numărul de coloane și rânduri ale ecranului LCD:
  lcd.begin(16, 2);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperatura = "); //Afiseaza temperatura prin portul serial
  Serial.println(DHT.temperature);
  Serial.print("Umiditate = "); //Afiseaza umiditatea prin portul serial
  Serial.println(DHT.humidity);

  // setați cursorul în coloana 0, rândul 1
  lcd.setCursor(0, 1);
  // afiseaza valoarea temperaturii pe ecran
  lcd.print(DHT.temperature);
  lcd.print("C");

  // setați cursorul în coloana 1, rândul 1
  lcd.setCursor(1, 1);
  // afiseaza valoarea umiditatii pe ecran
  lcd.print(DHT.humidity);


  delay(1500);
}
