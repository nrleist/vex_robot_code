/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Mon Aug 23 2021                                           */
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
  
  Brain.Screen.drawRectangle(139.5, 19.5, 200, 200, white);
  Brain.Screen.drawRectangle(149.5, 29.5, 90, 90, green);
  Brain.Screen.drawRectangle(239.5, 29.5, 90, 90, yellow);
  Brain.Screen.drawRectangle(149.5, 119.5, 90, 90, blue);
  Brain.Screen.drawRectangle(239.5, 119.5, 90, 90, red);
  
}
