/*Universidad Nacional Autónoma de México. | Facultad de Ingeniería.
   Elaborado por: Acosta Rodríguez Eder Alberto. | Nombre del Proyecto: AutoHome
   Correo de contacto: ederacosta473@gmail.com*/
#include<Servo.h>
#include <Keypad.h>
Servo Servito;
int val = 500,sensor = 2,nivel = 0;
const int receptor = 7, transmisor = 8, garage_ocupado = 2, garage_disponible = 1;
const byte filas = 4;
const byte columnas = 4;
const byte pin_filas[filas] = { 11, 10, 9, 8 };
const byte pin_columna[columnas] = { 7, 6, 5, 4 };
char coordenadas[filas][columnas] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '#', '0', '*', 'D' }
};
Keypad keypad = Keypad(makeKeymap(coordenadas), pin_filas, pin_columna, filas, columnas);
void setup()
{
  //Inicializamos la tarjeta arduino
  Serial.begin(9600);
  //Configuramos los pines a utilizar
  Servito.attach(9);
  pinMode(receptor, INPUT);
  pinMode(transmisor, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, INPUT);
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
  char tecla = keypad.getKey();

  if (tecla) {
    Serial.println(tecla);
  }
  switch (tecla){
    case'1':
      digitalWrite(3, HIGH);
    break;
    case'2':
      digitalWrite(3, LOW);
    break;    
    case'3':
      digitalWrite(12, HIGH);
    break;    
    case'4':
      digitalWrite(12, LOW);
    break;
  }
  Servito.write(45);
  delay(val);
  //Sección del sensor de luz
  
}
