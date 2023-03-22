// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver;
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

const int enableBridge1 = 2;
const int MotorForward1 = 3;
const int MotorReverse1 = 5;
const int MotorForward2 = 6;
const int MotorReverse2 = 7;

int Power  = 180;

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif

driver.init();

  pinMode(MotorForward1, OUTPUT);
  pinMode(MotorReverse1, OUTPUT);
  pinMode(MotorForward2, OUTPUT);
  pinMode(MotorReverse2, OUTPUT);

  pinMode(enableBridge1, OUTPUT);
  digitalWrite(enableBridge1, HIGH);


}

void loop()
{

  int x1Val = 0;
  int y1Val = 0;
  int x2Val = 0;

  uint8_t buf[100];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) 
  {
    buf[buflen] = 0;
    Serial.println((char*)buf);

    if (strstr((char*)buf, "Forward")) 
    {
      moveForward();
    } 
    else if (strstr((char*)buf, "Backward")) 
    {
      moveBackward();
    } 
    else if (strstr((char*)buf, "Left")) 
    {
      moveLeft();
    } 
    else if (strstr((char*)buf, "Right")) 
    {
      moveRight();
    } 
    else if (strstr((char*)buf, "Stop")) 
    {
      stopMotor();
    }
  }
}


void moveForward() {
  analogWrite(MotorForward1, 0);
  analogWrite(MotorForward2, Power);
  analogWrite(MotorReverse1, Power);
  analogWrite(MotorReverse2, 0);
}

void moveBackward() {
  analogWrite(MotorForward1, Power);
  analogWrite(MotorForward2, 0);
  analogWrite(MotorReverse1, 0);
  analogWrite(MotorReverse2, Power);
}

void moveLeft() {
  analogWrite(MotorForward1, Power);
  analogWrite(MotorForward2, Power);
  analogWrite(MotorReverse1, 0);
  analogWrite(MotorReverse2, 0);
}

void moveRight() {
  analogWrite(MotorForward1, 0);
  analogWrite(MotorForward2, 0);
  analogWrite(MotorReverse1, Power);
  analogWrite(MotorReverse2, Power);
}

void stopMotor() {
  analogWrite(MotorForward1, 0);
  analogWrite(MotorForward2, 0);
  analogWrite(MotorReverse1, 0);
  analogWrite(MotorReverse2, 0);
}
