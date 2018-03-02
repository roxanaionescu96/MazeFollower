int sensorPin1=GPP_0;  
int sensorPin2=GPP_1;
int sensorPin3=GPP_3;

int leftMotorSpeed=150;
int rightMotorSpeed=150;
char moveInMaze[1000];//l-left,r-right,f-forward ,b-back
int index=0;

//sensor read ??? asynchronus check,have to put delay or not    
int frontSensor;
int leftSensor;             
int rightSensor;

  
void stopMotors(){
  digitalWrite(PWM_1,LOW) ;
  digitalWrite(PWM_2,LOW) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,LOW) ;
}

int calculatePID(){
  //have to find values for them
  int kp;
  int kd;
  return (leftSensor-rightSensor)*kp+(rightSensor-leftSensor)*kd;
    
}
//check if the cell is black or white
boolean checkCell(){
   return (digitalRead(IO_0))==1;
}

void moveForward(){
  moveInMaze[index]='f';
  index++;
  digitalWrite(PWM_1,LOW) ;
  digitalWrite(PWM_2,HIGH) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,HIGH) ;
  analogWrite(PWM_0,rightMotorSpeed+calculatePID());
  analogWrite(PWM_5,leftMotorSpeed-calculatePID());
}
void moveLeft(){
  moveInMaze[index]='l';
  index++;
  digitalWrite(PWM_1,LOW) ;
  digitalWrite(PWM_2,HIGH) ;
  digitalWrite(PWM_3,HIGH) ;
  digitalWrite(PWM_4,LOW) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
  delay(100);
  stopMotors();
}
void moveRight(){
  moveInMaze[index]='r';
  index++;
  digitalWrite(PWM_1,HIGH) ;
  digitalWrite(PWM_2,LOW) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,HIGH) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
  delay(100);
  stopMotors();
}
void moveBack(){
  moveInMaze[index]='b';
  index++;
  digitalWrite(PWM_1,HIGH) ;
  digitalWrite(PWM_2,LOW) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,HIGH) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
  delay(100);
  digitalWrite(PWM_1,HIGH) ;
  digitalWrite(PWM_2,LOW) ;
  digitalWrite(PWM_3,LOW) ;
  digitalWrite(PWM_4,HIGH) ;
  analogWrite(PWM_0,rightMotorSpeed);
  analogWrite(PWM_5,leftMotorSpeed);
  delay(100);
  
}
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
  int cellSize=26;          
  frontSensor=Ultrasonic.read(sensorPin1); 
  leftSensor=Ultrasonic.read(sensorPin2);              
  rightSensor=Ultrasonic.read(sensorPin3);
  
  //first cell to check if black 
 // while(((checkCell())==false)){
 //   if(firstCellCheckExcep==1) break;
 // }
  //no left wall case
   if(leftSensor>cellSize) {
                            moveLeft();
                            moveForward();
                      }
        else if(frontSensor>cellSize){
                                moveForward();
                              }
            else if(rightSensor>cellSize){
                                    moveRight();
                                    moveForward();
                                    }
                   else {
                         moveRight();
                         moveRight();
                         moveForward();
                        }
                    
  delay(100);                                 
}
