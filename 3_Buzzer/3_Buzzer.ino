const int buzzer = 8 ; // buzzer la arduino pin 8

void setup () {
  pinMode (buzzer, OUTPUT); // Setați buzzer-pinul 8 ca ieșire
}

void loop () {
  tone(buzzer, 2000); // Trimite semnal sonor 2KHz ...
  delay(1000); // ... timp de 1 sec
  noTone(buzzer); // Opriți sunetul ...
  delay(1000); // ... pentru 1 sec
}
