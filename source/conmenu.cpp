#include "commenu.h"

int  addMenuToSystemList(stWindow*pstMenuHeader,stWindow*pstWindowToAdd)
{
	stWindow* pstWindowNode=pstMenuHeader;
	while (NULL != pstWindowNode->pNextWindow)
	{
		pstWindowNode = pstWindowNode->pNextWindow;
	}
	pstWindowNode->pNextWindow = pstWindowToAdd;
	pstWindowToAdd->pLastWindow = pstWindowNode;
	pstWindowToAdd->pNextWindow = NULL ;
}

void freeMenuList(struct tagWindow*pstMENUHeader)
{
	stWindow* pstWindowNode=pstMENUHeader;
	while (NULL != pstWindowNode->pNextWindow)
	{
		pstWindowNode = pstWindowNode->pNextWindow;
		if (NULL != pstWindowNode->pLastWindow->pImage)
		{
			pstWindowNode->pfPutImage(pstWindowNode);
		}
		free(pstWindowNode->pLastWindow);
	}
	if (NULL != pstWindowNode->pImage)
	{
	   pstWindowNode->pfPutImage(pstWindowNode);
	}
	free(pstWindowNode);
}

void freeList(struct tagMessage*pstMSG , struct tagWindow*pstCurrWindow )
{
	stWindow* pstWindowHeader = getMenuHeader(pstCurrWindow);
	freeMenuList(pstWindowHeader);
	freeStudentList(pstMSG->pstStudentHeader);
	freeTeacherList(pstMSG->pstTeacherHeader);
	freeClassList(pstMSG->pstClassHeader);
	freeDepartList(pstMSG->pstDepartment);
	free(pstMSG->pstMangerHeader);
}

int deleteOneNodeFromList(struct tagWindow*pstMenuHeader , int nMenuID)
{
	stWindow* pstWindowNode=pstMenuHeader->pNextWindow;
	stWindow* pstWindowNodeToFree=pstMenuHeader->pNextWindow;
	while (NULL != pstWindowNode->pNextWindow && NULL != pstWindowNode )
	{
		if (nMenuID == pstWindowNode->nMenuID)
		{
			pstWindowNodeToFree = pstWindowNode;
			pstWindowNode = pstWindowNode->pLastWindow;
			pstWindowNode->pNextWindow = pstWindowNodeToFree->pNextWindow;
			pstWindowNodeToFree->pNextWindow->pLastWindow = pstWindowNode;
			if (NULL != pstWindowNodeToFree->pImage)
			{   
				pstWindowNodeToFree->pfPutImage(pstWindowNodeToFree);
			}
			free(pstWindowNodeToFree);
			return TRUE ;
		}
		pstWindowNode = pstWindowNode->pNextWindow;
	}
	if (nMenuID == pstWindowNode->nMenuID)
	{
		pstWindowNode->pLastWindow->pNextWindow = NULL;
		if (NULL != pstWindowNode->pImage)
		{   
			pstWindowNode->pfPutImage(pstWindowNode);
		}
		free(pstWindowNode);
		return TRUE ;
	}
	return FALSE ;
}
stWindow*getMenuHeader(stWindow*pstCurrWindow)
{   
	stWindow* pstWindowNode=pstCurrWindow;
	while (NULL != pstWindowNode->pLastWindow )
	{
		pstWindowNode = pstWindowNode->pLastWindow;
	}
	return pstWindowNode;
}

stWindow*deleteCurrReturnLast(stWindow*pstCurrWindow)
{   
	stWindow*pstWindowNodeToFree = pstCurrWindow;
	pstCurrWindow = pstCurrWindow->pLastWindow;
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),pstWindowNodeToFree->nMenuID);
	return pstCurrWindow ;
}

stWindow*findNodeByID(stWindow*pstCurrWindow,unsigned long int unMeneID )
{
	stWindow*pstMenuHeader = getMenuHeader(pstCurrWindow);
	while (NULL != pstMenuHeader  )
	{
		if ( unMeneID == pstMenuHeader->nMenuID)
		{
			return pstMenuHeader;
		}
		pstMenuHeader = pstMenuHeader->pNextWindow;
	}
	return NULL;
}

void disableButThisWin(stWindow*pstCurrWindow)
{  
	stWindow*pstWindowNode ;
	stWindow*pstMenuHeader = getMenuHeader(pstCurrWindow);
	pstWindowNode = pstMenuHeader->pNextWindow;
	while ( NULL != pstWindowNode)
	{
		if (pstWindowNode->nMenuID != pstCurrWindow->nMenuID)
		{
			pstWindowNode->nCheckEvent = FALSE;
		}
		pstWindowNode = pstWindowNode->pNextWindow;
	}
}

void ableAllWin(stWindow*pstCurrWindow)
{
	stWindow*pstWindowNode ;
	stWindow*pstMenuHeader = getMenuHeader(pstCurrWindow);
	pstWindowNode = pstMenuHeader->pNextWindow;
	while ( NULL != pstWindowNode)
	{
		pstWindowNode->nCheckEvent = TRUE;
		pstWindowNode = pstWindowNode->pNextWindow;
	}
}

void deleteAllNodeButHeader(stWindow*pstMenuHeader)
{
	stWindow*pstWindowNode = pstMenuHeader;
	while(NULL != pstWindowNode->pNextWindow)
	{
		pstWindowNode = pstWindowNode->pNextWindow ;
	}
	pstWindowNode = pstWindowNode->pLastWindow ;
	while(NULL != pstWindowNode->pLastWindow)
	{
		deleteOneNodeFromList(pstMenuHeader , pstWindowNode->pNextWindow->nMenuID);
		pstWindowNode = pstWindowNode->pLastWindow ;
	}
	pstWindowNode->pNextWindow = NULL ;
}

int winDownTextDiaologPro(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE,char acTitle[][MAX_DIALOG_SHOW_LENGTH] )
{
	int i = 0;
	struct tagWindow* pstMenuHeader = getMenuHeader(pstCurrWindow);
	if (FALSE == pstCurrWindow->nDraw&& DOWN_TEXT_DIALOG == pstCurrWindow->nKind&&
		FALSE == pstCurrWindow->nMenuDown)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		bar(pstCurrWindow->top.nX+2,pstCurrWindow->top.nY+2,
			pstCurrWindow->top.nX+pstCurrWindow->nLength - 1,pstCurrWindow->top.nY+pstCurrWindow->nHeight-1);
		setcolor(DARKGRAY);
		settextstyle(SMALL_FONT,HORIZ_DIR,6);
		outtextxy(pstCurrWindow->top.nX+5,pstCurrWindow->top.nY+3,acTitle[0]);
		strcpy(pstCurrWindow->acInputTextDialog,acTitle[0]);
		pstCurrWindow->nDraw = TRUE;
	}
	if (FALSE == pstCurrWindow->nMenuDown && DOWN_TEXT_DIALOG == pstCurrWindow->nKind
		&& LEFTBUTTON == pstMSG->nButton &&TRUE == isAPositionInARectangle(pstCurrWindow->top.nX + pstCurrWindow->nLength,pstCurrWindow->top.nY,
		pstCurrWindow->top.nX + pstCurrWindow->nLength +20,pstCurrWindow->top.nY + 20 , pstMSG->MOUSE_position))
	{   
		disableButThisWin(pstCurrWindow);
		for (i = 0;i<pstCurrWindow->nTextLength;i++)
		{
			stWindow*pstDownTextBody=getNewWindow(pstCurrWindow->top.nX, pstCurrWindow->top.nY+pstCurrWindow->nHeight*(i+1)+2,
				pstCurrWindow->nLength + 20,pstCurrWindow->nHeight,DOWN_MENU_BODY,  i+1,acTitle[i]);
			pstDownTextBody->nHaveFather = TRUE;
			pstDownTextBody->nFatherID = pstCurrWindow->nMenuID;
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			addMenuToSystemList(pstMenuHeader,pstDownTextBody);
			pstDownTextBody->pfDrawWindow(pstDownTextBody);
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		pstCurrWindow->nMenuDown = TRUE;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY,
		pstCurrWindow->top.nX+pstCurrWindow->nLength + 20 ,pstCurrWindow->top.nY+(pstCurrWindow->nHeight)*(pstCurrWindow->nTextLength+1)+1,
		pstMSG->MOUSE_position) && DOWN_TEXT_DIALOG == pstCurrWindow->nKind)
	{  
		for (i = pstCurrWindow->nTextLength ; i> 0;i--)
		{  
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			deleteOneNodeFromList( pstMenuHeader, i);  
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	if (DOWN_MENU_BODY == pstCurrWindow->nKind)
	{ 
		struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,pstCurrWindow->nFatherID);
		if (FALSE == pstFatherWindow->nGetInputText)
		{
			strcpy(pstFatherWindow->acInputTextDialog,pstCurrWindow->acTitle);
			pstFatherWindow->nGetInputText = TRUE;
		}
		for(i = pstCurrWindow->nTextLength  ; i> 0;i--)
		{  
			pstMOUSE->pfCloseMOUSE(pstMOUSE);
			deleteOneNodeFromList( pstMenuHeader, i);  
			pstMOUSE->pfShowMOUSE(pstMOUSE);
		}
		ableAllWin(pstFatherWindow);
		pstFatherWindow->nMenuDown = FALSE;
	}
}

int  winProWarningButton(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{  
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList( getMenuHeader(pstCurrWindow), WARNING_WINDOW_ID);  
	ableAllWin(pstCurrWindow);
	deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	return TRUE;
}

int winProWarning(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	stWindow*  pstMENUHeader= getMenuHeader(pstCurrWindow);
	stWindow*pstWarnWindowButton;
	if (FALSE == pstCurrWindow->nActive)
	{
		stWindow*pstWarnWindowButton= getNewWindow(pstCurrWindow->top.nX+100,pstCurrWindow->top.nY+85
			,BUTTON_LENGTH,BUTTON_HEIGHT,BUTTON,  WARNING_WINDOW_BUTTON_ID ,"OK");
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		addMenuToSystemList(pstMENUHeader ,pstWarnWindowButton);
		pstWarnWindowButton->pfDrawWindow(pstWarnWindowButton);
		sound(1000);
		delay(100);
		nosound();
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nActive = TRUE ;
	}
	if (TRUE == pstCurrWindow->nStartMove &&TRUE== pstCurrWindow->nActive
		&&TRUE==pstMOUSE->pfisMove(pstMOUSE))
	{   
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		// deleteOneNodeFromList(pstMENUHeader,WARNING_WINDOW_BUTTON_ID);
		pstWarnWindowButton=findNodeByID(pstCurrWindow,WARNING_WINDOW_BUTTON_ID);
		//getNewWindow(pstCurrWindow->top.nX+100,pstCurrWindow->top.nY+85
		// ,BUTTON_LENGTH,BUTTON_HEIGHT,BUTTON,  WARNING_WINDOW_BUTTON_ID ,"OK");

		// addMenuToSystemList(pstMENUHeader ,pstWarnWindowButton);
		pstWarnWindowButton->top.nX = pstCurrWindow->top.nX+100;
		pstWarnWindowButton->top.nY = pstCurrWindow->top.nY+85;
		pstWarnWindowButton->pfDrawWindow(pstWarnWindowButton);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nActive = TRUE ;
	}
	return TRUE;
}

int Allert(struct tagWindow*pstCurrWindow,struct tagMOUSE*pstMOUSE,char acWarn[])
{    
	stWindow*  pstMENUHeader= getMenuHeader(pstCurrWindow);
	stWindow*pstWarnWindow= getNewWindow(200,200,254,124,WARNING_WINDOW,  WARNING_WINDOW_ID ,acWarn);
	// pstWarnWindow->nGetInputText = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	addMenuToSystemList(pstMENUHeader ,pstWarnWindow);
	pstWarnWindow->pfDrawWindow(pstWarnWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	disableButThisWin(pstWarnWindow);
}

void cleardevice()
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
}