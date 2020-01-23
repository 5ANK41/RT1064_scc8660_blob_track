#pragma once

#include "zf_pwm.h"

#define MOTOR1_A   PWM1_MODULE3_CHB_D1   //定义1电机正转PWM引脚
#define MOTOR1_B   PWM1_MODULE3_CHA_D0   //定义1电机反转PWM引脚

#define MOTOR2_A   PWM2_MODULE3_CHB_D3   //定义2电机正转PWM引脚
#define MOTOR2_B   PWM2_MODULE3_CHA_D2   //定义2电机反转PWM引脚

#define MOTOR3_A   PWM1_MODULE0_CHA_D12  //定义3电机正转PWM引脚
#define MOTOR3_B   PWM1_MODULE0_CHB_D13  //定义3电机反转PWM引脚

#define MOTOR4_A   PWM1_MODULE1_CHA_D14  //定义4电机正转PWM引脚
#define MOTOR4_B   PWM1_MODULE1_CHB_D15  //定义4电机反转PWM引脚


void pwm_test(int16 Left_front_value,int16 Right_front_value,int16 Left_rear_value,int16 Right_rear_value);

void Left_front_pwm_set1(int16 Left_front_value);
void Right_front_pwm_set1(int16 Right_front_value);
void Left_rear_pwm_set1(int16 Left_rear_value);
void Right_rear_pwm_set1(int16 Right_rear_value);

void Left_front_pwm_set2(int16 Left_front_value);
void Right_front_pwm_set2(int16 Right_front_value);
void Left_rear_pwm_set2(int16 Left_rear_value);
void Right_rear_pwm_set2(int16 Right_rear_value);