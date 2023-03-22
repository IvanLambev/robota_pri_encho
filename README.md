# Mini Tank Robot README

This document provides information on how to operate and set up the Mini Tank Robot. The robot is designed to move on two motors, with an Arduino Uno controlling the tank, and an Arduino Nano acting as the controller.

![alt text](https://github.com/IvanLambev/robota_pri_encho/blob/main/snimka%20na%20robota.jpg)

## Hardware Setup

The Mini Tank Robot consists of the following components:

- 2 Motors (1 on each side)
- Arduino Uno
- SN754410NE H-Bridge
- Arduino Nano
- 2 Joysticks
- K2159 433MHz Transmitter and Receiver modules

To set up the Mini Tank Robot, follow these steps:

1. Connect the motors to the SN754410NE H-Bridge. The H-Bridge will allow the motors to be controlled in both directions.
2. Connect the SN754410NE H-Bridge to the Arduino Uno. The H-Bridge should be connected to the digital pins on the Arduino Uno.
3. Connect the two joysticks to the Arduino Nano. The joysticks will provide the user input to control the tank.
4. Connect the K2159 433MHz Transmitter and Receiver modules to both the Arduino Uno and Nano. These modules will allow the Arduino Nano to send data to the Arduino Uno wirelessly.

Once all the components are connected, you can power on the Mini Tank Robot and begin using it.

## Software Setup

The software for the Mini Tank Robot is split into two parts: the Arduino code for the Arduino Uno and the Arduino code for the Arduino Nano.

### Arduino Uno Code

The code for the Arduino Uno can be found in the `[Arduino Uno code](https://github.com/IvanLambev/robota_pri_encho/blob/main/receiver/receiver.ino)` file. This code will read the data sent from the Arduino Nano and control the motors accordingly.

### Arduino Nano Code

The code for the Arduino Nano can be found in the [Arduino_Nano.ino](https://github.com/IvanLambev/robota_pri_encho/blob/main/transmiter/transmiter.ino). This code will read the analog output from the joysticks and send the data to the Arduino Uno using the K2159 433MHz Transmitter and Receiver modules.

Upload the code to the respective Arduinos using the Arduino IDE.

## Usage

To use the Mini Tank Robot, power it on and use the joysticks to control its movement. The left joystick controls the left motor, and the right joystick controls the right motor. Moving the joysticks forward will move the tank forward, moving them back will move the tank backward, and moving them to the sides will turn the tank.

## Conclusion

The Mini Tank Robot is a fun and interactive way to learn about robotics and programming. With its two motors and wireless controller, it offers a great introduction to basic robotics concepts. Enjoy!
