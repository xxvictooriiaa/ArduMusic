
/*
 * =========================================================================
 * PROJETO: Tocador de Música MP3 (Buzzer & Display)
 * OBJETIVO: Criar uma interface sonora e visual capaz de reproduzir
 *           melodias simplificadas através de um Buzzer, exibindo o 
 *           nome da música ou status no Display.
 * 
 * AUTORES: Lauanda Nobre E Victória Caroline
 * DATA DE CRIAÇÃO: 19/04/2026
 * ÚLTIMA MODIFICAÇÃO: 19/04/2026 as 18:03
 * VERSÃO: 0.1.0
 * =========================================================================
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define BUZZER 9
#define LED_VERDE 7
#define LED_VERMELHA 8

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);//tamanho em linhas e colunas do lcd display
  lcd.clear(); // limpar a tela
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  lcd.setCursor(3,0);
  lcd.print("Hello world");
  // SOM
  tone(BUZZER, 800, 1000);
  delay(2000); 
}