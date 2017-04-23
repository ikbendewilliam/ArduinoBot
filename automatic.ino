MANOEUVRE currentManoeuvre = NONE;
int previousDistance = DISTANCE_MAX;

void automaticInit()
{
  pinMode(PIN_DISTANCE_TRIGGER, OUTPUT); // Sets the PIN_DISTANCE_TRIGGER as an Output
  pinMode(PIN_DISTANCE_ECHO, INPUT); // Sets the PIN_DISTANCE_ECHO as an Input
}

void moveAutomatic()
{
  int distance = getDistance();

  if (distance == 0)
  {
    motorDirection = START;
    currentManoeuvre = NONE;
  }
  else
  {
    if (distance > DISTANCE_MAX)
    {
      motorDirection = START;
      currentManoeuvre = NONE;
    }
    else if (distance <= DISTANCE_GO_BACK)
    {
      motorDirection = BACK;
      currentManoeuvre = GO_BACK;
    }
    else if (currentManoeuvre == NONE)
    {
      motorDirection = START;

      if (distance < DISTANCE_MED)
      {
        motorDirection = SOFT_LEFT;
        currentManoeuvre = ROTATE_SOFT_LEFT;
      }
    }
    else if (currentManoeuvre == GO_BACK)
    {
      motorDirection = BACK;
      if (distance > DISTANCE_MED)
      {
        motorDirection = SOFT_LEFT;
        currentManoeuvre = ROTATE_SOFT_LEFT;
      }
    }
    else if (currentManoeuvre == ROTATE_SOFT_LEFT)
    {
      motorDirection = SOFT_LEFT;
      if (distance > DISTANCE_MED)
      {
        motorDirection = START;
        currentManoeuvre = NONE;
      }
      else if (distance < DISTANCE_MIN)
      {
        motorDirection = HARD_LEFT;
        currentManoeuvre = ROTATE_HARD_LEFT;
      }
      else if (distance < previousDistance)
      {
        motorDirection = SOFT_RIGHT;
        currentManoeuvre = ROTATE_SOFT_RIGHT;
      }
    }
    else if (currentManoeuvre == ROTATE_HARD_LEFT)
    {
      motorDirection = HARD_LEFT;
      if (distance > DISTANCE_MED)
      {
        motorDirection = SOFT_LEFT;
        currentManoeuvre = ROTATE_SOFT_LEFT;
      }
    }
    else if (currentManoeuvre == ROTATE_SOFT_RIGHT)
    {
      motorDirection = SOFT_RIGHT;
      if (distance > DISTANCE_MED)
      {
        motorDirection = START;
        currentManoeuvre = NONE;
      }
      else if (distance < DISTANCE_MIN)
      {
        motorDirection = HARD_RIGHT;
        currentManoeuvre = ROTATE_HARD_RIGHT;
      }
      else if (distance < previousDistance)
      {
        motorDirection = SOFT_LEFT;
        currentManoeuvre = ROTATE_SOFT_LEFT;
      }
    }
    else if (currentManoeuvre == ROTATE_HARD_RIGHT)
    {
      motorDirection = HARD_LEFT;
      if (distance > DISTANCE_MED)
      {
        motorDirection = SOFT_RIGHT;
        currentManoeuvre = ROTATE_SOFT_RIGHT;
      }
    }
    previousDistance = distance;
  }
}

int getDistance()
{
  // Clears the trigPin
  digitalWrite(PIN_DISTANCE_TRIGGER, LOW);
  delayMicroseconds(2);
  // Sets the PIN_DISTANCE_TRIGGER on HIGH state for 10 micro seconds
  digitalWrite(PIN_DISTANCE_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_DISTANCE_TRIGGER, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(PIN_DISTANCE_ECHO, HIGH);
  // Calculating the distance
  return duration * 0.034 / 2;
}


