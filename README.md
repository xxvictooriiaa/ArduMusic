# ArduMusic
Um software arduino para tocar musicas em bips de buzzer


## Montagem inicial do projeto – Dia 20/04/2026

No dia **20/04/2026** foi realizada a montagem inicial do circuito do projeto de um reprodutor de música utilizando a plataforma TickerCard. Nesta etapa, foi feita a organização dos principais componentes eletrônicos na protoboard e a conexão inicial entre o microcontrolador e os dispositivos responsáveis pela interface do sistema.

Foram conectados os seguintes elementos principais:

- Display LCD 16x2 para exibição das informações do sistema  
- Potenciômetro para ajuste de contraste do display  
- Buzzer piezoelétrico para reprodução sonora  
- LEDs verde e vermelho para sinalização do estado do sistema  
- Quatro botões para controle de navegação e seleção  
- Resistores para proteção e controle dos sinais elétricos  

O objetivo desta etapa foi validar a comunicação entre os componentes e estruturar a base física do projeto para a implementação do software nas próximas fases.


## Imagem da montagem

  <img src="imagens/arduino01.png" width="500">

## Vista esquemática

  <img src="imagens/vistaesquematizada01.png" width="500">

## Lista de Componentes
<img src="imagens/componentes 01.png" width="500">

##

## Atualização do projeto – Dia 24/04/2026

No dia **24/04/2026** foi realizada a atualização do circuito com a implementação dos resistores de referência pull-up e pull-down para melhorar a estabilidade dos botões do sistema.

Também foi iniciada a configuração das entradas no código para leitura mais confiável dos comandos do usuário, utilizando a configuração:

```cpp
pinMode(BOTAO_UP, INPUT_PULLUP);
pinMode(BOTAO_DOWN, INPUT_PULLUP);
pinMode(BOTAO_PLAY_PAUSE, INPUT_PULLUP);
pinMode(BOTAO_STOP, INPUT_PULLUP);

##

## Atualização do projeto – Dia 26/04/2026
 No dia **26/04/2026**, foi feito o código para a Navegação de Pull Up(Mexer Para Cima) e Pull Down(Mexer para Baixo), uma lógica de menu utilizando aritmética modular (%), permitando que o usuário navegue entre as 5 música de forma infinita retornando ao início ou ao fim da lista automaticamente. Também foi acrescentado o estado de Play,Pause e Stop, onde o mesmo botão alterna entre os estados de "Tocando" e "Pausado" (Toggle). O botão de Stop foi configurado para realizar um reset total das variáveis e interromper o sinal sonoro imediatamente.E por fim, foi colocado a função mostrarMenu() para exibir no LCD a posição real da faixa e o nome da música, mantendo uma instrução fixa de "Selecione..." na segunda linha para melhor usabilidade.

Também foi feitas implementações para o futuro como:
- Integração dos LEDs com as variáveis de estado, onde o LED verde indica reprodução ativa e o LED vermelho sinaliza pausa ou parada do sistema.
-Implementação de uma trava lógica (musicaIniciada) para garantir que a melodia seja disparada apenas uma vez ao apertar play, evitando bugs de reinicialização contínua do som durante o loop.

```cpp
// Config De Seleção de Música ---------------------------------------------------------------------
void loop()
{
  // PULL UP --------
  if (digitalRead(BOTAO_UP) == LOW) {
    musicaselecionada = (musicaselecionada + 1) % 5;
    mostrarMenu();
    delay(300);
  }

  // PULL DOWN---------
  if (digitalRead(BOTAO_DOWN) == LOW) {
    musicaselecionada = (musicaselecionada - 1 + 5) % 5;
    mostrarMenu();
    delay(300);
  }

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


  // EXECUTA A MÚSICA FORA DOS BOTÕES ♪♬♫
if (tocando && !pausado && !musicaIniciada) {
  musicaIniciada = true;
  // tocarMusica(musicaselecionada);
}
  }
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