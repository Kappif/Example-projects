//Acest program inchide si deschide un led o data pe secunda

int ledPin = 13;
int timp = 1000; //scris in milisecunde

void setup()
{
  pinMode( ledPin , OUTPUT);
}

void loop()
{
  digitalWrite(ledPin , HIGH); //Aprinde ledul
  delay(timp);
  digitalWrite(ledPin , LOW ); //Stinge ledul
  delay(timp);
}
