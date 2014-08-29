import procontroll.*;
import net.java.games.input.*;
import processing.serial.*;

Serial robotPort;

ControllIO controll;
ControllDevice gamepad;
ControllSlider movStick;
ControllSlider rotStick;
ControllSlider elevStick;
ControllSlider armTrigger;
ControllButton armLeftBumper;
ControllButton armRightBumper;
ControllButton fireLeftButton;
ControllButton fireRightButton;
ControllButton fillLeftButton;
ControllButton fillRightButton;

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
    if(device.getName().equals("Controller (Gamepad F310)")){
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
  armTrigger = gamepad.getSlider(4);
  armLeftBumper = gamepad.getButton(4);
  armRightBumper = gamepad.getButton(5);
  fireLeftButton = gamepad.getButton(2);
  fireRightButton = gamepad.getButton(1);
  fillLeftButton = gamepad.getButton(6);
  fillRightButton = gamepad.getButton(7);
  
  prevTime = millis();
  
  // Setup the window
  size(400, 400);
  font = createFont("Arial", 18, true);
  textFont(font);
  textAlign(LEFT);
}

void draw(){
  // Update values
  float mov = deadband(-movStick.getValue());
  float rot = deadband(rotStick.getValue());
  float elev = deadband(-elevStick.getValue());
  
  boolean armed = (armTrigger.getValue() >= TRIGGER_TOLERANCE && armLeftBumper.pressed());
  float fireLeft = (armed && fireLeftButton.pressed() && !fireRightButton.pressed()) ? 1.0 : 0.0;
  float fireRight = (armed && fireRightButton.pressed() && !fireLeftButton.pressed()) ? 1.0 : 0.0;
  
  float fillLeft = (fillLeftButton.pressed()) ? 1.0 : 0.0;
  float fillRight = (fillRightButton.pressed()) ? 1.0 : 0.0;
  
  // Send values to robot controller
  if(millis() - prevTime >= UPDATE_DELAY){
    robotPort.write(mov+","+rot+","+elev+","+fireLeft+","+fireRight+","+fillLeft+","+fillRight+"\n");
    
    prevTime = millis();
  }
  
  // Output values in the window
  background(255);
  fill(0);
  text("Mov: " + mov, 30, 80);
  text("Rot: " + rot, 30, 120);
  text("Elev: " + elev, 30, 160);
  text("Armed: " + armed, 30, 200);
  text("FireLeft: " + fireLeft, 30, 240);
  text("FireRight: " + fireRight, 30, 280);
  text("FillLeft: " + fillLeft, 30, 320);
  text("FillRight: " + fillRight, 30, 360);
}
