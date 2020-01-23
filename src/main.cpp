
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Michael                                                   */
/*    Created:      Fri May 24 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vext/vext.h"

#include "match.h"
#include "demobot.h"

using namespace vex;

vex::brain Brain;
vex::controller Controller;
vex::competition Competition;

vext::motor ramp(PORT5, gearSetting::ratio18_1, true); // ramp
vext::motor arm(PORT1, gearSetting::ratio6_1, false);

vex::motor IntakeA(vex::PORT8, gearSetting::ratio18_1, true);
vex::motor IntakeB(vex::PORT3, gearSetting::ratio18_1);
auto intake = vext::two(IntakeA, IntakeB);

vex::motor LeftMotor(PORT19, gearSetting::ratio18_1, true);
vex::motor RightMotor(PORT12, gearSetting::ratio18_1, false);
vex::motor LeftMotor2(PORT20, gearSetting::ratio18_1, true);
vex::motor RightMotor2(PORT11, gearSetting::ratio18_1, false);

demobot bot(LeftMotor, LeftMotor2, RightMotor, RightMotor2);


void pre_auton(void) {
  match::pre_auton(Controller, Brain);
  return;
}

void autonomous(void) {
  match::auton(bot, intake, ramp, arm);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  Sets up all the controller binds using the macros from vext              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  bot.bind(Controller.Axis1, Controller.Axis3); // Bind bot control to axis 1 and 3
                                                // (X,Y)
  btn(100, Controller.ButtonL1, Controller.ButtonR1,
      intake); // Bind controller buttons L1 and R1 to the intake motor
  btn(100, Controller.ButtonY, Controller.ButtonX, 
      arm);   // Bind controller buttons Y and X to the ar,

  Controller.ButtonB.pressed([] {
    bot.doCustomAction();
  });
}

//
// Do not modify, except to comment out the last linex
//

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  Controller.ButtonA.pressed([] { autonomous(); }); //for testing, disable for comp
}
