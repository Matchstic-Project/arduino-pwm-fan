# Arduino PWM fan
_PC 4-pin fan control via PWM signal_

## What is this?

This is a very small project that uses an Arduino to control the speed of a 4-pin PC fan. This then can be used in many applications, such as embedding within a 3D-printed solder extractor like this: [https://www.thingiverse.com/thing:69729](https://www.thingiverse.com/thing:69729)

## Required components

To make use of this, you will need:

- Arduino Uno
- 3- or 4-pin PC fan
- [optional] Potentiometer (e.g., [this one](https://thepihut.com/products/panel-mount-10k-potentiometer-breadboard-friendly))

If you only have a 3-pin fan, be aware that your fan will always run at maximum speed. Additionally, if you do not opt for using a potentiometer (for controlling fan speed), you will need to manually specify the fan speed in code.

## Hardware setup

Wiring is pretty simple:

- Connect your fan to a 12V power supply on its VIN and GND lines.
- Connect the fan's PWM signal input to digital 9 on the Arduino

[optional]
- Solder on wires to the potentiometer pins if required
- Connect its power pins to the 5V output pin and a GND pin on the Arduino
- The signal wire goes to analog 2

## Licensing

This project is licensed under the [Creative Commons BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/). 

It makes uses of code available from: [https://create.arduino.cc/projecthub/tylerpeppy/25-khz-4-pin-pwm-fan-control-with-arduino-uno-3005a1](https://create.arduino.cc/projecthub/tylerpeppy/25-khz-4-pin-pwm-fan-control-with-arduino-uno-3005a1)

I also ask that you also don't make commerical derivatives of it.

