#include <SoftwareSerial.h>
SoftwareSerial myserial(2, 3);
SoftwareSerial myserial2(8, 9);
unsigned int x;
String rx = "";
byte c, d;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);
  myserial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
     char r = Serial.read();
     //Serial.println(0);
     if(r == '\n'){
        x = rx.toInt();
        c = (x & 65280) >> 8;
        d = x & 255;
        myserial.write(c);
        myserial.write(d);
        //myserial2.write(45);
        //Serial.println(d | (c << 8));
        //speedToReach2 = speedToReach1;
        //Serial.print(speedToReach1);
        rx = "";
      }
      else{
         rx = rx + r;
        }
  }
  //delay(1000);
}
