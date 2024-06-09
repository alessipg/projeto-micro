#define botao 2
#define led 3
#define servo 4
#define degree 90

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(servo, OUTPUT);
}

bool estadoBotao;
bool estadoAnteriorBotao = LOW;
bool cancela = false;
byte pos;

void loop() {
  estadoBotao = digitalRead(botao);

  // Verifica se o botão foi pressionado (borda de subida)
  if (estadoBotao != estadoAnteriorBotao && estadoBotao == HIGH) {
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
      setAngulo(pos, servo);
      delay(15); // Ajuste este valor para controlar a velocidade do movimento
    }
  } else {
    // Move de 90 a 0 graus
    for (pos = degree; pos > 0; pos--) {
      setAngulo(pos, servo);
      delay(15); // Ajuste este valor para controlar a velocidade do movimento
    }
  }
}

void setAngulo(int angulo, int pin) {
  int val = map(angulo, 0, 180, 544, 2400); // Ajuste de valor para controle do servo
  digitalWrite(pin, HIGH);
  delayMicroseconds(val);
  digitalWrite(pin, LOW);
  delay(20); // Tempo necessário para o servo completar o movimento
}
