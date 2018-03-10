#include <Servo.h>
Servo talonSR;

int rawVal = 0;
int mappedVal = 0;

int potPin = 0;
int talonPin = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

talonSR.attach(talonPin);

}

void loop() {
  // put your main code here, to run repeatedly:
 
rawVal = analogRead(potPin);
mappedVal = map(rawVal, 0, 1023, 1000, 2000);

Serial.println(mappedVal);

talonSR.writeMicroseconds(mappedVal);

delay(5);

}
