// serial pin 0
const int flexpin = D0;
boolean isShut;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int flex;

 flex = analogRead(flexpin);
 Serial.println("bifford");
 checkTrap(flex);
 delay(5000);
}

void checkTrap(int flexValue){
 if(flexValue < 870){
  //Serial.println(flexValue);

  Serial.println("no critter. all systems normal");
  if(isShut == true){
   returnToNormal();
   isShut = false;
  }else{
    isShut = false;
  }
 }else{
  Serial.println(flexValue);
  Serial.println("looks like we caught one of them bastards!");
  isShut = true;
  showAlert();
 }
}

void showAlert(){
  // turn off normal indicator
  digitalWrite(ledNormal,LOW);
 //turn on alert
  blinkAlert();
}

void blinkAlert(){
  digitalWrite(ledAlert,HIGH);
  delay(100);
  digitalWrite(ledAlert,LOW);
  delay(100);
}

void returnToNormal(){
  digitalWrite(ledAlert,LOW);
  digitalWrite(ledNormal,HIGH);
}
