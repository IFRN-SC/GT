#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() {
  
  float sensorFrontal;
  float sensorLateral;
  
  sensorLateral = robo.lerSensorSonarDir();
  sensorFrontal = robo.lerSensorSonarFrontal();
  if(sensorFrontal < 10){
    desviarObstaculo();  
  }
  
  else if(sensorLateral < 10){ 
    sala3(); 
  }
 
  else{
    seguirLinha();  
  }
  
}
void Estrategia::seguirLinha() {

  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.fren();
    
  } else if (sensores.brancoPretoBrancoBranco()) {
    movimento.dir();
    
  } else if (sensores.brancoBrancoPretoBranco()) {
    movimento.esq();
    
  } else if (sensores.brancoBrancoBrancoPreto()) {
    movimento.exesq();
    delay(300);
  } else if (sensores.pretoBrancoBrancoBranco()) {
    movimento.exdir();
    delay(300);
  } else if (sensores.pretoPretoPretoPreto()) {
    movimento.frenlen();
  } else if(sensores.brancoPretoPretoBranco()) {
    movimento.frenlen();
  } else if(sensores.brancoBrancoPretoBranco()) {
    movimento.exdir();
    delay(250);
  } else if(sensores.pretoPretoPretoBranco())  {
    movimento.esq();
    delay(250);
  } else if(sensores.brancoPretoBrancoBranco())  {
    movimento.dir();
    delay(250);
  } else if(sensores.pretoPretoBrancoBranco())  {
    movimento.dir();
    delay(250);
  } else if(sensores.brancoBrancoPretoPreto())  {
    movimento.esq();
    delay(250);
  } 
  
}
void Estrategia::verde() {}
void Estrategia::sala3() {
  
  if (sensores.brancoBrancoBrancoBranco()) {
    movimento.superfrent();
  }
  else if(sensores.brancoPretoBrancoBranco()) {
   movimento.dirr();
  }
  else if (sensores.brancoBrancoPretoBranco()) {
    movimento.esqq(); 
  }
  else if (sensores.pretoPretoPretoPreto()) {
    movimento.dirr();
  }
  else if (sensores.pretoPretoBrancoBranco()) {
    movimento.esqq(); 
  }
  else if (sensores.brancoBrancoPretoPreto()) {
    movimento.dirr();
  }
  
}
void Estrategia::desviarObstaculo() {
     
     movimento.parar();
     delay(500);
     movimento.dir();
     delay(400);
     movimento.parar();
     delay(500);
     movimento.fren();
     delay(600);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(400);
     movimento.parar();
     delay(500);
     movimento.fren();
     delay(1000);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(400);
     movimento.parar();
     delay(500);
     movimento.esq();
     delay(150);

     while(sensores.brancoBrancoBrancoBranco()){
     movimento.frenlen();
     
     }
     
     
     
  }
