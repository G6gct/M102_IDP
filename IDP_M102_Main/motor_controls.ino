//Motor Controls 
void Forward(){
MotorL->setSpeed(225);
MotorR -> setSpeed(225);
MotorL->run(FORWARD);
MotorR->run(FORWARD);
LED_BLINKING = 1;
}

void Backward(){
MotorL->setSpeed(200);
MotorR -> setSpeed(200);
MotorL->run(BACKWARD);
MotorR->run(BACKWARD);
LED_BLINKING = 1;

}

void Left(){
MotorL->setSpeed(100);
MotorR -> setSpeed(100);
MotorL->run(BACKWARD);
MotorR->run(FORWARD);
delay(20);
LED_BLINKING = 1;
}

void Right(){
MotorL->setSpeed(100);
MotorR -> setSpeed(100);
MotorL->run(FORWARD);
MotorR->run(BACKWARD);  
delay(20);
LED_BLINKING = 1;
}

void Stop(){
 MotorL->setSpeed(0);
MotorR -> setSpeed(0);
MotorL->run(FORWARD);
MotorR->run(FORWARD);   
delay(20);
LED_BLINKING = 0;
}

void General_Run(int speed1, int speed2){
  if (speed1 >=0){
    MotorL->setSpeed(speed1);
    MotorL->run(FORWARD);
  }
  else if (speed1 < 0){
    MotorL->setSpeed(-speed1);
    MotorL->run(BACKWARD);
  }
  if (speed2 >=0){
    MotorR->setSpeed(speed2);
    MotorR->run(FORWARD);
  }
  else if (speed2 < 0){
    MotorR->setSpeed(-speed2);
    MotorR->run(BACKWARD);
  }
  LED_BLINKING = 1;
  delay(20);
}

void Right90(){
  Right();
  delay(200);
  Stop();

}

void Left90(){
  General_Run(70,100);
  delay(3000);
  Stop();
}
void Turn180(){
  Left();
  delay(5500);
  Stop();
}