// serial pin 0
const int flexpin = D0;
boolean isShut;

void setup() {
  Serial.begin(9600);
}

void loop() {
 int flex;

 flex = analogRead(flexpin);
 Spark.publish("status",flex);
 }
