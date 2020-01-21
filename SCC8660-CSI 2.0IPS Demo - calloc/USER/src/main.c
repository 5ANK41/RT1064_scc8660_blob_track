#include "headfile.h"

int main(void)
{
  MyInit();
  while(1)                               
  {
    if(scc8660_csi_finish_flag)
    {
      //systick_delay_ms(500);
      scc8660_csi_finish_flag = 0;
      RGB2LAB();
      find_blobs();
      ips200_displayimage8660_zoom(img_show[0],160,120,160,120);
    }
    BlobShow();
    //ThresholdCtl();
    //ThresholdShow();
  }
}





