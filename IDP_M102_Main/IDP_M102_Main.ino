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
#define LED_BLINK 2
#define LED_DEN_LOW 3  //green
#define LED_DEN_HIGH 4 //red
#define MAX_RANG (520)
#define ADC_SOLUTION (1023.0)
#define LINE_SENSOR_VLEFT 5 // Set pins for sensors
#define LINE_SENSOR_LEFT 6
#define LINE_SENSOR_RIGHT 7
#define LINE_SENSOR_VRIGHT 8
#define START_BUTTON 9
#define RESET_BUTTON 10
int sensityPin = A0;
void(* resetFunc) (void) = 0;
void setup() { //Setup code which only runs once
AFMS.begin();  // Start the motor shiel up
//Setup serial port for 9600 bits
Serial.begin(9600);
Wire.begin();
sensor.begin(0x50); //Set up TOF sensor
sensor.setMode(sensor.eContinuous,sensor.eHigh);
sensor.start();


pinMode(LED_BLINK, OUTPUT); //Set Pin2 as output for LED
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

while(start_button == 0){
  button_pressed();
  }
while (blocks_dropped < 2){
  while (start_complete==0){
    start();
  }
  reset_pressed();
  if(reset_button == 1){
    resetFunc();
  }
  update_sensor_history();
  block_possible();
  followLine();
  if ((block_stopped_history == 0)&&(LFSensorReading[3]== 1)) { //While no block, go in a clockwise path
    node_follower();  
    reset_pressed();
  }
  if ((block_stopped_history == 1)&&(LFSensorReading[0]== 1 )) {
    node_return();
    reset_pressed();
  }


}

if (LED_BLINKING == 1){
digitalWrite(LED_BLINK, (millis() / 250) % 2);}

}


























//dark_block_scan(50,-50);
//distance_prints();
//General_Run(120,-120);
//block_possible();
//dark_block_scan(120,-120);

//to_green();
