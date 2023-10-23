int delay_time = 30;

/* Define different cases
#define ON_LINE 0
#define LINE_ON_LEFT 1       
#define LINE_ON_RIGHT 2

// Defining directions
/* #define RIGHT 1
#define LEFT -1 */


int LFSensorReading[4]={0, 0, 0, 0};  //zeroed array for storing line sensor readings

// Function for reading the line sensors and storing them in an array
void LFSensorRead() {
  LFSensorReading[0] = digitalRead(LINE_SENSOR_VLEFT);
  LFSensorReading[1] = digitalRead(LINE_SENSOR_LEFT);
  LFSensorReading[2] = digitalRead(LINE_SENSOR_RIGHT);
  LFSensorReading[3] = digitalRead(LINE_SENSOR_VRIGHT);
// Code for printing out the line sensor readings and the current mode
  for (int i=0; i<4; i++){
    Serial.print(LFSensorReading[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
//3 of them at junction TODO: Code the 3 1110
// change to junction mode:; which junction at
}

void LineFollowStart() {
  if(    (LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 ))  {cases = LINE_ON_RIGHT;}
  else if((LFSensorReading[0]==0  )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorRead[3]== 1))  {cases = LINE_ON_VRIGHT;/*INCLUDE HIGHER STEERING POWER SETTING*/} 
  else if((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 ))  {cases = LINE_ON_LEFT;}
  else if((LFSensorReading[0]==1  )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorRead[3]== 0))  {cases = LINE_ON_VLEFT;/*INCLUDE HIGHER STEERING POWER SETTING*/}
  else if((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 ))  {cases = ON_LINE;}
  else if((LFSensorReading[0]==1  )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1 )&&(LFSensorRead[3]== 1))  {cases = HORIZONTAL_LINE;}

  //To add multiple cases 
}

void followLine(void) {
  LFSensorRead(); // calls the sensor reading
  LineFollowStart();  // calls the line sensors
  switch (cases)
   {

     case ON_LINE:
       Forward();
       delay(delay_time);
       break;

     case LINE_ON_LEFT:
       Left();
       delay(delay_time);
       break;
     
     case LINE_ON_RIGHT:
       Right();
       delay(delay_time);
       break;
    
  }
}