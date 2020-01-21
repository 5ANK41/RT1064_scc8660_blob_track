/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		systick
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.24
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 ********************************************************************************************************************/
 
 
 
 
#ifndef _zf_systick_h
#define _zf_systick_h

#include "common.h"
#include "fsl_lpspi.h"


#define SYSTICK_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_CpuClk)//����SYSTICK��ʱ��������ʱ��



void systick_delay(uint32 time);
void systick_timing(uint32 time);
void systick_start(void);
uint32 systick_getval(void);


//------------------------------------���º궨������SYSTICK��ʱ------------------------------------
void systick_delay_ms(uint32 ms);                                                                   //���뼶systick��ʱ���� ���ڵδ�ʱ�����ֻ��24λ������ú���ʵ�֣�������ʱʱ�䷶Χ�Ͽ�
#define systick_delay_us(time)      systick_delay(USEC_TO_COUNT(time, SYSTICK_SOURCE_CLOCK))        //����SYSTICK��ʱʱ��  ��λus   ��Χ0  -  16777215(0xffffff)/(kCLOCK_CpuClk*1000)ms   ��Ƶ500M �����ʱʱ���ԼΪ33ms
#define systick_delay_ns(time)      systick_delay(USEC_TO_COUNT(time, SYSTICK_SOURCE_CLOCK/1000))   //����SYSTICK��ʱʱ��  ��λns   ��Χ0  -  16777215(0xffffff)*1000/(kCLOCK_CpuClk)ns   ��Ƶ500M �����ʱʱ���ԼΪ33ms
    
    
//------------------------------------���º궨������SYSTICK��ʱ------------------------------------  
#define systick_timing_ms(time)     systick_timing(MSEC_TO_COUNT(time, SYSTICK_SOURCE_CLOCK))       //����SYSTICK��ʱʱ��  ��λms   ��Χ0  -  16777215(0xffffff)/(kCLOCK_CpuClk*1000)ms   ��Ƶ500M ���ʱʱ���ԼΪ33ms
#define systick_timing_us(time)     systick_timing(USEC_TO_COUNT(time, SYSTICK_SOURCE_CLOCK))       //����SYSTICK��ʱʱ��  ��λus   ��Χ0  -  16777215(0xffffff)/(kCLOCK_CpuClk)us        ��Ƶ500M ���ʱʱ���ԼΪ33ms
#define systick_timing_ns(time)     systick_timing(USEC_TO_COUNT(time, SYSTICK_SOURCE_CLOCK/1000))  //����SYSTICK��ʱʱ��  ��λns   ��Χ0  -  16777215(0xffffff)*1000/(kCLOCK_CpuClk)ns   ��Ƶ500M ���ʱʱ���ԼΪ33ms


//------------------------------------���º궨�����ڻ�ȡ��ǰSYSTICKʱ��------------------------------------
#define systick_getval_ms()         COUNT_TO_MSEC(systick_getval(),SYSTICK_SOURCE_CLOCK)            //��ȡSYSTICK��ǰ��ʱʱ��  ��λms
#define systick_getval_us()         COUNT_TO_USEC(systick_getval(),SYSTICK_SOURCE_CLOCK)            //��ȡSYSTICK��ǰ��ʱʱ��  ��λus
#define systick_getval_ns()         COUNT_TO_USEC(systick_getval()*1000,SYSTICK_SOURCE_CLOCK)       //��ȡSYSTICK��ǰ��ʱʱ��  ��λns

#endif