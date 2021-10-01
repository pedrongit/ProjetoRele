
#include <ros.h>
#include <std_msgs/Int8.h>  


//-------------------------------------------------------------------------- 
  #define rele1 1
  #define amostras 12 
  #define Vref 5
  #define Divisor 2.61
//---------------------------------------------------------------------------
void setup() {    //(◑_◑)
  Serial.begin(9600);
  pinMode(rele1, OUTPUT); 
  digitalWrite(rele1,HIGH);  
  std_msgs::Int8 msg;
  
}

float medicaoA0(){
  float Val= analogRead (A0), total =0;
  for (int i = 0; i < amostras; i++){
    total = total + Val*Vref*Divisor/1024 ;
  }
  float medicao = total/amostras;
  Serial.print("      A0:");
  Serial.print(medicao);
  return medicao;
}
float medicaoA1(){
  float Val= analogRead (A1),  total =0;
  for (int i = 0; i < amostras; i++){
    total = total + Val*Vref*Divisor/1023 ;
  }
  float medicao = total/amostras;
  Serial.print("      A1:");
  Serial.print(medicao);
  return medicao;
}
float medicaoA2(){
  float Val= analogRead (A2), total =0;
  for (int i = 0; i < amostras; i++){
    total = total + Val*Vref*Divisor/1023 ;
  }
  float medicao = total/amostras;
  Serial.print("      A2:");
  Serial.println(medicao);
  return medicao;
}

void ifrele1(){
  float VA0 = medicaoA0();
  if (VA0<12.8){
    digitalWrite(rele1,LOW);
  }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 int main() {
   
  
 ros::NodeHandle n;

int count = 0;
while (ros::ok())
 {

std_msgs::Int8 msg;
std::stringstream ss;

void loop() {// __________________  t(>.<t)
  medicaoA0();
  medicaoA1();
  medicaoA2();
  
  delay(1000);
}

  ros::init(medicao, "talker");
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int8>("chatter", 1000); //tipo de mensagem e seu tamanho
  ros::Rate loop_rate(10);  //frequencia do loop

  ROS_INFO("%d", medicao);
  chatter_pub.publish(medicao);
  ros::spinOnce();
  loop_rate.sleep();

 }
 return 0;
  }
