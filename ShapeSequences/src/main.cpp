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

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Brain.Screen.setPenColor(blue);
  Brain.Screen.drawCircle(150, 150, 20, yellow);
  wait(3, seconds);
  Brain.Screen.drawRectangle(10, 10, 100, 100, red);
  
}
