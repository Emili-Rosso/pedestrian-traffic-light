//DEFINIÇÃO DE VARIÁVEIS
//Pinos dos LEDs do semáforo para carros:
int vermelhoCar = 8;
int amareloCar = 9;
int verdeCar = 10;

//Pino do botão de solicitação para travessia na faixa de pedestre:
int botao = 11;

//Pinos dos LEDs do semáforo para pedestres:
int vermelhoPed = 12;
int verdePed = 13;

//Pinos do display:
int a = 5;
int b = 4;
int c = A3;
int d = A2;
int e = A1;
int f = 7;
int g = 6;

unsigned long tempoAnterior = 0;

int estado = 0;
bool pedidoPedestre = false;
bool displayIniciado = false;
int numeroAtual = 9;


void setup() {
  //Configuração de entradas e saídas:
  pinMode(vermelhoCar, OUTPUT);
  pinMode(amareloCar, OUTPUT);
  pinMode(verdeCar, OUTPUT);

  pinMode(vermelhoPed, OUTPUT);
  pinMode(verdePed, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(botao, INPUT_PULLUP);
}


void apagaDisplay() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop() {

  unsigned long agora = millis();

  //Se o botão for pressionado, a solicitação para a travessia na faixa de pedestre é verdadeira
  if (digitalRead(botao) == LOW) {
    pedidoPedestre = true;
  }

  switch (estado) {
      //Semáforo para carros está verde, semáforo para pedestre está vermelho
    case 0:
      digitalWrite(verdeCar, HIGH);
      digitalWrite(amareloCar, LOW);
      digitalWrite(vermelhoCar, LOW);

      digitalWrite(vermelhoPed, HIGH);
      digitalWrite(verdePed, LOW);

      apagaDisplay();

      if (pedidoPedestre) {
        estado = 1;
        tempoAnterior = agora;
      }
      break;

    //Semáforo para carros está amarelo por 3 segundos, semáforo para pedestres está vermelho
    case 1:
      digitalWrite(verdeCar, LOW);
      digitalWrite(amareloCar, HIGH);
      digitalWrite(vermelhoCar, LOW);

      if (agora - tempoAnterior >= 3000) {
        estado = 2;
        tempoAnterior = agora;
        numeroAtual = 10;
      }
      break;

    case 2:
      digitalWrite(vermelhoCar, HIGH);
      digitalWrite(amareloCar, LOW);
      digitalWrite(verdeCar, LOW);

      digitalWrite(vermelhoPed, LOW);
      digitalWrite(verdePed, HIGH);

      if (!displayIniciado) {
        apagaDisplay();
        acende9();
        numeroAtual = 8;
        tempoAnterior = agora;
        displayIniciado = true;
      }

      if (agora - tempoAnterior >= 1000 && displayIniciado) {
        tempoAnterior = agora;
        apagaDisplay();

        switch (numeroAtual) {
          case 8: acende8(); 
            break;
          case 7: acende7(); 
            break;
          case 6: acende6();
            break;
          case 5: acende5(); 
            break;
          case 4: acende4(); 
            break;
          case 3: acende3();
            break;
          case 2: acende2();
            break;
          case 1: acende1(); 
            break;
          case 0: acende0(); 
            break;
        }

        numeroAtual--;

        if (numeroAtual < 0) {
          estado = 3;
          displayIniciado = false;
          tempoAnterior = agora;
        }
      }
      break;

    case 3:
      pedidoPedestre = false;
      displayIniciado = false;
      estado = 0;
      break;
  }
}

void acende9() { //Display mostra o número 9
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void acende8() { //Display mostra o número 8
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void acende7() { //Display mostra o número 7
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void acende6() { //Display mostra o número 6
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void acende5() { //Display mostra o número 5
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void acende4() { //Display mostra o número 4
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void acende3() { //Display mostra o número 3
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void acende2() { //Display mostra o número 2
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void acende1() { //Display mostra o número 1
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void acende0() { //Display mostra o número 0
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
