#include "headfile.h"

static int LabTable[1024];
static int GamaTable1[32];
static int GamaTable2[64];
void MyInit()
{
  DisableGlobalIRQ();
  board_init();
  systick_delay_ms(100);
  scc8660_csi_init();
  ips200_init();
  EnableGlobalIRQ(0);
  
  //uart_init(USART_1,9600,UART1_TX_B12,UART1_RX_B13);
  //NVIC_SetPriority(LPUART1_IRQn,15);         //设置串口中断优先级 范围0-15 越小优先级越高
  //uart_rx_irq(USART_1,1);
  CreateTable();
}

void ThresholdCtl()
{
  uint8 dat;
  uart_query(USART_1,&dat);
  if(dat == 1)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      LL += 1;
    }
  }
  else if(dat == 2)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      LM += 1;
    }
  }
  else if(dat == 3)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      AL += 1;
    }
  }
  else if(dat == 4)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      AM += 1;
    }
  }
  else if(dat == 5)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      BL += 1;
    }
  }
  else if(dat == 6)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      BM += 1;
    }
  }
  else if(dat == 7)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      LL -= 1;
    }
  }
  else if(dat == 8)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      LM -= 1;
    }
  }
  else if(dat == 9)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      AL -= 1;
    }
  }
  else if(dat == 10)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      AM -= 1;
    }
  }
  else if(dat == 11)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      BL -= 1;
    }
  }
  else if(dat == 12)
  {
    CNT ++;
    if(CNT == 5)
    {
      CNT = 0;
      BM -= 1;
    }
  }
}
void ThresholdShow()
{
  ips200_showuint8(0,0,LL);
  ips200_showuint8(0,2,LM);
  ips200_showuint8(0,4,AL);
  ips200_showuint8(0,6,AM);
  ips200_showuint8(0,8,BL);
  ips200_showuint8(0,10,BM);
}

void BlobShow()
{
  ips200_showint16(0,8,beacon_x);
  ips200_showint16(0,10,beacon_y);
  ips200_showint16(0,12,pix_num);
  //ips200_showint16(0,8,blobs[0].x);
  //ips200_showint16(0,10,blobs[0].y);
  //ips200_showint16(0,12,blobs[0].pixels);
  //ips200_showint16(0,14,blobs[0].cnt);
  
  
}

void CreateTable()
{
  for (int I = 0; I < 1024; I++)
  {
    if (I > 9)
      LabTable[I] = (int)(pow((float)I / 1024, 1.0F / 3.0F) * 1024 );
    else
      LabTable[I] = (int)(7.787F * I + 141.2 );
  }
  for (int J = 0; J < 32; J++)
  {
    float x = J/32.0F;
    x = x>0.04045?pow((x+0.055f)/1.055f,2.4f):x/12.92;
    GamaTable1[J] = (int)(x*1024);
  }
  for (int K = 0; K < 64; K++)
  {
    float y = K/64.0F;
    y = y>0.04045?pow((y+0.055f)/1.055f,2.4f):y/12.92;
    GamaTable2[K] = (int)(y*1024);
  }
}

void RGB2LAB()
{
  int r = 0,g = 0,b = 0,x = 0,y = 0,z = 0;
  int i,j;
  for(i=0;i<120;i++)
  {
    for(j=0;j<160;j++)
    {
      img_show[i][j]=scc8660_csi_image[i][j];
      r=(img_show[i][j]&0Xf800)>>11;
      g=(img_show[i][j]&0X07e0)>>5;
      b=(img_show[i][j]&0X001f);
      x=(455026*GamaTable1[r]+394489*GamaTable2[g]+199046*GamaTable1[b])>>20;
      y=(223002*GamaTable1[r]+749900*GamaTable2[g]+75675*GamaTable1[b])>>20;
      z=(18619*GamaTable1[r]+114786*GamaTable2[g]+915097*GamaTable1[b])>>20;
      L = y > 9 ? (116 * LabTable[y] - 16384)>> 10: (903 * LabTable[y])>> 10;
      A = (500 * (LabTable[x] - LabTable[y]))>> 10;
      B = (200 * (LabTable[y] - LabTable[z]))>> 10;
      if((L>LL&&L<LM)&&(A>AL&&A<AM)&&(B>BL&&B<BM))
      {
        //img_show[i][j] = 0xE007;
        result[i][j]=1;
      }
      else
        result[i][j]=0;
    }
  }
}

