/*Universidad Nacional Autónoma de México. | Facultad de Ingeniería.
   Elaborado por: Acosta Rodríguez Eder Alberto. | Nombre del Proyecto: AutoHome
   Correo de contacto: ederacosta473@gmail.com*/
#include<Servo.h>
Servo Servito;
int val = 500;
const int receptor = 7, transmisor = 8, garage_ocupado = 2, garage_disponible = 1;
void setup()
{
  //Inicializamos la tarjeta arduino
  Serial.begin(9600);
  //Configuramos los pines a utilizar
  Servito.attach(9);
  pinMode(receptor, INPUT);
  pinMode(transmisor, OUTPUT);
}
void loop()
{
  //Sección de la ocupación del garage
  digitalWrite(transmisor, LOW);
  delayMicroseconds(val);
  digitalWrite(transmisor, HIGH);
  delayMicroseconds(val);
  tiempo = pulseIn(receptor, HIGH);
  distancia = 0.017 * tiempo;
  if(distancia <= 10 && distancia>0)
  {
    digitalWrite(garage_ocupado, HIGH);
    digitalWrite(garage_disponible, LOW);
    delay(distancia*10);
  }
  else
  {
    digitalWrite(garage_ocupado, LOW);
    digitalWrite(garage_disponible, HIGH);
    delay(distancia*10);
  }
  //Sección del servo para abrir la puerta principal
  Servito.write(45);
  delay(val);
  //Sección 
}
