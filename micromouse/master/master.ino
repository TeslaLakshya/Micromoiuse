#include <SPI.h>
String rx = "";
void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(115200); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   SPI.begin ();
   SPI.setClockDivider(SPI_CLOCK_DIV8);//divide the clock by 8
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
     char r = Serial.read();
     //Serial.println(0);
     if(r == '\n'){
        digitalWrite(SS, LOW);
        SPI.transfer(rx.toInt());
        digitalWrite(SS, HIGH);
        Serial.println(rx.toInt());
        //speedToReach2 = speedToReach1;
        //Serial.print(speedToReach1);
        rx = "";
      }
      else{
         rx = rx + r;
        }
  }
  //delay(2000);
}
