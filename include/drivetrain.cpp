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
class Drivetrain{
  protected:
    typedef struct{
      vex::motor *front;
      vex::motor *middle;
      vex::motor *rear;
    } SideMotors;
    typedef struct {
      SideMotors leftMotors;
      SideMotors rightMotors;
    } DrivetrainMotors;
  
  public:
    DrivetrainMotors drivetrainMotors;
    enum DriveMode{
      TankDrive,
      ArcadeDrive
    };
    Drivetrain(){
      
    }
    ~Drivetrain(){

    }
    void setDriveMode(DriveMode* mode){

    }
    void setMaximumVelocity(int vel){
      maximumVelocity = vel;
    }
    void setVelocityUnits(vex::velocityUnits units){
      velocityUnit = units;
    }
    void enableController(vex::controller control){
      con = &control;
    }
  
  protected:
    int maximumVelocity = 50;
    vex::velocityUnits velocityUnit = vex::velocityUnits::pct;
    vex::controller *con;
    DriveMode driveMode;
    
  private:
    void tankDrive(vex::controller con){
      if (drivetrainMotors.leftMotors.front != NULL){
        drivetrainMotors.leftMotors.front->setVelocity(con.Axis1.value(), velocityUnit);
      }
      if (drivetrainMotors.leftMotors.middle != NULL){
        drivetrainMotors.leftMotors.middle->setVelocity(con.Axis1.value(), velocityUnit);
      }
      if (drivetrainMotors.leftMotors.rear != NULL){
        drivetrainMotors.leftMotors.middle->setVelocity(con.Axis1.value(), velocityUnit);
      }
      if (drivetrainMotors.rightMotors.front != NULL){
        drivetrainMotors.rightMotors.front->setVelocity(con.Axis3.value(), velocityUnit);
      }

    }
    
    
    
    
};