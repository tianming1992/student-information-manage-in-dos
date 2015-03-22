#include "STUMENU.h"


void initStudentMenuSys(struct tagWindow*pstCurrWindow,struct tagMOUSE*pstMOUSE,struct tagMessage*pstMSG)
{
	stWindow*pstWindowNode ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	deleteAllNodeButHeader(pstMENUHeader);
	
	stWindow*pstDownMenu111=getNewWindow(3,22,116,25,DOWN_MENU_HEADER,  STUDENT_INFORMATION ,"Information");
	stWindow*pstDownMenu112=getNewWindow(123,22,116,25,DOWN_MENU_HEADER,  STUDENT_CLASS ,"Class&Table");
	stWindow*pstDownMenu113=getNewWindow(243,22,116,25,DOWN_MENU_HEADER,  STUDENT_SCORES ,"My Scores");
	stWindow*pstDownMenu114=getNewWindow(363,22,116,25,DOWN_MENU_HEADER,  STUDENT_HELP ,"Help");
	stWindow*pstDownMenu115=getNewWindow(483,22,116,25,DOWN_MENU_HEADER,  STUDENT_ABOUT,"About");
	/*test down text dialog*/ 
	/*stWindow*pstDownTextDialog=getNewWindow(200,200,200,20,DOWN_TEXT_DIALOG,  355,"name");
	stWindow*pstTextDialog =getNewWindow(200,250,TEXT_DIALOG_LENGTH,20,TEXTDIALOG,  356,"stuID"); 
	stWindow*pstChooseCircle =getNewWindow(200,300,50,20,CHOOSE_CIRCLE,  357,"stuID"); 
	stWindow*pstPasswordDialog =getNewWindow(200,350,TEXT_DIALOG_LENGTH,20,PASSWORD_DIALOG,  358,"stuID"); */
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	drawBackPage("STUDENT INFORMATION MANGE SYSTEM");
	pstMENUHeader->pLastWindow = NULL;
	pstMENUHeader->pNextWindow = NULL;
	addMenuToSystemList(pstMENUHeader,pstDownMenu111);
	addMenuToSystemList(pstMENUHeader,pstDownMenu112);
	addMenuToSystemList(pstMENUHeader,pstDownMenu113);
	addMenuToSystemList(pstMENUHeader,pstDownMenu114);
	addMenuToSystemList(pstMENUHeader,pstDownMenu115);
	pstWindowNode = pstMENUHeader->pNextWindow;
	while (pstWindowNode != NULL)
	{
		pstWindowNode->pfDrawWindow(pstWindowNode);
		pstWindowNode = pstWindowNode->pNextWindow;
	}
    pstMOUSE->pfShowMOUSE(pstMOUSE);
}

int  backtostuinit(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	stWindow*pstWindow ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	for (pstWindow = pstMENUHeader;NULL != pstWindow;)
	{   
		if ( pstWindow->nMenuID> 140)
		{
			pstWindow =deleteCurrReturnLast(pstWindow);
		}
		pstWindow = pstWindow->pNextWindow ;
	}
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
}

/*STUDENT_INFORMATION*/
int  winProFunc111(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody121=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,  STUDENT_INFORMATION_MY_INFO ,"My information");
		stWindow*pstDownMenuBody122=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  STUDENT_INFORMATION_EDIT_INFO ,"Edit information");
		stWindow*pstDownMenuBody130=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*2,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  	 STUDENT_INFORMATION_LOGIN  ,"Login Again");
		stWindow*pstDownMenuBody123=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*3,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  STUDENT_INFORMATION_EXIT ,"Exit");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody121);  
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody122);
        addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody130);	
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody123);
	    pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody121->pfDrawWindow(pstDownMenuBody121);
		pstDownMenuBody122->pfDrawWindow(pstDownMenuBody122);
		pstDownMenuBody130->pfDrawWindow(pstDownMenuBody130);
		pstDownMenuBody123->pfDrawWindow(pstDownMenuBody123);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		pstCurrWindow->nMenuDown = TRUE ;
	}
	if (TRUE == pstCurrWindow->nMenuDown && FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,
		pstCurrWindow->top.nY,pstCurrWindow->top.nX +pstCurrWindow->nLength,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*4,pstMSG->MOUSE_position )&&
		FALSE == isAPositionInARectangle(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
		pstCurrWindow->nHeight,pstCurrWindow->top.nX +DOWN_MENU_BODY_LENGTH,
		pstCurrWindow->top.nY+pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*4,pstMSG->MOUSE_position))
	{     
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EXIT);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_LOGIN);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EDIT_INFO );
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_INFORMATION_MY_INFO);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
}

/*STUDENT_CLASS */
int  winProFunc112(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody124=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,  STUDENT_CLASS_TABLE ,"My class table");
		stWindow*pstDownMenuBody125=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  STUDENT_CLASS_TEACHER ,"My teacher");
		stWindow*pstDownMenuBody126=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*2,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  STUDENT_CLASS_CHOOSE ,"Choose class");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody124);  
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody125);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody126);
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody124->pfDrawWindow(pstDownMenuBody124);
		pstDownMenuBody125->pfDrawWindow(pstDownMenuBody125);
		pstDownMenuBody126->pfDrawWindow(pstDownMenuBody126);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_CLASS_CHOOSE);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_CLASS_TEACHER );
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_CLASS_TABLE);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
}

/*STUDENT_SCORES*/
int winProFunc113(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody127=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,  STUDENT_SCORES_MYSCORE ,"My Scores");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody127);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody127->pfDrawWindow(pstDownMenuBody127);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_SCORES_MYSCORE);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
}

/*STUDENT_HELP*/
int winProFunc114(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody128=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY, STUDENT_HELP_HELP_INFO  ,"Help Infomation");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody128);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody128->pfDrawWindow(pstDownMenuBody128);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_HELP_HELP_INFO );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
} 

/*STUDENT_ABOUT*/
int winProFunc115(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody129=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH-60,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY, STUDENT_ABOUT_THIS_SYSTEM  ,"About System");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody129);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody129->pfDrawWindow(pstDownMenuBody129);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_ABOUT_THIS_SYSTEM );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
}

/* STUDENT_INFORMATION_MY_INFO */
int  winProFunc121(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EXIT);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_LOGIN);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EDIT_INFO );
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	cleardevice();
    pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	return TRUE;
}

/*edit info*/
int winProFunc122(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{  
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	stWindow*pstBaseButton141 =getNewWindow(10,60,BUTTON_LENGTH+80,BUTTON_HEIGHT,BUTTON,141 ,"EDIT BaseInfo");
	stWindow*pstSchoolButton142 =getNewWindow(150,60,BUTTON_LENGTH+80,BUTTON_HEIGHT,BUTTON,142 ,"EDIT SchoolInfo"); 
	stWindow*pstPasswordButton143 =getNewWindow(290,60,BUTTON_LENGTH+80,BUTTON_HEIGHT,BUTTON,143 ,"EDIT PassWord"); 

	stWindow* pstTrueName= getNewWindow(150,120,250,20,TEXTDIALOG,144 ,"true name");
    stWindow* pstBirthday = getNewWindow(150,160,250,20,TEXTDIALOG,145  ,"birth day");
	stWindow* pstIDcard = getNewWindow(150,200,250,20,TEXTDIALOG,146,"card id");
	stWindow* pstNation = getNewWindow(150,240,250,20,TEXTDIALOG,147,"nation");
	stWindow* pstTel= getNewWindow(150,280,250,20,TEXTDIALOG,148 ,"Tel");
	stWindow* pstOKButton149 = getNewWindow(450,420,BUTTON_LENGTH,25,BUTTON,149,"OK");
	
    struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EXIT);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_LOGIN);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_MY_INFO);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstBaseButton141);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstSchoolButton142);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstPasswordButton143);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTrueName);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstBirthday);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstIDcard);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstNation);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTel);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstOKButton149);
	cleardevice();
	pstBaseButton141->pfDrawWindow(pstBaseButton141);
	pstSchoolButton142->pfDrawWindow(pstSchoolButton142);
	pstPasswordButton143->pfDrawWindow(pstPasswordButton143);
	pstTrueName->pfDrawWindow(pstTrueName);
	pstBirthday->pfDrawWindow(pstBirthday);
	pstIDcard->pfDrawWindow(pstIDcard);
	pstNation->pfDrawWindow(pstNation);
	pstTel->pfDrawWindow(pstTel);
	pstOKButton149->pfDrawWindow(pstOKButton149);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	
	return TRUE;
}

/*STUDENT_INFORMATION_EXIT */
int winProFunc123(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{    
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_LOGIN);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EDIT_INFO );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_MY_INFO);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	freeList(pstMSG,getMenuHeader(pstCurrWindow));
	closegraph();
	exit(0);
	return TRUE;
}
/* STUDENT_INFORMATION_LOGIN*/ 
int winProFunc130(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{    
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_INFORMATION);
	stWindow*pstWindowNode ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);                                                                                                                                                                                                      
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EXIT);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_EDIT_INFO );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_INFORMATION_MY_INFO);
	ableAllWin(pstCurrWindow);
	deleteAllNodeButHeader(pstMENUHeader);
	stWindow*pstTextDialog411=getNewWindow(190,240,TEXT_DIALOG_LENGTH,20,TEXTDIALOG,    LOGIN_ID_DIALOG ,"username");
	stWindow*pstPassword412 =getNewWindow(190,290,TEXT_DIALOG_LENGTH,20,PASSWORD_DIALOG,  LOGIN_PASSWORD,"password"); 
	stWindow*pstButton413 =getNewWindow(370,350,BUTTON_LENGTH,BUTTON_HEIGHT,BUTTON,   LOGIN_LOGIN_BUTTON ,"login"); 
	stWindow*pstButton414 =getNewWindow(270,350,BUTTON_LENGTH,BUTTON_HEIGHT,BUTTON,   LOGIN_QUTI_BUTTON ,"quit"); 
	stWindow*pstButton415 =getNewWindow(355,180,BUTTON_LENGTH+40,BUTTON_HEIGHT,BUTTON,   LOGIN_REGISTER_BUTTON  ,"register"); 
	stWindow*pstChoose416 =getNewWindow(200,220,86,20,CHOOSE_CIRCLE,  LOGIN_CHOOSE_KIND,"choice kind"); 
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	loginPage();
	pstMENUHeader->pLastWindow = NULL;
	pstMENUHeader->pNextWindow = NULL;
	addMenuToSystemList(pstMENUHeader,pstTextDialog411);
	addMenuToSystemList(pstMENUHeader,pstPassword412);
	addMenuToSystemList(pstMENUHeader,pstButton413);
	addMenuToSystemList(pstMENUHeader,pstButton414);
	addMenuToSystemList(pstMENUHeader,pstButton415);
	addMenuToSystemList(pstMENUHeader,pstChoose416);

	pstWindowNode = pstMENUHeader->pNextWindow;
	while (pstWindowNode != NULL)
	{
		pstWindowNode->pfDrawWindow(pstWindowNode);
		pstWindowNode = pstWindowNode->pNextWindow;
	}
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	return TRUE;
}

/*STUDENT_CLASS_TABLE */
int winProFunc124(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	
	/*other pro*/
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_CLASS_CHOOSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_CLASS_TEACHER );
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	cleardevice();
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}

/*STUDENT_CLASS_TEACHER*/
int winProFunc125(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_CLASS_CHOOSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_CLASS_TABLE );
	cleardevice();
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}

/* STUDENT_CLASS_CHOOSE*/
int winProFunc126(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), STUDENT_CLASS_TEACHER);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),STUDENT_CLASS_TABLE );
	cleardevice();
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}

/*STUDENT_SCORES_MYSCORE */
int winProFunc127(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_SCORES);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	cleardevice();
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
    return TRUE;
}

/*STUDENT_HELP_HELP_INFO */
int winProFunc128(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_HELP);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	cleardevice();
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
    return TRUE;
}

/*   STUDENT_ABOUT_THIS_SYSTEM*/
int winProFunc129(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{ 
	/*other pro*/
	backtostuinit(pstCurrWindow,pstMSG,pstMOUSE);
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,STUDENT_ABOUT);
	struct tagWindow*pstTestWindow = findNodeByID(pstCurrWindow,355);  //test
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	cleardevice();
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	if (0 != strcmp(pstTestWindow->acInputTextDialog,"daiqian"))
	{
		Allert(pstCurrWindow,pstMOUSE,"Wrong input!");
	}
	 return TRUE;
}

 /*STUDENT_INFORMATION_EDITBASEINFO*/
int winProFunc141(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	stWindow*pstWindow ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	for (pstWindow = pstMENUHeader;NULL != pstWindow;)
	{   
		if ( pstWindow->nMenuID> 143)
		{
			pstWindow =deleteCurrReturnLast(pstWindow);
		}
		pstWindow = pstWindow->pNextWindow ;
	}
	stWindow* pstTrueName= getNewWindow(150,120,250,20,TEXTDIALOG,144 ,"true name");
	stWindow* pstBirthday = getNewWindow(150,160,250,20,TEXTDIALOG,145  ,"birth day");
	stWindow* pstIDcard = getNewWindow(150,200,250,20,TEXTDIALOG,146,"card id");
	stWindow* pstNation = getNewWindow(150,240,250,20,TEXTDIALOG,147,"nation");
	stWindow* pstTel= getNewWindow(150,280,250,20,TEXTDIALOG,148 ,"Tel");
	stWindow* pstOKButton149 = getNewWindow(450,420,BUTTON_LENGTH,25,BUTTON,149,"OK");
    addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTrueName);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstBirthday);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstIDcard);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstNation);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTel);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstOKButton149);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,100,620,450);
	pstTrueName->pfDrawWindow(pstTrueName);
	pstBirthday->pfDrawWindow(pstBirthday);
	pstIDcard->pfDrawWindow(pstIDcard);
	pstNation->pfDrawWindow(pstNation);
	pstTel->pfDrawWindow(pstTel);
	pstOKButton149->pfDrawWindow(pstOKButton149);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
}

/*#define   STUDENT_EDIT_OKBUTTON   149*/
int winProFunc149(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
  stWindow* pstTrueName= findNodeByID(pstCurrWindow,144);
  stWindow* pstBirthday = findNodeByID(pstCurrWindow,145);
  stWindow* pstIDcard = findNodeByID(pstCurrWindow,146);
  stWindow* pstNation = findNodeByID(pstCurrWindow,147);
  stWindow* pstTel= findNodeByID(pstCurrWindow,148);
  pstMOUSE->pfCloseMOUSE(pstMOUSE);
  if (0 == pstTrueName->nTextLength)
  {
	  Allert(pstCurrWindow , pstMOUSE ,"true name can not be empty!");
	  return FALSE ;
  }
  if (0 == pstBirthday->nTextLength)
  {
	  Allert(pstCurrWindow , pstMOUSE ,"birthday  can not be empty!");
	  return FALSE ;
  }
  if (0 == pstIDcard->nTextLength)
  {
	  Allert(pstCurrWindow , pstMOUSE ,"Id card  can not be empty!");
	  return FALSE ;
  }
  if (0 == pstNation->nTextLength)
  {
	  Allert(pstCurrWindow , pstMOUSE ,"nation  can not be empty!");
	  return FALSE ;
  }
  if (0 == pstTel->nTextLength)
  {
	  Allert(pstCurrWindow , pstMOUSE ,"tel can not be empty!");
	  return FALSE ;
  }
  strcpy(pstMSG->pstCurrStudent->baseInfo.acName,pstTrueName->acInputTextDialog);
  strcpy(pstMSG->pstCurrStudent->baseInfo.acIdentifyCardID,pstIDcard->acInputTextDialog);
  strcpy(pstMSG->pstCurrStudent->baseInfo.acBirthday,pstBirthday->acInputTextDialog);
  strcpy(pstMSG->pstCurrStudent->baseInfo.acNation,pstNation->acInputTextDialog);
  strcpy(pstMSG->pstCurrStudent->baseInfo.acTel,pstTel->acInputTextDialog);
  saveStudentListToFile(pstMSG->pstStudentHeader);
  pstMOUSE->pfCloseMOUSE(pstMOUSE);
  Allert(pstCurrWindow,pstMOUSE,"You have edited your base info!");
  return TRUE ;
}

/*#define   STUDENT_INFORMATION_EDITSCHOOLINFO 142*/
int winProFunc142(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	stWindow*pstWindow ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	for (pstWindow = pstMENUHeader;NULL != pstWindow;)
	{   
		if ( pstWindow->nMenuID> 143)
		{
			pstWindow =deleteCurrReturnLast(pstWindow);
		}
		pstWindow = pstWindow->pNextWindow ;
	}
}
/*#define   STUDENT_INFORMATION_EDITPASSWORD 143*/
int winProFunc143(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	stWindow*pstWindow ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	for (pstWindow = pstMENUHeader;NULL != pstWindow;)
	{   
		if ( pstWindow->nMenuID> 143)
		{
			pstWindow =deleteCurrReturnLast(pstWindow);
		}
		pstWindow = pstWindow->pNextWindow ;
	}
    stWindow* pstPassWordDialog150= getNewWindow(200,150,250,20,PASSWORD_DIALOG,150 ,"old password");
	stWindow* pstPassWordDialog151= getNewWindow(200,190,250,20,PASSWORD_DIALOG,151 ,"new password");
	stWindow* pstPassWordAgainDialog152= getNewWindow(200,230,250,20,PASSWORD_DIALOG,152 ,"password again");
	stWindow* pstOKButton153 = getNewWindow(450,420,BUTTON_LENGTH,25,BUTTON,153,"OK");
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	addMenuToSystemList(pstCurrWindow,pstPassWordDialog150);
	addMenuToSystemList(pstCurrWindow,pstPassWordDialog151);
	addMenuToSystemList(pstCurrWindow,pstPassWordAgainDialog152);
	addMenuToSystemList(pstCurrWindow,pstOKButton153);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,100,620,450);
	pstPassWordDialog150->pfDrawWindow(pstPassWordDialog150);
	pstPassWordDialog151->pfDrawWindow(pstPassWordDialog151);
	pstPassWordAgainDialog152->pfDrawWindow(pstPassWordAgainDialog152);
	pstOKButton153->pfDrawWindow(pstOKButton153);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	return TRUE;
} 
/* STUDENT_EDIT_PASSWORDOK*/
int winProFunc153(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
   stWindow* pstPassWordDialog150 = findNodeByID(pstCurrWindow,150);
   stWindow* pstPassWordDialog151 = findNodeByID(pstCurrWindow,151);
   stWindow* pstPassWordAgainDialog152 = findNodeByID(pstCurrWindow,152);
   printf("%s",pstMSG->pstCurrStudent->baseInfo.acPassWord);
   if (0!=strcmp(pstMSG->pstCurrStudent->baseInfo.acPassWord,pstPassWordDialog150->acInputTextDialog))
   {
	   Allert(pstCurrWindow , pstMOUSE ,"wrong password!");
	   return FALSE ;
   }
   if (0 == pstPassWordDialog151->nTextLength)
   {
	   Allert(pstCurrWindow , pstMOUSE ,"new password can not be empty!");
	   return FALSE ;
   }
   if (0!=strcmp( pstPassWordAgainDialog152->acInputTextDialog,pstPassWordDialog151->acInputTextDialog))
   {
	   Allert(pstCurrWindow , pstMOUSE ,"twice password are not the same!");
	   return FALSE ;
   }
   strcpy(pstMSG->pstCurrStudent->baseInfo.acPassWord,pstPassWordDialog151->acInputTextDialog);
   saveStudentListToFile(pstMSG->pstStudentHeader);
   Allert(pstCurrWindow,pstMOUSE,"you have edited your password");
   return TRUE ;
}