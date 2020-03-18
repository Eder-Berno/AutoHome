/*Universidad Nacional Autónoma de México. | Facultad de Ingeniería.
   Elaborado por: Acosta Rodríguez Eder Alberto. | Nombre del Proyecto: AutoHome*/
const int c=261, d=294, e=329, f=349, g=391, gS=415, a=440, aS=455, b=466, cH=523, cSH=554, dH=587, dSH=622, eH=659, fH=698, fSH=740, gH=784, gSH=830, aH=880;// Declaramos las constantes a utilizar
const int buzzerPin = 8; // Digital Pin 8
const int ledPin1 = 12;  // Digital Pin 12
const int ledPin2 = 13;  // Digital Pin 13
int counter = 0; // Declaramos un contador.
void setup()
{
  //Inicializamos la tarjeta arduino
  Serial.begin(9600);
  //Configuramos los pines a utilizar
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
void loop()
{
  //Play first section
  firstSection();

  //Play second section
  secondSection();

  //Variant 1
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);

  delay(500);

  //Repeat second section
  secondSection();

  //Variant 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  

  delay(650);
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
  //Detenemos el sonido del Buzzer
  noTone(buzzerPin);
  delay(50);
  counter++;  //Incrementamos el contador
}
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
  delay(500);
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
  delay(500);
}
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
  delay(325);
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
  delay(350);
}
