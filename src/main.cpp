#include "mainheader.hpp"

// int angle_0 = 1000;
// int angle_90 = 1500;
// int angle_180 = 2000;



void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SERVO_PWM_PIN, OUTPUT);
  pinMode(MOSFET_GATE_1, OUTPUT);
  pinMode(MOSFET_GATE_2, OUTPUT);
  pinMode(INPUT_FROM_POTENTIOMETER, INPUT);

  digitalWrite(MOSFET_GATE_1, HIGH);
  digitalWrite(MOSFET_GATE_2, HIGH);
  for (int i = 0; i < 10; i++)
  {
    turn_90_deg();
  }

  digitalWrite(MOSFET_GATE_1, LOW);
  digitalWrite(MOSFET_GATE_2, LOW);
  delay(1000);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // pwm_manual();
  // pwm_manual_2();
  // wayangHandServoMechanicsTest()
  digitalWrite(MOSFET_GATE_1, HIGH);
  digitalWrite(MOSFET_GATE_2, HIGH);
  analogReadValueToDegree();
  digitalWrite(MOSFET_GATE_1, LOW);
  digitalWrite(MOSFET_GATE_2, LOW);
}

