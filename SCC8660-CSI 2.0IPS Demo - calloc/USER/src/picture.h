#pragma once

typedef struct{
	int lable;
	int hight;
	int left;
	int right;
	int width;
}team;

typedef struct{
        //team grp[40];
        team *grp;
	int cnt;
}line;

typedef struct{
        //team grp[480];
        team *grp;
	int cnt;
	int x;
	int y;
	int pixels;
}blob;

void find_blobs();
void find_max();