class LightSensor
{
  private:
    int _pinNumber;
  public:
    LightSensor(const int pinNumber)
    {
      _pinNumber = pinNumber;
    }

    void init() const
    {
      pinMode(_pinNumber, INPUT);
    }

    bool isHigh() const
    {
      return (digitalRead(_pinNumber) == HIGH);
    }
};

