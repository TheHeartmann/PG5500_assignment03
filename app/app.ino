const int OUTPIN = A5;
Servo myservo;  // create servo object to control a servo

int servoPos = 0;

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(OUTPIN);  // attaches the servo on pin OUTPIN to the servo object

  Particle.function("servo", servoControl);
  Particle.function("lock", lock);
  Particle.function("unlock", unlock);
  Particle.variable("servoPos", &servoPos, INT);
}

int servoControl(String command) {
    const auto newPos = command.toInt();

    servoPos = constrain(newPos, 0, 180);

    myservo.write(servoPos);

    return 1;
}

int lock(String command)
{
    turnServo(0);
    return 1;
}

int unlock(String command) {
    turnServo(160);
    return 1;
}

void turnServo(int position)
{
    servoPos = constrain(position, 0, 160);
    myservo.write(servoPos);
}