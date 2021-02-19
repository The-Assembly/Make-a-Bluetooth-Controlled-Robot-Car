/*Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.*/
//Define L298N Dual H-Bridge Motor Controller Pins
#define dir1PinL  2    //Motor direction
#define dir2PinL  4    //Motor direction
#define speedPinL 6    // Needs to be a PWM pin to be able to control motor speed

#define dir1PinR  7    //Motor direction
#define dir2PinR  8   //Motor direction
#define speedPinR 5    // Needs to be a PWM pin to be able to control motor speed

/*From left to right, connect to D3,A1-A3 ,D10*/
#define LFSensor_0  3
#define LFSensor_1 A1
#define LFSensor_2 A2
#define LFSensor_3 A3
#define LFSensor_4 10

#define SERVO_PIN     9  //servo connect to D9

#define Echo_PIN   11 // Ultrasonic Echo pin connect to D11
#define Trig_PIN   12  // Ultrasonic Trig pin connect to D12

#define BUZZ_PIN     13  //buzzer connect to D13

int sensor[5];
#define AD_SPEED1   200  //avoidance motor speed
#define BACK_SPEED1  100     //back speed
#define BACK_SPEED2  150     //back speed
#define TRACK_SPEED   150  //line follow motor speed

int leftscanval, centerscanval, rightscanval, ldiagonalscanval, rdiagonalscanval;
int distancelimit = 30; //distance limit for obstacles in front           
int sidedistancelimit = 30; //minimum distance in cm to obstacles at both sides (the car will allow a shorter distance sideways)

const int turntime = 800; //Time the robot spends turning (miliseconds)
const int backtime = 600; //Time the robot spends turning (miliseconds)
int distance;
int numcycles = 0;

int thereis;
bool flag1=false;
bool stopFlag = true;
bool JogFlag = false;
uint16_t JogTimeCnt = 0;
uint32_t JogTime=0;

#define MAX_PACKETSIZE 32    //Serial receive buffer
char buffUART[MAX_PACKETSIZE];
unsigned int buffUARTIndex = 0;
unsigned long preUARTTick = 0;

enum DS
{
  MANUAL_DRIVE,
  AUTO_DRIVE_LF, //line follow
  AUTO_DRIVE_UO  //ultrasonic obstruction
}Drive_Status=MANUAL_DRIVE;

enum DN
{ 
  GO_ADVANCE, 
  GO_LEFT, 
  GO_RIGHT,
  GO_BACK,
  STOP_STOP,
  DEF
}Drive_Num=DEF;

