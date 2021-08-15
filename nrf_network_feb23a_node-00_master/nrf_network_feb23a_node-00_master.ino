/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
          == Base/ Master Node 00==
  by Venkata Gunasekhar V,ECE-D,RMKEC 
  Libraries:
  nRF24/RF24, https://github.com/nRF24/RF24
  nRF24/RF24Network, https://github.com/nRF24/RF24Network
*/
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define button1 4
#define button2 2
#define button3 3
#define led1 7
#define led2 6
#define led3 5
#define buzzer 8

RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
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
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
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
   
  }
  Serial.println("input");
  Serial.println(ip[3]);   
    
    
     
    
  //=====reading buttonstate Sending =====//
  
  
  int bs1 = digitalRead(button1);
  int bs2 = digitalRead(button2);  
  int bs3 = digitalRead(button3);
  if(bs1==1){
    op[0]=1;
    r=1;
    }
  
 
  if(bs2==1){
    op[1]=1;
    digitalWrite(led2,HIGH);
    }

  
  if(bs2==0){
    op[1]=0;
    digitalWrite(led2,LOW);
    }

  
  if(bs3==1){
    op[2]=1;
    digitalWrite(led3,HIGH);
    }
  
  if(bs3=0){
    op[2]=0;
    digitalWrite(led3,LOW);
    }
    
  
  //===== Sending =====//
  //  control at Node 01
  
Serial.println("output");
Serial.println(op[3]);
  
RF24NetworkHeader header2(node01);
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

  RF24NetworkHeader header2(node01);     // (Address where the data is going)
  bool ok = network.write(header2, &op, sizeof(op)); // Send the data
  //  Control at Node 02
  
  RF24NetworkHeader header3(node02);    // (Address where the data is going)
  bool ok3 = network.write(header3, &op, sizeof(op)); // Send the data
  
  network.update();    }
}
