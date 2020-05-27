#include <Keypad.h>
int ledPin = 11;
int Buzzer = 12;
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
void setup() 
{
    Serial.begin(9600);
    pinMode(Buzzer, OUTPUT);
}

void loop() 
{
    digitalWrite(Buzzer, LOW);
    Tecla = teclado.getKey();
    if (Tecla){
      Clave[Indice] = Tecla;
      Indice++;
      Serial.print(Tecla);
    }
    if (Indice == 6){
      if(!strcmp(Clave, Clave_Correcta)){
      analogWrite(ledPin, 0);
      digitalWrite(Buzzer, LOW);
      delay(20);}
      else{
      tone(Buzzer, 200);
      analogWrite(ledPin, 255);
      delay(100);
      noTone(Buzzer);
      delay(100);
      Indice = 0;}
    }
}
