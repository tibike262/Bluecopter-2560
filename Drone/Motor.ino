
void motorInit(){
  pinMode(MOTOR0,OUTPUT); 
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
  pinMode(MOTOR3,OUTPUT);
  analogWrite(MOTOR0,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR1,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR2,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR3,MOTOR_ZERO_LEVEL);
}

void motorArm(){
  analogWrite(MOTOR0,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR1,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR2,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR3,MOTOR_ZERO_LEVEL);
  while(rxVal[0]<1120){
  };
  PIDroll.resetI();
  PIDpitch.resetI();
  PIDyaw.resetI();
  PIDangleX.resetI();
  PIDangleY.resetI();
}

