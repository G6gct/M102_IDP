//Motor Controls 
void Forward(){
MotorL->setSpeed(225);
MotorR -> setSpeed(225);
MotorL->run(FORWARD);
MotorR->run(FORWARD);
LED_BLINKING = 1;

}

void Backward(){
MotorL->setSpeed(255);
MotorR -> setSpeed(255);
MotorL->run(BACKWARD);
MotorR->run(BACKWARD);
LED_BLINKING = 1;

}

void Left(){
MotorL->setSpeed(100);
MotorR -> setSpeed(200);
MotorL->run(BACKWARD);
MotorR->run(FORWARD);
delay(20);
LED_BLINKING = 1;
}

void Right(){
MotorL->setSpeed(200);
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
 // Serial.print("general");
}

void Right90(){
  delay(400);
  General_Run(255,-150);
  delay(1100);
  Stop();

}

void Left90(){
  delay(400);
  General_Run(-255,255);
  //Serial.print("HI");
  delay(1000);
  Stop();
  //Serial.print("Delayed");
}
void Turn180(){
  delay(400);
  General_Run(150,-150);
  delay(4100);
  Stop();
}

void to_box(){
  Forward();
  delay(4850);
  Backward();
  delay(4850);

}