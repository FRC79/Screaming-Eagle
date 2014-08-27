/* ROBOT CONTROLLER */
#include <RobotDrive.h>
#include <SpeedController.h>
#include <Servo.h>

RobotDrive drive;

int LEFT_VICTOR_PIN = 10;
int RIGHT_VICTOR_PIN = 11;

void setup(){
  drive.init(LEFT_VICTOR_PIN, RIGHT_VICTOR_PIN);
}

void loop(){
  drive.tankDrive(0.0, 0.0);
  delay(2000);
}


