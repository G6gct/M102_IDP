int distance_detection_TOF(){
  int distance_reading = sensor.getDistance();
  int true_distance = (distance_reading*0.1); //True distance away in cm
  return(true_distance);
}

int distance_detection_US(){
  float dist_t, sensity_t;
  sensity_t = analogRead(sensityPin);
  dist_t = sensity_t * MAX_RANG / ADC_SOLUTION;
  return(dist_t);
}
void button_pressed(){
  int val = digitalRead(START_BUTTON);
  if (val == HIGH){
    start_button = 1;
  }
}
void distance_prints(){
Serial.print("Time of flight reading: ");
Serial.print(distance_detection_TOF());
Serial.print("      Ultrasonic reading: ");
Serial.print(distance_detection_US());
Serial.print("        Average TOF reading:");
Serial.print(average_distance_TOF());
Serial.print("        Average US reading:");
Serial.print(average_distance_US());
Serial.println(" ");
delay(500);
}

void update_sensor_history(){
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
int average_distance_TOF(){
  int sum_TOF = 0;
  for(int i = 0; i <10; i++){
  sum_TOF = sum_TOF + distance_list_tof[i];
  }
  return(sum_TOF/10);
}
int average_distance_US(){
  int sum_US = 0;
  for(int i = 0; i <10; i++){
  sum_US = sum_US + distance_list_us[i];
  }
  return(sum_US/10);
}

void block_possible(){
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
