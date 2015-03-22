#include "mouse.h"

void putBkImage(struct tagMOUSE*pstMOUSE)
{  
	putimage( pstMOUSE->currPosition.nX,pstMOUSE->currPosition.nY,
		pstMOUSE->imageBuffer,COPY_PUT ); 
}
void getBkImage(struct tagMOUSE*pstMOUSE)
{
	getimage( pstMOUSE->currPosition.nX,pstMOUSE->currPosition.nY,
		16+ pstMOUSE->currPosition.nX,16+pstMOUSE->currPosition.nY,
		pstMOUSE->imageBuffer );
}
void getMouseStatus(struct tagMOUSE*pstMOUSE)
{   
	pstMOUSE->m.x.ax=3;
	int86(0x33,&pstMOUSE->m,&pstMOUSE->o);
	pstMOUSE->nButton=pstMOUSE->o.x.bx&7;
	_AX = 0x03;
	geninterrupt(0x33);
	if ( 0 == (_BX&1))
	{
		pstMOUSE->nLeftButtonUp = TRUE;
	}
	else
	{
        pstMOUSE->nLeftButtonUp = FALSE;
	}
	
   /*save last position*/
	pstMOUSE->lastPosition.nX=pstMOUSE->currPosition.nX;
	pstMOUSE->lastPosition.nY=pstMOUSE->currPosition.nY;
	/*get new position*/
	pstMOUSE->currPosition.nX=pstMOUSE->o.x.cx;
	pstMOUSE->currPosition.nY=pstMOUSE->o.x.dx;
	if ( TRUE == pstMOUSE->pfisMove(pstMOUSE))
	{
		putimage( pstMOUSE->lastPosition.nX,pstMOUSE->lastPosition.nY,
			pstMOUSE->imageBuffer,COPY_PUT ); 
		getimage( pstMOUSE->currPosition.nX,pstMOUSE->currPosition.nY,
			16+ pstMOUSE->currPosition.nX,16+pstMOUSE->currPosition.nY,
			pstMOUSE->imageBuffer );
		   drawMouse(pstMOUSE,0);
	}
}
int leftButtonDown(struct tagMOUSE*pstMOUSE)
{
	if (LEFTBUTTON==pstMOUSE->nButton)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int rightButtonDown(struct tagMOUSE*pstMOUSE)
{
	if (RIGHTBUTTON==pstMOUSE->nButton)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int isMove(struct tagMOUSE*pstMOUSE)
{
    if (pstMOUSE->currPosition.nX==pstMOUSE->lastPosition.nX&&
		pstMOUSE->currPosition.nY == pstMOUSE->lastPosition.nY)
    {
		return FALSE;
    }
	else
	{
		return TRUE;
	}
}

int  initMOUSE(struct tagMOUSE*pstMOUSE)
{
    int nImageSize;
	int retcode;
	pstMOUSE->o.x.ax=0;
	int86(51,&pstMOUSE->o,&pstMOUSE->o);
	retcode=pstMOUSE->o.x.ax;
	if(retcode==0)
	{
		return FALSE;
	}      
	pstMOUSE->o.x.ax=7;             /*   set the level max value  */  
	pstMOUSE->o.x.cx=2;
	pstMOUSE->o.x.dx=620;
	int86(51,&pstMOUSE->o,&pstMOUSE->o);
	pstMOUSE->o.x.ax=8;
	pstMOUSE->o.x.cx=2;          /*   set the vertical  max value*/
	pstMOUSE->o.x.dx=478;
	int86(51,&pstMOUSE->o,&pstMOUSE->o);   

	 pstMOUSE->nShape = ARROW;
	pstMOUSE->pfGetMouseStatus = getMouseStatus;
	pstMOUSE->pfLeftButtonDown=leftButtonDown;
	pstMOUSE->pfRightButtonDown=rightButtonDown;
	pstMOUSE->pfisMove=isMove;
	pstMOUSE->pfShowMOUSE=showMOUSE;
	pstMOUSE->pfCloseMOUSE=closeMOUSE;
	pstMOUSE->pfChangeStyle=changeStyle;
	pstMOUSE->nButton=-1;
	pstMOUSE->nAvoidSameStatus = -1;
	pstMOUSE->nLeftButtonUp = -1;
	pstMOUSE->m.x.ax=3;
	int86(0x33,&pstMOUSE->m,&pstMOUSE->o);
    pstMOUSE->currPosition.nX=pstMOUSE->o.x.cx;
	pstMOUSE->currPosition.nY=pstMOUSE->o.x.dx;
	pstMOUSE->lastPosition.nX=pstMOUSE->currPosition.nX;
	pstMOUSE->lastPosition.nY=pstMOUSE->currPosition.nY;
	nImageSize = imagesize( pstMOUSE->currPosition.nX,pstMOUSE->currPosition.nY,
		16+ pstMOUSE->currPosition.nX,16+pstMOUSE->currPosition.nY);
	pstMOUSE->imageBuffer = malloc(nImageSize);
	if (NULL ==	pstMOUSE->imageBuffer)
	{
		printf("fail to get image memory" );
		exit(0);
	}
	getimage( pstMOUSE->currPosition.nX,pstMOUSE->currPosition.nY,
		16+ pstMOUSE->currPosition.nX,16+pstMOUSE->currPosition.nY,
	pstMOUSE->imageBuffer );
	drawMouse(pstMOUSE,0);
     return TRUE;
}

void closeMOUSE(struct tagMOUSE*pstMOUSE)
{
	//pstMOUSE->o.x.ax = 2;
	//int86(0x33,&	pstMOUSE->o,&pstMOUSE->m);
	putBkImage(pstMOUSE);
}
void showMOUSE(struct tagMOUSE*pstMOUSE)
{
	 //pstMOUSE->o.x.ax = 1;
	//int86(0x33,&	pstMOUSE->o,&pstMOUSE->m);
	getimage( pstMOUSE->currPosition.nX,pstMOUSE->currPosition.nY,
		16+ pstMOUSE->currPosition.nX,16+pstMOUSE->currPosition.nY,
		pstMOUSE->imageBuffer );
	drawMouse(pstMOUSE,0);
}

int changeStyle(struct tagMOUSE*pstMOUSE ,int nStyle)
{   
	/*mscurstype  arrow={0x3fff,0x1fff,0x0fff,0x07ff,
		0x03ff,0x01ff,0x00ff,0x007f,
		0x003f,0x00ff,0x01ff,0x10ff,
		0x30ff,0xf87f,0xf87f,0xfc3f,
		0x0000,0x4000,0x6000,0x7000,
		0x7800,0x7c00,0x7e00,0x7f00,
		0x7f80,0x7e00,0x7c00,0x4600,
		0x0600,0x0300,0x0300,0x0180,0,0};
	mscurstype  hand = {-7681,-7681,-7681,-7681,-7681,-8192,-8192,-8192,
		0,    0,    0,    0,    0,    0,    0,    0,
		7680,4608,4608,4608,4608,5119,4681,4681,4681,
		-28671,-28671,-28671,-22767,-32767,-32767,-1,4,0};
	union REGS r;
	struct SREGS s;
	switch (nStyle)
	{
	case ARROW :
		pstMOUSE->stArrow = arrow;
		r.x.ax=9;
		r.x.bx=pstMOUSE->stArrow.hor;
		r.x.cx=pstMOUSE->stArrow.ver;
		r.x.dx=FP_OFF(&pstMOUSE->stArrow);
		s.es=FP_SEG(&pstMOUSE->stArrow);
		int86x(0x33,&r,&r,&s);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		break;
	case HAND:
		pstMOUSE->stHand = hand;
		r.x.ax=9;
		r.x.bx=pstMOUSE->stHand.hor;
		r.x.cx=pstMOUSE->stHand.ver;
		r.x.dx=FP_OFF(&pstMOUSE->stHand);
		s.es=FP_SEG(&pstMOUSE->stHand);
		int86x(0x33,&r,&r,&s);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		break;*/
    switch (nStyle)
    {
    case ARROW:
		pstMOUSE->nShape = ARROW;
        break;
   case HAND:
	   	pstMOUSE->nShape = HAND;
	   break;
    }

}

void drawMouse(struct tagMOUSE*pstMOUSE,int style)
{ 
	int x = pstMOUSE->currPosition.nX,y=pstMOUSE->currPosition.nY;
	int mousepic[8];mousepic[0]=x+1,mousepic[1]=y+1,mousepic[2]=x+1,mousepic[3]=y+1+12,mousepic[4]=x+1+3,mousepic[5]=y+1+7,mousepic[6]=x+1+9,mousepic[7]=y+1+7;
	if(ARROW == pstMOUSE->nShape)
	{
    setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(4,mousepic);}
	if(HAND == pstMOUSE->nShape)
	{
		setcolor(LIGHTBLUE);
	setlinestyle(0,3,1);
	line(x+1,y+1+5,x+1+11,y+1+5);
	line(x+1+6,y+1,x+1+6,y+1+11);
	}
}


