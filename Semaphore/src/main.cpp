#include <Arduino.h>

#define green 2
#define yellow 7
#define red 11

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  digitalWrite(green, HIGH);
  delay(2000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1500);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
}