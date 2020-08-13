#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int servoPositions[5];

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
}

void loop() {
  //read Serial sent from Python interface on computer
  int i = 0;
  while(Serial.available()){
    String input = Serial.readStringUntil('\n');
    servoPositions[i] = input.toInt();
    i++;
  }

  servo1.write(servoPositions[0]);
  servo2.write(servoPositions[1]);
  servo3.write(servoPositions[2]);
  servo4.write(servoPositions[3]);
  servo5.write(servoPositions[4]);
  
  delay(500);
}
