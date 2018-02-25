int sensorPin1=GPP_0;  
int sensorPin2=GPP_1;
int sensorPin3=GPP_3;
int leftMotorSpeed=150,rightMotorSpeed=150;
int  frontSensor,leftSensor,RightSensor; 

void moveForward(){
  digitalWrite(PWM_1,LOW) ;
  digitalWrite(PWM_2,HIGH) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,HIGH) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
}
void moveLeft(){
  digitalWrite(PWM_1,LOW) ;
  digitalWrite(PWM_2,HIGH) ;
  digitalWrite(PWM_3,HIGH) ;
  digitalWrite(PWM_4,LOW) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
}
void moveRight(){
  digitalWrite(PWM_1,HIGH) ;
  digitalWrite(PWM_2,LOW) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,HIGH) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
}
void moveBackward(){
  digitalWrite(PWM_1,HIGH) ;
  digitalWrite(PWM_2,LOW) ;
  digitalWrite(PWM_3,HIGH) ;
  digitalWrite(PWM_4,LOW) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
}
void setup() {
  Serial.begin(9600);                         
  Serial.println("Example: Single HC-SR04");  
  Ultrasonic.attach(sensorPin1); 
  Ultrasonic.attach(sensorPin2);  
  Ultrasonic.attach(sensorPin3);              
}

void loop()
{                 
  frontSensor=Ultrasonic.read(sensorPin1); 
  leftSensor=Ultrasonic.read(sensorPin2);              
  rightSensor=Ultrasonic.read(sensorPin3);             
  if(leftSensor>26) {
    moveLeft();
  }
  delay(100);                                 
}
