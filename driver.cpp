#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
MeRGBLed rgbled_7(7, 2);

void move(int direction, int speed) {
  int leftSpeed = 0;
  int rightSpeed = 0;
  if(direction == 1) {
    leftSpeed = speed;
    rightSpeed = speed;
  } else if(direction == 2) {
    leftSpeed = -speed;
    rightSpeed = -speed;
  } else if(direction == 3) {
    leftSpeed = -speed;
    rightSpeed = speed;
  } else if(direction == 4) {
    leftSpeed = speed;
    rightSpeed = -speed;
  }
  motor_9.run((9) == M1 ? -(leftSpeed) : (leftSpeed));
  motor_10.run((10) == M1 ? -(rightSpeed) : (rightSpeed));
}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  pinMode(A7, INPUT);
  rgbled_7.fillPixelsBak(0, 2, 1);
  while(!((0 ^ (analogRead(A7) > 10 ? 0 : 1))))
  {
    _loop();
  }

  move(1, 90 / 100.0 * 255);
  _delay(11);
  move(1, 0);

  move(4, 83 / 100.0 * 255);
  _delay(0.45);
  move(4, 0);

  move(1, 92 / 100.0 * 255);
  _delay(6);
  move(1, 0);

  move(3, 78 / 100.0 * 255);
  _delay(0.3);
  move(3, 0);

  move(1, 92 / 100.0 * 255);
  _delay(9.5);
  move(1, 0);

  move(3, 94 / 100.0 * 255);
  _delay(0.69);
  move(3, 0);

  move(1, 65 / 100.0 * 255);
  _delay(3);
  move(1, 0);

  rgbled_7.setColor(0,255,0,0);
  rgbled_7.show();
  _delay(3);
  rgbled_7.setColor(0,0,0,0);
  rgbled_7.show();

  move(2, 65 / 100.0 * 255);
  _delay(3);
  move(2, 0);

  move(4, 65 / 100.0 * 255);
  _delay(0.6);
  move(4, 0);

  move(1, 85 / 100.0 * 255);
  _delay(8);
  move(1, 0);

  move(3, 75 / 100.0 * 255);
  _delay(0.34);
  move(3, 0);

  move(1, 85 / 100.0 * 255);
  _delay(8);
  move(1, 0);

  move(4, 90 / 100.0 * 255);
  _delay(0.5);
  move(4, 0);

  move(1, 55 / 100.0 * 255);
  _delay(5);
  move(1, 0);

  rgbled_7.setColor(0,255,0,0);
  rgbled_7.show();
  _delay(3);
  rgbled_7.setColor(0,0,0,0);
  rgbled_7.show();

  move(2, 55 / 100.0 * 255);
  _delay(5);
  move(2, 0);

  move(3, 95 / 100.0 * 255);
  _delay(0.85);
  move(3, 0);

  move(1, 85 / 100.0 * 255);
  _delay(18);
  move(1, 0);

  move(3, 85 / 100.0 * 255);
  _delay(0.7);
  move(3, 0);

  move(1, 85 / 100.0 * 255);
  _delay(17);
  move(1, 0);

  move(3, 85 / 100.0 * 255);
  _delay(0.69);
  move(3, 0);

  move(1, 85 / 100.0 * 255);
  _delay(17);
  move(1, 0);

  move(3, 50 / 100.0 * 255);
  _delay(1);
  move(3, 0);

  move(1, 85 / 100.0 * 255);
  _delay(6);
  move(1, 0);

  move(4, 70 / 100.0 * 255);
  _delay(0.45);
  move(4, 0);

  move(1, 70 / 100.0 * 255);
  _delay(3);
  move(1, 0);

  rgbled_7.setColor(0,255,0,0);
  rgbled_7.show();
  _delay(3);
  rgbled_7.setColor(0,0,0,0);
  rgbled_7.show();

  move(2, 70 / 100.0 * 255);
  _delay(3);
  move(2, 0);

  move(3, 80 / 100.0 * 255);
  _delay(0.6);
  move(3, 0);

  move(1, 80 / 100.0 * 255);
  _delay(35);
  move(1, 0);

  move(3, 55 / 100.0 * 255);
  _delay(0.7);
  move(3, 0);

  move(1, 80 / 100.0 * 255);
  _delay(7);
  move(1, 0);

  move(3, 80 / 100.0 * 255);
  _delay(0.7);
  move(3, 0);

  move(1, 75 / 100.0 * 255);
  _delay(3);
  move(1, 0);

  rgbled_7.setColor(0,255,0,0);
  rgbled_7.show();
  _delay(3);
  rgbled_7.setColor(0,0,0,0);
  rgbled_7.show();

  move(2, 75 / 100.0 * 255);
  _delay(3);
  move(2, 0);

  move(4, 80 / 100.0 * 255);
  _delay(0.7);
  move(4, 0);

  move(1, 80 / 100.0 * 255);
  _delay(10);
  move(1, 0);

  move(3, 55 / 100.0 * 255);
  _delay(0.5);
  move(3, 0);

  move(1, 75 / 100.0 * 255);
  _delay(4);
  move(1, 0);

  move(4, 80 / 100.0 * 255);
  _delay(0.55);
  move(4, 0);

  rgbled_7.setColor(0,255,0,0);
  rgbled_7.show();
  _delay(3);
  rgbled_7.setColor(0,0,0,0);
  rgbled_7.show();

  move(3, 80 / 100.0 * 255);
  _delay(0.7);
  move(3, 0);

  move(1, 80 / 100.0 * 255);
  _delay(15);
  move(1, 0);

  move(3, 80 / 100.0 * 255);
  _delay(0.45);
  move(3, 0);

  move(1, 90 / 100.0 * 255);
  _delay(10);
  move(1, 0);

}

void _loop() {
}

void loop() {
  _loop();
}

