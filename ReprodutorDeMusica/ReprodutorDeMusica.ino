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
#define BUZZER 9

void setup()
{
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  // SOM
  tone(BUZZER, 800, 1000);
  delay(2000); 
}