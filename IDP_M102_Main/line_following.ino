

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
  /*for (int i=0; i<4; i++){
    Serial.print(LFSensorReading[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
*/
}


/*0000z
0001z
0010z
0100z
1000z
0011z
0101u
1001u IGNORE CASE
0110?
1010u
1100z
0111?
1011z
1101z
1110?
1111z
*/


/*line sensing logic
0000 on line
x010 line on right (1010*, 0010)
xx01 line on very right (1101, 1001*, 0101*, 0001)
010x line on left (0101*, 0100)
10xx line on very left (1011, 1010*, 1001*, 1000)
1111 Horizontal line/ T junction/ t junction
0011 Right corner/ |--
1100 Left corner/ --|

how to discern between junctions with heads?
*/
int junction = 0;

void LineFollowStart() {
  if (junction = 0) {
  if((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 ))  {cases = LINE_ON_RIGHT;}
  else if((LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 1 ))  {cases = LINE_ON_VRIGHT;} 
  else if((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 ))  {cases = LINE_ON_LEFT;}
  else if((LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 0 ))  {cases = LINE_ON_VLEFT;}
  else if((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 ))  {cases = ON_LINE;}
  else if(  (LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1))  
  { cases = HORIZONTAL_LINE; } 
  else {cases = IGNORE;}
  }
}

 /* if(  (LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1))
  { junction = 1; cases = RIGHT_CORNER;} 

  if(  (LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0))
  { junction = 2; cases = LEFT_CORNER;} 
  */
  


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

    case LINE_ON_VRIGHT:
       Right();
       delay(delay_time/2);
       break;
    
    case LINE_ON_VLEFT:
       Left();
       delay(delay_time/2);
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
  
//hard-coded path navigation (go around the perimeter of the grid, detect block, reverse path to start

int node = 0;
int prev_node = -1;

void node_follower(void){
  LFSensorRead(); // calls the sensor reading
  LineFollowStart();  // calls the line sensors

 if(  (LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1))
  { prev_node = node++;} 
  else if(  (LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 ))
  { prev_node = node--;} 
  else if(  (LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1)){
  if (node - prev_node > 0) { prev_node = node++; }
  else if (node - prev_node <0) { prev_node = node--;}

  }
 Serial.print(node);
 Serial.print(" ");
 Serial.println(" ");
}
 
  
  
  
