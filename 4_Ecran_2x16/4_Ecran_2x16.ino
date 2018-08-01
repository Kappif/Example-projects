//Acest proiect printeaza pe ecranul 2x16 un mesaj urmat de timpul de la ultimul reset
//Include biblioteca ecranului
#include <LiquidCrystal.h>


// inițializați biblioteca prin asocierea oricărui pin de interfață LCD necesar
// cu numarul pinului arduino la care este conectat
const int rs=PL2, EN=PL3, D4=PL4, D5=PL5, D6=PL6, D7=PL7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // configurați numărul de coloane și rânduri ale ecranului LCD:
  lcd.begin(16, 2);
  // Imprimați un mesaj pe ecranul LCD.
  lcd.print("hello, world!");
}

void loop() {
  // setați cursorul în coloana 0, rândul 1
  // (nota: linia 1 este al doilea rând, deoarece numărarea începe cu 0):
  lcd.setCursor(0, 1);
  // tipăriți numărul de secunde de la resetare:
  lcd.print(millis() / 1000);
}
