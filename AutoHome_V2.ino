/*Universidad Nacional Autónoma de México. | Facultad de Ingeniería.
   Elaborado por: Acosta Rodríguez Eder Alberto. | Nombre del Proyecto: AutoHome
   Correo de contacto: ederacosta473@gmail.com*/
//Declaraciones de LDR.
int ledPin = 11; // Led en Pin 11
int ldrPin = A4; // LDR en el pin analogico 4
int ldrValue = 0;
//Declaraciones de Teclado Matricial.
#include <Keypad.h>
const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {9,8,7,6};
byte pinesColumnas[COLUMNAS] = {5,4,3,2};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char Tecla, Clave[7], Clave_Correcta[7] = "231019";
byte Indice = 0;
------------------------------------------------------------------------------------------------------------
void setup() 
{
  Serial.begin(9600);
  // Proceso LDR.
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}
------------------------------------------------------------------------------------------------------------
void loop() 
{
  // Proceso LDR.
  ldrValue = analogRead(ldrPin); //entre 0 y 1023
  Serial.println(ldrValue);
  ldrValue = (ldrValue*255)/1023;
  analogWrite(ledPin, ldrValue);
  delay(500);
  // Proceso Teclado Matricial.
}
