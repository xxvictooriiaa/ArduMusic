
/*
 * =========================================================================
 * PROJETO: Tocador de Música MP3 (Buzzer & Display)
 * OBJETIVO: Criar uma interface sonora e visual capaz de reproduzir
 *           melodias simplificadas através de um Buzzer, exibindo o 
 *           nome da música ou status no Display.
 * 
 * AUTORES: Lauanda Nobre E Victória Caroline
 * DATA DE CRIAÇÃO: 19/04/2026
 * ÚLTIMA MODIFICAÇÃO: 26/04/2026 as 10:55
 * VERSÃO: 0.1.0
 * =========================================================================
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define BUZZER 6
#define LED_VERDE A2
#define LED_VERMELHA A1
#define BOTAO_UP 9
#define BOTAO_DOWN 7
#define BOTAO_PLAY_PAUSE 8
#define BOTAO_STOP 13

// Lista de Músicas -------------------------------------------------------------
String musicas[] = {"Zelda", "PacMan", "Mario", "AsaBranca", "Nokia"};
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
  lcd.setCursor( 0);
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
/*
  /// Pausa e Play -------------
if (digitalRead(BOTAO_PLAY_PAUSE) == LOW) {
    if (!tocando) {
      tocando = true;
      pausado = false;
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_VERMELHA, LOW);
    } 
    else {
      pausado = !pausado;

      // Futuramente vai Alterna os led entre Verde (Tocando) e Vermelho (Pausado)
      digitalWrite(LED_VERDE, !pausado);
      digitalWrite(LED_VERMELHA, pausado);
    }
    delay(300);
  }

  // STOP --------------------
 if (digitalRead(BOTAO_STOP) == LOW) {
    noTone(BUZZER);
    tocando = false;
    pausado = false;
    musicaIniciada = false; // Vai dar reset pra poder tocar de novo
    
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHA, HIGH);
    
    mostrarMenu();
    delay(300);

  }
  */
}

// ------------------ Função DO MENU ---------------------------
void mostrarMenu() {
  lcd.clear();
  
  // LINHA 0: Mostra a posição e o nome da música
  lcd.setCursor(0, 0);
  lcd.print(musicaselecionada + 1); 
  lcd.print("/5 ");
  lcd.print(musicas[musicaselecionada]);

  // LINHA 1: Instrução para o usuário
  lcd.setCursor(0, 1);
  lcd.print("Selecione..."); 
}