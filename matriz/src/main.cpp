#include <Arduino.h>
#include <Keypad.h>
#include <string.h>

# define red 5
# define green 3
# define blue 4

char mapatecla[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},

};

String senha= "2010";
String digitada;
byte pinos_linas[4] = {13,12,11,10};
byte pinos_colunas[4] = {9,8,7,6} ;

Keypad teclado = Keypad(makeKeymap(mapatecla),pinos_linas,pinos_colunas,4,4);

bool verificasenha(String sa, String sd ) {
  bool result = false;
  if (sa.compareTo(sd)) {
    result = true;
  }
  return result;
}

void leds( int state){ //0 - aguardando / 1 - digitando/ 2 - negado/ 3-aceito
  if (state==0) {
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
  } else if(state ==1) {
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
  } else if(state ==2) {
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
  }else if(state ==3) {
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
  }


}

void setup() {
  // put your setup code here, to run once:
  for(int i =6; i<14; i++) {
    pinMode(i,INPUT);
  }
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

  Serial.begin(9600);

}
int state = 0;
void loop() {
 

  char letra = teclado.getKey();
  if (letra != NO_KEY) {
    Serial.println(letra);
    if (letra =='#'){
      if(verificasenha(senha,digitada)){
        state = 3;
        leds(state);
        delay(30000);
        state = 0;
        leds(state);
      } else {
        state = 2;
        leds(state);
        delay(30000);
        state = 0;
        leds(state);
      }
      digitada ="";
    }else if(letra =='*') {
      digitada = "";
      digitalWrite(blue,LOW);
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      delay(500);
      digitalWrite(green,HIGH);
      digitalWrite(red,HIGH);
      delay(500);
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      delay(500);
      digitalWrite(green,HIGH);
      digitalWrite(red,HIGH);
      delay(500);

      state =0;
      leds(state);
     
    }else{
      digitada +=letra;
      state = 1;
    }
    leds(state);

  }

}
