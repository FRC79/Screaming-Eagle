Screaming-Eagle
===============

### Victor Calibration
In order to use the Arduino as the robot controller, the Victor Motor Controllers must be calibrated to use the correct PWM range. Use the victor_884_calibration.ino program in the [Arduino programming environment](http://arduino.cc/en/Main/Software) to do so along with the [Victor 884 datasheet](http://content.vexrobotics.com/docs/ifi-v884-users-manual-9-25-06.pdf) for reference to the calibration process. Once the victor_884_calibration.ino program is uploaded to the arduino board, open the Serial Monitor (Ctrl+Shift+M), and follow the instructions.

### Driver Station
For the joystick control libraries, download [procontroll.zip](http://creativecomputing.cc/p5libs/procontroll/procontroll.zip) , extract the folder, and move it to the libraries directory of your Processing folder.
