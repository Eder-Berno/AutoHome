#include<Servo.h>
Servo servo1;
int PinServo = 9, PulsoMin = 900, PulsoMax = 2100;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(PinServo, PulsoMin, PulsoMax);
}
void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(0);
  delay(3000);
  servo1.write(180);
  delay(3000);
}
