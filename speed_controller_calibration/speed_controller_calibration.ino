/* CALIBRATION CODE */
/* Connect the speed controller to the corresponding PWM pin on the arduino and
   GND (+5V is optional).
   
   FULL FORWARD - 180
   FULL BACKWARD - 0
   NEUTRAL - 90
   
   CAUTION: Clear you hands and wires of motor if attached to speed controller.
   
   INSTRUCTIONS:
   
   1. Connect arduino to speed controller.
   2. Wait for indicator LED on speed controller to turn away from blinking orange.
   3. Press and hold the "CAL" button on the speed controller.
   4. Wait about 12 seconds.
   5. Release the "CAL" button.
   
   If the speed controller is blinking orange, the program probably hasn't been
   uploaded, or the board is not wired correctly.
*/

#include <Servo.h>

int SPEED_CONTROLLER_PIN = 8; // set to the appropriate pin for your application

Servo sc;

void setup(){
  sc.attach(SPEED_CONTROLLER_PIN);
}

void loop(){
  // Forward
  sc.write(180);
  delay(2000);
  
  // Stop
  sc.write(90);
  delay(2000);
  
  // Reverse
  sc.write(0);
  delay(2000);
}

