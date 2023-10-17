// Define  pins for line sensors
const int LINE_SENSOR_VLEFT = 5; 
const int LINE_SENSOR_LEFT = 6; 
const int LINE_SENSOR_RIGHT = 7; 
const int LINE_SENSOR_VRIGHT = 8;
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
void setup() {
  Serial.begin(9600);
  // something something

}
void loop() {
  // put your main code here, to run repeatedly:

}
