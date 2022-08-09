#include <Arduino.h>
#include <Servo.h>

Servo servo1; // Cria um objeto servo
int pos = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(11);
}

void loop() {
  servo1.write(0);
  for(pos = 0; pos < 45; pos += 1){ 

  
  servo1.write(pos);
  delay(50); 
  }

  for(pos = 45; pos>=1; pos-=1){ 
  
  servo1.write(pos);
  delay(10);
  }


}