/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Tue Aug 24 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void wink() {
  while(true) {
    wait(3, seconds);
    Brain.Screen.drawCircle(274.5, 95, 9, black);
    wait(0.5, seconds);
    Brain.Screen.drawCircle(274.5, 95, 10, white);
    Brain.Screen.drawCircle(274.5, 95, 3, blue);
  }
}

void drawHead() {
  Brain.Screen.drawCircle(239.5, 119.5, 100, yellow);
}

void drawEyes() {
  Brain.Screen.drawCircle(209, 95, 10, white);
  Brain.Screen.drawCircle(209, 95, 3, blue);
  Brain.Screen.drawCircle(274.5, 95, 10, white);
  Brain.Screen.drawCircle(274.5, 95, 3, blue);
}

void messUpLeftEye() {
  Brain.Screen.drawCircle(209, 95, 9, black);
  Brain.Screen.drawCircle(209, 95, 10, white);
  Brain.Screen.drawCircle(209, 95, 3, blue);
}

void drawMouth() {
  for(int i = 0; i < 9; i++) {
      Brain.Screen.setPenColor(red);
      Brain.Screen.setPenWidth(3);
      Brain.Screen.drawLine(189+(i*5), 155+(i*3), 284.5-(i*5), 155+(i*3));
  }  
}

void drawNose() {
  for(int i = 0; i < 5; i++) {
      Brain.Screen.setPenColor(black);
      Brain.Screen.setPenWidth(3);
      Brain.Screen.drawLine(227+(i*3), 120+(i*3), 254.5-(i*3), 120+(i*3));
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  drawHead();
  drawEyes();
  drawMouth();
  drawNose();
  messUpLeftEye();
  wink();
}

