Attendance and object detection 
// Include the IQ Library
#include "iq_cpp.h"

// Allows for easier use of the VEX Library
using namespace vex;
int Obj_count = 0;

void Forward()
{
  while (Optical6.brightness() >= 80)
  {
    Drivetrain.drive(forward);
  }
  Drivetrain.stop();
  Drivetrain.driveFor(reverse, 50, mm);
}

void turn_right()
{
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.stop();
}
void turn_left()
{
  Drivetrain.turnFor(left, 180, degrees);
  Drivetrain.stop();
}

int Check_object()
{
  if(Distance1.objectDistance(mm)<250)
  {
    return 1;
  }
  else 
  {
    return 0;  
  }  
}


void Check_Obj(int x)
{
  for(int i = 0; i<x ; i++)
  {
    Drivetrain.driveFor(forward, 100, mm);
    Forward();
    wait(400,msec);
    turn_right();
    wait(400,msec);
    Obj_count = Obj_count + Check_object();
    wait(400,msec);
    turn_left();
    wait(400,msec);
    Obj_count = Obj_count + Check_object();
    wait(400,msec);
    turn_right();
    wait(1,seconds);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Begin project code
  Drivetrain.setDriveVelocity(30, percent);
  Drivetrain.setTurnVelocity(30, percent);
  Optical6.setLight(ledState::on);
  Optical6.setLightPower(100, percent);
  wait(1,seconds);
  Check_Obj(3);
  wait(500,msec);
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.setFont(mono12);
  Brain.Screen.print("No. of Objects: %d" ,Obj_count);
  Brain.Screen.newLine();
  wait(500,msec);
  Drivetrain.stop();
}
