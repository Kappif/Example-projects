//Acest proiect printeaza pe ecranul 2x16 un mesaj urmat de timpul de la ultimul reset

// includem libraria utilizata pentru a vorbi cu ecranul
#include <LiquidCrystal.h>


// initializam libraria prin asocierea pinilor de pe LCD 
// cu pinii de pe arduino

// rs= PL2, EN= PL3, D4=PL4, D5=PL5, D6=PL6, D7=PL7

const int rs = 37, en = 38, d4 = 39, d5 = 40, d6 = 41, d7 = 42;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // initializam randurile si coloanele LCD-ului
  lcd.begin(16, 2);
  // afiseaza un mesaj pe ecran
  lcd.print("hello, world!");
}

void loop() {
  // seteaza crusorul pe coloana 0 si randul 1
  // (nota: linia 1 inseamna al doilea rand, deoarece numaratoarea in programare incepe intotdeauna de la 0):
  lcd.setCursor(0, 1);
  // printeaza timpul trecut de la ultimul reset al arduino-ului
  lcd.print(millis() / 1000);
}

