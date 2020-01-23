#include "headfile.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void desult()
{
  for(int i=1;i<119;i++)
  {
    for(int j=1;j<159;j++)//防止数组越界
    {
      if( (result[i][j] == 1) && ( (result[i][j-1] == 0)&&(result[i][j+1] == 0) ) )
        result[i][j] = 0;
    }
  }
}

int match(team *nowteam,line *lastline,line *lastlines)
{
  int state = 0;
  int lab[40] = {0};
  int min = 0;
  if(lastline->cnt == 0)
    return 0;
  for(int i = 0;i<lastline->cnt;i++)
  {
    if( !(((nowteam->left < lastline->grp[i].left) && (nowteam->right < lastline->grp[i].left)) || ((nowteam->left > lastline->grp[i].right) && (nowteam->right > lastline->grp[i].right))) )
    {
      lab[state] = lastline->grp[i].lable;
      if(state == 0)
      {
        nowteam->lable = lastline->grp[i].lable;
        min = lab[0];
      }
      if(lab[state] < min)
        min = lab[state];
      state += 1;
    }
  }
  nowteam->lable = min;
  if(state == 0)
    return 0;
  else if(state == 1)
    return 1;
  else if(state > 1)
  {
    for(int j = 0;j < nowteam->hight;j++)//
    {
      for(int k = 0;k < lastlines[j].cnt;k++)
      {
        for(int l = 0;l < state;l++)
        {
          if(lastlines[j].grp[k].lable == lab[l])
            lastlines[j].grp[k].lable = min;
        }
      }
    }
    return state;
  }
  return 0;
}

void find_blobs()
{
  desult();
  team now;
  
  //line lines[120];
  //blob blobs[30];
  line *lines=(line*)calloc(120,sizeof(line));       ////111111111111111
  if(lines == NULL)
    ips200_showuint8(250,0,250);
  for(int i = 0;i < 120;i++)
  {
    lines[i].grp=(team*)calloc(40,sizeof(team));     //lines 的malloc   //////////////121212121212121212
    if(lines[i].grp == NULL)
      ips200_showuint8(250,2,250);
    lines[i].cnt = 0;
  }
  beacon_x = 0;
  beacon_y = 0;
  pix_num = 0;
  
  int count1 = 0,count2 = 0;//count1 色块数   count2同一行团数
  desult();
  for(int i = 1;i < 119;i++)
  {
    for(int j = 1;j < 159;j++)
    {
      if(result[i][j] == 1)
      {
        if(result[i][j-1] == 0)
        {
          now.left = j;
          now.hight = i;
        }
        if(result[i][j+1] == 0)
        {
          now.right = j;//团结束 
          now.width = now.right - now.left + 1;
          int state = match(&now,&lines[i-1],lines);
          if(state == 0)
          {
            now.lable = count1;
            count1 += 1;
          }
          lines[i].grp[count2] = now;
          count2 += 1;
          lines[i].cnt += 1;
        }
      }
    }
    lines[i].grp=(team*)realloc(lines[i].grp,count2*sizeof(team));//重新分配每一行的空间
    count2 = 0;
  }
  int *number = (int*)calloc(count1,sizeof(int));             ////////////22222222222222222
  if(number == NULL)
    ips200_showuint8(250,4,250);
  for(int i = 1;i < 119;i++)
  {
    for(int j = 0;j < lines[i].cnt;j++)
    {
      for(int k = 0;k < count1;k++)
      {
        if( k == lines[i].grp[j].lable)
          number[k] += 1;//统计label为k的team个数 
      }
    }
  }
  
  blob *blobs=(blob*)calloc(count1,sizeof(blob));    //blobs的malloc///////////////3333333333333333333333333
  if(blobs == NULL)
    ips200_showuint8(250,6,250);
  for(int i = 0;i < count1;i++)
  {
    if(number[i] != 0)
    {
      blobs[i].grp=(team*)calloc(number[i],sizeof(team)); ////////////////32323232323232
      if(blobs[i].grp == NULL)
        ips200_showuint8(250,8,250);
    }
    
    else
      blobs[i].grp = NULL;
    blobs[i].cnt = 0;
  }
  
  for(int i = 1,dat = 0,count = 0;i < 120;i++)
  {
    //分配给blob
    for(int j = 0;j < lines[i].cnt;j++)
    {
      dat = lines[i].grp[j].lable;
      count = blobs[dat].cnt;
      blobs[dat].grp[count] = lines[i].grp[j];
      blobs[dat].cnt += 1;
    }
  }
  for(int i = 0;i < count1;i++)
  {
    if(blobs[i].grp != NULL)
    {
      blobs[i].pixels = 0;
      blobs[i].x = 0;
      blobs[i].y = 0;
      for(int j = 0;j < blobs[i].cnt;j++)
      {
        blobs[i].pixels += blobs[i].grp[j].width;
        blobs[i].x += blobs[i].grp[j].left + blobs[i].grp[j].width/2;
        blobs[i].y += blobs[i].grp[j].hight;
      }
      blobs[i].x /= blobs[i].cnt;
      blobs[i].y /= blobs[i].cnt;
      if(blobs[i].pixels > pix_num)
      {
        beacon_x = blobs[i].x;
        beacon_y = blobs[i].y;
        pix_num = blobs[i].pixels;
      }
    }
  }
  for(int i = 0;i < 120;i++)
  {
    free(lines[i].grp); 
    lines[i].grp = NULL;   ////12121212
  }
  free(lines);
  lines = NULL;    ////1111111
  
  for(int i = 0;i < count1;i++)
  {
    free(blobs[i].grp);   /////3333333333333333
    blobs[i].grp = NULL;
  }
  free(blobs);   ////////3232323232323
  blobs = NULL;
  free(number);   /////2222222222
  number = NULL;
}

void draw_rtg(int x,int y,int pixels,int width)
{
  int size = (int)( sqrt(pixels) );
  int left = x - size;
  int right = x + size;
  int up = y - size;
  int down = y + size;
  for(int i = left - width;i <= right + width;i++)
  {
    if(i < 0)
      i = 0;
    for(int j = up -width;j <= up + width;j++)
    {
      if(j < 0)
        j = 0;
      img_show[j][i] = 0xFFFF;
    }
    for(int k = down -width;k <= down + width;k++)
    {
      if(k < 0)
        k = 0;
      img_show[k][i] = 0xFFFF;
    }
  }
  for(int i = up + width;i <= down - width;i++)
  {
    if(i < 0)
      i = 0;
    for(int j = left -width;j <= left + width;j++)
    {
      if(j < 0)
        j = 0;
      img_show[i][j] = 0xFFFF;
    }
    for(int k = right -width;k <= right + width;k++)
    {
      if(k < 0)
        k = 0;
      img_show[i][k] = 0xFFFF;
    }
  }
}
