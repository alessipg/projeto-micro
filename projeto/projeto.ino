#define botao 2
#define led 3
#define degree 90

#include <ServoGG.h>

ServoGG myservo(4);
bool estadoBotao;
bool estadoAnteriorBotao = LOW;
bool cancela = false;
byte pos;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}


void loop() {
  estadoBotao = digitalRead(botao);

  // Verifica se o botão foi pressionado (borda de subida)
  if (estadoBotao != estadoAnteriorBotao && estadoBotao == HIGH) {
    cancela = !cancela;
    digitalWrite(led, cancela);
    switchServo(cancela);
    delay(5000);
    cancela = !cancela;
    digitalWrite(led, cancela);
    switchServo(cancela);
  }
  
  estadoAnteriorBotao = estadoBotao;
}

void switchServo(bool estado) {
  if (estado) {
    // Move de 0 a 90 graus
    for (pos = 0; pos < degree; pos++) {
      myservo.setAngulo(pos);
    }
  } else {
    // Move de 90 a 0 graus
    for (pos = degree; pos > 0; pos--) {
      myservo.setAngulo(pos);
    }
  }
}
