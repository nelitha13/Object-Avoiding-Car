int trig1=47;
int echo1=46;
int speedd=140;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trig1,OUTPUT);
pinMode(echo1,INPUT);
Serial.begin(9600);

 pinMode(22,OUTPUT);
 pinMode(23,OUTPUT);
 pinMode(2,OUTPUT);

 pinMode(44,OUTPUT);
 pinMode(45,OUTPUT);
 pinMode(3,OUTPUT);
}

void loop() {
 distance=ultrasensor();
  Serial.println(distance);
delay(5);
if (distance>24){
  motor_right_Fwd();
  motor_left_Fwd();
}
else {
motor_left_Fwd();
motor_right_Bwd();
}

 
}
int stop_motor(){
  digitalWrite(22,LOW);
  digitalWrite(23,LOW);
  digitalWrite(44,LOW);
  digitalWrite(45,LOW);
  analogWrite(2,0);
  analogWrite(3,0);
}
int motor_left_Bwd(){
  digitalWrite(22,HIGH);
  digitalWrite(23,LOW);
  analogWrite(2,speedd);
}
int motor_right_Bwd(){
  digitalWrite(44,HIGH);
  digitalWrite(45,LOW);
  analogWrite(3,speedd);
}

int motor_left_Fwd(){
  digitalWrite(23,HIGH);
  digitalWrite(22,LOW);
  analogWrite(2,speedd);
}
int motor_right_Fwd(){
  digitalWrite(45,HIGH);
  digitalWrite(44,LOW);
  analogWrite(3,speedd);
}

int ultrasensor(){
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);

   int t = pulseIn(echo1,HIGH);
  long distance = (t/29)/2;
  return distance;
}
