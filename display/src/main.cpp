#include <Arduino.h>

//3,2,5,12,7,9,10,13
int PINMODES[8] = {3, 2, 5, 12, 7, 9, 10, 13};

int numeros[10][8] = {
    {1, 1, 0, 1, 1, 1, 1, 1}, //0
    {0, 0, 0, 1, 0, 0, 1, 1}, //1
    {1, 1, 1, 0, 0, 1, 1, 1}, //2
    {1, 0, 1, 1, 0, 1, 1, 1}, //3
    {0, 0, 1, 1, 1, 0, 1, 1}, //4
    {1, 0, 1, 1, 1, 1, 0, 1}, //5
    {1, 1, 1, 1, 1, 1, 0, 1}, //6
    {0, 0, 0, 1, 0, 1, 1, 1}, //7
    {1, 1, 1, 1, 1, 1, 1, 1}, //8
    {1, 0, 1, 1, 1, 1, 1, 1}, //9
};

void ascentePIN(int pin)
{
  digitalWrite(pin, HIGH);
}
void apagarPIN(int pin)
{
  digitalWrite(pin, LOW);
}

void number(int num)
{

  for (int i = 0; i < 8; i++)
  {
    if (numeros[num][i] == 1)
    {
      ascentePIN(PINMODES[i]);
    }
    else
    {
      apagarPIN(PINMODES[i]);
    }
  }
}

void setup()
{
  //3,2,5,12,7,9,10,13

  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  number(9);
  delay(1000);
  number(8);
  delay(1000);
  number(7);
  delay(1000);
  number(6);
  delay(1000);
  number(5);
  delay(1000);
  number(4);
  delay(1000);
  number(3);
  delay(1000);
  number(2);
  delay(1000);
  number(1);
  delay(1000);
  number(0);
  delay(1000);
}
