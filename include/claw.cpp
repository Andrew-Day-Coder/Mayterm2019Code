/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Andrew                                           */
/*    Created:      Sat Jun 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "v5_vcs.h"

// A global instance of vex::brain used for printing to the V5 brain screen
class Claw : vex::motor{
  public:
    // --- constructors ---
    Claw(int motorPort, vex::gearSetting gearing):vex::motor(motorPort, gearing){
      power = 75;
      powerUnit = vex::velocityUnits::pct;
      angle = 60;
      rotationUnit = vex::rotationUnits::deg;
      closed = true;
      resetRotation();
    }
    ~Claw(){
      stop();
    }
    // --- getters and setters ---
    int getPower(){
      return power;
    }
    void setPower(int p){
      power = p;
    }
    vex::velocityUnits getPowerUnits(){
      return powerUnit;
    }
    void setPowerUnits(vex::velocityUnits units){
      powerUnit = units;
    }
    
    int getAngle(){
      return angle;
    }
    void setAngle(int a){
      angle = a;
    }
    vex::rotationUnits getRotationUnits(){
      return rotationUnit;
    }
    void setRotationUnits(vex::rotationUnits units){
      rotationUnit = units;
    }
    // --- object methods ---
    void open(){
      rotateTo(-angle, rotationUnit, power, powerUnit);
    }
    void close(){
      stop();
    }
    void toggle(){
      if(closed == true){
        open();
      }
      else{
        close();
      }
    }
    
  private:
    int power;
    bool closed;
    vex::velocityUnits powerUnit;
    int angle;
    vex::rotationUnits rotationUnit;
}; 

