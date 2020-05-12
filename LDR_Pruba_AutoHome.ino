int ledPin = 11; // Piezo on Pin 11
int ldrPin = A4; // LDR en el pin analogico 4
int ldrValue = 0;

void setup() { 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}

void loop() { 
  ldrValue = analogRead(ldrPin); //entre 0 y 1023
  Serial.println(ldrValue);
  ldrValue = (ldrValue*255)/1023;
  analogWrite(ledPin, ldrValue);
  delay(500);
}

