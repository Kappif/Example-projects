// Acest program foloseste un senzor de prezenta umana sa detecteze daca exista personae in jur
// si apoi afiseaza un mesaj pe ecranul LCD

//Include biblioteca ecranului
#include <LiquidCrystal.h>


// inițializați biblioteca prin asocierea oricărui pin de interfață LCD necesar
// cu numarul pinului arduino la care este conectat
const int rs=PL2, EN=PL3, D4=PL4, D5=PL5, D6=PL6, D7=PL7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pinSenzor = 4;
int indicator = 13;


void setup()
{
  // configurați numărul de coloane și rânduri ale ecranului LCD:
  lcd.begin(16, 2);
  // seteaza pinul senzori ca pin de intrare care v-a luat valori
  pinMode(pinSenzor,INPUT);
  // seteaza pinul "indicator" ca pin de iesire care v-a afisa valori
  pinMode(indicator,OUTPUT);
  // begin serial port
  Serial.begin(9600);
}

void loop()
{
  int state = digitalRead(pinSenzor);
  digitalWrite(indicator,state); //Aprinde un led daca se afla oameni in jur
  if(state == 1)
  {
    // setați cursorul pe coloana 0, rândul 1
    lcd.setCursor(0, 1);
    // afiseaza mesaj pe ecran la pozitia cursorului
    lcd.print("Om detectat!");
    // Afiseaza prin modulul serial
    Serial.println("Cineva se afla in zona!");
  }
  else if(state == 0)
  {
    // setați cursorul pe coloana 0, rândul 1
    lcd.setCursor(0, 1);
    // afiseaza mesaj pe ecran la pozitia cursorului
    lcd.print("Nu e nimeni.");
    // Afiseaza prin modulul serial
    Serial.println("Nu e nimeni");
  }
  delay(500);
}
