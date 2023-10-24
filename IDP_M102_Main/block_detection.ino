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
}/*
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
