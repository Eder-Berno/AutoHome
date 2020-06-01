#include <Keypad.h>
#include<Servo.h>
Servo servo1;
int pinServo = 10, pulsomax = 2000, pulsomin = 1000;
int ledPin = 11; // Led en Pin 11
const int receptor = A1, transmisor = A0, garage_ocupado = A2, garage_disponible = A3; 
int distancia, tiempo;
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
int tecla = 0, menu_nivel = 0, valor = 0;
char Tecla, Clave[7], Clave_Correcta[7] = "231019";
char op_seleccionada = ' ';
int Buzzer = 12;
byte Indice = 0;
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  pinMode(Buzzer, OUTPUT);
  servo1.attach(pinServo);
  pinMode(receptor, INPUT);
  pinMode(transmisor, OUTPUT);
  pinMode(garage_ocupado, OUTPUT);
  pinMode(garage_disponible, OUTPUT);
  
}

void loop() {
  digitalWrite(Buzzer, LOW);
    Tecla = teclado.getKey();
    if (Tecla){
      Clave[Indice] = Tecla;
      Indice++;
      //Serial.print(Tecla);
    }
    if (Indice == 6){
      if(!strcmp(Clave, Clave_Correcta)){
      analogWrite(ledPin, 0);
      digitalWrite(Buzzer, LOW);
      delay(20);
        if (menu_nivel == 0){
    Serial.println("Selecciona una tarea a realizar por AutoHome");
    Serial.println("A) Sensor LDR.");
    Serial.println("B) Sensor del Garage.");
    Serial.println("C) Abrir la puerta principal.");
    tecla = 0;
    while(tecla == NULL){
      tecla = teclado.getKey();
      if (tecla == 'A' || tecla == 'B' || tecla == 'C');{
        op_seleccionada = tecla;
        menu_nivel = 1;
      }
    }
  }
  if (op_seleccionada !=  ' '){
    switch(op_seleccionada){
      case 'A':
        op_A();
        break;
      case 'B':
        op_B();
        break;
      case 'C':
        servo1.write(180);
        delay(2000);
        servo1.write(0);
        delay(2000);
        break;
    }
  }}
      else{
      tone(Buzzer, 200);
      analogWrite(ledPin, 255);
      delay(100);
      noTone(Buzzer);
      delay(100);
      Indice = 0;}
    }

}

void op_A(){
  int ldrPin = A4; // LDR en el pin analogico 4
  int ldrValue = 0;
  valor = 0;
  tecla = 0;
  while(tecla != '#'){
  tecla = teclado.getKey();
  if(tecla != NO_KEY){
  // Proceso LDR.
  ldrValue = analogRead(ldrPin); //entre 0 y 1023
  ldrValue = ldrValue/10;
  //Serial.println(ldrValue);
  if(ldrValue >= 0 && ldrValue <= 20){
    analogWrite(ledPin, 0);
    delay(500);
  }
  else if(ldrValue >= 20){
      analogWrite(ledPin, 255);
      delay(500);
  }
  }
  }
 menu_nivel=0;
}

void op_B(){
  valor = 0;
  tecla = 0;
  while(tecla != '#'){
  tecla = teclado.getKey();
  if(tecla != NO_KEY){
 analogWrite(transmisor, 255);
  delay(1);
  analogWrite(transmisor, 0);
  tiempo = pulseIn(receptor, 255);
  distancia = (tiempo/2)/29;
  Serial.println(distancia);
  delay(200);
  if(distancia == 0){
    analogWrite(garage_ocupado, 255);
    analogWrite(garage_disponible, 0);
  }
  else if (distancia >=1 && distancia <=70){
    analogWrite(garage_ocupado, 0);
    analogWrite(garage_disponible, 255);
  }
  }
  }
 menu_nivel=0;
}

