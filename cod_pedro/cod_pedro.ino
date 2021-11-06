
#include  <LiquidCrystal.h>

//-------------------------------------------------------------------------- 
  #define R1 1
  #define amostras 1000
  #define Vref 5
  #define Divisor 10.14
//---------------------------------------------------------------------------
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//

float medicao(const uint8_t);
void printlcd(int, int , float, int);

void setup() {    //(◑_◑)
  Serial.begin(9600);
  pinMode(R1, OUTPUT); 
  digitalWrite(R1,HIGH);  
  lcd.begin(16, 2);
}


float ao;

//---------------------------------------------------------------------------

String stringA0 = "B1:";

//---------------------------------------------------------------------------
void loop(){
   //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  ao=medicao(A0);
  
  ao=((ao-10.5)/2.6)*100;
  String stringThree = stringA0 + ao+"%";
  
  Serial.println(analogRead(A0));
  //Envia o texto entre aspas para o LCD
  lcd.print(stringThree);
  lcd.setCursor(0, 1);
  lcd.print("oi2");
  delay(1000);

}

float medicao(const uint8_t pino){
  float Val, total;
  total = 0;
  Val = analogRead(pino);
  Serial.println(Val);
  for (int i = 0; i < amostras; i++){
    total = total + Val*Vref*Divisor/1023 ;
  }
  Serial.println(total/amostras);
  return total/amostras;
}

void printlcd(int coluna, int linha, float medicao, int bateria){
  
}