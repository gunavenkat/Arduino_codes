unsigned long ms_from_start =0;
unsigned long ms_previous_read_LED1 = 0;
unsigned long LED1_interval=1000;

#define LED1 3

int LED1_state=0;

void setup() {
  pinMode(LED1, OUTPUT);
}

void loop() {
  ms_from_start = millis();
  if (ms_from_start-ms_previous_read_LED1>LED1_interval){
    ms_previous_read_LED1=ms_from_start;
    if (LED1_state==0) LED1_state=1; else LED1_state=0;
    digitalWrite(LED1,LED1_state);
  }
}