//Define for Bluetooth:
int IN4 = 4;

//Speed of the Motors
int speed = 0;

//Define for Ultrasonic:
int trigPin = 11;
int echoPin = 12;

void setup()


char incoming_value = "";

//Define pins for Motor:
int ENA = 10; //Enable Pin of the Right Motor (must be PWM)
int IN1 = 9;  //Control Pin
int IN2 = 8;

int ENB = 3; //Enable Pin of the Left Motor (must be PWM)
int IN3 = 5;
int IN4 = 4;

//Speed of the Motors
int speed = 0;

//Define for Ultrasonic:
int trigPin = 11;
int echoPin = 12;

void setup()
{

  //for Bluetooth
  Serial.begin(9600);

  //for Motor
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //for Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Use analogWrite to set initial motor speed
  setSpeed(speed);
}

void loop()
{

  if (Serial.available() > 0)
  {
    delay(10);
    incoming_value = Serial.read();

    if (UltraSonic() >= 10)
    {
      {

        switch (incoming_value)
        {
          case 'R': //Right
            right();
            break;

          case 'L': //Left
            left();
            break;

          case 'B': //Back
            backward();
            break;

          case 'F': //Forward
            forward();
            break;
 
          case 'S': //Stop
            stop();
            break;

          case '0':
            speed = 0;
            setSpeed(speed);
            break;

          case '1':
            speed = 100;
            setSpeed(speed);
            break;

          case '2':
            speed = 120;
            setSpeed(speed);
            break;

          case '3':
            speed = 130;
            setSpeed(speed);
            break;

          case '4':
            speed = 140;
            setSpeed(speed);
            break;

          case '5':
            speed = 150;
            setSpeed(speed);
            break;

          case '6':
            speed = 160;
            setSpeed(speed);
            break;

          case '7':
            speed = 170;
            setSpeed(speed);
            break;

          case '8':
            speed = 200;
            setSpeed(speed);
            break;

          case '9':
            speed = 220;
            setSpeed(speed);
            break;

          case '10':
            speed = 255;
            setSpeed(speed);
            break;

          default:
            Serial.println("Wrong choice");
            break;
        } // End of switch
      }
    }

    else
    {
      switch (incoming_value)
      {
        case 'B': //Backward
          backward();
          break;

        case 'S': //Stop
          stop();
          break;

        default:
          Serial.println("Wrong choice");
          break;
      }
    }
  }
}

void left()
{
  //Turn LEFT
  //motor A Backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //motor B Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("LEFT");
  delay(40);
}

void right()
{
  //Turn RIGHT
  //motor A Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //motor B Backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("RIGHT");
  delay(40);
}

void forward(){
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
Serial.println("FORWARD");
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("BACKWARD");
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("STOP");
}

void setSpeed(int speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  Serial.print("Speed: ");
  Serial.println(speed);
}

float UltraSonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin

  float duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound

  float distance = (duration / 2) * 0.0343;

  if (distance > 400)
  {
    distance = 400;
  }
  else if (distance < 2)
  {
    distance = 2;
  }

  Serial.println(distance);

  return distance;
}
