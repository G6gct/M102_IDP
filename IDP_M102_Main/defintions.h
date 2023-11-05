int cases = 0;
int Scases =0;
int is_block_detected = 0;
int block_stopped_history = 0;
int start_complete =0;
int initiate = 1;
int start_button = 0;
int LED_BLINKING = 0;
int delay_time = 50;
int reset_button = 0;
int x = 1000;
int y = 1000;
int distance_list_tof[10]={2000,2000,2000,2000,2000,2000,2000,2000,2000,2000}; //Setup sesnor lists
int distance_list_us[10]={2000,2000,2000,2000,2000,2000,2000,2000,2000,2000};
int average_tof;
int average_us;
int index = 0;
int node = 0;
int blocks_dropped=0;
int LFSensorReading[4]={0, 0, 0, 0};  //zeroed array for storing line sensor readings
int blocktype = 0;
int line_adjustment =0;
int ended = 0;
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
#define RIGHT_CORNER 4
#define LEFT_CORNER 5
#define four_white 6
#define IGNORE 7
#define START_BOX 8
#define RIGHT_CORNER_ADJUST 9
#define in_box 0
#define right_forward 1
#define left_forward 2
#define on_line 3

// Defining directions
#define RIGHT 1
#define LEFT -1

// Prototype fucntions  
// Line Following
void LFSensorRead();
void LineSensorStart();
void followLine();
void StartingCases();
void start();
void lineadjust();
void node_follower();
void node_return();
void centerLine();
//Block Detection
int distance_detection_TOF();
int distance_detection_US();
void button_pressed();
void reset_pressed();
void distance_prints();
void update_sensor_history();
int average_distance_TOF();
int average_distance_US();
void block_possible();
void block_detected();
void block_stop();
void reset_block_stop();
void dark_block_scan();
void block_drop_off();
void victory_dance();
//Motor Controls
void Forward();
void Backward();
void Left();
void Right();
void Stop();
void General_Run();
void Right90();
void Right75();
void Left90();
void Left105();
void Turn180();
void to_box_red();
void to_box_green();