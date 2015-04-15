import procontroll.*;
import net.java.games.input.*;
import processing.serial.*;

Serial robotPort;

ControllIO controll;

ControllDevice gamepad;
ControllSlider movStick;
ControllSlider rotStick;
ControllSlider elevStick;
ControllSlider turretStick;
ControllButton armLeftTrigger;
ControllButton armLeftBumper;
ControllButton armRightTrigger;
ControllButton fireLeftButton;
ControllButton fireRightButton;
ControllButton fillLeftButton;
ControllButton fillRightButton;
ControllButton fillBothButton;

PFont font;

float DEBOUNCE_TOLERANCE = 0.25;
float TRIGGER_TOLERANCE = 0.75;
float UPDATE_DELAY = 50; // millis

long prevTime = 0;

float deadband(float input){
  return (abs(input) <= DEBOUNCE_TOLERANCE) ? 0 : input;
}

int getGamepadId(){
  for(int i=0; i < controll.getNumberOfDevices(); i++){
    ControllDevice device = controll.getDevice(i);
    if(device.getName().contains("Controller") || device.getName().contains("Logitech Dual Action")){
      return i;
    }
  }
  
  return -1;
}

// TODO
int getSerialId(){
  return -1;
}

void setup(){
  
  // Establish serial connection with robot controller
  robotPort = new Serial(this, Serial.list()[0], 9600); 
//  println(Serial.list());  
  
  // Setup the controller (start indexing from 0)
  controll = ControllIO.getInstance(this);
  gamepad = controll.getDevice(getGamepadId());
  movStick = gamepad.getSlider(0);
  rotStick = gamepad.getSlider(1);
  elevStick = gamepad.getSlider(2);
  turretStick = gamepad.getSlider(3);
  armLeftTrigger = gamepad.getButton(7);
  armLeftBumper = gamepad.getButton(5);
  armRightTrigger = gamepad.getButton(8);
  fireLeftButton = gamepad.getButton(1);
  fireRightButton = gamepad.getButton(3);
  fillLeftButton = gamepad.getButton(9);
  fillRightButton = gamepad.getButton(10);
  fillBothButton = gamepad.getButton(2);
  
  prevTime = millis();
  
  // Setup the window
  size(400, 460);
  font = createFont("Arial", 18, true);
  textFont(font);
  textAlign(LEFT);
}

void draw(){
  // Update values
  float mov = deadband(-movStick.getValue());
  float rot = deadband(rotStick.getValue());
  float elev = deadband(-elevStick.getValue());
  float turret = deadband(turretStick.getValue());
  
  boolean armed = (armLeftTrigger.pressed() && armRightTrigger.pressed() && armLeftBumper.pressed());
  float fireLeft = (armed && fireLeftButton.pressed() && !fireRightButton.pressed()) ? 1.0 : 0.0;
  float fireRight = (armed && fireRightButton.pressed() && !fireLeftButton.pressed()) ? 1.0 : 0.0;
  
  float fillLeft = (fillLeftButton.pressed() || fillBothButton.pressed()) ? 1.0 : 0.0;
  float fillRight = (fillRightButton.pressed() || fillBothButton.pressed()) ? 1.0 : 0.0;
  
  // Send values to robot controller
  if(millis() - prevTime >= UPDATE_DELAY){
    robotPort.write(mov+","+rot+","+elev+","+turret+","+fireLeft+","+fireRight+","+fillLeft+","+fillRight+"\n");
    
    prevTime = millis();
  }
  
  // Output values in the window
  background(255);
  fill(0);
  text("Mov: " + mov, 30, 80);
  text("Rot: " + rot, 30, 120);
  text("Elev: " + elev, 30, 160);
  text("Turret: " + turret, 30, 200);
  text("Armed: " + armed, 30, 240);
  text("FireLeft: " + fireLeft, 30, 280);
  text("FireRight: " + fireRight, 30, 320);
  text("FillLeft: " + fillLeft, 30, 360);
  text("FillRight: " + fillRight, 30, 400);
}
