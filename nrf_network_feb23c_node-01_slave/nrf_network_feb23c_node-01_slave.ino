/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
        == Node 01 (Child of Master node 00) == 
  by Venkata Gunasekhar V,ECE-d,RMKEC   
*/
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define button1 2
#define led1 6
#define led2 7
#define led3 8
#define buzzer 4

RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t master = 00;      // Address of the master node in Octal format
const uint16_t node02 = 02;
int r;
int ip[]={0,0,0};
int op[]={0,0,0};
void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  r=0;
}
void loop() {
network.update();
  //===== Receiving =====//
  if ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header(this_node);
    
    network.read(header, &ip, sizeof(ip)); // Read the incoming data=ip
    if(ip[0]==1) {
      r=1;            
      }
    if(ip[1]==1) {
      digitalWrite(led2,HIGH);            
      }
    if(ip[1]==0) {
      digitalWrite(led2,LOW);            
      }
    if(ip[2]==1) {
      digitalWrite(led3,HIGH);            
      }
    if(ip[2]==0) {
      digitalWrite(led3,LOW);            
      }  
   
  }
  Serial.println("input");
  Serial.println(ip[3]);   
    
    
     
    
  //=====reading buttonstate Sending =====//
  
  
  int bs1 = digitalRead(button1);
  
  if(bs1==1){
    op[0]=1;
    r=1;
    }
  
 
  
  
  //===== Sending =====//
  //  control at master
  
Serial.println("output");
Serial.println(op[3]);
  
RF24NetworkHeader header2(master);
bool ok=network.write(header2, &op, sizeof(op)); // Send the data
  //  Control at Node 02
  
RF24NetworkHeader header3(node02);
bool ok2=network.write(header3, &op, sizeof(op)); // Send the data



 while(r){
      digitalWrite(buzzer,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      delay(500);
      digitalWrite(buzzer,LOW);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(250);

  //  Control at master 
  RF24NetworkHeader header2(master);     // (Address where the data is going)
  bool ok = network.write(header2, &op, sizeof(op)); // Send the data
  //  Control at Node 02
  
  RF24NetworkHeader header3(node02);    // (Address where the data is going)
  bool ok3 = network.write(header3, &op, sizeof(op)); // Send the data
  
  network.update();    } 
}
