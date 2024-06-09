#include <Servo.h>

#define botao 2
#define led 3
#define servo 4
Servo myservo;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  myservo.attach(servo);
}
bool estadoBotao;
bool estadoAnteriorBotao;
bool cancela = false;
int pos;
void loop() {
  estadoBotao=digitalRead(botao);
  if(estadoBotao != estadoAnteriorBotao && estadoBotao == 1){
  	digitalWrite(led, !digitalRead(led));
    switchServo();
    delay(30);
  }
  
  estadoAnteriorBotao=estadoBotao;
}

void switchServo(){

if (digitalRead(led)) {
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
  }else{
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}