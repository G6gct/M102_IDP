// Include all required libraries 
#include "Wire.h"
#include <Adafruit_MotorShield.h>
#include "defintions.h"
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "Arduino.h"
#include "DFRobot_VL53L0X.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();  // Intialise motor shield
Adafruit_DCMotor *MotorL = AFMS.getMotor(4); // Call M1 motor myMotor
Adafruit_DCMotor *MotorR = AFMS.getMotor(1); // Call M2 motor
DFRobot_VL53L0X sensor; //Sets up TOF sensor
#define LED_BLINK 2 // blue blinking 
#define LED_DEN_LOW 3  //green
#define LED_DEN_HIGH 4 //red
#define MAX_RANG (520) //US sensor maximum range
#define ADC_SOLUTION (1023.0) // Bitrate 
#define LINE_SENSOR_VLEFT 5 // Set pins for sensors
#define LINE_SENSOR_LEFT 6 
#define LINE_SENSOR_RIGHT 7
#define LINE_SENSOR_VRIGHT 8
#define START_BUTTON 9
#define RESET_BUTTON 10
int sensityPin = A0;
void(* resetFunc) (void) = 0; // When called, restarts program
void setup() { //Setup code which only runs once
AFMS.begin();  // Start the motor shield up
Serial.begin(9600);//Setup serial port for 9600 bits
Wire.begin();
sensor.begin(0x50); //Set up TOF sensor
sensor.setMode(sensor.eContinuous,sensor.eHigh);
sensor.start();


pinMode(LED_BLINK, OUTPUT); //Set pins for LED
pinMode(LED_DEN_LOW, OUTPUT); 
pinMode(LED_DEN_HIGH, OUTPUT);
pinMode(LINE_SENSOR_VLEFT, INPUT); // Set pins for sensors
pinMode(LINE_SENSOR_LEFT, INPUT);
pinMode(LINE_SENSOR_RIGHT, INPUT);
pinMode(LINE_SENSOR_VRIGHT, INPUT);
pinMode(START_BUTTON, INPUT);
pinMode(RESET_BUTTON,INPUT);

}



void loop(){ //Looping code

while(start_button == 0){ // Wait for the start button to be pressed
  button_pressed();
  }
while (blocks_dropped < 2){ // Repeats the hard coded route twice 
  while (start_complete==0){ // Adjusts the robot to the first line
    start();
  }
  reset_pressed();
  if(reset_button == 1){ // Check if the reset button has been pressed
    resetFunc();
  }
  update_sensor_history(); // Various commands to check its enviroment
  block_possible();
  followLine();
  if ((block_stopped_history == 0)&&(LFSensorReading[3]== 1)) { //While no block, go in a clockwise path
    node_follower();  
    reset_pressed();
  }
  if ((block_stopped_history == 1)&&(LFSensorReading[0]== 1 )) { // While there is a block, reverse the path it has taken
    node_return();
    reset_pressed();
  }


}
line_adjustment = 0;  // Adjust itself to the start line
while (line_adjustment == 0){
lineadjust();}

if (ended == 0){ // Get in the box properly
  Backward();
  delay(1000);
  Stop();
  victory_dance(); // Funky lights
}

delay(600000); //Stop the program from whatever its doing
}
