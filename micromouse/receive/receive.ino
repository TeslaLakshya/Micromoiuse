unsigned int rx;
byte x = 0;
byte low, high;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
} 
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    //s = micros();
     //byte r = Serial.read();
     //Serial.println(r);
     /*if(r == '\n'){
        //speedToReach2 = speedToReach1;
        //Serial.println(rx);
        rx = "";
      }
      else{
         rx = rx + r;
        }*/
        if(x == 0) {
          low = Serial.read();
          x = 1;  
        }
        else {
          high = Serial.read();
          rx = (high * 256) + low;
          Serial.print(low);
          Serial.print("  ");
          Serial.print(high);
          Serial.print("  ");
          Serial.println(rx);
          x = 0;  
        }
        //e = micros();
       
  }

  //Serial.println(e-s);

}
