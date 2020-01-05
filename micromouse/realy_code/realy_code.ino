int pin = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() > 0) {
      int x = Serial.read();
      Serial.println(x); 
   }
}
