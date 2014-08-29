/* ROBOT CONTROLLER */
#include <Relay.h>
#include <RobotDrive.h>
#include <SpeedController.h>
#include <Servo.h>

const int NUM_FIELDS = 7;
float value[NUM_FIELDS];

float mov = 0.0;
float rot = 0.0;
float elev = 0.0;
float fireLeft = 0.0;
float fireRight = 0.0;
float fillLeft = 0.0;
float fillRight = 0.0;

RobotDrive drive;
SpeedController elevator;
Relay leftComp(2, 12);
Relay rightComp(3, 13);
Relay leftShot(6, 4);
Relay rightShot(7, 5);

void setup(){
  drive.init(10, 11); // left and right victor pins
  elevator.attach(9);
  leftComp.init();
  rightComp.init();
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
      if(i==3) fireLeft = value[i];
      if(i==4) fireRight = value[i];
      if(i==5) fillLeft = value[i];
      if(i==6) fillRight = value[i];
    }
  }
  
  // Set motor values
  drive.arcadeDrive(mov, rot);
  elevator.set(elev);
  
  if(fillLeft == 1.0){
    leftComp.forward();
  } else {
    leftComp.off();
  }
  
  if(fillRight == 1.0){
    rightComp.forward();
  } else {
    rightComp.off();
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


