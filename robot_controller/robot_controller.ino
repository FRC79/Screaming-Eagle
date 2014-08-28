/* ROBOT CONTROLLER */
#include <Compressor.h>
#include <RobotDrive.h>
#include <SpeedController.h>
#include <Servo.h>

int PRESSURE_SWITCH_PIN = 2;
int COMPRESSOR_PIN = 3;
int LEFT_VICTOR_PIN = 10;
int RIGHT_VICTOR_PIN = 11;

RobotDrive drive;
Compressor compressor(PRESSURE_SWITCH_PIN, COMPRESSOR_PIN);

void setup(){
  drive.init(LEFT_VICTOR_PIN, RIGHT_VICTOR_PIN);
  compressor.init();
}

void loop(){
  drive.tankDrive(0.0, 0.0);
  
  compressor.run();
  
  delay(15);
}


