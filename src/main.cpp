/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Andrew                                           */
/*    Created:      Sat Jun 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "claw.cpp"
#include "drivetrain.cpp"
// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

Claw c(vex::PORT13, vex::gearSetting::ratio36_1);
Drivetrain dt;

int main() {
  dt.drivetrainMotors.rightMotors.front = new vex::motor(vex::PORT13); 
  con.ButtonR1.released([](){c.open();});
  con.ButtonR2.released([](){c.close();});
  while(1) {
      // Allow other tasks to run
      vex::this_thread::sleep_for((int) 1000/60);
    }
}
