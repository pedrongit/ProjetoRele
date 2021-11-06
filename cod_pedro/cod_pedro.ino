
#include  <LiquidCrystal.h>

//-------------------------------------------------------------------------- 
  #define R1 1
  #define amostras 12 
  #define Vref 5
  #define Divisor 2.61
//---------------------------------------------------------------------------

float medicao(const uint8_t);
void printlcd(int, int , float, int);

void setup() {    //(◑_◑)
  Serial.begin(9600);
  pinMode(R1, OUTPUT); 
  digitalWrite(R1,HIGH);  
}


float medicao(const uint8_t pino){
  float Val, total;
  total = 0;
  Val = analogRead(pino);
  for (int i = 0; i < amostras; i++){
    total = total + Val*Vref*Divisor/1023 ;
  }
  return total/amostras;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void loop(){

}

float medicao(const uint8_t pino){
  float Val, total;
  total = 0;
  Val = analogRead(pino);
  for (int i = 0; i < amostras; i++){
    total = total + Val*Vref*Divisor/1023 ;
  }
  return total/amostras;
}

void printlcd(int coluna, int linha, float medicao, int bateria){
  lc
}