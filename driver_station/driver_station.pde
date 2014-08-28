import procontroll.*;
import net.java.games.input.*;
import processing.serial.*;

ControllIO controll;
ControllDevice gamepad;
ControllSlider movStick;
ControllSlider rotStick;
ControllSlider elevStick;
ControllSlider armTrigger;
ControllButton armLeftBumper;
ControllButton armRightBumper;
ControllButton fireAButton;

PFont font;

float DEBOUNCE_TOLERANCE = 0.25;
float TRIGGER_TOLERANCE = 0.75;

float deadband(float input){
  return (abs(input) <= DEBOUNCE_TOLERANCE) ? 0 : input;
}

int getGamepadId(){
  for(int i=0; i < controll.getNumberOfDevices(); i++){
    ControllDevice device = controll.getDevice(i);
    if(device.getName().equals("Controller (XBOX 360 For Windows)")){
      return i;
    }
  }
  
  return -1;
}

void setup(){
  // Setup the controller (start indexing from 0)
  controll = ControllIO.getInstance(this);
  gamepad = controll.getDevice(getGamepadId());
  movStick = gamepad.getSlider(0);
  rotStick = gamepad.getSlider(1);
  elevStick = gamepad.getSlider(2);
  armTrigger = gamepad.getSlider(4);
  armLeftBumper = gamepad.getButton(4);
  armRightBumper = gamepad.getButton(5);
  fireAButton = gamepad.getButton(0);
  
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
  
  boolean armed = (armTrigger.getValue() >= TRIGGER_TOLERANCE && armLeftBumper.pressed() && armRightBumper.pressed());
  boolean fire = (armed && fireAButton.pressed());
  
  // Output values in the window
  background(255);
  fill(0);
  text("Mov: " + mov, 30, 80);
  text("Rot: " + rot, 30, 120);
  text("Elev: " + elev, 30, 160);
  text("Armed: " + armed, 30, 200);
  text("Fire: " + fire, 30, 240);
}
