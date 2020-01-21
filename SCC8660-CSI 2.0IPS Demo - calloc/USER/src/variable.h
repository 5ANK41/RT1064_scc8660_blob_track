#pragma once
#include "common.h"
#include "picture.h"



//速度
extern int16 basic_speed;                      //速度

extern int16 Left_front_speed;                //左前轮速度
extern int16 Right_front_speed;               //右前轮速度
extern int16 Left_rear_speed;                 //左后轮速度
extern int16 Right_rear_speed;                //右后轮速度
extern int16 average_speed;                    //平均速度

extern int16 Left_front_goalspeed;            //左前轮目标速度
extern int16 Right_front_goalspeed;           //右前轮目标速度
extern int16 Left_rear_goalspeed;             //左后轮目标速度
extern int16 Right_rear_goalspeed;            //右后轮目标速度




//extern blob blobs[240];
//extern line lines[120];
extern uint16 beacon_x;
extern uint16 beacon_y;
extern uint16 pix_num;
extern uint16 img_show[120][160];
extern uint8 result[120][160];

extern int L,A,B;
extern int LL,LM,AL,AM,BL,BM,CNT;