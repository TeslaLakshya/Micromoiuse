#include <SoftwareSerial.h>
SoftwareSerial myserial(2, 3);
unsigned int x;
byte y, c, d;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(myserial.available() > 0) {
    if(y == 0) {
      c = myserial.read();
      y = 1;
    }
    else {
      d = myserial.read();
      y = 0;
      x = d | (c << 8);
      Serial.println(x);
      }
      /*byte d = myserial.read();
      x = d | (c << 8);*/
      //Serial.println(c);
    }
}
