/* ROBOT CONTROLLER */
#include <Relay.h>
#include <RobotDrive.h>
#include <SpeedController.h>
#include <Servo.h>

// ROBOT MAP
int LEFT_COMPRESSOR_1_PIN = -1;
int LEFT_COMPRESSOR_2_PIN = -1;
int RIGHT_COMPRESSOR_1_PIN = -1;
int RIGHT_COMPRESSOR_2_PIN = -1;

int LEFT_FIRE_SOLENOID_PIN = -1;
int RIGHT_FIRE_SOLENOID_PIN = -1;

int LEFT_DRIVE_MOTOR_PIN = -1;
int RIGHT_DRIVE_MOTOR_PIN = -1;
int TURRET_MOTOR_PIN = -1;
int ELEVATOR_MOTOR_PIN = -1;

// INITIAL VALUES
const int NUM_FIELDS = 8;
float value[NUM_FIELDS];

float mov = 0.0;
float rot = 0.0;
float elev = 0.0;
float turret = 0.0;
float fireLeft = 0.0;
float fireRight = 0.0;
float fillLeft = 0.0;
float fillRight = 0.0;

// OBJECT DECLARATIONS
RobotDrive drive;
SpeedController elevator;
SpeedController turret;

Relay leftComp1(LEFT_COMPRESSOR_1_PIN);
Relay leftComp2(LEFT_COMPRESSOR_2_PIN);
Relay rightComp1(RIGHT_COMPRESSOR_1_PIN);
Relay rightComp2(RIGHT_COMPRESSOR_2_PIN);

Relay leftShot(LEFT_FIRE_SOLENOID_PIN);
Relay rightShot(RIGHT_FIRE_SOLENOID_PIN);

void setup(){
  // Init motors
  drive.init(LEFT_DRIVE_MOTOR_PIN, RIGHT_DRIVE_MOTOR_PIN);  // Setup the drivetrain controls
  elevator.attach(ELEVATOR_MOTOR_PIN);                      // Setup the elevator
  turret.attach(TURRET_MOTOR_PIN);                          // Setup the turret
  
  // Init compressors
  leftComp1.init();
  leftComp2.init();
  rightComp1.init();
  rightComp2.init();
  
  // Init fire solenoids
  leftShot.init();
  rightShot.init();
  
  Serial.begin(9600);
}

void loop(){
  // Serial data relay from driver station
  if(Serial.available()){
    for(int i=0; i < NUM_FIELDS; i++){
      value[i] = Serial.parseFloat();
      if(i==0) mov = value[i];
      if(i==1) rot = value[i];
      if(i==2) elev = value[i];
      if(i==3) turret = value[i];
      if(i==4) fireLeft = value[i];
      if(i==5) fireRight = value[i];
      if(i==6) fillLeft = value[i];
      if(i==7) fillRight = value[i];
    }
  }
  
  // Set motor values
  drive.arcadeDrive(mov, rot);
  elevator.set(elev);
  turret.set(turret);
  
  // Relay values on buttons
  if(fillLeft == 1.0){
    leftComp1.forward();
    leftComp2.forward();
  } else {
    leftComp1.off();
    leftComp2.off();
  }
  
  if(fillRight == 1.0){
    rightComp1.forward();
    rightComp2.forward();
  } else {
    rightComp1.off();
    rightComp2.off();
  }
  
  if(fireLeft == 1.0){
    leftShot.forward();
  } else {
    leftShot.off();
  }
  
  if(fireRight == 1.0){
    rightShot.forward();
  } else {
    rightShot.off();
  }
  
  delay(15);
}


