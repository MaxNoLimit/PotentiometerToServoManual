#include "mainheader.hpp"

int angle_0 = 500;
int angle_90 = 1500;
int angle_180 = 2500;

int amount_of_wave = 10;

int max_period = 20000;

void pwm_manual()
{
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_0_deg();
    }
    Serial.println("0 deg");
    delay(100);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_90_deg();
    }
    Serial.println("90 deg");
    delay(100);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_180_deg();
    }
    Serial.println("180 deg");
    delay(100);
}

void pwm_manual_2()
{
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_0_deg_2();
    }
    Serial.println("0 deg");
    delay(100);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_90_deg_2();
    }
    Serial.println("90 deg");
    delay(100);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_180_deg_2();
    }
    Serial.println("180 deg");
    delay(100);
}

void analogWritePWM()
{
    analogWrite(SERVO_PWM_PIN, 64);
    delay(1000);
    analogWrite(SERVO_PWM_PIN, 0);
    delay(1000);
}

void turn_0_deg()
{
    digitalWrite(SERVO_PWM_PIN, HIGH);
    Serial.println("PWM 1");
    delayMicroseconds(angle_0);
    digitalWrite(SERVO_PWM_PIN, LOW);
    Serial.println("PWM 0");
    delayMicroseconds(max_period - angle_0);
}

void turn_90_deg()
{
    digitalWrite(SERVO_PWM_PIN, HIGH);
    Serial.println("PWM 1");
    delayMicroseconds(angle_90);
    digitalWrite(SERVO_PWM_PIN, LOW);
    Serial.println("PWM 0");
    delayMicroseconds(max_period - angle_90);
}

void turn_180_deg()
{
    digitalWrite(SERVO_PWM_PIN, HIGH);
    Serial.println("PWM 1");
    delayMicroseconds(angle_180);
    digitalWrite(SERVO_PWM_PIN, LOW);
    Serial.println("PWM 0");
    delayMicroseconds(max_period - angle_180);
}

void turn_0_deg_2()
{
    analogWrite(SERVO_PWM_PIN, 6);
    delay(angle_0);
    analogWrite(SERVO_PWM_PIN, 0);
    delay(max_period - angle_0);
}

void turn_90_deg_2()
{
    analogWrite(SERVO_PWM_PIN, 19);
    delay(angle_90);
    analogWrite(SERVO_PWM_PIN, 0);
    delay(max_period - angle_90);
}

void turn_180_deg_2()
{
    analogWrite(SERVO_PWM_PIN, 32);
    delay(angle_180);
    analogWrite(SERVO_PWM_PIN, 0);
    delay(max_period - angle_180);
}

void wayangHandServoMechanicsTest()
{
    digitalWrite(MOSFET_GATE_1, HIGH);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_180_deg();
    }
    digitalWrite(MOSFET_GATE_1, LOW);

    // delay(1000);

    digitalWrite(MOSFET_GATE_2, HIGH);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_180_deg();
    }
    digitalWrite(MOSFET_GATE_2, LOW);

    // delay(1000);

    digitalWrite(MOSFET_GATE_1, HIGH);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_0_deg();
    }
    digitalWrite(MOSFET_GATE_1, LOW);

    // delay(1000);

    digitalWrite(MOSFET_GATE_2, HIGH);
    for (int i = 0; i < amount_of_wave; i++)
    {
        turn_0_deg();
    }
    digitalWrite(MOSFET_GATE_2, LOW);

    // delay(1000);
}

void degreeSpin(int degree)
{
    int tValue = 2000 * degree / 180;
    int widthHigh = tValue + 500;
    int widthLow = 20000 - widthHigh;

    for (int i = 0; i < amount_of_wave; i++)
    {
        digitalWrite(SERVO_PWM_PIN, HIGH);
        delayMicroseconds(widthHigh);
        digitalWrite(SERVO_PWM_PIN, LOW);
        delayMicroseconds(widthLow);
    }
}

void analogReadValueToDegree()
{
    int sensorValue = analogRead(INPUT_FROM_POTENTIOMETER);
    int degree = map(sensorValue, 0, 4095, 0, 180);
    degreeSpin(degree);
}