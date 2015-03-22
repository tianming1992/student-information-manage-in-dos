#include "teamenu.h"


void initTeacherMenuSys(struct tagWindow*pstCurrWindow,struct tagMOUSE*pstMOUSE,struct tagMessage*pstMSG)
{
	stWindow*pstWindowNode ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	deleteAllNodeButHeader(pstMENUHeader);

	stWindow*pstDownMenu211=getNewWindow(3,22,116,25,DOWN_MENU_HEADER,   TEACHER_INFORMATION,"Information");
	stWindow*pstDownMenu212=getNewWindow(123,22,116,25,DOWN_MENU_HEADER,  TEACHER_CLASS ,"Class");
	stWindow*pstDownMenu213=getNewWindow(243,22,116,25,DOWN_MENU_HEADER,  TEACHER_SCORES ,"Scores");
	stWindow*pstDownMenu214=getNewWindow(363,22,116,25,DOWN_MENU_HEADER,   TEACHER_HELP ,"Help");
	stWindow*pstDownMenu215=getNewWindow(483,22,116,25,DOWN_MENU_HEADER,    TEACHER_ABOUT ,"About");
	/*test down text dialog*/ 
	/*stWindow*pstDownTextDialog=getNewWindow(200,200,200,20,DOWN_TEXT_DIALOG,  355,"name");
	stWindow*pstTextDialog =getNewWindow(200,250,TEXT_DIALOG_LENGTH,20,TEXTDIALOG,  356,"stuID"); 
	stWindow*pstChooseCircle =getNewWindow(200,300,50,20,CHOOSE_CIRCLE,  357,"stuID"); 
	stWindow*pstPasswordDialog =getNewWindow(200,350,TEXT_DIALOG_LENGTH,20,PASSWORD_DIALOG,  358,"stuID"); */
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	drawBackPage("TEACHER INFORMATION MANGE SYSTEM");
	pstMENUHeader->pLastWindow = NULL;
	pstMENUHeader->pNextWindow = NULL;
	addMenuToSystemList(pstMENUHeader,pstDownMenu211);
	addMenuToSystemList(pstMENUHeader,pstDownMenu212);
	addMenuToSystemList(pstMENUHeader,pstDownMenu213);
	addMenuToSystemList(pstMENUHeader,pstDownMenu214);
	addMenuToSystemList(pstMENUHeader,pstDownMenu215);
	pstWindowNode = pstMENUHeader->pNextWindow;
	while (pstWindowNode != NULL)
	{
		pstWindowNode->pfDrawWindow(pstWindowNode);
		pstWindowNode = pstWindowNode->pNextWindow;
	}
	pstMOUSE->pfShowMOUSE(pstMOUSE);
}



/*   TEACHER_INFORMATION */
int  winProFunc211(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody221=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,  TEACHER_INFORMATION_MYINFO ,"My information");
		stWindow*pstDownMenuBody222=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,   TEACHER_INFORMATION_EDIT  ,"Edit information");
		stWindow*pstDownMenuBody223=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*2,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY, TEACHER_INFORMATION_EXIT ,"Exit");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody221);  
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody222);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody223);
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody221->pfDrawWindow(pstDownMenuBody221);
		pstDownMenuBody222->pfDrawWindow(pstDownMenuBody222);
		pstDownMenuBody223->pfDrawWindow(pstDownMenuBody223);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nMenuDown = TRUE ;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,
		pstCurrWindow->top.nY,pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*3,pstMSG->MOUSE_position )&&
		FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight,pstCurrWindow->top.nX +DOWN_MENU_BODY_LENGTH,
		pstCurrWindow->top.nY+pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*3,pstMSG->MOUSE_position))
	{     
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_EXIT);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_EDIT );
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), TEACHER_INFORMATION_MYINFO);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
}

/*   TEACHER_CLASS    */
int  winProFunc212(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody224=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,   TEACHER_CLASS_MYCLASS ,"My class table");
		stWindow*pstDownMenuBody225=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY, TEACHER_CLASS_STU  ,"my students");
		stWindow*pstDownMenuBody226=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*2,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,   TEACHER_CLASS_EDIT ,"exit info");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody224);  
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody225);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody226);
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody224->pfDrawWindow(pstDownMenuBody224);
		pstDownMenuBody225->pfDrawWindow(pstDownMenuBody225);
		pstDownMenuBody226->pfDrawWindow(pstDownMenuBody226);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nMenuDown = TRUE ;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,
		pstCurrWindow->top.nY,pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*3,pstMSG->MOUSE_position )&&
		FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight,pstCurrWindow->top.nX +DOWN_MENU_BODY_LENGTH,
		pstCurrWindow->top.nY+pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*3,pstMSG->MOUSE_position))
	{     
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_CLASS_EDIT);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_CLASS_STU );
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), TEACHER_CLASS_MYCLASS);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
}

/*  TEACHER_SCORES  */
int winProFunc213(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody227=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,  TEACHER_SCORES_INPUT ,"Input Scores");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody227);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody227->pfDrawWindow(pstDownMenuBody227);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nMenuDown = TRUE ;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,
		pstCurrWindow->top.nY,pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,pstMSG->MOUSE_position )&&
		FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight,pstCurrWindow->top.nX +DOWN_MENU_BODY_LENGTH,
		pstCurrWindow->top.nY+pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,pstMSG->MOUSE_position))
	{     
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), TEACHER_SCORES_INPUT);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
}

/*  TEACHER_HELP   */
int winProFunc214(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody228=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY, TEACHER_HELP_HELP_INFO  ,"Help Infomation");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody228);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody228->pfDrawWindow(pstDownMenuBody228);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nMenuDown = TRUE ;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,
		pstCurrWindow->top.nY,pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,pstMSG->MOUSE_position )&&
		FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight,pstCurrWindow->top.nX +DOWN_MENU_BODY_LENGTH,
		pstCurrWindow->top.nY+pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,pstMSG->MOUSE_position))
	{     
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), TEACHER_HELP_HELP_INFO  );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
} 

/*   TEACHER_ABOUT */
int winProFunc215(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody229=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH-60,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY, TEACHER_ABOUT_ABOUT ,"About System");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody229);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody229->pfDrawWindow(pstDownMenuBody229);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nMenuDown = TRUE ;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,
		pstCurrWindow->top.nY,pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,pstMSG->MOUSE_position )&&
		FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight,pstCurrWindow->top.nX +DOWN_MENU_BODY_LENGTH-60,
		pstCurrWindow->top.nY+pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,pstMSG->MOUSE_position))
	{     
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), TEACHER_ABOUT_ABOUT );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
}

/*TEACHER_INFORMATION_MYINFO  :*/
int  winProFunc221(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_EXIT);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_EDIT );
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	Allert(pstCurrWindow,pstMOUSE,"wo X ! ");
	return TRUE;
}

/* TEACHER_INFORMATION_EDIT  */
int winProFunc222(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_EXIT);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_MYINFO );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	Allert(pstCurrWindow,pstMOUSE,"HAHA");
	return TRUE;
}

/* TEACHER_INFORMATION_EXIT  */
int winProFunc223(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{    
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_EDIT );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_INFORMATION_MYINFO );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	Allert(pstCurrWindow,pstMOUSE,"HAHA");
	return TRUE;
}

/* TEACHER_CLASS_MYCLASS  :*/
int winProFunc224(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), TEACHER_CLASS_EDIT);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_CLASS_STU );
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}



/* TEACHER_CLASS_STU:*/
int winProFunc225(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  TEACHER_CLASS_EDIT);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_CLASS_MYCLASS);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}


/*TEACHER_CLASS_EDIT */
int winProFunc226(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  TEACHER_CLASS_STU );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),TEACHER_CLASS_MYCLASS );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}

/* TEACHER_SCORES_INPUT */
int winProFunc227(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow, TEACHER_SCORES);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	return TRUE;
}

/*TEACHER_HELP_HELP_INFO */
int winProFunc228(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,TEACHER_HELP);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	return TRUE;
}

/*  TEACHER_ABOUT_THIS_SYSTEM*/
int winProFunc229(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{ 
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow, TEACHER_ABOUT);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	
	return TRUE;
}