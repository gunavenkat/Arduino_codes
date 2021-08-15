const int analogInPin = A4;  
const int analogOutPin = 9; 

// voltmeter code for voltage measurements range
// from 0-51.6v
//--by using voltage bridge circuit
//i used two resistors of 1kohm(0.906kohm) &10kohm(9.4kohm) as voltage bridge.
//change of resistance can change the range of the voltmeter
float sensorValue = 0;        //float for accuracy
float outputValue = 0;        

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  float sum=0;//sum of sensor values(1-1023)
  float sum1=0;//sum of voltage values(0-51.6)
  int i;
  for(i=0;i<1000;i++){              //to find the average since the analog input varies frequently
  
  sensorValue = analogRead(analogInPin);//analog input value
  
  outputValue = (sensorValue*51.6) / 1023;  //calculated voltage value
  
  sum=sum+outputValue;
  sum1=sum1+sensorValue;
  delay(1);
  }
  Serial.print(sum1 / 1000);
  Serial.print("\t voltage = ");
  Serial.println(sum / 1000);
  

  
  
}
