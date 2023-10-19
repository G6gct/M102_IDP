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
#define LED_DEN_LOW 3
#define LED_DEN_HIGH 4
#define MAX_RANG (520)
#define ADC_SOLUTION (1023.0)
#define LINE_SENSOR_VLEFT 5 // Set pins for sensors
#define LINE_SENSOR_LEFT 6
#define LINE_SENSOR_RIGHT 7
#define LINE_SENSOR_VRIGHT 8
int sensityPin = A0;

void setup() { //Setup code which only runs once
AFMS.begin();  // Start the motor shiel up
//Setup serial port for 9600 bits
Serial.begin(9600);
Wire.begin();
sensor.begin(0x50); //Set up TOF sensor
sensor.setMode(sensor.eContinuous,sensor.eHigh);
sensor.start();
//Serial. begin(9600);
int distance_list_tof[100]; //Setup sesnor lists
int distance_list_us[100];
int i = 0;


pinMode(LED_BLINK, OUTPUT); //Set Pin2 as output for LED
pinMode(LED_DEN_LOW, OUTPUT);
pinMode(LED_DEN_HIGH, OUTPUT);
pinMode(LINE_SENSOR_VLEFT, INPUT); // Set pins for sensors
pinMode(LINE_SENSOR_LEFT, INPUT);
pinMode(LINE_SENSOR_RIGHT, INPUT);
pinMode(LINE_SENSOR_VRIGHT, INPUT);

}

void loop(){ //Looping code
digitalWrite(LED_BLINK, (millis() / 1000) % 2);
//distance_detection_US();
followLine();
//Left();
}



