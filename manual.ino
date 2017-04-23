void moveManual() 
{
  checkCommand(CMD_START);
  checkCommand(CMD_STOP);
  checkCommand(CMD_BACK);
  checkCommand(CMD_TURN_HARD_LEFT);
  checkCommand(CMD_TURN_HARD_RIGHT);
  checkCommand(CMD_TURN_SOFT_LEFT);
  checkCommand(CMD_TURN_SOFT_RIGHT);
}

void checkCommand(Command command)
{
  if (command.inString(inputString))
  {
    motorDirection = command.getDirection();
  }
}
