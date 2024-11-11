#include <LiquidCrystal.h> 


const int pinoVenda = 7;       
const int pinoReposicao = 6;  
const int pinoBuzzer = 8;      


int estoque = 20;               
const int limiteEstoqueBaixo = 5; 


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 
  lcd.begin(16, 2); 
  lcd.print("Controle de Estoque");

  
  pinMode(pinoVenda, INPUT_PULLUP); 
  pinMode(pinoReposicao, INPUT_PULLUP); 
  pinMode(pinoBuzzer, OUTPUT);       

  delay(2000); 
  lcd.clear(); 
}

void loop() {
  bool venda = digitalRead(pinoVenda) == LOW;  
  bool reposicao = digitalRead(pinoReposicao) == LOW;  

  if (venda && estoque > 0) {
    estoque--; 
    tone(pinoBuzzer, 1000, 200);
    delay(500); 
  }

  if (reposicao) {
    estoque++; 
    tone(pinoBuzzer, 500, 200);
    delay(500);
  }

 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estoque: ");
  lcd.print(estoque);

  if (estoque <= limiteEstoqueBaixo) {
    lcd.setCursor(0, 1);
    lcd.print("Estoque Baixo!");
    tone(pinoBuzzer, 2000, 1000); 
  } else {
    noTone(pinoBuzzer);
  }

  delay(200); 
}
