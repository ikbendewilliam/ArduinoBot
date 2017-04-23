class Command
{
  private:
    String _value;
    MOTOR_DIRECTION _direction;

  public:
    Command(const String value, const MOTOR_DIRECTION direction)
    {
      _value = value;
      _direction = direction;
    }

    bool inString(const String string) const
    {
      return string.indexOf(_value) >= 0;
    }

    MOTOR_DIRECTION getDirection() const
    {
      return _direction;
    }
};

