#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

#include <Arduino.h>

#define SERVO_PWM_PIN 25
#define MOSFET_GATE_1 33
#define MOSFET_GATE_2 32
#define INPUT_FROM_POTENTIOMETER 34

void turn_0_deg();
void turn_0_deg_2();

void turn_90_deg();
void turn_90_deg_2();

void turn_180_deg();
void turn_180_deg_2();

void pwm_manual();
void pwm_manual_2();

void analogWritePWM();

void wayangHandServoMechanicsTest();


void degreeSpin(int degree);
void analogReadValueToDegree();


#endif //MAINHEADER_HPP