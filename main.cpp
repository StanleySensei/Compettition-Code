/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here

vex::directionType reverse = vex::directionType::rev;
vex::directionType forward = vex::directionType::fwd;
vex::velocityUnits rpm = vex::velocityUnits::rpm;

vex::motor ClawMotor = vex::motor (vex::PORT1, vex::gearSetting::ratio18_1,false);
vex::motor Claw2Motor = vex::motor (vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor ArmMotor = vex::motor (vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor Arm2Motor = vex::motor (vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor MiddleMotor = vex::motor (vex::PORT5, vex::gearSetting::ratio18_1, false);
vex::motor LeftMotor = vex::motor (vex::PORT6, vex::gearSetting::ratio18_1, false);
vex::motor RightMotor = vex::motor (vex::PORT7, vex::gearSetting::ratio18_1, false);
vex::controller Controller1 = vex::controller();

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
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

void autonomous( void ) {
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

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................

    //Foward and Backwards Control
    if(Controller1.Axis3.value()){
      ArmMotor.spin(vex::directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);
    }
    if(Controller1.Axis2.value()){
      Arm2Motor.spin(vex::directionType::fwd, Controller1.Axis2.value(), velocityUnits:: pct);
    }
    
    //Claw Arm Control
    if(Controller1.ButtonL1.pressing()){
      ClawMotor.spin(vex::directionType:: fwd, Controller1.ButtonL1.pressing(), velocityUnits:: pct);
      Claw2Motor.spin(vex::directionType:: fwd, Controller1.ButtonL1.pressing(),velocityUnits:: pct);
    }

    if(Controller1.ButtonL2.pressing()){
      ClawMotor.spin(vex::directionType:: rev, Controller1.ButtonL2.pressing(), velocityUnits:: pct);
      Claw2Motor.spin(vex::directionType:: rev, Controller1.ButtonL2.pressing(),velocityUnits:: pct);
    }
    
    //Cube Storage Motor
    if(Controller1.ButtonR1.pressing()){
      MiddleMotor.spin(vex::directionType:: fwd, Controller1.ButtonR1.pressing(), velocityUnits:: pct);
      MiddleMotor.spin(vex::directionType:: fwd, Controller1.ButtonR1.pressing(),velocityUnits:: pct);
    }

    if(Controller1.ButtonR2.pressing()){
      MiddleMotor.spin(vex::directionType:: rev, Controller1.ButtonR2.pressing(), velocityUnits:: pct);
      MiddleMotor.spin(vex::directionType:: rev, Controller1.ButtonR2.pressing(),velocityUnits:: pct);
    }

    //Claw Motor Toggle
    if(Controller1.ButtonY.pressing() && ){
      ClawMotor.spin(vex::directionType:: fwd, Controller1.ButtonY.pressing(), velocityUnits:: pct);
      Claw2Motor.spin(vex::directionType:: fwd, Controller1.ButtonY.pressing(),velocityUnits:: pct);
    } else if(Controller1.ButtonY.pressing())


    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
}
