#include "manmenu.h"

void initMangerMenuSys(stWindow*pstCurrWindow , stMOUSE*pstMOUSE ,stMessage*pstMSG)
{
	stWindow*pstWindowNode ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	deleteAllNodeButHeader(pstMENUHeader);
    
	stWindow*pstDownMenu311=getNewWindow(3,22,116,25,DOWN_MENU_HEADER,   MANAGER_INFORMATION  ,"Information");
	stWindow*pstDownMenu312=getNewWindow(123,22,116,25,DOWN_MENU_HEADER,  MANAGER_CLASS    ,"Class");
	stWindow*pstDownMenu313=getNewWindow(243,22,116,25,DOWN_MENU_HEADER, MANAGER_DEPARTMENT   ,"Department");
	stWindow*pstDownMenu314=getNewWindow(363,22,116,25,DOWN_MENU_HEADER, MANAGER_HELP ,"Help");
	stWindow*pstDownMenu315=getNewWindow(483,22,116,25,DOWN_MENU_HEADER,  MANAGER_ABOUT  ,"About");
    pstMOUSE->pfCloseMOUSE(pstMOUSE);
	drawBackPage("MANAGER OF THE INFORMATION PLATOM");
    pstMENUHeader->pLastWindow = NULL;
	pstMENUHeader->pNextWindow = NULL;
	addMenuToSystemList(pstMENUHeader,pstDownMenu311);
	addMenuToSystemList(pstMENUHeader,pstDownMenu312);
	addMenuToSystemList(pstMENUHeader,pstDownMenu313);
	addMenuToSystemList(pstMENUHeader,pstDownMenu314);
	addMenuToSystemList(pstMENUHeader,pstDownMenu315);
	
	pstWindowNode = pstMENUHeader->pNextWindow;
	while (pstWindowNode != NULL)
	{
		pstWindowNode->pfDrawWindow(pstWindowNode);
		pstWindowNode = pstWindowNode->pNextWindow;
	}
	pstMOUSE->pfShowMOUSE(pstMOUSE);
}

int  backtoinit(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{  
	stWindow*pstWindow ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	for (pstWindow = pstMENUHeader;NULL != pstWindow;)
	{   
	   	if ( pstWindow->nMenuID> 340)
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
/*MANAGER_INFORMATION*/
int  winProFunc311(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{   
		
		stWindow*pstDownMenuBody321=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,  MANAGER_INFORMATION_EDIT ,"Edit Password");
		stWindow*pstDownMenuBody322=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  MANAGER_INFORMATION_SEARCH ,"Search");
		stWindow*pstDownMenuBody330=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*2,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  MANAGER_INFORMATION_LOGIN ,"Login Again");
		stWindow*pstDownMenuBody323=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*3,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  MANAGER_INFORMATION_EXIT ,"Exit");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody321);  
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody322);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody323);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody330);
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody321->pfDrawWindow(pstDownMenuBody321);
		pstDownMenuBody322->pfDrawWindow(pstDownMenuBody322);
		pstDownMenuBody330->pfDrawWindow(pstDownMenuBody330);
		pstDownMenuBody323->pfDrawWindow(pstDownMenuBody323);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_INFORMATION_EXIT);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  MANAGER_INFORMATION_LOGIN);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_INFORMATION_SEARCH );
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_INFORMATION_EDIT);
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
}

/*  MANAGER_CLASS  */
int  winProFunc312(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{   
		
		stWindow*pstDownMenuBody324=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,   MANAGER_CLASS_NEW     ,"New class");
		stWindow*pstDownMenuBody325=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  MANAGER_CLASS_SHOW   ,"Show Class");
		stWindow*pstDownMenuBody326=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4+DOWN_MENU_BODY_HEIGHT*2,DOWN_MENU_BODY_LENGTH,
			DOWN_MENU_BODY_HEIGHT,DOWN_MENU_BODY,  MANAGER_CLASS_EDIT ,"Edit class");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody324);  
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody325);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody326);
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody324->pfDrawWindow(pstDownMenuBody324);
		pstDownMenuBody325->pfDrawWindow(pstDownMenuBody325);
		pstDownMenuBody326->pfDrawWindow(pstDownMenuBody326);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_CLASS_EDIT);
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_CLASS_SHOW  );
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_CLASS_NEW  );
        pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
}

/*MANAGER_DEPARTMENT */
int winProFunc313(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{   
		
		stWindow*pstDownMenuBody327=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,   MANAGER_DEPARTMENT_NEW  ,"New Department");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody327);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody327->pfDrawWindow(pstDownMenuBody327);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  MANAGER_DEPARTMENT_NEW );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
}

/* MANAGER_HELP */
int winProFunc314(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody328=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,   MANAGER_HELP_HELP_INFO  ,"Help Infomation");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody328);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody328->pfDrawWindow(pstDownMenuBody328);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),   MANAGER_HELP_HELP_INFO );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
} 

/*MANAGER_ABOUT*/
int winProFunc315(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	if (FALSE == pstCurrWindow->nMenuDown && pstCurrWindow->pfIsMouseInside(pstCurrWindow,pstMSG))
	{
		stWindow*pstDownMenuBody329=getNewWindow(pstCurrWindow->top.nX,pstCurrWindow->top.nY+
			pstCurrWindow->nHeight+4,DOWN_MENU_BODY_LENGTH-60,DOWN_MENU_BODY_HEIGHT,
			DOWN_MENU_BODY,   MANAGER_ABOUT_THIS_SYSTEM   ,"About System");
		disableButThisWin(pstCurrWindow);
		addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDownMenuBody329);  
		pstMOUSE->pfCloseMOUSE(pstMOUSE);
		pstDownMenuBody329->pfDrawWindow(pstDownMenuBody329);
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
		deleteOneNodeFromList(getMenuHeader(pstCurrWindow),   MANAGER_ABOUT_THIS_SYSTEM  );
		pstMOUSE->pfShowMOUSE(pstMOUSE);
		ableAllWin(pstCurrWindow);
		pstCurrWindow->nMenuDown = FALSE;
	}
	return TRUE;
}

/*  MANAGER_INFORMATION_EDIT  */
int  winProFunc321(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{    
    backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	stWindow* pstPassWordDialog361= getNewWindow(200,150,250,20,PASSWORD_DIALOG,361 ,"old password");
	stWindow* pstPassWordDialog362= getNewWindow(200,190,250,20,PASSWORD_DIALOG,362 ,"new password");
	stWindow* pstPassWordAgainDialog363 = getNewWindow(200,230,250,20,PASSWORD_DIALOG,363 ,"password again");
	stWindow* pstOKButton364 = getNewWindow(450,420,BUTTON_LENGTH,25,BUTTON,MANAGER_INFORMATION_EDIT_OK_BUTTON ,"OK");
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_INFORMATION_EXIT);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  MANAGER_INFORMATION_LOGIN);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  MANAGER_INFORMATION_SEARCH);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstPassWordDialog361);
    addMenuToSystemList(getMenuHeader(pstCurrWindow),pstPassWordDialog362);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstPassWordAgainDialog363);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstOKButton364);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
	pstPassWordDialog361->pfDrawWindow(pstPassWordDialog361);
	pstPassWordDialog362->pfDrawWindow(pstPassWordDialog362);
	pstPassWordAgainDialog363->pfDrawWindow(pstPassWordAgainDialog363);  
	pstOKButton364->pfDrawWindow(pstOKButton364);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	return TRUE;
}

/* MANAGER_INFORMATION_SEARCH */
int winProFunc322(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	 backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_INFORMATION_EXIT);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  MANAGER_INFORMATION_LOGIN);
      pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),   MANAGER_INFORMATION_EDIT );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	Allert(pstCurrWindow,pstMOUSE,"HAHA");
	return TRUE;
}

/* MANAGER_INFORMATION_LOGIN */
int winProFunc330(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_INFORMATION);
	stWindow*pstWindowNode ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_INFORMATION_EXIT);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),  MANAGER_INFORMATION_SEARCH);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),   MANAGER_INFORMATION_EDIT );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
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

/*  MANAGER_INFORMATION_EXIT  */
int winProFunc323(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{    
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_INFORMATION);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_INFORMATION_LOGIN );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_INFORMATION_SEARCH );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_INFORMATION_EDIT );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	freeList(pstMSG,getMenuHeader(pstCurrWindow));
	closegraph();
	exit(0);
	return TRUE;
}

/* MANAGER_CLASS_NEW   */
int winProFunc325(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
    backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	stWindow* pstDepartName376= getNewWindow(200,310,250,20,TEXTDIALOG,376 ,"department name");
	stWindow* pstClassName368= getNewWindow(200,80,250,20,TEXTDIALOG,368 ,"class name");
	stWindow* pstClassID369 = getNewWindow(200,120,250,20,TEXTDIALOG,369 ,"class ID");
	stWindow* pstTeacherName370 = getNewWindow(200,150,250,20,TEXTDIALOG,370 ,"teacher name");
	stWindow* pstTeacherID371 = getNewWindow(200,190,250,20,TEXTDIALOG,371 ,"teacher ID");
	stWindow* pstPosition372 = getNewWindow(200,270,250,20,TEXTDIALOG,372 ,"class position");
	stWindow* pstTimeWeek373 = getNewWindow(200,230,50,20,DOWN_TEXT_DIALOG,373 ,"week");
	stWindow* pstTiemRank374 = getNewWindow(320,230,50,20,DOWN_TEXT_DIALOG,374 ,"rank");
	stWindow* pstClassOK375 = getNewWindow(450,420,BUTTON_LENGTH,25, BUTTON,375 ,"OK");
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_CLASS_EDIT );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_CLASS_SHOW );
    addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDepartName376 );
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstClassName368 );
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstClassID369);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTeacherName370);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTeacherID371);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstPosition372);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTimeWeek373);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstTiemRank374);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstClassOK375);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
	pstDepartName376->pfDrawWindow(pstDepartName376);
	pstClassName368->pfDrawWindow(pstClassName368);
	pstClassID369->pfDrawWindow(pstClassID369);
	pstTeacherName370->pfDrawWindow(pstTeacherName370);
	pstTeacherID371->pfDrawWindow(pstTeacherID371);
	pstPosition372->pfDrawWindow(pstPosition372);
	pstTimeWeek373->pfDrawWindow(pstTimeWeek373);
	pstTiemRank374->pfDrawWindow(pstTiemRank374);
	pstClassOK375->pfDrawWindow(pstClassOK375);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
    return TRUE;
}

/* MANAGER_CLASS_SHOW*/
int winProFunc326(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	 backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_CLASS_EDIT);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), MANAGER_CLASS_NEW );
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);

	return TRUE;
}

/*  MANAGER_CLASS_EDIT*/
int winProFunc327(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_CLASS);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_CLASS_SHOW );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),MANAGER_CLASS_NEW  );
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
	ableAllWin(pstCurrWindow);
    return TRUE;
}

/*   MANAGER_DEPARTMENT_NEW */
int winProFunc324(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	backtoinit(pstCurrWindow,pstMSG,pstMOUSE);///////////////////////
	stWindow* pstDepartName365= getNewWindow(200,200,250,20,TEXTDIALOG,365 ,"department name");
	stWindow* pstDepartID366 = getNewWindow(200,250,250,20,TEXTDIALOG,366 ,"department ID");
	stWindow* pstOKButton367 = getNewWindow(450,420,BUTTON_LENGTH,25, BUTTON,MANAGER_DEPARTMENT_NEW_OK_BUTTON ,"OK");
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,  MANAGER_DEPARTMENT);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDepartName365);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstDepartID366);
	addMenuToSystemList(getMenuHeader(pstCurrWindow),pstOKButton367);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450);
	pstDepartName365->pfDrawWindow(pstDepartName365);
	pstDepartID366->pfDrawWindow(pstDepartID366);
	pstOKButton367->pfDrawWindow(pstOKButton367);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	return TRUE;
}

/* MANAGER_HELP_HELP_INFO   */
int winProFunc328(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
    backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,MANAGER_HELP);
	pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
	return TRUE;
}

/*   MANAGER_ABOUT_THIS_SYSTEM  */
int winProFunc329(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{ 
	 backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	/*other pro*/
	struct tagWindow*pstFatherWindow = findNodeByID(pstCurrWindow,  MANAGER_ABOUT);
   pstFatherWindow->nMenuDown = FALSE ;
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	pstCurrWindow = deleteCurrReturnLast(pstCurrWindow);
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	ableAllWin(pstCurrWindow);
   return TRUE;
}

/*MANAGER_INFORMATION_EDIT_OK_BUTTON*/
int winProFunc364(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
   struct tagWindow*pstOldPassword = findNodeByID(pstCurrWindow,  361);
   struct tagWindow*pstNewPassword= findNodeByID(pstCurrWindow, 362);
   struct tagWindow*pstNewPasswordAgain = findNodeByID(pstCurrWindow, 363);
   if (0!=strcmp(pstMSG->pstCurrManger->acPassWord,pstOldPassword->acInputTextDialog))
   {
	   Allert(pstCurrWindow , pstMOUSE ,"wrong password!");
	   return FALSE ;
   }
   if (0 == pstNewPassword->nTextLength)
   {
	   Allert(pstCurrWindow , pstMOUSE ,"new password can not be empty!");
	   return FALSE ;
   }
   if (0!=strcmp( pstNewPassword->acInputTextDialog,pstNewPasswordAgain->acInputTextDialog))
   {
	   Allert(pstCurrWindow , pstMOUSE ,"twice password are not the same!");
	   return FALSE ;
   }
   strcpy(pstMSG->pstMangerHeader->acPassWord , pstNewPassword->acInputTextDialog);
   saveMangerToFile(pstMSG->pstMangerHeader);
   pstMOUSE->pfCloseMOUSE(pstMOUSE);
   deleteOneNodeFromList(getMenuHeader(pstCurrWindow),361);
   deleteOneNodeFromList(getMenuHeader(pstCurrWindow),362);
   deleteOneNodeFromList(getMenuHeader(pstCurrWindow),363);
   deleteCurrReturnLast(pstCurrWindow);
   setcolor(WHITE);
   setfillstyle(SOLID_FILL ,WHITE);
   bar(10,60,620,450);  
   pstMOUSE->pfShowMOUSE(pstMOUSE);
   return TRUE ;
}

/* MANAGER_DEPARTMENT_NEW_OK_BUTTON*/
int winProFunc367(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	stWindow* pstDepartName365=findNodeByID(pstCurrWindow,365); 
	stWindow* pstDepartID366 = findNodeByID(pstCurrWindow,366);
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	if (0 == pstDepartName365->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"Department name can not be empty!");
		return FALSE ;
	}

	if (0 == pstDepartID366->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"Department ID can not be empty!");
		return FALSE ;
	}
	stDepartment * pstNodeToAdd = (stDepartment *)calloc(1,sizeof(stDepartment));
    strcpy(pstNodeToAdd->acDepartment ,pstDepartName365->acInputTextDialog);//
	strcpy(pstNodeToAdd->acDepartID,pstDepartID366->acInputTextDialog);
	if(NULL == findDepartmentByName(pstMSG->pstDepartment,pstNodeToAdd))
		
	{
		addDepartmentToList(pstMSG->pstDepartment,pstNodeToAdd);
	    saveDepartmentListToFile(pstMSG->pstDepartment);
	}
	else
	{
		Allert(pstCurrWindow , pstMOUSE ,"This department exists already!");
		return FALSE ;
	}
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),365);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow),366);
	deleteCurrReturnLast(pstCurrWindow);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL ,WHITE);
	bar(10,60,620,450); 
	pstMOUSE->pfShowMOUSE(pstMOUSE);
	return TRUE ;
}

/*MANAGER_CLASS_NEW_TIMEWEEK 373*/
int  winProFunc373(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	char test[5][MAX_DIALOG_SHOW_LENGTH] = {"Mon","Tues","Wen","Thur","Fri"};
	pstCurrWindow->nTextLength = 5;
	winDownTextDiaologPro(pstCurrWindow,pstMSG,pstMOUSE,test);
	if (TRUE ==pstCurrWindow->nGetInputText)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		bar(pstCurrWindow->top.nX+2,pstCurrWindow->top.nY+2,
			pstCurrWindow->top.nX+pstCurrWindow->nLength - 1,pstCurrWindow->top.nY+pstCurrWindow->nHeight-1);
		setcolor(DARKGRAY);
		settextstyle(SMALL_FONT,HORIZ_DIR,6);
		outtextxy(pstCurrWindow->top.nX+5,pstCurrWindow->top.nY+3,pstCurrWindow->acInputTextDialog);
		pstCurrWindow->nGetInputText = FALSE;

	}
	return TRUE ;
}

/*MANAGER_CLASS_NEW_TIMERANK 374*/
int  winProFunc374(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	char test[4][MAX_DIALOG_SHOW_LENGTH] = {"NO.1","NO.2","NO.3","NO.4"};
	pstCurrWindow->nTextLength = 4;
	winDownTextDiaologPro(pstCurrWindow,pstMSG,pstMOUSE,test);
	if (TRUE ==pstCurrWindow->nGetInputText)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		bar(pstCurrWindow->top.nX+2,pstCurrWindow->top.nY+2,
			pstCurrWindow->top.nX+pstCurrWindow->nLength - 1,pstCurrWindow->top.nY+pstCurrWindow->nHeight-1);
		setcolor(DARKGRAY);
		settextstyle(SMALL_FONT,HORIZ_DIR,6);
		outtextxy(pstCurrWindow->top.nX+5,pstCurrWindow->top.nY+3,pstCurrWindow->acInputTextDialog);
		pstCurrWindow->nGetInputText = FALSE;

	}
	return TRUE ;
}

/*MANAGER_CLASS_NEW_OK 375*/
int winProFunc375(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
    struct tagWindow*pstCLASSNAME = findNodeByID(pstCurrWindow,  368);
	struct tagWindow*pstCLASSID = findNodeByID(pstCurrWindow,  369);
	struct tagWindow*pstTEACHERNAME = findNodeByID(pstCurrWindow,  370);
	struct tagWindow*pstTEACHERID = findNodeByID(pstCurrWindow,  371);
	struct tagWindow*pstPOSITION = findNodeByID(pstCurrWindow,  372);
	struct tagWindow*pstTIMEWEEK = findNodeByID(pstCurrWindow,  373);
	struct tagWindow*pstTIMERANK = findNodeByID(pstCurrWindow,  374);
	struct tagWindow*pstDepart = findNodeByID(pstCurrWindow,  376);
	stClass * pstNodeToAdd = (stClass *)calloc(1,sizeof(stClass ));
	if (0 == pstCLASSNAME ->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"class name can not be empty!");
		return FALSE ;
	}
	if (0 == pstCLASSID->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"class ID can not be empty!");
		return FALSE ;
	}
	if (0 == pstTEACHERNAME->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"teacher name can not be empty!");
		return FALSE ;
	}
	if (0 == pstTEACHERID->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"teacher ID can not be empty!");
		return FALSE ;
	}
	if (0 == pstPOSITION->nTextLength)
	{
		Allert(pstCurrWindow , pstMOUSE ,"class position  can not be empty!");
		return FALSE ;
	}
	strcpy(pstNodeToAdd->acClassName,pstCLASSNAME->acInputTextDialog);
	strcpy(pstNodeToAdd->acClassId,pstCLASSID->acInputTextDialog);
	strcpy(pstNodeToAdd->acTeacnerName,pstTEACHERNAME->acInputTextDialog);
	strcpy(pstNodeToAdd->acTeacherID,pstTEACHERID->acInputTextDialog);
	strcpy(pstNodeToAdd->acPosition,pstPOSITION->acInputTextDialog);
	strcpy(pstNodeToAdd->acDepart,pstDepart->acInputTextDialog);
	if (0 == strcmp(pstTIMEWEEK->acInputTextDialog , "Mon"))
	{
		pstNodeToAdd->classTime.nWeek = 1;
	}
	if (0 == strcmp(pstTIMEWEEK->acInputTextDialog , "Tues"))
	{
		pstNodeToAdd->classTime.nWeek = 2;
	}
	if (0 == strcmp(pstTIMEWEEK->acInputTextDialog , "Wen"))
	{
		pstNodeToAdd->classTime.nWeek = 3;
	}
	if (0 == strcmp(pstTIMEWEEK->acInputTextDialog , "Thur"))
	{
		pstNodeToAdd->classTime.nWeek = 4;
	}
	if (0 == strcmp(pstTIMEWEEK->acInputTextDialog , "Fri"))
	{
		pstNodeToAdd->classTime.nWeek = 5;
	}
	
	if (0 == strcmp(pstTIMERANK->acInputTextDialog , "NO.1"))
	{
		pstNodeToAdd->classTime.nRank  = 1;
	}
	if (0 == strcmp(pstTIMERANK->acInputTextDialog , "NO.2"))
	{
		pstNodeToAdd->classTime.nRank  = 2;
	}
	if (0 == strcmp(pstTIMERANK->acInputTextDialog , "NO.3"))
	{
		pstNodeToAdd->classTime.nRank  = 3;
	}
	if (0 == strcmp(pstTIMERANK->acInputTextDialog , "NO.4"))
	{
		pstNodeToAdd->classTime.nRank  = 4;
	}
	if (NULL == findClassByID(pstMSG->pstClassHeader,pstNodeToAdd))
	{
		addClassToList(pstMSG->pstClassHeader,pstNodeToAdd);
		saveClassListToFile(pstMSG->pstClassHeader);
	}
	else
	{
		Allert(pstCurrWindow , pstMOUSE ,"This class ID have already existed!");
		return FALSE ;
    }
	pstNodeToAdd = findClassByDepartName(pstMSG->pstClassHeader,"english");
	backtoinit(pstCurrWindow,pstMSG,pstMOUSE);
	return TRUE ;
}


