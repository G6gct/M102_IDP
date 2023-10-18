int distance_detection_TOF(){
  int distance_reading = sensor.getDistance();
  int true_distance = (distance_reading-1.13)/1.13; //True distance away in cm
  Serial.print("Distance for TOF is : ");
  Serial.println((distance_reading-1.13)/1.13);
  return(true_distance);
}



int distance_detection_US(){
  float dist_t, sensity_t;
  sensity_t = analogRead(sensityPin);
  dist_t = sensity_t * MAX_RANG / ADC_SOLUTION;
  Serial.print("Distance for US is: ");
  Serial.println(dist_t);
  return(dist_t);
}



