int cases = 0;
int Scases =0;
int is_block_detected = 0;
int block_stopped_history = 0;
int initiate = 1;
int start_button = 0;
int LED_BLINKING = 0;
int delay_time = 100;
int x = 1000;
int y = 1000;
int distance_list_tof[10]={2000,2000,2000,2000,2000,2000,2000,2000,2000,2000}; //Setup sesnor lists
int distance_list_us[10]={2000,2000,2000,2000,2000,2000,2000,2000,2000,2000};
int average_tof;
int average_us;
int index = 0;
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
#define HORIZONTAL_LINE 3
#define LINE_ON_VRIGHT 4
#define LINE_ON_VLEFT 5
#define RIGHT_CORNER 6
#define LEFT_CORNER 7
#define four_white 8
#define IGNORE 9

#define in_box 0
#define right_forward 1
#define left_forward 2
#define on_line 3

// Defining directions
#define RIGHT 1
#define LEFT -1

// temp boolean definitions
bool LT1;   
bool RT1;
bool RT2;
bool RT3;
bool RT4;
bool RT5;
bool RT6;
bool RT7;
bool RT8;
bool RT9;
bool LT2;

// Importing functions in this file for use in main programme

// Line Following
void LFSensorRead();
void LineSensorStart();
void followLine();
void StartingCases();
void start();

//Block Detection
int distance_detection_TOF();
int distance_detection_US();
void button_pressed();


//Motor Controls
void Forward();
void Backward();
void Left();
void Right();
void Stop();
void General_Run();
void Right90();
void Left90();
void Turn180();

//temp functions
void FCpath(); 
void resetRobotState();