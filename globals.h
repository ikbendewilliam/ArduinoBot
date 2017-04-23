static const Command CMD_START("start", START);
static const Command CMD_STOP("stop", STOP);
static const Command CMD_BACK("back", BACK);
static const Command CMD_TURN_HARD_LEFT("hard left", HARD_LEFT);
static const Command CMD_TURN_HARD_RIGHT("hard right", HARD_RIGHT);
static const Command CMD_TURN_SOFT_LEFT("soft left", SOFT_LEFT);
static const Command CMD_TURN_SOFT_RIGHT("soft right", SOFT_RIGHT);
static const Command CMD_AUTOMATIC("automatic", STOP);
static const Command CMD_MANUAL("manual", STOP);
static const Command CMD_LINE("line", STOP);
static const Command CMD_END(";", STOP);

static const Motor MTR_LEFT(11, 10);
static const Motor MTR_RIGHT(6, 5);

static const LightSensor SNS_LEFT(7);
static const LightSensor SNS_MIDDLE(4);
static const LightSensor SNS_RIGHT(3);

static const int DISTANCE_MAX = 50;
static const int DISTANCE_MED = 40;
static const int DISTANCE_MIN = 30;
static const int DISTANCE_GO_BACK = 10;

static const int PIN_DISTANCE_TRIGGER = A0;
static const int PIN_DISTANCE_ECHO = A1;

static const bool DEBUGGING = false;
static const bool TEST_MOTOR = false;

