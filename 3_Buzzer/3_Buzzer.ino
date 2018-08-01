const int buzzer = ; // buzzer la arduino pin 8

void setup () {
  pinMode (buzzer, OUTPUT); // Setați buzzer-pinul 8 ca ieșire
}

void loop () {
  tone(buzzer, 1000); // Trimite semnal sonor 1KHz ...
  delay(1000); // ... timp de 1 sec
  noTone(buzzer); // Opriți sunetul ...
  delay(1000); // ... pentru 1 sec
}
