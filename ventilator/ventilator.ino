#define POWER 5
#define DIR1 3
#define DIR2 4


void setup() {
  pinMode(POWER,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  digitalWrite(POWER,HIGH);
  digitalWrite(DIR1,HIGH);
  digitalWrite(DIR2,LOW);
}

void loop() {
}
   
