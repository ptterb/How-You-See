/* 

 How We See Logic Control
 Created by Tom Arthur May 1 2013
 Analog Input to Keyboard Output
 BlinkM LED Output 

 Leonardo use SCL (C) & SDA (D) for MaxM
 
 Resistor readings: 129, 918, 695, 19
 
 Revision 3

 */

#include "Wire.h"
#include "BlinkM_funcs.h"

const int areas[]={A0, A1, A2, A3, A4, A5}; // input pins for visual areas
int readings[6]; // analog pin readings

const char areaKeys[6][5]={   // brain cable 1, 2, 3, 4 & no connection
  {'A', 'B', 'C', 'D', '1'},  // vision function 1
  {'E', 'F', 'G', 'H', '2'},  // vision function 2
  {'I', 'J', 'K', 'L', '3'},  // vision function 3
  {'M', 'N', 'O', 'P', '4'},  // vision function 4
  {'Q', 'R', 'S', 'T', '5'},  // vision function 5
  {'U', 'V', 'W', 'X', '6'}}; // vision function 6
char currentKeys[6];          // store current key for each function
boolean sendChange = true;

const byte blinkm_addr[]={9, 10, 11, 12, 0}; // maxM controller addresses on i2c
const int areaColors[7][3]={                 // colors for each vision area.
  {48, 0, 255},                              // vision function 1 color value
  {0, 255, 0},                               // vision function 2 color value
  {0, 80, 255},                              // vision function 3 color value
  {255, 0, 0},                               // vision function 4 color value
  {255, 0, 150},                             // vision function 5 color value
  {255, 144, 0},                               // vision function 6 color value
  {255, 255, 0}};                                // all off
char currentColors[]={0,0,0,0};              // store last key for state change check

const int operationOn = 2; // button: turn keyboard operation on or off

void setup() {
  BlinkM_begin(); // start maxMs
  delay(10);
  BlinkM_stopScript(0);
  BlinkM_setRGB(0, 0,0,0); // set all to black
  delay(2000);
  BlinkM_playScript(0, 5,0,0 ); // play attract script

  pinMode(operationOn, INPUT);     // set operation pin to input
  digitalWrite(operationOn, HIGH); // turn on pullup resistors

  Keyboard.begin(); // initialize control over the keyboard
}

void loop() {

//if (digitalRead(operationOn) == LOW){  // check each of the analog inputs

  for (int r = 0; r < 6; r++)
  {
    char lastKey = currentKeys[r];                       // last key to check if state has changed
    readings[r] = analogRead(areas[r]);                  // get reading from analog pin & write to array

    if (readings[r] >= 1 && readings[r] <= 40){          // brain connector 1
      currentKeys[r] = areaKeys[r][0];

      if (currentKeys[r] != lastKey){
        updateLED(0, r, areaKeys[r][0]);
        sendChange = true;
      }
    }
    else if (readings[r] >= 898 && readings[r] <= 938){   // brain connector 2
      currentKeys[r] = areaKeys[r][1];

      if (currentKeys[r] != lastKey){
        updateLED(1, r, areaKeys[r][1]);
        sendChange = true;
      }
    }
    else if (readings[r] >= 675 && readings[r] <= 750){    // brain connector 3
      currentKeys[r] = areaKeys[r][2];

      if (currentKeys[r] != lastKey){
        updateLED(2, r, areaKeys[r][2]);
        sendChange = true;
      }
    }
    else if (readings[r] >= 109 && readings[r] <= 149){   // brain connector 4
      currentKeys[r] = areaKeys[r][3];

      if (currentKeys[r] != lastKey){
        updateLED(3, r, areaKeys[r][3]);
        sendChange = true;
      }
    }
    else {                                            // no brain connector   
      currentKeys[r] = areaKeys[r][4];
      if (currentKeys[r] != lastKey){
        sendChange = true;

        for (int i = 0; i < 4; i++){
          if (currentColors[i] == lastKey){
            idleLED(i, 5);
          }
        }
      }
    }



  // send update to status of all brain areas when a change is detected
  if (sendChange == true){
    for (int k = 0; k < 6; k++){
      Keyboard.write(currentKeys[k]); 
    }
    sendChange = false;
  }
 }

  delay(200);
}


void updateLED(int address, int bArea, char keyPress){
  BlinkM_stopScript(blinkm_addr[address]);
  BlinkM_fadeToRGB(blinkm_addr[address], areaColors[bArea][0], areaColors[bArea][1], areaColors[bArea][2]); //blinkm_addr[0]
  delay(250);
  currentColors[address] = keyPress;
}

void idleLED(int address, int program){
  BlinkM_playScript(blinkm_addr[address], program,0,0 );
}