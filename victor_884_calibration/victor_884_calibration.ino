/* CALIBRATION CODE */
/* Connect the Victor to the corresponding PWM pin on the arduino,
   GND, and +5V.
   
   FULL FORWARD - 180
   FULL BACKWARD - 0
   NEUTRAL - 90
*/

#include <Servo.h>

int VICTOR_PIN = 8;

Servo victor;

void setup(){
  victor.attach(VICTOR_PIN);
  
  Serial.begin(9600);
  Serial.println("CALIBRATION PROGRAM");
  Serial.println("----------------------------");
  Serial.println("Hold and continue to hold the \"Cal\" button");
  Serial.println("Once the Victor begins flashing RED and GREEN,");
  Serial.println("type \"start\" and hit enter in the Serial Monitor.");
  Serial.println("Remember to keep the \"Cal\" button held for the whole");
  Serial.println("calibration.");
  Serial.println();
  Serial.print("TYPE \"start\" to begin: ");
}

char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

char serialInputEquals(char* This) {
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }
        index=0;
        return(1);
    }
    else {
        return(0);
    }
}

void loop(){
  if(serialInputEquals("start")){
    Serial.println();
    Serial.println("CALIBRATION STARTED (Keep holding \"Cal\" button)");
    Serial.println();
    
    // Actual calibration code (first full forward, then full backward, then neutral position
    Serial.print("PERFORMING FULL FORWARD...");
    victor.write(180);
    delay(1500);
    Serial.println("done.");
    
    Serial.print("PERFORMING FULL BACKWARD...");
    victor.write(0);
    delay(1500);
    Serial.println("done.");
    
    Serial.print("PERFORMING NEUTRAL POSITION...");
    victor.write(90);
    delay(1500);
    Serial.println("done.");
    
    Serial.println();
    Serial.println("Release the \"Cal\" button.");
    Serial.println("Calibration is complete!");
  }
}

