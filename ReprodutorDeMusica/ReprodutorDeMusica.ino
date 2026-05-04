
/*
 * =========================================================================
 * PROJETO: Tocador de Música MP3 (Buzzer & Display)
 * OBJETIVO: Criar uma interface sonora e visual capaz de reproduzir
 *           melodias simplificadas através de um Buzzer, exibindo o 
 *           nome da música ou status no Display.
 * 
 * AUTORES: Lauanda Nobre E Victória Caroline
 * DATA DE CRIAÇÃO: 19/04/2026
 * ÚLTIMA MODIFICAÇÃO: 03/04/2026 as 16:37
 * VERSÃO: 0.1.0
 * =========================================================================
 */
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define BUZZER 6
#define LED_VERDE A0
#define LED_VERMELHA A1
#define BOTAO_UP 9
#define BOTAO_DOWN 7
#define BOTAO_PLAY_PAUSE 8
#define BOTAO_STOP 10


// --- notas musicais ---
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

//------------------------------------


// --- musicas---

// 1 - Zelda
const int tempoZelda PROGMEM = 88; 
const int melodiaZelda[] PROGMEM = {
  NOTE_AS4,-2, NOTE_F4,8, NOTE_F4,8, NOTE_AS4,8, NOTE_GS4,16, NOTE_FS4,16, NOTE_GS4,-2,
  NOTE_AS4,-2, NOTE_FS4,8, NOTE_FS4,8, NOTE_AS4,8, NOTE_A4,16, NOTE_G4,16, NOTE_A4,-2, REST,1, 
  NOTE_AS4,4, NOTE_F4,-4, NOTE_AS4,8, NOTE_AS4,16, NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,
  NOTE_F5,2, NOTE_F5,8, NOTE_F5,8, NOTE_F5,8, NOTE_FS5,16, NOTE_GS5,16, NOTE_AS5,-2, NOTE_AS5,8, NOTE_AS5,8, NOTE_GS5,8, NOTE_FS5,16,
  NOTE_GS5,-8, NOTE_FS5,16, NOTE_F5,2, NOTE_F5,4, NOTE_DS5,-8, NOTE_F5,16, NOTE_FS5,2, NOTE_F5,8, NOTE_DS5,8,
  NOTE_CS5,-8, NOTE_DS5,16, NOTE_F5,2, NOTE_DS5,8, NOTE_CS5,8, NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8, 
  NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8
};

// 2 - Pac man
const int tempopacman PROGMEM = 105; 
const int melodiaPacMan[] PROGMEM = {
  NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
  NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8, NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, NOTE_B5, 32,
  NOTE_FS5, -16, NOTE_DS5, 8, NOTE_DS5, 32, NOTE_E5, 32, NOTE_F5, 32, NOTE_F5, 32, NOTE_FS5, 32, NOTE_G5, 32, NOTE_G5, 32, NOTE_GS5, 32, NOTE_A5, 16, NOTE_B5, 8
};

// 3- Mario
const int tempomario PROGMEM = 100; 
const int melodiaMario[] PROGMEM = {
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8, REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4
};

//4- Asa Branca

const int tempoasabranca PROGMEM = 120; 
const int melodiaasabranca[] PROGMEM = {
  NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4, NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4, NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8, NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8
};

//5- Nokia

const int temponokia PROGMEM = 180; 
const int melodiaNokia[] PROGMEM = {
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4, NOTE_A4, 2
};

// Nomes das músicas em PROGMEM
const char nome_Zelda[] PROGMEM = "Zelda";
const char nome_PacMan[] PROGMEM = "PacMan";
const char nome_Mario[] PROGMEM = "Mario";
const char nome_AsaBranca[] PROGMEM = "AsaBranca";
const char nome_Nokia[] PROGMEM = "Nokia";

const char* const musicas[] PROGMEM = {nome_Zelda, nome_PacMan, nome_Mario, nome_AsaBranca, nome_Nokia};
int musicaselecionada = 0;

bool tocando = false;
bool pausado = false;
bool musicaIniciada = false;

//--------------------------------------------------------------------------------------

void setup(){
 
  Serial.begin(9600);
  
  lcd.begin(16,2);// Definir o Tamanho em linhas e colunas do lcd display
  lcd.clear(); // Limpar a tela do lcd
  
  // Definindo pinos
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHA, OUTPUT);
  pinMode(BOTAO_UP, INPUT_PULLUP);
  pinMode(BOTAO_DOWN, INPUT);
  pinMode(BOTAO_PLAY_PAUSE, INPUT);
  pinMode(BOTAO_STOP, INPUT);
  
  // bip de inicio - Por Lauanda
  tone(BUZZER, 220, 200);
  delay(250);
  tone(BUZZER, 640, 200);
  delay(250);
  tone(BUZZER, 880, 400);
  delay(450);
  
  // menu inicial
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Reprodutor MP3");
  delay(2000);

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Feito por:");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Lauanda e");
  lcd.setCursor(3, 1);
  lcd.print("Victoria");
  delay(3000); // Espera 3 segundos para lerem os nomes

  lcd.clear(); // Limpa para entrar no menu principal
  mostrarMenu();
}


void loop(){
  //noTone(BUZZER);
  //digitalWrite(BUZZER,LOW);
  // botão próxima musica PULL UP
  if (digitalRead(BOTAO_UP) == LOW) {
    musicaselecionada = (musicaselecionada + 1) % 5;
    mostrarMenu();
    delay(300);
  }
  // botão música anterior PULL DOWN
  if (digitalRead(BOTAO_DOWN) == HIGH) {
    musicaselecionada = (musicaselecionada - 1 + 5) % 5;
    mostrarMenu();
    delay(300);
  }

    /// Pausa e Play -------------
  if (digitalRead(BOTAO_PLAY_PAUSE) == HIGH) {
    if (musicaIniciada == false) {
      // Se a música ainda não começou, dá o "Start"
      tocando = true;
      pausado = false;
      musicaIniciada = true;
      
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_VERMELHA, LOW);
      
      lcd.setCursor(0, 1);
      lcd.print("Tocando...");
    } 
    else {
      // Se a música já iniciou, apenas alterna entre Pausa e Play
      if (pausado == true) {
        pausado = false;
        tocando = true;
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_VERMELHA, LOW);
        
        lcd.setCursor(0, 1);
        lcd.print("Tocando...");
      } 
      else {
        pausado = true;
        tocando = false;
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_VERMELHA, HIGH);
        
        lcd.setCursor(0, 1);
        lcd.print("Pausado");
      }
    }
    delay(300); // Debounce para evitar cliques duplos
  }



  // STOP --------------------
  if (digitalRead(BOTAO_STOP) == HIGH) {
    noTone(BUZZER);           // Para o som imediatamente
    tocando = false;
    pausado = false;
    musicaIniciada = false;   // Permite que a música recomece do zero no próximo Play

    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHA, HIGH);
    
    // Volta visualmente para o menu
    mostrarMenu();
    delay(300);
  }


// tocar musica
  if (tocando && !pausado && musicaIniciada) {
    executarMelodia(musicaselecionada);
  }
}

// ------------------ Função DO MENU ---------------------------
void mostrarMenu() {
  lcd.clear();
  
  // LINHA 0: Mostra a posição e o nome da música
  lcd.setCursor(0, 0);
  lcd.print(musicaselecionada + 1); 
  lcd.print("/5 ");
  
  // Ler string de PROGMEM
  char nomeMusica[15];
  strcpy_P(nomeMusica, (const char*)pgm_read_word(&musicas[musicaselecionada]));
  lcd.print(nomeMusica);

  // LINHA 1: Instrução para o usuário
  lcd.setCursor(0, 1);
  lcd.print("Selecione..."); 
}

void atualizarLEDs() {
  if (tocando) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHA, LOW);
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHA, HIGH);
  }
}


void pararMusica() {
  noTone(BUZZER);
  tocando = false;
  pausado = false;
  musicaIniciada = false;
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHA, HIGH);
  mostrarMenu();
}

void executarMelodia(int musica) {
  const int *melodia;
  int notas;
  int tempo;

  if (musica == 0) { melodia = melodiaZelda; notas = sizeof(melodiaZelda)/sizeof(int)/2; tempo = pgm_read_word(&tempoZelda); }
  else if (musica == 1) { melodia = melodiaPacMan; notas = sizeof(melodiaPacMan)/sizeof(int)/2; tempo = pgm_read_word(&tempopacman); }
  else if (musica == 2) { melodia = melodiaMario; notas = sizeof(melodiaMario)/sizeof(int)/2; tempo = pgm_read_word(&tempomario); }
  else if (musica == 3) { melodia = melodiaasabranca; notas = sizeof(melodiaasabranca)/sizeof(int)/2; tempo = pgm_read_word(&tempoasabranca); }
  else { melodia = melodiaNokia; notas = sizeof(melodiaNokia)/sizeof(int)/2; tempo = pgm_read_word(&temponokia); }

  int wholenote = (60000 * 4) / tempo;

  for (int thisNote = 0; thisNote < notas * 2; thisNote = thisNote + 2) {
    // Verifica se houve comando de Stop ou Pause durante a música
    if (digitalRead(BOTAO_STOP) == HIGH) { pararMusica(); return; }
    if (digitalRead(BOTAO_PLAY_PAUSE) == HIGH) { 
      pausado = true; tocando = false; atualizarLEDs(); 
      lcd.setCursor(0,1); lcd.print("Pausado   ");
      delay(300); return; 
    }

    int divider = pgm_read_word(&melodia[thisNote + 1]);
    int noteDuration = (divider > 0) ? (wholenote / divider) : (wholenote / abs(divider) * 1.5);

    tone(BUZZER, pgm_read_word(&melodia[thisNote]), noteDuration * 0.9);
    delay(noteDuration);
    noTone(BUZZER);
  }
  
  pararMusica(); 
}