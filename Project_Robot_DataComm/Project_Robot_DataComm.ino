#include "enums.h"
#include "Command.h"
#include "Motor.h"
#include "LightSensor.h"
#include "globals.h"

MOTOR_STATE motorState = MANUAL;
MOTOR_DIRECTION motorDirection = STOP;
String inputString = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Setup complete");

  MTR_LEFT.init();
  MTR_RIGHT.init();

  SNS_LEFT.init();
  SNS_MIDDLE.init();
  SNS_RIGHT.init();

  automaticInit();

  if (TEST_MOTOR)
    testMotor();
}

void loop() {
  if (!TEST_MOTOR)
  {
    checkSerial();
    if (motorState == AUTOMATIC)
      moveAutomatic();
    else if (motorState == LINE)
      moveLine();

    useMotor();
  }

  if (DEBUGGING)
    debug();

  delayMicroseconds(10);
}

void checkSerial()
{
  if (Serial.available() > 0)
  {
    for (int i = Serial.available(); i > 0; i--)
    {
      char c = Serial.read();
      inputString += c;
    }

    if (CMD_END.inString(inputString))
    {
      if (motorState == MANUAL)
        moveManual();

      if (CMD_AUTOMATIC.inString(inputString) && motorState != AUTOMATIC)
      {
        motorState = AUTOMATIC;
        motorDirection = STOP;
      }
      else if (CMD_MANUAL.inString(inputString) && motorState != MANUAL)
      {
        motorState = MANUAL;
        motorDirection = STOP;
      }
      else if (CMD_LINE.inString(inputString) && motorState != LINE)
      {
        motorState = LINE;
        motorDirection = STOP;
      }
      inputString = "";
    }
  }
}

void useMotor()
{
  switch (motorDirection)
  {
    case START:
      MTR_LEFT.forward();
      MTR_RIGHT.forward();
      break;
    case BACK:
      MTR_LEFT.back();
      MTR_RIGHT.back();
      break;
    case SOFT_LEFT:
      MTR_LEFT.stop();
      MTR_RIGHT.forward();
      break;
    case HARD_LEFT:
      MTR_LEFT.back();
      MTR_RIGHT.forward();
      break;
    case SOFT_RIGHT:
      MTR_LEFT.forward();
      MTR_RIGHT.stop();
      break;
    case HARD_RIGHT:
      MTR_LEFT.forward();
      MTR_RIGHT.back();
      break;
    default: //STOP
      MTR_LEFT.stop();
      MTR_RIGHT.stop();
  }
}

