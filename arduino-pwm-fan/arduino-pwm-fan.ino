/*
 * Arduino PWM fan control w/ potentiometer input
 * ==============================================
 * 
 * This sketch is derived from:
 * https://create.arduino.cc/projecthub/tylerpeppy/25-khz-4-pin-pwm-fan-control-with-arduino-uno-3005a1
 * 
 * It allows you to control a PWM 4-pin PC fan via your Arduino Uno.
 * 
 * The general idea is to make use of the 10 PWM phase-correct mode
 * on timer 1 OCR1A, available via pin 9. This allows for control
 * over the speed of the fan via setting a value in the range
 * 0 - 100.
 * 
 * Furthermore, input from a potentiometer hooked up to analog pin
 * 2 is used to drive the fan speed. If you do not have a "pot", you
 * should hardcode your expected speed by setting FORCE_SPEED to >= 0.
 * 
 * Debugging notes:
 * 
 * Q1. Fan doesn't spin up?
 * A1. Make sure you are using a 12V supply to your fan, and make sure 
 *     that the PWM_FREQ_HZ variable matches the specification for your
 *     fan model.
 *     
 * Q2. Compiler issues complaining about OCR1A etc.
 * A2. This sketch is specific to the Arduino Uno. You should find the
 *     corresponding names for your board.
 * 
 * Created by Matt Clarke (Matchstic), 2021.
 */

const byte POT_PIN = 2;
const byte OC1A_PIN = 9;

// Adjust this value to set the frequency to your fan's needs
const word PWM_FREQ_HZ = 20000;
const word TCNT1_TOP = 16000000 / (2 * PWM_FREQ_HZ);

const int FORCE_SPEED = -1;

void setup() {
  
  pinMode(OC1A_PIN, OUTPUT);

  // Clear Timer1 control and count registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  
  TCCR1A |= (1 << COM1A1) | (1 << WGM11);
  TCCR1B |= (1 << WGM13) | (1 << CS10);
  ICR1 = TCNT1_TOP;
}

void loop() {
    const int rotation = analogRead(POT_PIN);

    const int duty = ((double)rotation / 1023.0) * 100.0;
    setPwmDuty(FORCE_SPEED > -1 ? FORCE_SPEED : duty);
    
    delay(20);
}

/**
 * Sets the speed of the fan
 * 
 * @param duty A value between 0 and 100
 */
void setPwmDuty(byte duty) {
  OCR1A = (word)(duty * TCNT1_TOP) / 100;
}
