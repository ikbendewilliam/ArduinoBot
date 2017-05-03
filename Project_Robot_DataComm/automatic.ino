MANOEUVRE currentManoeuvre = NONE;
int distanceBefore = 0;
int distanceBeforeThat = 0;

void automaticInit()
{
  pinMode(PIN_DISTANCE_TRIGGER, OUTPUT); // Sets the PIN_DISTANCE_TRIGGER as an Output
  pinMode(PIN_DISTANCE_ECHO, INPUT); // Sets the PIN_DISTANCE_ECHO as an Input
}

void moveAutomatic()
{
  int distance = getDistance();
  //int avgDistance = (distance + distanceBefore + distanceBeforeThat) / 3;

  delay(5);
  //Serial.println(String("distance: ") + distance);
  //Serial.println(String("avgDistance: ") + avgDistance);


  if (distance == 0)
    currentManoeuvre = NONE;
  else
  {
    if (distance > DISTANCE_MAX)
      currentManoeuvre = NONE;
    else if (distance <= DISTANCE_MIN)
      currentManoeuvre = GO_BACK;
    else if (currentManoeuvre == NONE)
    {
      if (distance <= DISTANCE_MED)
        currentManoeuvre = ROTATE_HARD_LEFT;
    }
    else if (currentManoeuvre == GO_BACK)
    {
      if (distance > DISTANCE_MED)
        currentManoeuvre = ROTATE_HARD_LEFT;
    }
    else if (currentManoeuvre == ROTATE_HARD_LEFT)
    {
      if (distance > DISTANCE_MAX)
        currentManoeuvre = NONE;
    }
  }
  switch (currentManoeuvre)
  {
    case NONE:
      motorDirection = START;
      break;
    case GO_BACK:
      motorDirection = BACK;
      break;
    case ROTATE_HARD_LEFT:
      motorDirection = HARD_LEFT;
      break;
    default: // should not appear
      motorDirection = STOP;
  }
  distanceBeforeThat = distanceBefore;
  distanceBefore = distance;
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
  long duration = pulseIn(PIN_DISTANCE_ECHO, HIGH, 7000);  // Timeout duration of 60 cm of sound wave travel time in microseconds (std: 1 sec)
  // Calculating the distance
  return duration * 0.034 / 2;
}


