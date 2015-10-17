int sensor=0;
int minVal=10; // minimum force read from serial
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor=analogRead(0);
  Serial.println(sensor);
  delay(1000);
}
