#include <robo_hardware2.h>
#include <Servo.h>

float v1, v2, v3, v4; //Armazena valores para 12 testes BRANCO E PRETO(faremos vários testes, pois assim o resultado é mais preciso)
float s1, s2, s3, s4; //Armazena as somas dos 12 testes REFLETE-BRANCO ou REFLETE-PRETO
float sRME, sRE, sRD, sRMD; //VALOR CALIBRADO DE CADA SENSOR(MÉDIA FINAL)
boolean endC, endStop;
float contador = 1;

void setup() {
  Serial.begin(9600);
  robo.configurar(false);

  while (!robo.botao1Pressionado() );
  Serial.println("CALIBRADOR INICIADO!");
  robo.ligarLed(1);


  while (!endC) {

    while (!robo.botao1Pressionado() );
    Serial.println("BRANCO COMEÇOU!");

    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();

    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;



    Serial.println("BRANCO PRONTO!");
    robo.ligarLed(2);


    while ( !robo.botao1Pressionado() );
    Serial.println("PRETO COMEÇOU!");

    v1 = robo.lerSensorLinhaMaisEsq();
    v2 = robo.lerSensorLinhaEsq();
    v3 = robo.lerSensorLinhaDir();
    v4 = robo.lerSensorLinhaMaisDir();


    s1 = v1 + s1;
    s2 = v2 + s2;
    s3 = v3 + s3;
    s4 = v4 + s4;

    Serial.println("PRETO COMEÇOU!");
    robo.ligarLed(3);


    Serial.println("ESCOLHA PARAR (BOTÃO 2) OU CONTINUAR (BOTÃO 1)!");

    while (!endStop) { //Stop


      if (robo.botao2Pressionado()) {
        endC = true;
        endStop = true;
        robo.desligarLed(1);
        Serial.println("CALIBRADOR DESLIGADO!");
      }
      else if (robo.botao1Pressionado()) {
        endC = false;
        endStop = true;
        robo.desligarLed(2);
        robo.desligarLed(3);
        Serial.println("MAIS UMA CALIBRAÇÃO!");
      }

    }

    contador++;

  }
  

    sRME = s1 / (contador*2);
    sRE = s2 / (contador*2);
    sRD = s3 / (contador*2);
    sRMD = s4/ (contador*2);

    Serial.println("Mais Esquerdo: ");
    Serial.println(sRME);
    Serial.println("Esquerdo: ");
    Serial.println(sRE);
    Serial.println("Direito: ");
    Serial.println(sRD);
    Serial.println("Mais Direito: ");
    Serial.println(sRMD);
}



void loop() {

}