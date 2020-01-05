int right90sensor = 4, right45sensor = 6, left90sensor = 3, left45sensor = 5, frontSensor = 7;
int pwm2 = 2, pwm1 = 8, in1 = 9, in2 = 10, in3 = 11, in4 = 12, initpwm1 = 255, initpwm2 = 255, incrementVal = 5;
bool state = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(right90sensor, INPUT);
  pinMode(right45sensor, INPUT);
  pinMode(left90sensor, INPUT);
  pinMode(left45sensor, INPUT);
  pinMode(frontSensor, INPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //analogWrite(pwm1, initpwm1);
  //analogWrite(pwm2, initpwm2);
  /*while(true) {
    if(digitalRead(right90sensor) == HIGH && digitalRead(left90sensor) == HIGH) {
      delay(2000);
      digitalWrite(in2, HIGH);
      digitalWrite(in4, HIGH);
      analogWrite(pwm1, initpwm1);
      analogWrite(pwm2, initpwm2);
      break;
    }
  }*/
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(pwm1, 150);
  analogWrite(pwm2, 225);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(state) {
    if(digitalRead(right90sensor) == LOW && digitalRead(left90sensor) == LOW) {
      analogWrite(pwm1, 100);
      analogWrite(pwm2, 100);
    }
    if(digitalRead(right90sensor) == LOW && digitalRead(left90sensor) == HIGH)//increase right motor speed 
    {
      //initpwm1 += incrementVal;
      analogWrite(pwm1, 255);
    }
  
    if(digitalRead(right90sensor) == HIGH && digitalRead(left90sensor) == LOW)//increase left motor speed 
    {
      //initpwm2 += incrementVal;
      analogWrite(pwm2, 255);
    }
  //}
  if(digitalRead(frontSensor) == LOW)
    state = true;
  /*Serial.print(initpwm1);
  Serial.print(" ");
  Serial.println(initpwm2);*/
}
