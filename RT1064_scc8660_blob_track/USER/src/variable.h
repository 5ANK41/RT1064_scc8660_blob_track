#pragma once
#include "common.h"
#include "picture.h"



//�ٶ�
extern int16 basic_speed;                      //�ٶ�

extern int16 Left_front_speed;                //��ǰ���ٶ�
extern int16 Right_front_speed;               //��ǰ���ٶ�
extern int16 Left_rear_speed;                 //������ٶ�
extern int16 Right_rear_speed;                //�Һ����ٶ�
extern int16 average_speed;                    //ƽ���ٶ�

extern int16 Left_front_goalspeed;            //��ǰ��Ŀ���ٶ�
extern int16 Right_front_goalspeed;           //��ǰ��Ŀ���ٶ�
extern int16 Left_rear_goalspeed;             //�����Ŀ���ٶ�
extern int16 Right_rear_goalspeed;            //�Һ���Ŀ���ٶ�




//extern blob blobs[240];
//extern line lines[120];
extern uint16 beacon_x;
extern uint16 beacon_y;
extern uint16 pix_num;
extern uint16 img_show[120][160];
extern uint8 result[120][160];

extern int L,A,B;
extern int LL,LM,AL,AM,BL,BM,CNT;