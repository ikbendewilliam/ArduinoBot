class Motor
{
  private:
    int _pinForward;
    int _pinBack;

  public:
    Motor(const int pinForward, const int pinBack)
    {
      _pinForward = pinForward;
      _pinBack = pinBack;
    }

    void init() const
    {
      pinMode(_pinForward, OUTPUT);
      pinMode(_pinBack, OUTPUT);
      Serial.println();
    }

    void forward() const
    {
      digitalWrite(_pinForward, HIGH);
      digitalWrite(_pinBack, LOW);
    }

    void back() const
    {
      digitalWrite(_pinForward, LOW);
      digitalWrite(_pinBack, HIGH);
    }

    void stop() const
    {
      digitalWrite(_pinForward, LOW);
      digitalWrite(_pinBack, LOW);
    }
};

