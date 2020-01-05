int trigPinF = 6, trigPinR = 4, trigPinL = 2, echoPinF = 7, echoPinR = 5, echoPinL = 3, left_enable = 8, right_enable = 13, offset = 60;//offset is bot chassis length in cm
int previous_error = 0;
double Kp = 0.001, Ki = 0.001, Kd = 0.001;      // constants for scaling P I D effects (will need adjusting)
double error, P, I = 0,  D;      // error variables
double total;
double L_enable_val = 200, R_enable_val = 200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPinF, OUTPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinF, INPUT);
  pinMode(echoPinR, INPUT);
  pinMode(echoPinL, INPUT);
  pinMode(left_enable, OUTPUT);
  pinMode(right_enable, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //setting direction of motors
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  analogWrite(left_enable, 50);
  //analogWrite(right_enable, 150);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for(int i = 150; i < 255; i += 5) {
    analogWrite(left_enable, i);
    analogWrite(right_enable, i);
    delay(1000);
  }
  /*int start = millis();
  error = readRight() - readLeft();
  P = error * Kp;
  I = ((I + error)*1)*Ki;    
  D = ((error - previous_error)/1) * Kd;
  previous_error = error;
  total = (P+I+D);
  L_enable_val -= (total);
  L_enable_val = constrain(L_enable_val, 150, 200);      // may need to adjust
    \
  R_enable_val += (total); 
  R_enable_val = constrain(R_enable_val, 150, 200);
    
  analogWrite(right_enable, L_enable_val);            // enable pins and values 
                                                     // must be global
  analogWrite(left_enable, R_enable_val);
  while(!((millis() - start) >= 1)){};*/
}

long readLeft() {
  long duration, distance;//try changing if memory exceeds
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(5);
  //send pulse
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  //receive pulse
  duration = pulseIn(echoPinL, HIGH);
  //find distance
  distance = (duration/2) * 0.343;
  //Serial.println(distance);
  if(distance > 5000) {
    long x = readRight();
    return x - offset;  
  }
  else {
    return distance;
  }  
}

long readRight() {
  long duration, distance;//try changing if memory exceeds
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(5);
  //send pulse
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  //receive pulse
  duration = pulseIn(echoPinR, HIGH);
  //find distance
  distance = (duration/2) * 0.343;
  //Serial.println(distance);
  return distance;
  if(distance > 5000) {
    long x = readLeft();
    return x - offset;  
  }
  else {
    return distance;
  } 
}

long readFront() {
  long duration, distance;//try changing if memory exceeds
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(5);
  //send pulse
  digitalWrite(trigPinF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinF, LOW);
  //receive pulse
  duration = pulseIn(echoPinF, HIGH);
  //find distance
  distance = (duration/2) * 0.343;
  return distance;    
}
