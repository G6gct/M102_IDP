// Function for reading the line sensors and storing them in an array
void LFSensorRead() {
  LFSensorReading[0] = digitalRead(LINE_SENSOR_VLEFT);
  LFSensorReading[1] = digitalRead(LINE_SENSOR_LEFT);
  LFSensorReading[2] = digitalRead(LINE_SENSOR_RIGHT);
  LFSensorReading[3] = digitalRead(LINE_SENSOR_VRIGHT);
// Code for printing out the line sensor readings and the current mode
 /* for (int i=0; i<4; i++){
    Serial.print(LFSensorReading[i]);
    Serial.print(" ");
  }
  Serial.println(" ");*/
}

// Function to differentiate sensor cases
int junction = 0;
void LineFollowStart() {
  if((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 ))  {cases = LINE_ON_RIGHT;} // line on the right, to adjust right
  else if((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 ))  {cases = LINE_ON_LEFT;} // line on the left, to adjust left
  else if((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 ))  {cases = ON_LINE;} // on the line, no adjustments
  //else if(  (LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1))  { cases = HORIZONTAL_LINE; } // horizontal line found, turn right to adjust
  else {cases = IGNORE;}
  
}

   /* if(  (LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1))
  { junction = 1; cases = RIGHT_CORNER;} 

  if(  (LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0))
  { junction = 2; cases = LEFT_CORNER;} 
  */
  


// Function for line following and adjustment with switch cases
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
       delay(100);
       Left();
       break;
     
     case LINE_ON_RIGHT:
       delay(100);
       Right();
       break;

    case RIGHT_CORNER:
       Right90();
       delay(500);
       junction = 0;
       break;
    
    case LEFT_CORNER:
       Left90();
       delay(500);
       junction = 0;
       break;

    case HORIZONTAL_LINE:
       Right90();
       delay(delay_time/2);
       break;
    
    case IGNORE:
       Forward();
       delay(delay_time/2);
       junction = 0;
       break;
  }
}

// Starting motion from intial box to first intersection
void StartingCases(){
  if     ((LFSensorReading[3]==1) && (LFSensorReading[0]==0))   {Scases = right_forward;}
  else if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0) &&(LFSensorReading[3]== 0 )){Scases = in_box;}
  else if ((LFSensorReading[3]==0) && (LFSensorReading[0]== 1)) {Scases = left_forward;}
  else if ((LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1) &&(LFSensorReading[3]== 1 )){Scases = on_line;}
  else {Scases = IGNORE;}
}
void start(void){
  LFSensorRead();
  StartingCases();
  switch (Scases) {
    case in_box:
      Forward();
      delay(delay_time);
      break;

    case right_forward:
      General_Run(100,-100);
      delay(delay_time);
      break;

    case left_forward:
      General_Run(-100,100);
      delay(delay_time);
      break;

    case IGNORE:
       Forward();
       delay(delay_time/2);
       break;

    case on_line:
      Forward();
      delay(300);
      Stop();
      delay(delay_time);
      //General_Run(150,150);
      start_complete = 1;
      break;}
}
void lineadjust(void){
  LFSensorRead();
  StartingCases();
  switch (Scases) {
    case in_box:
      Forward();
      delay(delay_time);
      break;

    case right_forward:
      General_Run(100,-100);
      delay(delay_time);
      break;

    case left_forward:
      General_Run(-100,100);
      delay(delay_time);
      break;

    case IGNORE:
       Forward();
       delay(delay_time/2);
       break;

    case on_line:
      Forward();
      delay(300);
      Stop();
      delay(delay_time);
      //General_Run(150,150);
      line_adjustment = 1;
      break;}
}
  
// Blocks-on-corners path navigation (go around the perimeter of the grid, detect block, reverse path to start)

int prev_node = -1;
void node_follower(void){
  LFSensorRead(); // calls the sensor reading
  LineFollowStart();  // calls the line sensors

  node++; // increment the node count
  Serial.print(node);
  Serial.println(" ");

  if (node == 1 || node == 11) {junction = 1; cases = LEFT_CORNER;}
  else if (node == 0 || node == 2 || node == 5 || node == 6 || node == 7 || node == 10) {cases = ON_LINE;}
  else if (node == 3 || node == 8) {junction = 2; cases = RIGHT_CORNER;}
  else if (node==4 || node ==9) {cases = RIGHT_CORNER_ADJUST;}

  switch (cases) {

     case ON_LINE:
       Forward();
       delay(500);
       break;

    case RIGHT_CORNER:
       delay(400);
       Stop();
       //delay(500);
       Right90();
       //delay(500);
       break;
    case RIGHT_CORNER_ADJUST:
    {
      delay(400);
      Stop();
      //delay(500);
      Right75();
      //delay(500);
      break;
    }
    case LEFT_CORNER:
       delay(400);
       Stop();
       //delay(500);
       Left90();
       //delay(500);
       break;

  }
     

}

void node_return(void){
  LFSensorRead(); // calls the sensor reading
  LineFollowStart();  // calls the line sensors

  node--; //decrement the node count
  Serial.print(node);
  Serial.println(" ");
  if (node == 1 || node == 11) {junction = 1; cases = RIGHT_CORNER;}
  else if (node == 2 || node == 5 || node == 6 || node == 7 || node == 10) {cases = ON_LINE;}
  else if (node == 3 || node == 4 || node == 8 || node == 9) {junction = 2; cases = LEFT_CORNER;}
  else if (node == 0) {junction = 1; cases = START_BOX;}

  switch (cases) {

     case ON_LINE:
       Forward();
       delay(500);
       break;

    case RIGHT_CORNER:
       Stop();
       delay(500);
       Right75();
       delay(500);
       break;
    
    case LEFT_CORNER:
       Stop();
       delay(500);
       Left90();
       delay(500);
       break;
    
    case START_BOX:
       Stop();
       centerLine();
       Forward();
       delay(1750);
       Stop();
       block_drop_off();
       break;

  }
}


void centerLine(void) {
LFSensorRead(); // calls the sensor reading
LineFollowStart();  // calls the line sensors
  switch (cases)
   {
     case LINE_ON_LEFT:
       delay(100);
       Left();
       break;
     
     case LINE_ON_RIGHT:
       delay(100);
       Right();
       break;
  }
}