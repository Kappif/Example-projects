//Acest program foloseste un senzor de prezenta umana sa detecteze daca exista personae in jur.

int pinSenzor = 4;
int indicator = 13;
void setup()
{
  pinMode(pinSenzor,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int state = digitalRead(pinSenzor);
  digitalWrite(indicator,state); //Aprinde un led daca se afla oameni in jur
  if(state == 1)
    Serial.println("Cineva se afla in zona!"); //Afiseaza prin modulul serial
  else if(state == 0)
    Serial.println("Nu e nimeni");
  delay(500);
}
