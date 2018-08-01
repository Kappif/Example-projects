// Acest exemplu arata distanta intre senzorul ultrasonic si cel mai apropiat obiect cu afisaz pe LCD

// Include biblioteca ecranului
#include <LiquidCrystal.h>

int pinDeclansare = 22;    // pinul care trimite semnal ultrasonic
int pinEcou = 23;    // pinul care primeste ecoul ultrasonic
long duration, cm, inches;


// inițializați biblioteca prin asocierea oricărui pin de interfață LCD necesar
// cu numarul pinului arduino la care este conectat
const int rs=PL2, EN=PL3, D4=PL4, D5=PL5, D6=PL6, D7=PL7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
  // Serial Port begin
  Serial.begin (9600);
  // Define inputs and outputs
  pinMode(pinDeclansare, OUTPUT);
  pinMode(pinEcou, INPUT);
  // configurați numărul de coloane și rânduri ale ecranului LCD:
  lcd.begin(16, 2);
}

void loop()
{
  // Senzorul e declansat de un puls mai lung de 5 milisecunde
  // Incepem cu un puls low ca sa asiguram calitatea pulsului high
  digitalWrite(pinDeclansare, LOW);
  delayMicroseconds(5);
  digitalWrite(pinDeclansare, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinDeclansare, LOW);

  // Citeste valoarea initiala
  // durata este in milisecunde

  duration = pulseIn(pinEcou, HIGH);

  // folosim o formula matematica sa schimbam din milisecunde in centimetri
  cm = (duration/2) / 29.1;

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  // setați cursorul pe coloana 0, rândul 1
  lcd.setCursor(0, 1);
  // afiseaza pe ecran valoarea distantei in cm
  lcd.print(cm);
  lcd.print("cm");

  delay(250);
}
