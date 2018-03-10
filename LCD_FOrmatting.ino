/*
  Arduino Starter Kit example
  Project 11  - Crystal Ball

  This sketch is written to accompany Project 11 in the
  Arduino Starter Kit

  Parts required:
  220 ohm resistor
  10 kilohm resistor
  10 kilohm potentiometer
  16x2 LCD screen
  tilt switch


  Created 13 September 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

int incomingByte [] = {0, 0, 0, 0, 0, 0, 0};
int terminalByte = 30;
int byteStep = 0;
int junk = 0;

char setupStr[] = "  Motor Tester  ";
char setupStr2[] = "   mrElectric   ";
int strL = sizeof(setupStr);
int strL2 = sizeof(setupStr2);

int lcdWidth = 16;
int lcdHeight = 2;

void setup() {
  lcd.begin(lcdWidth, lcdHeight);
  Serial.begin(9600);
  lcd.setCursor(0, 0);

  for(int i = 0; i < lcdWidth; i++){
    lcd.setCursor(i, 0);
    lcd.print((char)255);
    lcd.setCursor(i, 1);
    lcd.print((char)255);
    delay(200);
  }

  for(int i = 0; i < lcdWidth; i++){  
    lcd.setCursor(i, 0);
    lcd.print(setupStr[i]);
    lcd.setCursor(i, 1);
    lcd.print(setupStr2[i]);
    delay(200);
  }

}

void loop() {
  
}

