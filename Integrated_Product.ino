// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo talonSR;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

char setupStr[] = "  Motor Tester  ";
char setupStr2[] = "   mrElectric   ";
int strL = sizeof(setupStr);
int strL2 = sizeof(setupStr2);

int lcdWidth = 16;
int lcdHeight = 2;

int fwdPin = 1;
int revPin = 2;
int potPin = 3;
int talonPin = 4;

int offValue = 1500;

int rawVal = 0;
int mappedVal = 0;
int sendVal = 0;
int percent = 0;

int dir = 0;
char offStr[] = "Off    ";
char fwdStr[] = "Forward";
char revStr[] = "Reverse";

void setup() {
  lcd.begin(lcdWidth, lcdHeight);
  Serial.begin(9600);
  lcd.setCursor(0, 0);

  talonSR.attach(talonPin);

  pinMode(fwdPin, INPUT_PULLUP);
  pinMode(revPin, INPUT_PULLUP);

  for(int i = 0; i < lcdWidth; i++){
    lcd.setCursor(i, 0);
    lcd.print((char)255);
    lcd.setCursor(i, 1);
    lcd.print((char)255);
    delay(75);
  }

  for(int i = 0; i < lcdWidth; i++){  
    lcd.setCursor(i, 0);
    lcd.print(setupStr[i]);
    lcd.setCursor(i, 1);
    lcd.print(setupStr2[i]);
    delay(75);
  }
  delay(500);
  lcd.clear();

}

void loop() {

/*if(Serial.available() > 0){
  rawVal = Serial.read();
}*/
  
  rawVal = analogRead(potPin);
  mappedVal = map(rawVal, 0, 1023, 0, 500);
  percent = map(rawVal, 0, 1023, 0, 100);

  if(fwdPin == false){
    sendVal = 1500+mappedVal;
    dir = 1;
  } else if(revPin == false){
    sendVal = 1500-mappedVal;
    dir = 2;
  } else {
    sendVal = offValue;
    dir = 0;
  }

talonSR.writeMicroseconds(sendVal);

//lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Power: ");
lcd.print(percent);
lcd.print("%");
for(int i = 0; i < 7; i++){
  lcd.setCursor(i, 1);
  if(dir == 0){
    lcd.print(offStr[i]);
  } else if(dir == 1){
    lcd.print(fwdStr[i]);
  } else {
    lcd.print(revStr[i]);
  }
}
  
}

