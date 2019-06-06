/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Andrew                                           */
/*    Created:      Sat Jun 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "v5_vcs.h"
#define MIN(a, b) a < b ? a : b;
#define MAX(a, b) a > b ? a : b;

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
    void setSideMotorsVelocity(SideMotors *sideMotors, int velocity){
      if (sideMotors->front != NULL){
        sideMotors->front->setVelocity(velocity, velocityUnit);
      }
      if (sideMotors->middle != NULL){
        sideMotors->middle->setVelocity(velocity, velocityUnit);
      }
      if (sideMotors->rear != NULL){
        sideMotors->rear->setVelocity(velocity, velocityUnit);
      }
    }
  protected:
    int maximumVelocity = 50;
    vex::velocityUnits velocityUnit = vex::velocityUnits::pct;
    vex::controller *con;
    DriveMode driveMode;
    
  private:
    void tankDrive(vex::controller* ctrl){
      setSideMotorsVelocity(&drivetrainMotors.leftMotors, ctrl->Axis3.value());
      setSideMotorsVelocity(&drivetrainMotors.rightMotors, ctrl->Axis2.value());
    }
    void arcadeDrive(vex::controller* ctrl){
      int result;

      result =  MIN(ctrl->Axis3.value() + ctrl->Axis1.value(), 127);
      setSideMotorsVelocity(&drivetrainMotors.leftMotors,result);

      result =  MAX(ctrl->Axis3.value() - ctrl->Axis1.value(), -127);
      setSideMotorsVelocity(&drivetrainMotors.rightMotors, result);
    }
    
    
    
    
};
