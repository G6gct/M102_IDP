int distance_detection_TOF(){ //Updates the distance of TOF
  int distance_reading = sensor.getDistance();
  int true_distance = (distance_reading*0.1); //True distance away in cm
  return(true_distance);
}

int distance_detection_US(){ //Update distance of US
  float dist_t, sensity_t;
  sensity_t = analogRead(sensityPin);
  dist_t = sensity_t * MAX_RANG / ADC_SOLUTION;
  return(dist_t);
}
void button_pressed(){ //Checks whether or not the button has initiated the program
  int val = digitalRead(START_BUTTON);
  if (val == HIGH){
    start_button = 1;
  }
}
void reset_pressed(){
  int val = digitalRead(RESET_BUTTON);
  if (val == HIGH){
    reset_button = 1;
  }
}
void distance_prints(){ //Use this function to check the readings
Serial.print("Time of flight reading: ");
Serial.print(distance_detection_TOF());
Serial.print("      Ultrasonic reading: ");
Serial.print(distance_detection_US());
Serial.print("        Average TOF reading:");
Serial.print(average_distance_TOF());
Serial.print("        Average US reading:");
Serial.print(average_distance_US());
Serial.println(" ");
//delay(500);
}

void update_sensor_history(){ //Update the array of length 10 of the sensors
  index  = index + 1;
  int TOF_read = distance_detection_TOF();
  int US_read = distance_detection_US();
  if (index == 11){
    index = 0;
    distance_list_tof[index]= TOF_read;
    distance_list_us[index] = US_read;
  }

  else {
    distance_list_tof[index]= TOF_read;
    distance_list_us[index] = US_read;
  } 
}
int average_distance_TOF(){ //average of TOF array
  int sum_TOF = 0;
  for(int i = 0; i <10; i++){
  sum_TOF = sum_TOF + distance_list_tof[i];
  }
  return(sum_TOF/10);
}
int average_distance_US(){ //average of US array
  int sum_US = 0;
  for(int i = 0; i <10; i++){
  sum_US = sum_US + distance_list_us[i];
  }
  return(sum_US/10);
}

void block_possible(){ //checkes if a block is near using the TOF sensor
  int x = average_distance_TOF();

  if (x<10){
    is_block_detected =1;
    Serial.print("block is present");
    Serial.println(" ");
    block_stop();
  }
  else {
    is_block_detected = 0;
  }
}

void block_detected(){
 /* Serial.print(average_distance_TOF());
  Serial.print("                      ");
  Serial.print(average_distance_US());
  Serial.println("          ");*/
  if (average_distance_TOF()<20 && average_distance_US()<10){
    digitalWrite(LED_DEN_LOW,HIGH);
    digitalWrite(LED_DEN_HIGH,LOW);}
    is_block_detected = 1;
  if (average_distance_TOF()<20&& average_distance_US()>10){
     digitalWrite(LED_DEN_HIGH,HIGH);
     digitalWrite(LED_DEN_LOW,LOW);}
     is_block_detected = 1;
  if (average_distance_TOF()>20&& average_distance_US()>10){
    digitalWrite(LED_DEN_LOW,LOW);
    digitalWrite(LED_DEN_HIGH,LOW);
    is_block_detected = 0;
  }
}
void block_stop(){
    if (block_stopped_history == 0){
      block_stopped_history = 1;
      Stop();
      delay(1000);
      for (int i = 0;i<30;i++){
        update_sensor_history();
      }
      block_detected();
      delay(5000);
    }
}

void reset_block_stop(){
  block_stopped_history = 0;}

void dark_block_scan(int spd1,int spd2){ //need to make another function similar to block similar for this case and for it not to be called once the blocks on the intersections have been found as it causes the robot to stop. 
//Call this function when your at the corner of a junction, specify the motor speeds
  int distance_from_corner = average_distance_TOF();
  int initial_time = millis();
  int time_passed =millis();
  int off_course = 0;
  while ((distance_from_corner > 100) || ((time_passed - initial_time) < 5000)){ //Looks for a block as it rotates, edit the time it rotates for so that it is about 90 degrees if nothing gets detected
    update_sensor_history();
    distance_from_corner = average_distance_TOF();
    General_Run(spd1,spd2);
    time_passed = millis();
    Serial.print(average_distance_TOF());
    Serial.println(" ");
  }
  if (distance_from_corner < 100){
    initial_time = millis();
    time_passed =  millis();
    while ((distance_from_corner > 10) || ((time_passed - initial_time)< 10000) || off_course == 0){
      update_sensor_history();
      Forward();
      distance_from_corner = average_distance_TOF();}
      if (distance_from_corner > 100){
          off_course = 1;
      }
      time_passed = millis();
    Turn180();
    Forward();
    delay(time_passed-initial_time);
     //need to calibrate both Turn180 and Forward so that it doesnt go off course
  } //after the function has been called, it should have either done a 90 degree turn or gone and retrieved a block and returned roughly to the same place with requirement of turning or returned without a block
  Stop();} // A function to test wheter or not there is a block can now be called to indentify what it has 
/*
void detection_diffeence(){
  //cases only for competiton 1
  int diff =  abs(distance_detection_TOF()- distance_detection_US())
  if(diff >40) {detect = NOTHING;}
  else if(5<diff<40){detect = POSSIBLE;}
  else if diff < 5 {detect = BLOCK;} 
  switch (detect){
    case NOTHING
      break;
    case POSSIBLE;
     //do something
     break;
     case BLOCK;
    //some sort of code to indentify the block type
     //code to return to start
  }
}*/
