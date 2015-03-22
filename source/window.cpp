/*****************************************************************************
Copyright (c) 2010, zoutianming&daiqian. All rights reserved.
------------------------------------------------------------------------------
window.c
Module Name: menu
Date Created:  2010-10-22
Author: zoutianming&daiqian
Description: based menu system modules 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
#include "WINDOW.H"

/*****************************************************************************
Func Name:buttonEventSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: button's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  buttonEventSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
	if (pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg))
	{  
		if(FALSE == pstCurrWindow->nActive)
		{
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(LIGHTRED);
			rectangle(pstCurrWindow->top.nX-2,pstCurrWindow->top.nY-2,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+pstCurrWindow->nHeight+1);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		if (LEFTBUTTON == pstMsg->nButton
			&&pstCurrWindow->nPress==  FALSE)
			{
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(WHITE);
			rectangle(pstCurrWindow->top.nX-2,pstCurrWindow->top.nY-2,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+pstCurrWindow->nHeight+1);
		    pstCurrWindow->nPress= TRUE;
			pstCurrWindow->pfDrawWindow(pstCurrWindow);
			delay(300);
			pstCurrWindow->nPress= FALSE;
			pstCurrWindow->pfDrawWindow(pstCurrWindow);
		    pstMOUSE->pfShowMOUSE(pstMOUSE);
			return TRUE;
		}
		pstCurrWindow->nActive = TRUE ;
		return FALSE;
	}
	else 
	{   
		if(TRUE == pstCurrWindow->nActive )
		{
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(WHITE);
			rectangle(pstCurrWindow->top.nX-2,pstCurrWindow->top.nY-2,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+pstCurrWindow->nHeight+1);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive = FALSE;
		}
	}
	/*if (TRUE == pstMsg->nKbhit && ENTER == pstMsg->nKeyInput && pstCurrWindow->nPress==  FALSE)
	{
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		setcolor(BK_COLOR);
		rectangle(pstCurrWindow->top.nX-2,pstCurrWindow->top.nY-2,
			pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+pstCurrWindow->nHeight+1);
		pstCurrWindow->nPress= TRUE;
		pstCurrWindow->pfDrawWindow(pstCurrWindow);
		delay(300);
		pstCurrWindow->nPress= FALSE;
		pstCurrWindow->pfDrawWindow(pstCurrWindow);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		return TRUE;
    }*/
	return FALSE;
}

/*****************************************************************************
Func Name: textDialogEventSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description:  textDialog's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int   textDialogEventSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
	if (LEFTBUTTON == pstMsg->nButton)
	{
		if (pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg)
			&&pstCurrWindow->nActive==  FALSE)
		{   
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(LIGHTRED);
			rectangle(pstCurrWindow->top.nX-1,pstCurrWindow->top.nY-1,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+20+1);
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive= TRUE;
		}
		else if( TRUE == pstCurrWindow->nActive && 
			FALSE == pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg) )
		{   
			setcolor(WHITE);
            pstMOUSE->pfCloseMOUSE(pstMOUSE);
			rectangle(pstCurrWindow->top.nX-1,pstCurrWindow->top.nY-1,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+20+1);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive = FALSE;
		}
	}
	/*get key value*/
	if (TRUE == pstMsg->nKbhit && TRUE == pstCurrWindow->nActive)
	{   
		char cInputKey[2];
		cInputKey[0] = pstMsg->nKeyInput;
		cInputKey[1] = '\0';
		if((pstMsg->nKeyInput>31)&&(pstMsg->nKeyInput<127))
		{     
			++pstCurrWindow->nTextLength;
			if (pstCurrWindow->nTextLength>MAX_INPUT_LENGTH-1)
			{
				pstCurrWindow->nTextLength = MAX_INPUT_LENGTH-1 ;
			    return  -1 ;
			}
            pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength-1] = cInputKey[0];
            pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength] = '\0';
		    pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setwritemode(0);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL,WHITE);
			bar(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1),pstCurrWindow->top.nY+3,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1)+8,pstCurrWindow->top.nY+3+8);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1)+2,pstCurrWindow->top.nY+20-2);
			setcolor(DARKGRAY);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			outtextxy(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1),pstCurrWindow->top.nY+3,cInputKey);
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
	    }
		if (BACKSPACE == pstMsg->nKeyInput)
		{    
			char cInputKey[2];
			--pstCurrWindow->nTextLength;
			if( pstCurrWindow->nTextLength <0 )
			{
				pstCurrWindow->nTextLength = 0 ;
			}
			cInputKey[0] = pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength];
             pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength] = '\0';
             cInputKey[1] = '\0';
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setwritemode(0);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength+1)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength+1)+2,pstCurrWindow->top.nY+20-2);
			setcolor(WHITE);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
		    outtextxy(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength),
				pstCurrWindow->top.nY+3,cInputKey);
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
	}
	/*show the  cursor*/
	if (TRUE == pstCurrWindow->nActive && FALSE ==pstMsg->nKbhit &&TRUE == pstCurrWindow->nCheckEvent)
	{    
        pstCurrWindow->nLayTime++;
		if (pstCurrWindow->nLayTime == 20000)
		{  
		   pstMOUSE->pfCloseMOUSE(pstMOUSE);
            setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
	   }
		if (pstCurrWindow->nLayTime == 40000)
		{  
		    pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nLayTime = 0;
        }
	}
	return FALSE;
}

/*****************************************************************************
Func Name: passWordDialogSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: passWordDialog's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  passWordDialogSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
	if (LEFTBUTTON == pstMsg->nButton)
	{
		if (pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg)
			&&pstCurrWindow->nActive==  FALSE)
		{   
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(LIGHTRED);
			rectangle(pstCurrWindow->top.nX-1,pstCurrWindow->top.nY-1,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+20+1);
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive= TRUE;
		}
		else if( TRUE == pstCurrWindow->nActive && 
			FALSE == pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg) )
		{   
			setcolor(WHITE);
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			rectangle(pstCurrWindow->top.nX-1,pstCurrWindow->top.nY-1,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+20+1);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive = FALSE;
		}
	}
	/*get key value*/
	if (TRUE == pstMsg->nKbhit && TRUE == pstCurrWindow->nActive)
	{   
		char cInputKey[2];
		cInputKey[0] = pstMsg->nKeyInput;
		cInputKey[1] = '\0';
		if((pstMsg->nKeyInput>31)&&(pstMsg->nKeyInput<127))
		{     
			++pstCurrWindow->nTextLength;
			if (pstCurrWindow->nTextLength>MAX_INPUT_LENGTH-1)
			{
				pstCurrWindow->nTextLength = MAX_INPUT_LENGTH-1 ;
				return  -1 ;
			}
			pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength-1] = cInputKey[0];
			pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength] = '\0';
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setwritemode(0);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL,WHITE);
			bar(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1),pstCurrWindow->top.nY+3,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1)+8,pstCurrWindow->top.nY+3+8);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1)+2,pstCurrWindow->top.nY+20-2);
			setcolor(DARKGRAY);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			outtextxy(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength-1),pstCurrWindow->top.nY+3,"*");
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		if (BACKSPACE == pstMsg->nKeyInput)
		{    
			char cInputKey[2];
			--pstCurrWindow->nTextLength;
			if( pstCurrWindow->nTextLength <0 )
			{
				pstCurrWindow->nTextLength = 0 ;
			}
			cInputKey[0] = pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength];
			pstCurrWindow->acInputTextDialog[pstCurrWindow->nTextLength] = '\0';
			cInputKey[1] = '\0';
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setwritemode(0);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength+1)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength+1)+2,pstCurrWindow->top.nY+20-2);
			setcolor(WHITE);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			outtextxy(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength),
				pstCurrWindow->top.nY+3,"*");
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
	}
	/*show the  cursor*/
	if (TRUE == pstCurrWindow->nActive && FALSE ==pstMsg->nKbhit &&TRUE == pstCurrWindow->nCheckEvent)
	{    
		pstCurrWindow->nLayTime++;
		if (pstCurrWindow->nLayTime == 20000)
		{  
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(DARKGRAY);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		if (pstCurrWindow->nLayTime == 40000)
		{  
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(WHITE);
			line(pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+2,
				pstCurrWindow->top.nX+2+8*(pstCurrWindow->nTextLength)+2,pstCurrWindow->top.nY+20-2);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nLayTime = 0;
		}
	}
	return FALSE;
}

/*****************************************************************************
Func Name:DownMenuHeaderSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: DownMenuHeader's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  DownMenuHeaderSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
	if (TRUE == pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg))
	{   
		pstMOUSE->pfChangeStyle(pstMOUSE,HAND);
		if(FALSE == pstCurrWindow->nActive)
		{
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		setcolor(LIGHTRED);
		rectangle(pstCurrWindow->top.nX-2,pstCurrWindow->top.nY-2,
			pstCurrWindow->top.nX+pstCurrWindow->nLength+2,pstCurrWindow->top.nY+pstCurrWindow->nHeight+2);
		rectangle(pstCurrWindow->top.nX-1,pstCurrWindow->top.nY-1,
			pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+pstCurrWindow->nHeight+1);
		setcolor(LIGHTGRAY);
		line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		//rectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		//	pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY+pstCurrWindow->nHeight);
		setcolor(LIGHTGREEN);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(pstCurrWindow->top.nX+12,pstCurrWindow->top.nY+12,pstCurrWindow->acTitle);
		pstCurrWindow->nActive = TRUE;
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
        
	}
	else 
	  {   
		if(TRUE == pstCurrWindow->nActive)
		{   
			pstMOUSE->pfChangeStyle(pstMOUSE,ARROW);
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(LIGHTGRAY);
			rectangle(pstCurrWindow->top.nX-1,pstCurrWindow->top.nY-1,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+1,pstCurrWindow->top.nY+pstCurrWindow->nHeight+1);
			rectangle(pstCurrWindow->top.nX-2,pstCurrWindow->top.nY-2,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+2,pstCurrWindow->top.nY+pstCurrWindow->nHeight+2);
			rectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
				pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY+pstCurrWindow->nHeight);
			setcolor(LIGHTGRAY);
			line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
				pstCurrWindow->top.nX,pstCurrWindow->top.nY);
			line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
				pstCurrWindow->top.nX,pstCurrWindow->top.nY);
			//rectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
				//pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY+pstCurrWindow->nHeight);
			setcolor(DARKGRAY);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(pstCurrWindow->top.nX+12,pstCurrWindow->top.nY+12,pstCurrWindow->acTitle);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive = FALSE ;
		}
	}
	return TRUE;
}

/*****************************************************************************
Func Name:downMenuBodySelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: downMenuBody's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  downMenuBodySelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
	if (pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg))
	{   
		if(FALSE == pstCurrWindow->nActive)
		{   
		    pstMOUSE->pfCloseMOUSE(pstMOUSE);
			fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
				pstCurrWindow->nLength,pstCurrWindow->nHeight,LIGHTGREEN);
			setcolor(GREEN);
			rectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
				pstCurrWindow->nLength+pstCurrWindow->top.nX,pstCurrWindow->nHeight+pstCurrWindow->top.nY);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			outtextxy(pstCurrWindow->top.nX+10,pstCurrWindow->top.nY+3,pstCurrWindow->acTitle);
			 pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive = TRUE;
		}
        if (LEFTBUTTON == pstMsg->nButton)
        {
		    return TRUE;
        }
	}
	else 
	{
		if(TRUE == pstCurrWindow->nActive)
		{   
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
            drawDownMenuBody(pstCurrWindow);
		    pstMOUSE->pfShowMOUSE(pstMOUSE);
		    pstCurrWindow->nActive = FALSE ;
		}
	}
	return FALSE ;
}

/*****************************************************************************
Func Name:downTextDialogSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description:downTextDialog's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  downTextDialogSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{  
	if (TRUE == isAPositionInARectangle(pstCurrWindow->top.nX + pstCurrWindow->nLength,pstCurrWindow->top.nY,
		pstCurrWindow->top.nX + pstCurrWindow->nLength +20,pstCurrWindow->top.nY + 20 , pstMsg->MOUSE_position))
	{  
		if(FALSE == pstCurrWindow->nActive)
		{
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(LIGHTRED);
			rectangle(pstCurrWindow->top.nX + pstCurrWindow->nLength,pstCurrWindow->top.nY,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+20,pstCurrWindow->top.nY+20);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		if (LEFTBUTTON == pstMsg->nButton)
		{
			return TRUE;
		}
		pstCurrWindow->nActive = TRUE ;
		return TRUE;
  }
	else 
	{   
		if(TRUE == pstCurrWindow->nActive )
		{
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			setcolor(LIGHTGRAY);
			rectangle(pstCurrWindow->top.nX + pstCurrWindow->nLength,pstCurrWindow->top.nY,
				pstCurrWindow->top.nX+pstCurrWindow->nLength+20,pstCurrWindow->top.nY+20);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
			pstCurrWindow->nActive = FALSE;
		}
	}   
	return TRUE;
}

/*****************************************************************************
Func Name:warningWindowSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description:warningWindow's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  warningWindowSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
     if (TRUE == isAPositionInARectangle(pstCurrWindow->top.nX+4,
		 pstCurrWindow->top.nY,pstCurrWindow->top.nX+240,pstCurrWindow->top.nY+80,pstMsg->MOUSE_position))
     {
           	pstMOUSE->pfChangeStyle(pstMOUSE,HAND);
			if (FALSE == pstCurrWindow->nStartMove && LEFTBUTTON ==pstMsg->nButton)
			{
				pstCurrWindow->nStartMove = TRUE;
				pstCurrWindow->mousePositionWhenLeftKit.nX = pstMsg->MOUSE_position.nX-pstCurrWindow->top.nX;
                pstCurrWindow->mousePositionWhenLeftKit.nY = pstMsg->MOUSE_position.nY-pstCurrWindow->top.nY; 
				/*pstMOUSE->pfCloseMOUSE(pstMOUSE);
				pstCurrWindow->pfPutImage(pstCurrWindow);
				pstCurrWindow->top.nX = pstMsg->MOUSE_position.nX ;
				pstCurrWindow->top.nY = pstMsg->MOUSE_position.nY;
				pstCurrWindow->pfSaveImage(pstCurrWindow);
		        pstMOUSE->pfShowMOUSE(pstMOUSE);*/
			}
			if (TRUE == pstCurrWindow->nStartMove && FALSE == pstMOUSE->nLeftButtonUp)
			{
                if (TRUE == pstMOUSE->pfisMove(pstMOUSE) && 
					pstMOUSE->currPosition.nY > 	pstCurrWindow->mousePositionWhenLeftKit.nY+2 &&
					pstMOUSE->currPosition.nX > pstCurrWindow->mousePositionWhenLeftKit.nX+2  &&
					(640 - pstMOUSE->currPosition.nX ) > (pstCurrWindow->nLength -  pstCurrWindow->mousePositionWhenLeftKit.nX+2 )&&
                    (480 - pstMOUSE->currPosition.nY ) > (pstCurrWindow->nHeight -  pstCurrWindow->mousePositionWhenLeftKit.nY+2 ))
                {
                     pstMOUSE->pfCloseMOUSE(pstMOUSE);
			        putimage(pstCurrWindow->top.nX,pstCurrWindow->top.nY,pstCurrWindow->pImage,COPY_PUT);
			       // putPixel(pstCurrWindow->storecolor,pstCurrWindow);
					 pstCurrWindow->top.nX = pstMsg->MOUSE_position.nX - 	pstCurrWindow->mousePositionWhenLeftKit.nX;
				     pstCurrWindow->top.nY = pstMsg->MOUSE_position.nY - pstCurrWindow->mousePositionWhenLeftKit.nY; 
			         getimage(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
				  	 pstCurrWindow->nLength+pstCurrWindow->top.nX,pstCurrWindow->nHeight+pstCurrWindow->top.nY,
				     	 pstCurrWindow->pImage );
					// getPixel(pstCurrWindow->storecolor,pstCurrWindow);
					  drawWarningWindow(pstCurrWindow);
					   pstMOUSE->pfShowMOUSE(pstMOUSE);		 
                }
			}
			if(TRUE == pstCurrWindow->nStartMove && TRUE == pstMOUSE->nLeftButtonUp)
			{
				pstCurrWindow->nStartMove = FALSE;
			}
     }
	 else
	 {
           	pstMOUSE->pfChangeStyle(pstMOUSE,ARROW);
			pstCurrWindow->nStartMove = FALSE;
			if (LEFTBUTTON ==pstMsg->nButton && FALSE == pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMsg))
			{    
				 pstMOUSE->pfCloseMOUSE(pstMOUSE);
				setcolor(LIGHTGREEN);
				circle(pstCurrWindow->top.nX+2+30,pstCurrWindow->top.nY+2+50,15);
				settextstyle(DEFAULT_FONT,0,2);
				 outtextxy(pstCurrWindow->top.nX+25+2,pstCurrWindow->top.nY+2+40,"!");
				 sound(1000);
				 delay(60);
				 nosound();
                 moveBall(pstCurrWindow->top.nX+85,pstCurrWindow->top.nY+2,20,170);
				 setcolor(RED);
				 circle(pstCurrWindow->top.nX+2+30,pstCurrWindow->top.nY+2+50,15);
				 settextstyle(DEFAULT_FONT,0,2);
				 outtextxy(pstCurrWindow->top.nX+25+2,pstCurrWindow->top.nY+2+40,"!");
				 pstMOUSE->pfShowMOUSE(pstMOUSE);		 
			}
	 }
         return TRUE;
}

/*****************************************************************************
Func Name:chooseCircleSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: chooseCircle's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  chooseCircleSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
      if (LEFTBUTTON == pstMsg->nButton)
      {
		  if (TRUE == isAPositionInARectangle(pstCurrWindow->top.nX - 10,pstCurrWindow->top.nY - 10,
			  pstCurrWindow->top.nX + 10,pstCurrWindow->top.nY + 10 , pstMsg->MOUSE_position)
			  && FALSE ==  pstCurrWindow->nGetInputText)
		  {   
			   pstMOUSE->pfCloseMOUSE(pstMOUSE);
			  setcolor(WHITE);
			//  floodfill(pstCurrWindow->top.nX,pstCurrWindow->top.nY,LIGHTGRAY);
			  setfillstyle(SOLID_FILL,WHITE);
			  fillellipse(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,10,10);
			  setcolor(BLUE);	
			  setfillstyle(SOLID_FILL,BLUE);
			  fillellipse(pstCurrWindow->top.nX,pstCurrWindow->top.nY,5,5);
			  pstMOUSE->pfShowMOUSE(pstMOUSE);		 
			  pstCurrWindow->nGetInputText = TRUE;
		  }
		  if (TRUE == isAPositionInARectangle(pstCurrWindow->top.nX + pstCurrWindow->nLength - 10,pstCurrWindow->top.nY - 10,
			  pstCurrWindow->top.nX + pstCurrWindow->nLength +10,pstCurrWindow->top.nY + 10 , pstMsg->MOUSE_position)
			  && TRUE ==  pstCurrWindow->nGetInputText)
		  {    
			  pstMOUSE->pfCloseMOUSE(pstMOUSE);
			  setcolor(WHITE);
			  //  floodfill(pstCurrWindow->top.nX,pstCurrWindow->top.nY,LIGHTGRAY);
			  setfillstyle(SOLID_FILL,WHITE);
			  fillellipse(pstCurrWindow->top.nX,pstCurrWindow->top.nY,10,10);
			  setcolor(BLUE);	
			  setfillstyle(SOLID_FILL,BLUE);
			  fillellipse(pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY,5,5);
			  pstMOUSE->pfShowMOUSE(pstMOUSE);		 
			  pstCurrWindow->nGetInputText = FALSE;
	      }
     }
}

/*****************************************************************************
Func Name: rightButtonMenuSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: rightButtonMenu's self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  rightButtonMenuSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{    

      return TRUE;
}

/*****************************************************************************
Func Name:eventSelfAction
Date Created: 2010-10-22
Author: zoutianming
Description: all kinds windows' self action to the events happened 
Input:struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int  eventSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{    
	switch (pstCurrWindow->nKind)
	{
	case TEXTDIALOG :
		{
			textDialogEventSelfAction(pstCurrWindow,pstMsg,pstMOUSE);
			return FALSE;
			break;
		}
	case PASSWORD_DIALOG :
		{
		    passWordDialogSelfAction(pstCurrWindow,pstMsg,pstMOUSE);
			return FALSE;
			break;
		}
	case BUTTON:
		{
			if(TRUE == buttonEventSelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	case DOWN_MENU_HEADER:
		{
			if(TRUE == DownMenuHeaderSelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	case DOWN_MENU_BODY:
		{
			if (TRUE == downMenuBodySelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	case DOWN_TEXT_DIALOG:
		{
			if (TRUE == downTextDialogSelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	case WARNING_WINDOW:
		{
			if (TRUE == warningWindowSelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	case RIGHT_BUTTON_MENU:
		{
			if (TRUE ==rightButtonMenuSelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	case CHOOSE_CIRCLE:
		{
			if (TRUE == chooseCircleSelfAction(pstCurrWindow,pstMsg,pstMOUSE))
			{
				return pstCurrWindow->nMenuID;
			}
			break;
		}
	}
	return FALSE;
}

int isMouseInside(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG)
{   
    if (pstMSG->MOUSE_position.nX>pstCurrWindow->top.nX&&
			pstMSG->MOUSE_position.nX<pstCurrWindow->top.nX+pstCurrWindow->nLength&&
			pstMSG->MOUSE_position.nY>pstCurrWindow->top.nY&&
			pstMSG->MOUSE_position.nY<pstCurrWindow->top.nY+pstCurrWindow->nHeight)
		{
			return TRUE;
		}
	   return FALSE;
}

void drawButton(struct tagWindow* pstCurrWindow)
{
    if(FALSE == pstCurrWindow->nPress)
	{
		fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
			pstCurrWindow->nLength,pstCurrWindow->nHeight,BUTTON_COLOR_DARK);
		fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
			pstCurrWindow->nLength-1,pstCurrWindow->nHeight-1,BUTTON_COLOR_LIGHT);  
		fillRectangle(pstCurrWindow->top.nX+1,pstCurrWindow->top.nY+1,
		pstCurrWindow->nLength-1,pstCurrWindow->nHeight-1,BUTTON_COLOR); 
		setcolor(BLACK);
		line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
			pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY+pstCurrWindow->nHeight);
		line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
			pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY+pstCurrWindow->nHeight);
		setcolor(WHITE);
		line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		setcolor(LIGHTGREEN);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(pstCurrWindow->top.nX+10,pstCurrWindow->top.nY+5,pstCurrWindow->acTitle);
	}
	else 
	{
		fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
			pstCurrWindow->nLength,pstCurrWindow->nHeight,BUTTON_COLOR_LIGHT);
		fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
			pstCurrWindow->nLength-1,pstCurrWindow->nHeight-1,BUTTON_COLOR_DARK);  
		fillRectangle(pstCurrWindow->top.nX+1,pstCurrWindow->top.nY+1,
			pstCurrWindow->nLength-1,pstCurrWindow->nHeight-1,BUTTON_COLOR); 
		setcolor(BLACK);
		line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		setcolor(BK_COLOR);
		line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
			pstCurrWindow->top.nX,pstCurrWindow->top.nY);
		setcolor(BLUE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(pstCurrWindow->top.nX+12,pstCurrWindow->top.nY+7,pstCurrWindow->acTitle);
	}
}

void drawTextDialog(int x,int y,int width,int nColor,char *acTitle)
{   
	setwritemode(0);
	setcolor(nColor);
	rectangle(x,y,x+width,y+20);
	setcolor(DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	settextjustify(2,2);
	outtextxy(x-8,y+3,acTitle);
	settextjustify(LEFT_TEXT,TOP_TEXT);
}

void drawDownMenuHeader(struct tagWindow*pstCurrWindow)
{    
	fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		pstCurrWindow->nLength,pstCurrWindow->nHeight,LIGHTGRAY);
	fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		pstCurrWindow->nLength-1,pstCurrWindow->nHeight-1,BUTTON_COLOR_DARK);  
	fillRectangle(pstCurrWindow->top.nX+1,pstCurrWindow->top.nY+1,
		pstCurrWindow->nLength-1,pstCurrWindow->nHeight-1,LIGHTGRAY); 
	setcolor(BLACK);
	line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
		pstCurrWindow->top.nX,pstCurrWindow->top.nY);
	line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
		pstCurrWindow->top.nX,pstCurrWindow->top.nY);
	setcolor(LIGHTGRAY);
	line(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
		pstCurrWindow->top.nX,pstCurrWindow->top.nY);
	line(pstCurrWindow->top.nX,pstCurrWindow->top.nY+pstCurrWindow->nHeight,
		pstCurrWindow->top.nX,pstCurrWindow->top.nY);
	//rectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		//pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY+pstCurrWindow->nHeight);
	setcolor(DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(pstCurrWindow->top.nX+12,pstCurrWindow->top.nY+12,pstCurrWindow->acTitle);
}

void drawDownMenuBody(struct tagWindow*pstCurrWindow)
{   
	fillRectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		pstCurrWindow->nLength,pstCurrWindow->nHeight,BUTTON_COLOR_LIGHT);
	setcolor(DARKGRAY);
	rectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		pstCurrWindow->nLength+pstCurrWindow->top.nX,pstCurrWindow->nHeight+pstCurrWindow->top.nY);
	setcolor(DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(pstCurrWindow->top.nX+10,pstCurrWindow->top.nY+5,pstCurrWindow->acTitle);
}

void drawDownTextDialog(struct tagWindow*pstCurrWindow)
{
	drawTextDialog( pstCurrWindow->top.nX, pstCurrWindow->top.nY, pstCurrWindow->nLength,LIGHTGRAY,
		pstCurrWindow->acTitle);
	fillRectangle(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,
		20,20,LIGHTGRAY); 
	setcolor(DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(pstCurrWindow->top.nX+pstCurrWindow->nLength+5,
		pstCurrWindow->top.nY+5,"V");
	outtextxy(pstCurrWindow->top.nX+pstCurrWindow->nLength+5,
		pstCurrWindow->top.nY+5+5,"V");
}

/*by daiqian*/
void drawarning(int x,int y,char s[])
{
	char s1[25],s2[25],s3[25];
	int nlong=strlen(s);
	int i,j;

	settextstyle(2,0,4);
	setcolor(8);
	rectangle(x,y,x+250,y+120);
	setfillstyle(1,BLUE);
	bar(x,y,x+250,y+120);
	setfillstyle(1,7);
	bar(x+3,y+20,x+247,y+118);
	rectangle(x+4,y+21,x+246,y+117);
	setcolor(9);
	rectangle(x-2,y-2,x+252,y+122);
	rectangle(x-1,y-1,x+251,y+121);
	settextstyle(2,0,6);
	setcolor(4);
	outtextxy(x+8,y,"warning");
	circle(x+30,y+50,15);
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(x+25,y+40,"!");
	setcolor(4);
	settextstyle(2,0,5);
	if(nlong<24)
	{
		strcpy(s1,s);
		outtextxy(x+62,y+27,s1);

	}
	else if(nlong<47)
	{

		for(i=0;i<23;i++)
		{
			s1[i]=s[i];
		}

		s1[24]='\0';
		if(s[23]!=' ')
		{
			s1[23]='-';
		}
		for(i=23;i<nlong;i++)
		{
			s2[i-23]=s[i];
		}
		s2[nlong-23]='\0';
		outtextxy(x+62,y+27,s1);
		outtextxy(x+62,y+42,s2);
	}
	else if(nlong>46)
	{

		for(i=0;i<23;i++)
		{
			s1[i]=s[i];
		}

		s1[24]='\0';
		if(s[23]!=' ')
		{
			s1[23]='-';
		}
		for(i=23;i<46;i++)
		{
			s2[i-23]=s[i];
		}
		s2[24]='\0';
		if(s[46]!='\0')
		{
			s2[23]='-';
		}


		for(i=46;i<nlong;i++)
		{
			s3[i-46]=s[i];
		}
		s3[nlong-46]='\0';
		outtextxy(x+62,y+27,s1);
		outtextxy(x+62,y+42,s2);
		outtextxy(x+62,y+57,s3);
	}
}
void drawWarningWindow(struct tagWindow*pstCurrWindow)
{
      drawarning(pstCurrWindow->top.nX+2,pstCurrWindow->top.nY+2,pstCurrWindow->acTitle);   
}

void drawChooseCircleWindow(struct tagWindow*pstCurrWindow)
{   
	setcolor(RED);
    circle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,11);
	circle(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,11);
	setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
	fillellipse(pstCurrWindow->top.nX,pstCurrWindow->top.nY,10,10);
	fillellipse(pstCurrWindow->top.nX+pstCurrWindow->nLength,pstCurrWindow->top.nY,10,10);
    setcolor(BLUE);	
	circle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,5);
	setfillstyle(SOLID_FILL,BLUE);
	fillellipse(pstCurrWindow->top.nX,pstCurrWindow->top.nY,5,5);
}

void drawPassWordDialog(struct tagWindow*pstCurrWindow)
{  
	drawTextDialog( pstCurrWindow->top.nX, pstCurrWindow->top.nY, pstCurrWindow->nLength,LIGHTGRAY,
		pstCurrWindow->acTitle);
}

void drawWindow(struct tagWindow*pstCurrWindow)
{   
	switch (pstCurrWindow->nKind)
	{
	case TEXTDIALOG :
		drawTextDialog( pstCurrWindow->top.nX, pstCurrWindow->top.nY, pstCurrWindow->nLength,LIGHTGRAY,
			pstCurrWindow->acTitle);
		break;
	case BUTTON:
		drawButton(pstCurrWindow);
		break;
	case DOWN_MENU_HEADER:
		drawDownMenuHeader(pstCurrWindow);
		break;
	case DOWN_MENU_BODY:
         /*save image*/
		pstCurrWindow->pfSaveImage(pstCurrWindow);
		drawDownMenuBody(pstCurrWindow);
		break;
   case DOWN_TEXT_DIALOG:
        drawDownTextDialog(pstCurrWindow);
		break;
   case WARNING_WINDOW:
	   /*save image*/
	  pstCurrWindow->pfSaveImage(pstCurrWindow);
	  drawWarningWindow(pstCurrWindow);
	   break;
   case CHOOSE_CIRCLE:
	   pstCurrWindow->nGetInputText = TRUE ;
	   drawChooseCircleWindow(pstCurrWindow);
	   break;
   case PASSWORD_DIALOG:
	   pstCurrWindow->nGetInputText = TRUE ;
	   drawPassWordDialog(pstCurrWindow);
	   break;  
    }
}

void showTextDialogCursor(struct tagWindow*pstCurrWindow)
{
	settextstyle(0,0,1);
	setwritemode(1);
	setcolor(0);
	delay(500);
	line(pstCurrWindow->top.nX+5+8*pstCurrWindow->nTextLength,pstCurrWindow->top.nY+1,
		pstCurrWindow->top.nX+5+8*pstCurrWindow->nTextLength,pstCurrWindow->top.nY+12); 
	setwritemode(0);
}

void saveImage(struct tagWindow* pstCurrWindow)
{
	unsigned unSize;
	unSize = imagesize(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
	   pstCurrWindow->nLength+pstCurrWindow->top.nX,pstCurrWindow->nHeight+pstCurrWindow->top.nY);
	   pstCurrWindow->pImage = malloc(unSize);
	   if (NULL == pstCurrWindow->pImage)
		{
			printf("fail to get image memory" );
		    exit(0);
		}
	getimage(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		pstCurrWindow->nLength+pstCurrWindow->top.nX,pstCurrWindow->nHeight+pstCurrWindow->top.nY,
		pstCurrWindow->pImage );
}

void putImage(struct tagWindow*pstCurrWindow )
{
	putimage(pstCurrWindow->top.nX,pstCurrWindow->top.nY,pstCurrWindow->pImage,COPY_PUT);
	free(pstCurrWindow->pImage);
	pstCurrWindow->pImage = NULL;
}


/*make a new window*/
struct tagWindow* getNewWindow(int nX,int nY,int nLength,int nHeight,int nKind,unsigned long int nMenuID,char* pacTitle)
{   
    struct tagWindow* pstCurrWindow;
	if((pstCurrWindow=(struct tagWindow*)malloc(1*sizeof(struct tagWindow)))==NULL)
	{
		printf("NO ENOUGH MEMORY");
		exit(1);
	}
	pstCurrWindow->top.nX = nX;
	pstCurrWindow->top.nY= nY;
	pstCurrWindow->mousePositionWhenLeftKit.nX=0;
    pstCurrWindow->mousePositionWhenLeftKit.nY=0;
	pstCurrWindow->nActive = FALSE;
	pstCurrWindow->nFatherID = 0;
	pstCurrWindow->nHaveFather = FALSE;
	pstCurrWindow->nHeight=nHeight;
	pstCurrWindow->nLength=nLength;
	pstCurrWindow->nMenuID=nMenuID;
	pstCurrWindow->nPress = FALSE ;
    pstCurrWindow->nKind=nKind;
	pstCurrWindow->nGetInputText = FALSE;
	pstCurrWindow->nTextLength = 0 ;
	pstCurrWindow->nLayTime = 0;
	pstCurrWindow->nMenuDown = FALSE;
	pstCurrWindow->nStartMove = FALSE;
	pstCurrWindow->nDraw = FALSE;
	pstCurrWindow->pImage = NULL;
	pstCurrWindow->nCheckEvent = TRUE;
	strcpy(pstCurrWindow->acTitle,pacTitle);
	pstCurrWindow->pfDrawWindow=drawWindow;
    pstCurrWindow->pfIsMouseInside=isMouseInside;
	pstCurrWindow->pfEventSelfAction=eventSelfAction;
	pstCurrWindow->pfShowTextDialogCursor=showTextDialogCursor;
	pstCurrWindow->pfSaveImage=saveImage;
	pstCurrWindow->pfPutImage = putImage;

	switch (pstCurrWindow->nKind)
	{
	case TEXTDIALOG :
    break;
	}
	return pstCurrWindow;
}

void fillRectangle(int nX,int nY,int nLength,int nHeight,int nColor )
{
	int i;
	setcolor(nColor);
	for(i=nY;i<=nY+nHeight;i++)
	{
          line(nX,i,nX+nLength,i);
	}
}

int isAPositionInARectangle(int nTopx,int nTopy,int nBottomx,int nBottomy,stPosition currPosition)
{
	if (currPosition.nX>nTopx+2 && currPosition.nX<nBottomx-2&&
		currPosition.nY<nBottomy-2 && currPosition.nY > nTopy+2)
	{
		return TRUE;
	}
	return FALSE;
}

void moveBall(int x,int y,int nheight,int nwidth)
{
	unsigned int size;
	int nbiao=x;
	void * pcur1;
	void * pcur2;
	size = imagesize(x, y, x+20, y+nheight);
	pcur1= malloc(size);
	pcur2= malloc(size);
	getimage(x, y, x+20, y+nheight, pcur1);
	setfillstyle(1,15);
	bar(x,y,x+20,y+nheight);
	getimage(x, y, x+20, y+nheight, pcur2);
	putimage(x,y,pcur1, COPY_PUT);
	while(x <nbiao+nwidth)
	{   
		putimage(x-7,y,pcur1,COPY_PUT);
		getimage(x, y, x+20, y+nheight, pcur1);
		unsigned int size;
		int nbiao=x;
		void * pcur1;
		void * pcur2;
		size = imagesize(x, y, x+20, y+nheight);
		pcur1= malloc(size);
		pcur2= malloc(size);
		getimage(x, y, x+20, y+nheight, pcur1);
		setfillstyle(1,15);
		bar(x,y,x+20,y+nheight);
		getimage(x, y, x+20, y+nheight, pcur2);
		putimage(x,y,pcur1, COPY_PUT);
		while(x <nbiao+nwidth)
		{
			putimage(x-7,y,pcur1,COPY_PUT);
			getimage(x, y, x+20, y+nheight, pcur1);
			putimage(x,y,pcur2, COPY_PUT);
            x+=7;
			delay(2);
		}
       putimage(x-7,y,pcur1, COPY_PUT);
		free(pcur1);
		free(pcur2);
	    x+=7;
	}
	free(pcur1);
	free(pcur2);
}
void getPixel(unsigned **storeColor,struct tagWindow*pstCurrWindow)
{  
	int i=0,j=0;
    for (i=0;i<pstCurrWindow->nHeight;i++)
    {
		for (j=0;j<pstCurrWindow->nLength ;j++)
		{
			storeColor[i][j] = getpixel(j+pstCurrWindow->nLength,i+pstCurrWindow->nHeight);
		}
    }
}
void putPixel(unsigned **storeColor,struct tagWindow*pstCurrWindow)
{  
	int i=0,j=0;
	for (i=0;i<pstCurrWindow->nHeight ;i++)
	{
		for (j=0;j<pstCurrWindow->nLength ;j++)
		{
		   putpixel(j+pstCurrWindow->nLength,i+pstCurrWindow->nHeight,storeColor[i][j] );
		}
	}
}