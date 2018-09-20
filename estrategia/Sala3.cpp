#include "Sala3.h"
#include "robo_hardware2.h"

void Sala3:: alinhar() {

  movimento.dirS3();
  delay(100);
  while (!robo.botao2Pressionado());
}

void Sala3:: rampa() {

  parar = false;

  while (!parar) {

    if (sensores.brancoBrancoBrancoBranco()) {
      movimento.frenmed();
    }
    else if (sensores.brancoPretoBrancoBranco()) {
      movimento.dirr();
    }
    else if (sensores.brancoBrancoPretoBranco()) {
      movimento.esqq();
    }
    else if (sensores.brancoBrancoBrancoPreto()) {
      movimento.exesq();
    }
    else if (sensores.pretoBrancoBrancoBranco()) {
      movimento.exdir();
    }
    else if (sensores.pretoPretoPretoPreto()) {
      movimento.superfrent();
      delay(900);


      movimento.parar();
      while (true);
      parar = true;
    }
    else if (sensores.pretoPretoBrancoBranco()) {
      robo.acionarMotores(80, 100);
      delay(1000);

      movimento.parar();

      parar = true;
    }
    else if (sensores.brancoBrancoPretoPreto()) {
      robo.acionarMotores(100, 80);
      delay(1000);


      movimento.parar();

      parar = true;
    }
  }
}
