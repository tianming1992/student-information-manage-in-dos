#include "page.h"
void drawBackPage(char * acTitle)
{   
	int i;
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(0,0,640,480);
	setcolor(9);
	rectangle(1,1,639,479);

	setfillstyle(1,1);
	bar(1,1,639,19);
	settextstyle(0,0,1);
	setcolor(15);
	outtextxy(4,6,acTitle);

	setfillstyle(1,7);
	bar(1,20,639,50);
	for(i=0;i<4;i++)
	{
		setcolor(1);
		line(120+120*i,20,120+120*i,50);
	}

	setfillstyle(1,15);
	bar(2,50,628,479);

	setbkcolor(7);
	setfillstyle(8,15);
	bar(630,53,639,479);


	setfillstyle(1,1);
	bar(0,1,2,480);
	setfillstyle(8,7);
	bar(0,469,639,480);
	setcolor(8);
	rectangle(5,52,626,459);
	setcolor(7);
	rectangle(7,54,624,457);
	setcolor(0);
	settextstyle(3,0,3);
	outtextxy(607,12,"x");
	setbkcolor(BLUE);
	setcolor(RED);
	rectangle(10,60,620,450);
}

void loginPage()
{   
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(0,0,640,480);
	setbkcolor(LIGHTCYAN);
	setcolor(BLUE);
	settextstyle(2,0,6);
	outtextxy(100,80,"Public Information Service Platform of");
	settextstyle(2,0,8);
	outtextxy(480,74,"HUST");
	rectangle(2,1,638,478);
	setcolor(LIGHTBLUE);
	rectangle(4,3,636,476);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(96,144,508,409);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(100,150,500,400);
	rectangle(98,148,502,402);
    
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
    bar(110,160,490,390);
	setcolor(BLUE);
    rectangle(111,161,488,389);
    rectangle(112,162,489,388);
    setcolor(DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	settextstyle(2,0,5);
	outtextxy(130,215,"student");
	outtextxy(220,215,"teacher");
   setfillstyle(SOLID_FILL,WHITE);
	log(170 ,450);
}

void log(int x,int y)
{
	int i;
	setcolor(11);
	rectangle(x+1,y+1,x+299,y+19);
	setcolor(8);
	rectangle(x,y,x+300,y+20);
	settextstyle(2,0,4);
	outtextxy(x+5,y+3,"Copyright@zoutianming&daiqian,All Rights Reaseved");
	setcolor(8);
	rectangle(x+2,y+2,x+298,y+18);
	setcolor(10);
	for(i=5;i<300;i+=25)
	{
		line(x+i,y+1,x+i+15,y+1);
		line(x+i,y+19,x+i+15,y+19);
		line(x+1,y+2,x+1,y+18);
		line(x+299,y+2,x+299,y+18);
	}
}

void registerPage()
{   
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(0,0,640,480);
    setbkcolor(WHITE);
	setcolor(BLUE);
	settextstyle(2,0,9);
	outtextxy(45,30,"Registration New");
	line(30,80,540,80);
	line(30,79,540,79);
	setfillstyle(1,LIGHTBLUE);
	bar(30,81,540,84);
	rectangle(2,1,638,478);
	setcolor(LIGHTBLUE);
	rectangle(4,3,636,476);
	setfillstyle(1,7);
	bar(100,127,500,130);
	setcolor(8);
	line(100,125,500,125);
	line(100,126,500,126);
	setcolor(BLUE);
	settextstyle(0,0,1);
	outtextxy(60,105,"BOY");
	outtextxy(120,105,"GIRL");
}