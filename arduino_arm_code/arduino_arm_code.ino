#include <SoftwareSerial.h>

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
  while(Serial.available()){
    String input = Serial.readStringUntil('\n');
    servoPositions[0] = input.substring(0,3).toInt();
    servoPositions[1] = input.substring(3,6).toInt();
    servoPositions[2] = input.substring(6,9).toInt();
    servoPositions[3] = input.substring(9,12).toInt();
    servoPositions[4] = input.substring(12,15).toInt();
  }

  servo1.write(servoPositions[0]);
  servo2.write(servoPositions[1]);
  servo3.write(servoPositions[2]);
  servo4.write(servoPositions[3]);
  servo5.write(servoPositions[4]);
  
  delay(500);
}
