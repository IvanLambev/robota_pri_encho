// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

const int joystickX1 = A3;
const int joystickY1 = A2;
const int joystickX2 = A6;


RH_ASK driver;
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

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

}

void loop()
{
  int joystickValX1 = analogRead(joystickX1) / 10;
  int joystickValY1 = analogRead(joystickY1) / 10;
  int joystickValX2 = analogRead(joystickX2) / 10;

  // Check joystick values and send corresponding message
  if (joystickValX1 == 102) { // Joystick pushed forward
    driver.send((uint8_t *)"Forward", 7);
  } else if (joystickValX1 == 0) { // Joystick pulled backward
    driver.send((uint8_t *)"Backward", 8);
  } else if (joystickValY1 == 102) { // Joystick pushed to the right
    driver.send((uint8_t *)"Right", 5);
  } else if (joystickValY1 == 0) { // Joystick pushed to the left
    driver.send((uint8_t *)"Left", 4);
  } else { // Joystick in center position
    driver.send((uint8_t *)"Stop", 4);
  }
  
  driver.waitPacketSent();

  //delay(100);
}