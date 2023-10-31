//Motor Controls 
void Forward(){
MotorL->setSpeed(225);
MotorR -> setSpeed(210);
MotorL->run(FORWARD);
MotorR->run(FORWARD);
LED_BLINKING = 1;
digitalWrite(LED_BLINK, (millis() / 250) % 2);
}

void Backward(){
MotorL->setSpeed(225);
MotorR -> setSpeed(210);
MotorL->run(BACKWARD);
MotorR->run(BACKWARD);
LED_BLINKING = 1;
digitalWrite(LED_BLINK, (millis() / 250) % 2);

}

void Left(){
MotorL->setSpeed(100);
MotorR -> setSpeed(180);
MotorL->run(BACKWARD);
MotorR->run(FORWARD);
delay(20);
LED_BLINKING = 1;
digitalWrite(LED_BLINK, (millis() / 250) % 2);
}

void Right(){
MotorL->setSpeed(180);
MotorR -> setSpeed(100);
MotorL->run(FORWARD);
MotorR->run(BACKWARD);  
delay(20);
LED_BLINKING = 1;
digitalWrite(LED_BLINK, (millis() / 250) % 2);
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
  digitalWrite(LED_BLINK, (millis() / 250) % 2);
 // Serial.print("general");
}

void Right90(){
  delay(400);
  General_Run(255,-150);
  delay(1150);
  Stop();

}
void Right75(){
  delay(400);
  General_Run(255,-150);
  delay(900);
  Stop();

}

void Left90(){
  delay(400);
  General_Run(-150,255);
  //Serial.print("HI");
  delay(1200);
  Stop();
  //Serial.print("Delayed");
}
void Turn180(){
  delay(400);
  General_Run(150,-150);
  delay(4300);
  Stop();
}

void to_box(){
  Forward();
  delay(4850);
  Backward();
  delay(4850);

}