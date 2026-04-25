
/*
 * =========================================================================
 * PROJETO: Tocador de Música MP3 (Buzzer & Display)
 * OBJETIVO: Criar uma interface sonora e visual capaz de reproduzir
 *           melodias simplificadas através de um Buzzer, exibindo o 
 *           nome da música ou status no Display.
 * 
 * AUTORES: Lauanda Nobre E Victória Caroline
 * DATA DE CRIAÇÃO: 19/04/2026
 * ÚLTIMA MODIFICAÇÃO: 25/04/2026 as 15:10
 * VERSÃO: 0.1.0
 * =========================================================================
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define BUZZER 9
#define LED_VERDE A2
#define LED_VERMELHA A1
#define BOTAO_UP 6
#define BOTAO_DOWN 7
#define BOTAO_PLAY_PAUSE 8
#define BOTAO_STOP 13

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);// Definir o Tamanho em linhas e colunas do lcd display
  lcd.clear(); // Limpar a tela do lcd
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHA, OUTPUT);
  pinMode(BOTAO_UP, INPUT_PULLUP);
  pinMode(BOTAO_DOWN, INPUT_PULLUP);
  pinMode(BOTAO_PLAY_PAUSE, INPUT_PULLUP);
  pinMode(BOTAO_STOP, INPUT_PULLUP);

}

void loop()
{
  lcd.setCursor(3,0);
  lcd.print("Hello world");
  // SOM
  tone(BUZZER, 800, 1000);
  delay(2000); 
}