void debug()
{
  int distance = getDistance();
  Serial.println(String("=================================================="));
  Serial.println(String("motors: "));
  Serial.println(String(" motorDirection: ") + motorDirectionAsString());

  Serial.println(String("sensors: "));
  Serial.println(String(" left: ") + (SNS_LEFT.isHigh() ? "on" : "off"));
  Serial.println(String(" middle: ") + (SNS_MIDDLE.isHigh() ? "on" : "off"));
  Serial.println(String(" right: ") + (SNS_RIGHT.isHigh() ? "on" : "off"));
  Serial.println(String(" distance: ") + distance + "cm");
}

void testMotor()
{
  Serial.println(String("=================================================="));
  Serial.println(String("Starting motor tests"));
  Serial.println(String("=================================================="));

  Serial.println(String("Test move START (0.1sec)"));
  MTR_LEFT.forward();
  MTR_RIGHT.forward();
  delay(100);
  MTR_LEFT.stop();
  MTR_RIGHT.stop();
  delay(900);
  Serial.println(String("Test move BACK (0.1sec)"));
  MTR_LEFT.back();
  MTR_RIGHT.back();
  delay(100);
  MTR_LEFT.stop();
  MTR_RIGHT.stop();
  delay(900);
  Serial.println(String("Test move SOFT_LEFT (0.1sec)"));
  MTR_LEFT.stop();
  MTR_RIGHT.forward();
  delay(100);
  MTR_LEFT.stop();
  MTR_RIGHT.stop();
  delay(900);
  Serial.println(String("Test move HARD_LEFT (0.1sec)"));
  MTR_LEFT.back();
  MTR_RIGHT.forward();
  delay(100);
  MTR_LEFT.stop();
  MTR_RIGHT.stop();
  delay(900);
  Serial.println(String("Test move SOFT_RIGHT (0.1sec)"));
  MTR_LEFT.forward();
  MTR_RIGHT.stop();
  delay(100);
  MTR_LEFT.stop();
  MTR_RIGHT.stop();
  delay(900);
  Serial.println(String("Test move HARD_RIGHT (0.1sec)"));
  MTR_LEFT.forward();
  MTR_RIGHT.back();
  delay(100);
  MTR_LEFT.stop();
  MTR_RIGHT.stop();
  delay(900);

  Serial.println(String("=================================================="));
  Serial.println(String("Finished motor tests"));
  Serial.println(String("=================================================="));
}

String motorDirectionAsString()
{
  switch (motorDirection)
  {
    case START:
      return "Start";
      break;
    case STOP:
      return "Stop";
      break;
    case BACK:
      return "Back";
      break;
    case SOFT_LEFT:
      return "Soft left";
      break;
    case HARD_LEFT:
      return "Hard left";
      break;
    case SOFT_RIGHT:
      return "Soft right";
      break;
    case HARD_RIGHT:
      return "Hard Right";
      break;
    default:
      return "MOTORDIRECTION NOT FOUND";
  }
}
