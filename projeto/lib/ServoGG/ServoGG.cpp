#include "Arduino.h"
#include "ServoGG.h"

ServoGG::ServoGG(int pin){
  pinMode(pin, OUTPUT);
  _pin = pin;
}


void ServoGG::setAngulo(int angulo) {
  int val = map(angulo, 0, 180, 544, 2400); // Ajuste de valor para controle do servo
  digitalWrite(_pin, HIGH);
  delayMicroseconds(val);
  digitalWrite(_pin, LOW);
  delay(20); // Tempo necessário para o servo completar o movimento
}