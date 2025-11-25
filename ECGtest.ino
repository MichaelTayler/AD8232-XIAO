#define LOplus 8
#define LOminus 9
uint16_t val = 0;

void setup() {
  Serial.begin(19200);
  pinMode(LOplus, INPUT); // Setup for leads off detection LO +
  pinMode(LOminus, INPUT); // Setup for leads off detection LO -
  analogReadResolution(12);
  delay(100);
}

void loop() {
  
  if((digitalRead(LOplus) == 1)||(digitalRead(LOminus) == 1)){Serial.println(0);}
  else{
  val = 0;
  val += analogRead(A10);
  val += analogRead(A10);
  val += analogRead(A10);
  val += analogRead(A10);
  val = val>>2;

  Serial.print("1000,4000,");  Serial.println(val);}
  delay(15);
}