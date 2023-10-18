//Motor Controls 
void Forward(){
MotorL->setSpeed(255);
MotorR -> setSpeed(255);
MotorL->run(FORWARD);
MotorR->run(FORWARD);
//Serial.print("Going forward");
//Serial.print("\n");

}

void Backward(){
MotorL->setSpeed(255);
MotorR -> setSpeed(255);
MotorL->run(BACKWARD);
MotorR->run(BACKWARD);
//Serial.print("Backward");
//Serial.print("\n");
delay(20);
}

void Left(){
MotorL->setSpeed(100);
MotorR -> setSpeed(100);
MotorL->run(BACKWARD);
MotorR->run(FORWARD);
//Serial.print("Going left");
//Serial.print("\n");
delay(20);
}

void Right(){
MotorL->setSpeed(30);
MotorR -> setSpeed(30);
MotorL->run(FORWARD);
MotorR->run(BACKWARD);  
delay(20);
//Serial.print("Going right");
//Serial.print("\n");
}

void Stop(){
 MotorL->setSpeed(0);
MotorR -> setSpeed(0);
MotorL->run(FORWARD);
MotorR->run(FORWARD);   
delay(20);
}