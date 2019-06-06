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
  public:
    typedef struct{
      /*
        this structure holds the motor
        pointers for one side of the robot
      */
      vex::motor *front;
      vex::motor *middle;
      vex::motor *rear;
    }SideMotor;
    typedef struct{
      /*
        this structure holds two SideMotor
        structs and is the main access to 
        the motors in this class 
      */
      SideMotor leftSide;
      SideMotor rightSide;
    }DrivetrainMotors;
    typedef struct{
      vex::controller *primary;
      vex::controller *partner;
    } Controllers;
    enum ControlMode{
      /*
        This enum contains the different modes of 
        controlling the drivetrain
        ------------------------------------------
        | Controller = Main Controller           |
        | Partner = Partner Controller           |
        | Manual = No Controller, for automation |
        ------------------------------------------
      */
      Controller,
      Partner,
      Manual,
    };
    enum DriveMode{
      /*
        this enum holds the different driving
        control modes for the robot
      */
      TankDrive,
      ArcadeDrive,
    };
    void setDriveMode(DriveMode mode){
      /*
        this method changes the different
        drive modes of the robot
      */
      driveMode = mode;
    }
    void setControlMode(ControlMode mode){
      /*
        this method changes how the robot
        is controlled
      */
      controlMode = mode;
    }
    private:
      DriveMode driveMode;
      ControlMode controlMode;
      Controllers controllers;
};