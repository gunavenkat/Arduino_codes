//This is the project of Arduino Bluetooth Car From RC Rock Crawler

#include <Servo.h>

Servo myservo;  
int pos = 45; //initial servo position
int m1=7;    //to motor controller pin
int m2=8;    //to motor controller pin
int ms1=5;   //speed control  
float i;
int l=126;   //leftmost position in servo
int r=48;    //rightmost position in servo
int m=87;    //centre position in servo
char c;      //input character from bluetooth module
int x=20;   
int y=25; 

void setup() 
{ 
  
  pinMode(m1,OUTPUT);   
  pinMode(m2,OUTPUT);   
  pinMode(ms1,OUTPUT);
  myservo.attach(3);   
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  
  if(Serial.available() > 0){ 
    c = Serial.read(); 
    Serial.write(c);
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(c){
    case 'F':  
      forward();
      break;
    case 'B':  
      back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'G':  
      forwardleft();
      break;
    case 'H':  
      backleft();
      break;
    case 'I':  
      forwardright();
      break;
    case 'J':  
      backright();
      break;
    case 'S':
      Stop();
      break;
    case 'D':
      Stopall();
      break;
    case '1':
      i=1*x+y;
      break;
    case '2':
      i=2*x+y;
      break;
    case '3':
      i=3*x+y;
      break;
    case '4':
      i=4*x+y;
      break;
    case '5':
      i=5*x+y;
      break;
    case '6':
      i=6*x+y;
      break;
    case '7':
      i=7*x+y;
      break;
    case '8':
      i=8*x+y;
      break;
    case '9':
      i=9*x+y;
      break;
    case 'q':
      i=10*x+y;
      break;
      
}}}
void forward()
{digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
myservo.write(m);
analogWrite(ms1,i);

}

void back()
{digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
myservo.write(m);
analogWrite(ms1,i);
  
}

void left()
{digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
myservo.write(l);
analogWrite(ms1,i);

}

void right()
{digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
myservo.write(r);
analogWrite(ms1,i);

} 
void forwardleft()
{digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
myservo.write(l);
analogWrite(ms1,i);

}

void backleft()
{digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
myservo.write(l);
analogWrite(ms1,i);
}
void forwardright()
{digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
myservo.write(r);
analogWrite(ms1,i);

}

void backright()
{digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
myservo.write(r);
analogWrite(ms1,i);

}

void Stop()
{digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
myservo.write(m);
analogWrite(ms1,0);

}
void Stopall()
{digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
myservo.write(m);
analogWrite(ms1,0);

}
