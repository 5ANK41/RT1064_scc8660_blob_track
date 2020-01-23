#include "headfile.h"
#include "servo.h"
//设置占空比为 百分之 (1000/TIMER1_PWM_DUTY_MAX*100)
void pwm_test(int16 Left_front_value,int16 Right_front_value,int16 Left_rear_value,int16 Right_rear_value)
{
  if(0<=Left_front_value) //电机1   正转 
    {
      pwm_duty(MOTOR1_A, Left_front_value);
      pwm_duty(MOTOR1_B, 0);
    }
    else                //电机1   反转
    {
      pwm_duty(MOTOR1_A, 0);
      pwm_duty(MOTOR1_B, -Left_front_value);
    }
    
    if(0<=Right_front_value) //电机2   正转
    {
      pwm_duty(MOTOR2_A, Right_front_value);
      pwm_duty(MOTOR2_B, 0);
    }
    else                //电机2   反转
    {
      pwm_duty(MOTOR2_A, 0);
      pwm_duty(MOTOR2_B, -Right_front_value);
    }
    
    if(0<=Left_rear_value) //电机3   正转
    {
      pwm_duty(MOTOR3_A, Left_rear_value);
      pwm_duty(MOTOR3_B, 0);
    }
    else                //电机3   反转
    {
      pwm_duty(MOTOR3_A, 0);
      pwm_duty(MOTOR3_B, -Left_rear_value);
    }
    
    if(0<=Right_rear_value) //电机4   正转
    {
      pwm_duty(MOTOR4_A, Right_rear_value);
      pwm_duty(MOTOR4_B, 0);
    }
    else                //电机4   反转
    {
      pwm_duty(MOTOR4_A, 0);
      pwm_duty(MOTOR4_B, -Right_rear_value);
    }
}

void Left_front_pwm_set1(int16 Left_front_value)
{
  if(0<=Left_front_value) //电机1   正转 
    {
      pwm_duty(MOTOR1_A, Left_front_value);
      pwm_duty(MOTOR1_B, 0);
    }
    else                //电机1   反转
    {
      pwm_duty(MOTOR1_A, 0);
      pwm_duty(MOTOR1_B, -Left_front_value);
    }
}
void Right_front_pwm_set1(int16 Right_front_value)
{
  if(0<=Right_front_value) //电机2   正转
    {
      pwm_duty(MOTOR2_A, Right_front_value);
      pwm_duty(MOTOR2_B, 0);
    }
    else                //电机2   反转
    {
      pwm_duty(MOTOR2_A, 0);
      pwm_duty(MOTOR2_B, -Right_front_value);
    }
}
void Left_rear_pwm_set1(int16 Left_rear_value)
{
  if(0<=Left_rear_value) //电机3   正转
    {
      pwm_duty(MOTOR3_A, Left_rear_value);
      pwm_duty(MOTOR3_B, 0);
    }
    else                //电机3   反转
    {
      pwm_duty(MOTOR3_A, 0);
      pwm_duty(MOTOR3_B, -Left_rear_value);
    }
}
void Right_rear_pwm_set1(int16 Right_rear_value)
{
  if(0<=Right_rear_value) //电机4   正转
    {
      pwm_duty(MOTOR4_A, Right_rear_value);
      pwm_duty(MOTOR4_B, 0);
    }
    else                //电机4   反转
    {
      pwm_duty(MOTOR4_A, 0);
      pwm_duty(MOTOR4_B, -Right_rear_value);
    }
}

void Left_front_pwm_set2(int16 Left_front_value)
{
  if(0<=-Left_front_value) //电机4   正转
    {
      pwm_duty(MOTOR4_A, -Left_front_value);
      pwm_duty(MOTOR4_B, 0);
    }
    else                //电机4   反转
    {
      pwm_duty(MOTOR4_A, 0);
      pwm_duty(MOTOR4_B, Left_front_value);
    }
}
void Right_front_pwm_set2(int16 Right_front_value)
{
  if(0<=-Right_front_value) //电机3   正转
    {
      pwm_duty(MOTOR3_A, -Right_front_value);
      pwm_duty(MOTOR3_B, 0);
    }
    else                //电机3   反转
    {
      pwm_duty(MOTOR3_A, 0);
      pwm_duty(MOTOR3_B, Right_front_value);
    }
}
void Left_rear_pwm_set2(int16 Left_rear_value)
{
  if(0<=-Left_rear_value) //电机2   正转
    {
      pwm_duty(MOTOR2_A, -Left_rear_value);
      pwm_duty(MOTOR2_B, 0);
    }
    else                //电机2   反转
    {
      pwm_duty(MOTOR2_A, 0);
      pwm_duty(MOTOR2_B, Left_rear_value);
    }
}
void Right_rear_pwm_set2(int16 Right_rear_value)
{
  if(0<=-Right_rear_value) //电机1   正转 
    {
      pwm_duty(MOTOR1_A, -Right_rear_value);
      pwm_duty(MOTOR1_B, 0);
    }
    else                //电机1   反转
    {
      pwm_duty(MOTOR1_A, 0);
      pwm_duty(MOTOR1_B, Right_rear_value);
    }
}