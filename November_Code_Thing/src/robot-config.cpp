#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor BR = motor(PORT10, ratio18_1, false);
motor BL = motor(PORT11, ratio18_1, false);
motor FR = motor(PORT9, ratio18_1, false);
motor FL = motor(PORT4, ratio18_1, false);
controller Controller1 = controller(primary);
motor GoalLift = motor(PORT12, ratio18_1, false);
motor RingRamp = motor(PORT13, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}