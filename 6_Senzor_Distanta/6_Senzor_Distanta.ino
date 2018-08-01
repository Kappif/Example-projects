//Acest exemplu arata distanta intre senzorul ultrasonic si cel mai apropiat obiect

int pinDeclansare = 22;    //pinul care trimite semnal ultrasonic
int pinEcou = 23;    //pinul care primeste ecoul ultrasonic
long duration, cm, inches;

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(pinDeclansare, OUTPUT);
  pinMode(pinEcou, INPUT);
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

  pinMode(pinEcou, INPUT);
  duration = pulseIn(pinEcou, HIGH);

  // folosim o formula matematica sa schimbam din milisecunde in centimetri
  cm = (duration/2) / 29.1;

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);
}
