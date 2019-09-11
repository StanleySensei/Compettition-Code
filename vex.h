/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::motor ClawMotor = vex::motor (vex::PORT1, vex::gearSetting::ratio18_1,false);
 vex::motor Claw2Motor = vex::motor (vex::PORT2, vex::gearSetting::ratio18_1, false);
 vex::motor ArmMotor = vex::motor (vex::PORT3, vex::gearSetting::ratio18_1, false);
 vex::motor Arm2Motor = vex::motor (vex::PORT4, vex::gearSetting::ratio18_1, false);
 vex::motor MiddleMotor = vex::motor (vex::PORT5, vex::gearSetting::ratio18_1, false);
 vex::motor LeftMotor = vex::motor (vex::PORT6, vex::gearSetting::ratio18_1, false);
 vex::motor RightMotor = vex::motor (vex::PORT7, vex::gearSetting::ratio18_1, false);
 vex::brain Brain;
 vex::controller Controller;
