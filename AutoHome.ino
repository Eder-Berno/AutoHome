/*Universidad Nacional Autónoma de México. | Facultad de Ingeniería.
   Elaborado por: Acosta Rodríguez Eder Alberto. | Nombre del Proyecto: AutoHome
   Correo de contacto: ederacosta473@gmail.com*/
#include<Servo.h>
#include <Keypad.h>
Servo Servito;
int valor, valor_pre, sensor = 2,nivel = 0;
float distancia= 0, tiempo= 0;
const int receptor = A1, transmisor = A0, garage_ocupado = A2, garage_disponible = A3,LDR = A4, LED_LDR = 11;
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
  /*
  //Inicializamos la tarjeta arduino
  Serial.begin(9600);
  //Configuramos los pines a utilizar
  Servito.attach(9);
  pinMode(receptor, INPUT);
  pinMode(transmisor, OUTPUT);
  pinMode(garage_ocupado, OUTPUT);
  pinMode(garage_disponible, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(LED_LDR, OUTPUT);
}
void loop()
{
  /*
  analogWrite(garage_disponible, 255);
  //Sección de la ocupación del garage
  analogWrite(transmisor, LOW);
  delayMicroseconds(4);
  analogWrite(transmisor, HIGH);
  delayMicroseconds(10);
  tiempo = (pulseIn(receptor, HIGH)/2);
  //distancia = 0.017 * tiempo;
  distancia = tiempo *0.0343;
  if(distancia <= 2)
  {
    analogWrite(garage_ocupado, 255);
    analogWrite(garage_disponible, 0);
    delayMicroseconds(10);
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
  delay(1);*/
  //Sección del sensor de luz
  valor_pre =analogRead(LDR);
  Serial.println(valor);
  valor=(valor_pre)/10;
  analogWrite(LED_LDR, valor);
  delay(500); 
}
