//Acest program te lasa sa ajustezi intensitatea unui led prin modulare de puls


int led = 13;          // pinul de care e atasat ledul
int intensitate = 0;    // intensitatea initiala
int decolorare = 5;    // cat de tare se decoloreaza ledul

void setup() {
  // declara pin 13 ca iesire:
  pinMode(led, OUTPUT);
}


void loop() {
  // seteaza intensitatea pinului 13:
  analogWrite(led, intensitate);

  // schimba intensitatea la fiecare mers prin ciclu
  intensitate = intensitate + decolorare;

  // schimba directia in care se schimba intensitatea cand se ajunge la capat
  if (intensitate <= 0 || intensitate >= 255) {
    decolorare = -decolorare;
  }
  // asteapta 30 de milisecunde ca sa se observe efectul de schimbare a culorii
  delay(30);
}
