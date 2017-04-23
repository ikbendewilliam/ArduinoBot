void moveLine()
{
  bool snsLeft = SNS_LEFT.isHigh();
  bool snsMiddle = SNS_MIDDLE.isHigh();
  bool snsRight = SNS_RIGHT.isHigh();

  if (snsMiddle && (snsLeft == snsRight)) // if only middle or all 3
  {
    motorDirection = START;
  }
  else if (snsLeft)
  {
    if (snsMiddle)
      motorDirection = SOFT_RIGHT;
    else
      motorDirection = HARD_RIGHT;
  }
  else if (snsRight)
  {
    if (snsMiddle)
      motorDirection = SOFT_LEFT;
    else
      motorDirection = HARD_LEFT;
  }
  else // None
    motorDirection = STOP;
}

