float t=10; //time delay
int d=100; //duty cycle
int p=13;  // pin
const int analogInPin = A0;  
const int analogOutPin = 3; 
float sensorValue = 0;        //float for accuracy
float outputValue = 0; 
void setup() {
  Serial.begin(9600);
  pinMode(p, OUTPUT);
}


void loop() {
  digitalWrite(p, HIGH);   
  delay(t);                       
  digitalWrite(p, LOW);    
  delay(t);    
  sensorValue = analogRead(analogInPin);//analog input value
  
  outputValue = (sensorValue*5) / 1023;   
  Serial.print(sensorValue);
  Serial.print("\t voltage = ");
  Serial.println(outputValue);                 
}
