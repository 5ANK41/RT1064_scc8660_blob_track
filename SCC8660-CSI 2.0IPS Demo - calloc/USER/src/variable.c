#include "headfile.h"


//速度
int16 basic_speed = 0;                      //速度

int16 Left_front_speed = 0;                //左前轮速度
int16 Right_front_speed = 0;               //右前轮速度
int16 Left_rear_speed = 0;                 //左后轮速度
int16 Right_rear_speed = 0;                //右后轮速度
int16 average_speed = 0;                    //平均速度

int16 Left_front_goalspeed = 0;            //左前轮目标速度
int16 Right_front_goalspeed = 0;           //右前轮目标速度
int16 Left_rear_goalspeed = 0;             //左后轮目标速度
int16 Right_rear_goalspeed = 0;            //右后轮目标速度

















uint16 img_show[120][160]={0};
uint8 result[120][160]={0};
//line lines[120];
//AT_SDRAM_SECTION_ALIGN(blob blobs[240],64);
uint16 beacon_x = 0;
uint16 beacon_y = 0;
uint16 pix_num = 0;
int L = 0,A = 0,B = 0;
int LL = 30,LM = 100,AL = 15,AM = 127,BL = 15,BM = 127,CNT = 0;