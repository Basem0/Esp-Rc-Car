#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// Define pin numbers
#define ena 25
#define r1 16
#define r2 17
#define enb 26
#define l1 27
#define l2 14
int maxSpeed = 255;
int minSpeed = 100;

// Function to control left forward
void wheelrf(int speed){
  analogWrite(ena, speed);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  delay(5);
}

// Function to control left backward
void wheelrb(int speed) {
  analogWrite(ena, speed);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  delay(5);
}

// Function to control right forward
void wheellf(int speed) {
  analogWrite(enb, speed);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(5);
}

// Function to control right backward
void wheellb(int speed) {
  analogWrite(enb, speed);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(5);
}
void stop() {
  analogWrite(enb, maxSpeed);
  analogWrite(enb, maxSpeed);
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  delay(5);
}

// Function to move forward
void forward() {
  analogWrite(ena, maxSpeed);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  analogWrite(enb, maxSpeed);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(5);
}

// Function to move backward
void backward(){
  analogWrite(ena, maxSpeed);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  analogWrite(enb, maxSpeed);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(5);
}

// Function to turn right
void right() {
  analogWrite(ena, maxSpeed);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  analogWrite(enb, maxSpeed);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(5);
}

// Function to turn left
void left() {
  analogWrite(ena, maxSpeed);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  analogWrite(enb, maxSpeed);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
}
void RF() {
  analogWrite(ena, maxSpeed);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  analogWrite(enb, minSpeed);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(5);
}
void RB() {
  analogWrite(ena, maxSpeed);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  analogWrite(enb, minSpeed);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(5);
}
void LF() {
  analogWrite(ena, minSpeed);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  analogWrite(enb, maxSpeed);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(5);
}
void LB() {
  analogWrite(ena, minSpeed);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  analogWrite(enb, maxSpeed);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(5);
}

void setup() {
  Serial.begin(115200);

  SerialBT.begin("beso"); // Bluetooth device name

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.write(command);
    if('F' == command)
    {
      forward();
    }
    else if('B' == command)
    {
      backward();
    }
    else if('R' == command)
    {
      right();
    }
    else if('L' == command)
    {
      left();
    }
    else if('G' == command)
    {
      LF();
    }
    else if('I' == command)
    {
      RF();
    }
    else if('H' == command)
    {
      LB();
    }
    else if('J' == command)
    {
      RB();
    }
    else if('S' == command)
    {
      stop();
    }
    else{
      stop();
    }
  }
}
