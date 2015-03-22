#ifndef  _MOUSE_H_
#define  _MOUSE_H_
#include "position.h"
#include "CONMICRO.h"
#include <dos.h>
#include <graphics.h>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define  LEFTBUTTON 1
#define  RIGHTBUTTON 2
#define  RIGHTBUTTONUP 3b
#define  ARROW 1
#define  HAND  2

typedef struct tagStype{
	int mak[2][16];
	int hor;
	int ver;
}mscurstype;

typedef struct tagMOUSE{
	union REGS m,o;
	stPosition currPosition;
	stPosition lastPosition;
	int nButton;
	int nLeftButtonUp;
	int nAvoidSameStatus;
	int nShape;
	struct tagStype stArrow;
	struct tagStype stHand;
	/*save image*/
	void *imageBuffer;
	int (*pfLeftButtonDown)(struct tagMOUSE*);
	int (*pfRightButtonDown)(struct tagMOUSE*);
	int (*pfisMove)(struct tagMOUSE*);
	void (*pfGetMouseStatus)(struct tagMOUSE*);
	void (*pfCloseMOUSE)(struct tagMOUSE*);
	void(*pfShowMOUSE)(struct tagMOUSE*);
	int (*pfChangeStyle)(struct tagMOUSE*,int);
}stMOUSE;

void getMouseStatus(struct tagMOUSE*);
int leftButtonDown(struct tagMOUSE*);
int rightButtonDown(struct tagMOUSE*);
int isMove(struct tagMOUSE*);
int changeStyle(struct tagMOUSE*,int);

int  initMOUSE(struct tagMOUSE*);
void closeMOUSE(struct tagMOUSE*);
void showMOUSE(struct tagMOUSE*);
void drawMouse(struct tagMOUSE*,int style);
void putBkImage(struct tagMOUSE*);
void getBkImage(struct tagMOUSE*);


#endif