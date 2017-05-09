void moveLine()
{
  bool snsLeft = SNS_LEFT.isHigh();
  bool snsMiddle = SNS_MIDDLE.isHigh();
  bool snsRight = SNS_RIGHT.isHigh();

  if (snsLeft == snsRight) // if outer are either both on or off
  {
    motorDirection = START;
  }
  else if (snsLeft)
  {
    if (snsMiddle)
      motorDirection = SOFT_LEFT;
    else
      motorDirection = HARD_LEFT;
  }
  else// if (snsRight)
  {
    if (snsMiddle)
      motorDirection = SOFT_RIGHT;
    else
      motorDirection = HARD_RIGHT;
  }
}

