#include <AFMotor.h>

#include <Arduino.h>
#include <SoftwareSerial.h>

int analogValue;

int incomingByte;

SoftwareSerial mySerial(A0, A1);

class Car {
  private: 
  AF_DCMotor* motorLeft;
  AF_DCMotor* motorRight;
  public: 
  Car(int mLeft, int mRight);
  void setSpeedCar(int, int);
  void setDirectionLeft(int);
  void setDirectionRight(int);
};

Car::Car(int mLeft, int mRight) {
  motorLeft = new AF_DCMotor(mLeft, MOTOR34_64KHZ);
  motorRight = new AF_DCMotor(mRight, MOTOR34_64KHZ);
  motorLeft->setSpeed(255);
  motorRight->setSpeed(255);
}

void Car::setSpeedCar(int left, int right) {
  motorLeft->setSpeed(left);
  motorRight->setSpeed(right);
}

void Car::setDirectionLeft(int dirLeft) {
  switch(dirLeft) {
    case 0:
      motorLeft->run(FORWARD);
      break;
    case 1:
      motorLeft->run(BACKWARD);
      break;
    default:
      motorLeft->run(RELEASE);
      break;
  }
}

void Car::setDirectionRight(int dirRight) {
  switch(dirRight) {
    case 0:
      motorRight->run(FORWARD);
      break;
    case 1:
      motorRight->run(BACKWARD);
      break;
    default:
      motorRight->run(RELEASE);
      break;
  }
}

Car *car;

int M_LEFT = 4;
int M_RIGHT = 3;

int MOVE_FORWARD = 0;
int MOVE_BACKWARD = 1;
int MOVE_RELEASE = 2;

void setup()
{  
  Serial.begin(9600);  
  mySerial.begin(9600);
  car = new Car(M_LEFT, M_RIGHT);
  car->setSpeedCar(255, 255);

}

void loop() {
  if (mySerial.available() > 0) {
    incomingByte = mySerial.read();
    
    switch(incomingByte) {
      case '1':
      Serial.println("1");
      car->setDirectionLeft(MOVE_FORWARD);
      car->setDirectionRight(MOVE_FORWARD);
      car->setSpeedCar(255, 255);
      break;
      case '2':
      Serial.println("2");
      car->setDirectionLeft(MOVE_FORWARD);
      car->setDirectionRight(MOVE_FORWARD);
      break;
      case '3':
      Serial.println("3");
      car->setDirectionLeft(MOVE_FORWARD);
      car->setDirectionRight(MOVE_RELEASE);
      car->setSpeedCar(255, 240);
      break;
      case '4':
      Serial.println("4");
      car->setDirectionLeft(MOVE_BACKWARD);
      car->setDirectionRight(MOVE_BACKWARD);
      break;
      case '5':
      Serial.println("5");
      car->setDirectionLeft(MOVE_RELEASE);
      car->setDirectionRight(MOVE_RELEASE);
      break;
      case '6':
      Serial.println("6");
      car->setDirectionLeft(MOVE_BACKWARD);
      car->setDirectionRight(MOVE_BACKWARD);
      break;
      case '7':
      Serial.println("7");
      car->setDirectionLeft(MOVE_RELEASE);
      car->setDirectionRight(MOVE_FORWARD);
      car->setSpeedCar(255, 255);  
      break;
      case '8':
      Serial.println("8");
      car->setDirectionLeft(MOVE_FORWARD);
      car->setDirectionRight(MOVE_FORWARD);
      break;
      default: 
      Serial.println("another");
      break;
    }
  }
}
