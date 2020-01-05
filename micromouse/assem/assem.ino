int stepPin1 = 5;
int stepPin2 = 6;
void setup() {
  // put your setup code here, to run once:
  DDRD |= (1 << stepPin1);
  DDRD |= (1 << stepPin2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
