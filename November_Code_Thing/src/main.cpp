/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// BR                   motor         10              
// BL                   motor         11              
// FR                   motor         9               
// FL                   motor         4               
// Controller1          controller                    
// GoalLift             motor         12              
// RingRamp             motor         13              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {


  BL.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())*2, velocityUnits::pct); //(Axis3+Axis1)*2;
        BR.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())*2, velocityUnits::pct);//(Axis3-Axis1)*2;
        FL.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())*2, velocityUnits::pct); //(Axis3+Axis1)*2;
        FR.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())*2, velocityUnits::pct);//(Axis3-Axis1)*2;
  
  if(Controller1.ButtonUp.pressing()){
          GoalLift.spin(directionType::fwd, 50, vex::velocityUnits::pct);
          
        }
        else if(Controller1.ButtonDown.pressing()){
          GoalLift.spin(directionType::rev, 50, vex::velocityUnits::pct);
        }
        else{
        GoalLift.spin(directionType::rev, 0, vex::velocityUnits::pct);
          
        }
 
 if(Controller1.ButtonA.pressing()){
RingRamp.spin(directionType::fwd, 50, vex::velocityUnits::pct);

 }
  else if(Controller1.ButtonDown.pressing()){
          RingRamp.spin(directionType::rev, 50, vex::velocityUnits::pct);
  }
  else{
        RingRamp.spin(directionType::rev, 0, vex::velocityUnits::pct);
          
        }

        
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}