#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {

  sensorBaixo = robo.lerSensorSonarDir();
  sensorLateral = robo.lerSensorSonarEsq();
  sensorFrontal = robo.lerSensorSonarFrontal();

  if (sensorLateral < 10 && sensores.entSala3()) {
    sala3();
  } 
  else if (sensorLateral < 10) {
    oSala3.rampa();
  }

  else if (sensorFrontal < 5) {
    desviarObstaculo();
  }
  else {
    seguirLinha();
  }

}
void Estrategia::redutor() {
  movimento.superfrent();
  delay(50);

  seguirLinha();
}

void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.fren();

  }
  else if (sensores.brancoPretoBrancoBranco()) {
    movimento.dir();

  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.esq();

  }
  else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exesq();
    delay(300);
  }
  else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exdir();
    delay(300);
  }
  else if (sensores.pretoPretoPretoPreto()) {
    movimento.frenlen();
  }
  else if (sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.exdir();
    delay(250);
  }
  else if (sensores.pretoPretoPretoBranco())  {
    movimento.esq();
    delay(250);
  }
  else if (sensores.brancoPretoBrancoBranco())  {
    movimento.dir();
    delay(250);
  }
  else if (sensores.pretoPretoBrancoBranco())  {
    movimento.dir();
    delay(250);
  }
  else if (sensores.brancoBrancoPretoPreto())  {
    movimento.esq();
    delay(250);
  }
}
void Estrategia::verde() {}

void Estrategia::led() {

  static long redLedInterval = 300;
  static bool redLedState = false;
  static   long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > redLedInterval) {
    previousMillis = currentMillis;

    if (redLedState == LOW) {
      robo.ligarTodosLeds();
      redLedState = HIGH;

    }
    else {

      robo.desligarTodosLeds();
      redLedState = LOW;

    }
  }
}

void Estrategia::sala3() {

  oSala3.alinhar();
}

void Estrategia::desviarObstaculo() {
  parar = false;
  movimento.obReLen();
  delay(500);
  movimento.obEsq();
  delay(480);
  movimento.obFren();
  delay(890);
  movimento.obDir();
  delay(360);
  movimento.obFren();
  delay(1200);
  movimento.obDir();
  delay(260);
  movimento.obFrenLen();

  while (!parar) {


    sensorLateral = robo.lerSensorSonarEsq();
    if (sensorLateral < 20 && sensores.pretoPretoPretoPreto()) {
      voltarParaALinha();

    }
    else if (sensorLateral < 20 && sensores.pretoPretoBrancoBranco()) {
      voltarParaALinha();

    }
    else if (sensorLateral < 20 && sensores.brancoBrancoPretoPreto()) {
      voltarParaALinha();

    }
    else if (sensorLateral < 20 && sensores.pretoBrancoBrancoBranco()) {
      voltarParaALinha();

    }
    else if (sensorLateral < 20 && sensores.brancoBrancoBrancoPreto()) {
      voltarParaALinha();

    }
    else if (sensorLateral < 20 && sensores.brancoPretoPretoPreto()) {
      voltarParaALinha();

    }
    else if (sensorLateral < 20 && sensores.pretoPretoPretoBranco()) {
      voltarParaALinha();

    }

  }

}

void Estrategia:: voltarParaALinha() {
  robo.ligarLed(1);
  movimento.obRe();
  delay(300);
  robo.acionarMotores(70, 15);
  delay(660);
  robo.acionarMotores(-15, -50);
  delay(550);
  parar = true;
}

