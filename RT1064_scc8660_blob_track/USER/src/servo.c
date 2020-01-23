#include "headfile.h"
#include "servo.h"
//����ռ�ձ�Ϊ �ٷ�֮ (1000/TIMER1_PWM_DUTY_MAX*100)
void pwm_test(int16 Left_front_value,int16 Right_front_value,int16 Left_rear_value,int16 Right_rear_value)
{
  if(0<=Left_front_value) //���1   ��ת 
    {
      pwm_duty(MOTOR1_A, Left_front_value);
      pwm_duty(MOTOR1_B, 0);
    }
    else                //���1   ��ת
    {
      pwm_duty(MOTOR1_A, 0);
      pwm_duty(MOTOR1_B, -Left_front_value);
    }
    
    if(0<=Right_front_value) //���2   ��ת
    {
      pwm_duty(MOTOR2_A, Right_front_value);
      pwm_duty(MOTOR2_B, 0);
    }
    else                //���2   ��ת
    {
      pwm_duty(MOTOR2_A, 0);
      pwm_duty(MOTOR2_B, -Right_front_value);
    }
    
    if(0<=Left_rear_value) //���3   ��ת
    {
      pwm_duty(MOTOR3_A, Left_rear_value);
      pwm_duty(MOTOR3_B, 0);
    }
    else                //���3   ��ת
    {
      pwm_duty(MOTOR3_A, 0);
      pwm_duty(MOTOR3_B, -Left_rear_value);
    }
    
    if(0<=Right_rear_value) //���4   ��ת
    {
      pwm_duty(MOTOR4_A, Right_rear_value);
      pwm_duty(MOTOR4_B, 0);
    }
    else                //���4   ��ת
    {
      pwm_duty(MOTOR4_A, 0);
      pwm_duty(MOTOR4_B, -Right_rear_value);
    }
}

void Left_front_pwm_set1(int16 Left_front_value)
{
  if(0<=Left_front_value) //���1   ��ת 
    {
      pwm_duty(MOTOR1_A, Left_front_value);
      pwm_duty(MOTOR1_B, 0);
    }
    else                //���1   ��ת
    {
      pwm_duty(MOTOR1_A, 0);
      pwm_duty(MOTOR1_B, -Left_front_value);
    }
}
void Right_front_pwm_set1(int16 Right_front_value)
{
  if(0<=Right_front_value) //���2   ��ת
    {
      pwm_duty(MOTOR2_A, Right_front_value);
      pwm_duty(MOTOR2_B, 0);
    }
    else                //���2   ��ת
    {
      pwm_duty(MOTOR2_A, 0);
      pwm_duty(MOTOR2_B, -Right_front_value);
    }
}
void Left_rear_pwm_set1(int16 Left_rear_value)
{
  if(0<=Left_rear_value) //���3   ��ת
    {
      pwm_duty(MOTOR3_A, Left_rear_value);
      pwm_duty(MOTOR3_B, 0);
    }
    else                //���3   ��ת
    {
      pwm_duty(MOTOR3_A, 0);
      pwm_duty(MOTOR3_B, -Left_rear_value);
    }
}
void Right_rear_pwm_set1(int16 Right_rear_value)
{
  if(0<=Right_rear_value) //���4   ��ת
    {
      pwm_duty(MOTOR4_A, Right_rear_value);
      pwm_duty(MOTOR4_B, 0);
    }
    else                //���4   ��ת
    {
      pwm_duty(MOTOR4_A, 0);
      pwm_duty(MOTOR4_B, -Right_rear_value);
    }
}

void Left_front_pwm_set2(int16 Left_front_value)
{
  if(0<=-Left_front_value) //���4   ��ת
    {
      pwm_duty(MOTOR4_A, -Left_front_value);
      pwm_duty(MOTOR4_B, 0);
    }
    else                //���4   ��ת
    {
      pwm_duty(MOTOR4_A, 0);
      pwm_duty(MOTOR4_B, Left_front_value);
    }
}
void Right_front_pwm_set2(int16 Right_front_value)
{
  if(0<=-Right_front_value) //���3   ��ת
    {
      pwm_duty(MOTOR3_A, -Right_front_value);
      pwm_duty(MOTOR3_B, 0);
    }
    else                //���3   ��ת
    {
      pwm_duty(MOTOR3_A, 0);
      pwm_duty(MOTOR3_B, Right_front_value);
    }
}
void Left_rear_pwm_set2(int16 Left_rear_value)
{
  if(0<=-Left_rear_value) //���2   ��ת
    {
      pwm_duty(MOTOR2_A, -Left_rear_value);
      pwm_duty(MOTOR2_B, 0);
    }
    else                //���2   ��ת
    {
      pwm_duty(MOTOR2_A, 0);
      pwm_duty(MOTOR2_B, Left_rear_value);
    }
}
void Right_rear_pwm_set2(int16 Right_rear_value)
{
  if(0<=-Right_rear_value) //���1   ��ת 
    {
      pwm_duty(MOTOR1_A, -Right_rear_value);
      pwm_duty(MOTOR1_B, 0);
    }
    else                //���1   ��ת
    {
      pwm_duty(MOTOR1_A, 0);
      pwm_duty(MOTOR1_B, Right_rear_value);
    }
}