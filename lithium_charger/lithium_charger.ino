
int p=2;  // pin
const int analogInPin = A0;  

float sensorValue = 0;        //float for accuracy
float outputValue = 0; 
void setup() {
  Serial.begin(9600);
  pinMode(p, OUTPUT);
}


void loop() {
      
  sensorValue = analogRead(analogInPin);//analog input value
  outputValue = (sensorValue * 5) / 1023; 
  if(outputValue >= 4.2){ //charge blink voltage check
     digitalWrite(p, HIGH);   
  delay(500);                       
  digitalWrite(p, LOW);    
  delay(500);  
  }else{
    digitalWrite(p, LOW); }
    
  Serial.print(sensorValue);
  Serial.print("\t voltage = ");
  Serial.println(outputValue);                 
}
