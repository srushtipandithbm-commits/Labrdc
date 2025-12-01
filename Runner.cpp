Line runner 
Keep the right motor in reverse 
And while keeping the robot for running initially don’t keep the sensor touching the initial black line keep it a little front if not it will not move for 3rd time 
Code :

#include "iq_cpp.h"

// Allows for easier use of the VEX Library
using namespace vex;
double enc1 = 0.00;
double enc2 = 0.00;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Begin project code
  Right_Motor.setVelocity(20, percent);
  Left_Motor.setVelocity(20, percent);
  LightSensor.setLight(ledState::on);
  LightSensor.setLightPower(100, percent);
  double enc1 = Right_Motor.position(turns);
  double enc2 = Left_Motor.position(turns);
  wait(1,seconds);

  //First line
  while(LightSensor.brightness() >= 80)
  {
    Right_Motor.spin(forward);
    Left_Motor.spin(forward);
  }
    Right_Motor.stop();
    Left_Motor.stop();
    wait(500,msec);
    enc1 = Right_Motor.position(turns);
    enc2 = Left_Motor.position(turns);
    
    wait(1,seconds);

    while (Right_Motor.position(turns) > 0 && Left_Motor.position(turns) > 0)
    {
      Right_Motor.spin(reverse);
      Left_Motor.spin(reverse);
      wait(100,msec);
    }
    Right_Motor.stop();
    Left_Motor.stop();
    wait(1,seconds);

//Second Line

while(Right_Motor.position(turns) < (enc1 + 1.0000) && Left_Motor.position(turns) < (enc2 + 1.0000))
{
  Right_Motor.spin(forward);
  Left_Motor.spin(forward);
}
while(LightSensor.brightness() >= 80)
  {
    Right_Motor.spin(forward);
    Left_Motor.spin(forward);
  }
    Right_Motor.stop();
    Left_Motor.stop();
    wait(500,msec);
    enc1 = Right_Motor.position(turns);
    enc2 = Left_Motor.position(turns);
    
    wait(1,seconds);

    while (Right_Motor.position(turns) > 0 && Left_Motor.position(turns) > 0)
    {
      Right_Motor.spin(reverse);
      Left_Motor.spin(reverse);
      wait(100,msec);
    }
    Right_Motor.stop();
    Left_Motor.stop();
    wait(1,seconds);


//Third Line
while(Right_Motor.position(turns) < (enc1 + 1.0000) && Left_Motor.position(turns) < (enc2 + 1.0000))
{
  Right_Motor.spin(forward);
  Left_Motor.spin(forward);
}
while(LightSensor.brightness() >= 80)
  {
    Right_Motor.spin(forward);
    Left_Motor.spin(forward);
  }
    Right_Motor.stop();
    Left_Motor.stop();
    wait(500,msec);
    enc1 = Right_Motor.position(turns);
    enc2 = Left_Motor.position(turns);
  
    wait(1,seconds);

    while (Right_Motor.position(turns) > 0 && Left_Motor.position(turns) > 0)
    {
      Right_Motor.spin(reverse);
      Left_Motor.spin(reverse);
      wait(100,msec);
    }
    Right_Motor.stop();
    Left_Motor.stop();
    wait(15,seconds);
}
