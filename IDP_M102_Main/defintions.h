int cases = 0;
int Scases =0;

//Define for port locations
#define LED_BLINK 2
#define LED_DEN_LOW 3
#define LED_DEN_HIGH 4
#define MAX_RANG (520)
#define ADC_SOLUTION (1023.0)
// Define  pins for line sensors
const int LINE_SENSOR_VLEFT = 5; 
const int LINE_SENSOR_LEFT = 6; 
const int LINE_SENSOR_RIGHT = 7; 
const int LINE_SENSOR_VRIGHT = 8;
/*
#define LINE_SENSOR_VLEFT 5 
#define INE_SENSOR_LEFT 6
#define LINE_SENSOR_RIGHT 7
#define LINE_SENSOR_VRIGHT 8 */


// Define different cases
#define ON_LINE 0
#define LINE_ON_LEFT 1       
#define LINE_ON_RIGHT 2

#define in_box 0
#define right_forward 1
#define left_forward 2
#define on_line 3

// Defining directions
#define RIGHT 1
#define LEFT -1


// Importing functions in this file for use in main programme
void LFSensorRead();
void LineSensorStart();
void followLine();
void StartingCases();
void start();