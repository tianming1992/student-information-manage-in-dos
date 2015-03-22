#include "MENUSYS.h"


int  Eventpro(struct tagWindow*pstMenuHeader,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE)
{
	stWindow* pstWindowNode=pstMenuHeader->pNextWindow;
	while (NULL != pstWindowNode )
	{   
		if(TRUE == pstWindowNode->nCheckEvent)
		{
			if (pstWindowNode->pfEventSelfAction(pstWindowNode,pstMsg,pstMOUSE) > 0)
			{
				windowPro( pstWindowNode,pstMsg,pstMOUSE);
                windowPro2( pstWindowNode,pstMsg,pstMOUSE);
			} 
		}
		pstWindowNode = pstWindowNode->pNextWindow ;
	}
	return TRUE;
}

stWindow* initLoginMenuSystem(stMOUSE*pstMOUSE)
{
	stWindow* pstWindowNode;
	stWindow*pstMENUHeader= getNewWindow(3,22,116,25,DOWN_MENU_HEADER,  STUDENT_MENU_HEADER ,"HEADER");
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
	return pstMENUHeader ;
}

/* LOGIN_LOGIN_BUTTON*/
int  winProFunc413(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
     char acID[35];
	 struct tagWindow*pstuserNameWindow = findNodeByID(pstCurrWindow, LOGIN_ID_DIALOG);
	 struct tagWindow*pstPasswordWindow = findNodeByID(pstCurrWindow, LOGIN_PASSWORD);
     struct tagWindow*pstUserkind = findNodeByID(pstCurrWindow, LOGIN_CHOOSE_KIND);
     if (0 == pstuserNameWindow ->nTextLength)
     {
		 Allert(pstCurrWindow,pstMOUSE,"user name can't be empty !") ;
		 return FALSE ;
     }
	 if (0 == pstPasswordWindow->nTextLength)
	 {
		 Allert(pstCurrWindow,pstMOUSE,"password can not be empty ! ") ;
	     return FALSE ;
	 }
	 if (0 == strcmp(pstuserNameWindow->acInputTextDialog , "ADMIN"))
	 {
		 if(0 == strcmp(pstPasswordWindow->acInputTextDialog , pstMSG->pstMangerHeader->acPassWord))
		 {
              initMangerMenuSys(pstCurrWindow,pstMOUSE,pstMSG);
			  pstMSG->pstCurrManger =pstMSG->pstMangerHeader ;
			  return TRUE ;
		 }
		 else
		 {
			 Allert(pstCurrWindow,pstMOUSE,"password wrong ! ") ;
			 return FALSE ;
		 }
	 }
     if (TRUE == pstUserkind->nGetInputText)
	 {
		 stStudent*pstCurrStudent = findStudentByUserName(pstMSG->pstStudentHeader,pstuserNameWindow->acInputTextDialog);
		 if (NULL == pstCurrStudent)
		 {
			 Allert(pstCurrWindow,pstMOUSE,"this student do not exist ! ") ;
			 return FALSE ;
		 }
		 if (0 != strcmp(pstCurrStudent->baseInfo.acPassWord , pstPasswordWindow->acInputTextDialog))
		 {
			 Allert(pstCurrWindow,pstMOUSE,"password wrong ! ") ;
			 return FALSE ;
		 }
		 initStudentMenuSys(pstCurrWindow,pstMOUSE,pstMSG);
	     pstMSG->pstCurrStudent->baseInfo = pstCurrStudent->baseInfo ;
		 pstMSG->pstCurrStudent->schoolInfo = pstCurrStudent->schoolInfo ;
		 pstMSG->pstCurrStudent->classAndScore = pstCurrStudent->classAndScore;
		 printf("%s",pstMSG->pstCurrStudent->baseInfo.acPassWord );//debug by tianming
		 return TRUE ;
	 }
	 if (FALSE == pstUserkind->nGetInputText)
	 {
		 stTeacher*pstCurrTeacher = findTeacherByUserName(pstMSG->pstTeacherHeader,pstuserNameWindow->acInputTextDialog);
		 if (NULL == pstCurrTeacher)
		 {
			 Allert(pstCurrWindow,pstMOUSE,"this teacher do not exist ! ") ;
			 return FALSE ;
		 }
		 if (0 != strcmp(pstCurrTeacher->baseInfo.acPassWord , pstPasswordWindow->acInputTextDialog))
		 {
			 Allert(pstCurrWindow,pstMOUSE,"password wrong ! ") ;
			 return FALSE ;
		 }
		 initTeacherMenuSys(pstCurrWindow,pstMOUSE,pstMSG);
		 pstMSG->pstCurrTeacher->baseInfo = pstCurrTeacher->baseInfo;
         pstMSG->pstCurrTeacher->schoolInfo= pstCurrTeacher->schoolInfo;
		 return TRUE ;
	 }
	 return FALSE ;
}

/*LOGIN_QUTI_BUTTON */
int  winProFunc414(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
    freeMenuList(getMenuHeader(pstCurrWindow));
     closegraph();
	 return TRUE ;
}
                 
 /*LOGIN_REGISTER_BUTTON */
int  winProFunc415(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{     
	 stWindow*	pstWindowNode ;
	 struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
	 stWindow* pstNameDialog450 = getNewWindow(260,95,250,20,TEXTDIALOG,REGISTER_NAME_DIALOG ,"username");
	 stWindow* pstDepartDownText459 = getNewWindow(150,150,290,20,DOWN_TEXT_DIALOG,REGISTER_DEPARTMENT_DOWNTEXT,"department");
	 stWindow* pstIDCardDialog451 = getNewWindow(150,180,250,20,TEXTDIALOG,REGISTER_IDCARD_DIALOG  ,"card id");
	 stWindow* pstBirthdayDialog452 = getNewWindow(150,210,250,20,TEXTDIALOG,REGISTER_BIRTHDAY_DIALOG ,"birthday");
	 stWindow* pstSexChoose453 = getNewWindow(100,105,70,25,CHOOSE_CIRCLE,REGISTER_SEX_CHOOSE  ,"sex");
	 stWindow* pstNationDialog455 = getNewWindow(150,240,250,20,TEXTDIALOG,REGISTER_NATION_DIALOG ,"nation");
	 stWindow* pstUserSortDownText456 = getNewWindow(150,270,116,20,DOWN_TEXT_DIALOG, REGISTER_STUSORT_DOWNTEXT ,"student\teacher");
	 stWindow* pstOKButton460 = getNewWindow(450,420,BUTTON_LENGTH,25,BUTTON,REGISTER_OK_BUTTON ,"OK");
	 stWindow* pstPassWordDialog461= getNewWindow(150,360,250,20,PASSWORD_DIALOG,461 ,"password");
	 stWindow* pstPassWordAgainDialog462 = getNewWindow(150,390,250,20,PASSWORD_DIALOG,462 ,"password again");
	 stWindow* pstBackButton463 = getNewWindow(350,420,BUTTON_LENGTH,25,BUTTON,REGISTER_BACK_BUTTON ,"BACK");
    /*delete the window objects from the menu list*/
	pstMOUSE->pfCloseMOUSE(pstMOUSE);
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), LOGIN_ID_DIALOG );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), LOGIN_PASSWORD );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), LOGIN_LOGIN_BUTTON );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), LOGIN_QUTI_BUTTON );
	deleteOneNodeFromList(getMenuHeader(pstCurrWindow), LOGIN_CHOOSE_KIND );
	deleteCurrReturnLast(pstCurrWindow);

	addMenuToSystemList(pstMENUHeader,pstNameDialog450 );
	addMenuToSystemList(pstMENUHeader,pstDepartDownText459);
	addMenuToSystemList(pstMENUHeader,pstIDCardDialog451);
	addMenuToSystemList(pstMENUHeader, pstBirthdayDialog452 );
	addMenuToSystemList(pstMENUHeader,pstSexChoose453);
	addMenuToSystemList(pstMENUHeader,pstNationDialog455 );
	addMenuToSystemList(pstMENUHeader, pstUserSortDownText456 );
	addMenuToSystemList(pstMENUHeader,pstOKButton460 );
	addMenuToSystemList(pstMENUHeader,pstPassWordDialog461);
	addMenuToSystemList(pstMENUHeader,pstPassWordAgainDialog462 );
	addMenuToSystemList(pstMENUHeader,pstBackButton463);
    registerPage();
	pstWindowNode = pstMENUHeader->pNextWindow;
	while (pstWindowNode != NULL)
	{
		pstWindowNode->pfDrawWindow(pstWindowNode);
		pstWindowNode = pstWindowNode->pNextWindow;
	}
    pstMOUSE->pfShowMOUSE(pstMOUSE);
}

/*register back button*/
int  winProFunc463(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	stWindow*pstWindowNode ;
	struct tagWindow* pstMENUHeader = getMenuHeader(pstCurrWindow);
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
	
}
/* REGISTER_OK_BUTTON  460 */
int  winProFunc460(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	stWindow* pstName= findNodeByID(pstCurrWindow,REGISTER_NAME_DIALOG);
	stWindow* pstDepartment=findNodeByID(pstCurrWindow,REGISTER_DEPARTMENT_DOWNTEXT);
	stWindow*pstIDCard =findNodeByID(pstCurrWindow,REGISTER_IDCARD_DIALOG);
	stWindow*pstBirthday =findNodeByID(pstCurrWindow,REGISTER_BIRTHDAY_DIALOG);
	stWindow* pstSex=findNodeByID(pstCurrWindow,REGISTER_SEX_CHOOSE );
	stWindow* pstNation=findNodeByID(pstCurrWindow,REGISTER_NATION_DIALOG);
	stWindow*pstUserSort =findNodeByID(pstCurrWindow,REGISTER_STUSORT_DOWNTEXT );
    stWindow* pstPassWord=  findNodeByID(pstCurrWindow,461);
	stWindow* pstPassWordAgain=findNodeByID(pstCurrWindow,462);
    if (0 == pstName->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE,"name  can't be empty !") ;
		return FALSE ;
	}
	if (0 == strcmp(pstName->acInputTextDialog , "ADMIN"))
	{
		Allert(pstCurrWindow,pstMOUSE,"can not  register this name !") ;
		return FALSE ;
	}
  if (0 == pstDepartment->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE,"department can not be empty ! ") ;
		return FALSE ;
	}
	if (0 == pstIDCard->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE,"card Id can not be empty ! ") ;
		return FALSE ;
	}
    if (FALSE == checkJustNumber(pstIDCard->acInputTextDialog))
    {
		Allert(pstCurrWindow,pstMOUSE,"card Id can not include characters! ") ;
		return FALSE ;
    }
	if (0 == pstBirthday->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE," birthday not be empty ! ") ;
		return FALSE ;
	}
	if (0 == pstNation->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE,"nation can not be empty ! ") ;
		return FALSE ;
	}
	if (0 == pstPassWord->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE,"password can not be empty ! ") ;
		return FALSE ;
	}
	if (0 == pstPassWordAgain->nTextLength)
	{
		Allert(pstCurrWindow,pstMOUSE,"please input your password again ! ") ;
		return FALSE ;
	}
	if (0 != strcmp(pstPassWord->acInputTextDialog , pstPassWordAgain->acInputTextDialog))
	{
		Allert(pstCurrWindow,pstMOUSE,"twice password are not the same! ") ;
		return FALSE ;
	}
   if (0 == strcmp(pstUserSort->acInputTextDialog ,"student"))
   {
      struct tagStudent *pstToAdd = (struct tagStudent*)calloc(1,sizeof(struct tagStudent));
	  if (FALSE == isSameStudent(pstMSG->pstStudentHeader ,pstName->acInputTextDialog ))
	  {
         	Allert(pstCurrWindow,pstMOUSE,"this user name has been registered! ") ;
			return FALSE ;
	  }
	  strcpy(pstToAdd->baseInfo.acUserName ,pstName->acInputTextDialog);
	  strcpy(pstToAdd->baseInfo.acIdentifyCardID,pstIDCard->acInputTextDialog);
	  strcpy(pstToAdd->baseInfo.acNation,pstNation->acInputTextDialog);
	  strcpy(pstToAdd->baseInfo.acPassWord,pstPassWord->acInputTextDialog);
	  strcpy(pstToAdd->baseInfo.acBirthday,pstBirthday->acInputTextDialog);
	  strcpy(pstToAdd->schoolInfo.acDepartment,pstDepartment->acInputTextDialog);
	  if (TRUE == pstSex->nGetInputText)
	  {
		  pstToAdd->baseInfo.nSex = BOY ;
	  }
	  else
	  {
		  pstToAdd->baseInfo.nSex = GIRL ;
	  }
	  addStudentToList(pstMSG->pstStudentHeader,pstToAdd);
	  saveStudentListToFile(pstMSG->pstStudentHeader);
   }
   if (0 == strcmp(pstUserSort->acInputTextDialog ,"teacher"))
   {
	   struct tagTeacher *pstToAdd = (struct tagTeacher*)calloc(1,sizeof(struct tagTeacher));
	   if (FALSE == isSameTeacher(pstMSG->pstTeacherHeader ,pstName->acInputTextDialog ))
	   {
		   Allert(pstCurrWindow,pstMOUSE,"this user name has been registered! ") ;
		   return FALSE ;
	   }
	   strcpy(pstToAdd->baseInfo.acUserName ,pstName->acInputTextDialog);
	   strcpy(pstToAdd->baseInfo.acIdentifyCardID,pstIDCard->acInputTextDialog);
	   strcpy(pstToAdd->baseInfo.acNation,pstNation->acInputTextDialog);
	   strcpy(pstToAdd->baseInfo.acPassWord,pstPassWord->acInputTextDialog);
	   strcpy(pstToAdd->baseInfo.acBirthday,pstBirthday->acInputTextDialog);
	   strcpy(pstToAdd->schoolInfo.acDepartment,pstDepartment->acInputTextDialog);
	   if (FALSE == pstSex->nGetInputText)
	   {
		   pstToAdd->baseInfo.nSex = BOY ;
	   }
	   else
	   {
		   pstToAdd->baseInfo.nSex = GIRL ;
	   }
	   addTeacherToList(pstMSG->pstTeacherHeader,pstToAdd);
	   saveTeacherListToFile(pstMSG->pstTeacherHeader);
    }
    /*restore the login page*/
   winProFunc463(pstCurrWindow,pstMSG,pstMOUSE);
   return TRUE ;
}

int  winProFunc355(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{   
	char test[6][MAX_DIALOG_SHOW_LENGTH] = {"hello","sorry","sfsdf","sfsf","adfg","daiqian"};
	pstCurrWindow->nTextLength = 6;
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
/* REGISTER_STUSORT_DOWNTEXT 456*/
int  winProFunc456(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	char test[2][MAX_DIALOG_SHOW_LENGTH] = {"student","teacher"};
	pstCurrWindow->nTextLength = 2;
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

/*REGISTER_DEPARTMENT_DOWNTEXT */
int  winProFunc459(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	char test[20][MAX_DIALOG_SHOW_LENGTH];
	int i =0;
	stDepartment* pstDepart = pstMSG->pstDepartment->pstNextDepartment ;
	pstCurrWindow->nTextLength = getDepartmentListLength(pstMSG->pstDepartment);
	for(i = 0 ; i<pstCurrWindow->nTextLength ; i++)
	{   
		
		strcpy(test[i],pstDepart->acDepartment);
		// printf("%s\n",test[i]);
		pstDepart = pstDepart->pstNextDepartment ;
	}
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

int  windowPro(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{
	unsigned long int idToSwitch = pstCurrWindow->nMenuID;
   if (TRUE == pstCurrWindow->nHaveFather )
	{
		 idToSwitch =  pstCurrWindow->nFatherID;
	}
	switch (idToSwitch)
	{
	case  WARNING_WINDOW_ID  :
		winProWarning(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  WARNING_WINDOW_BUTTON_ID  :
		winProWarningButton(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  LOGIN_LOGIN_BUTTON  :
		winProFunc413(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  LOGIN_QUTI_BUTTON  :
		winProFunc414(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case LOGIN_REGISTER_BUTTON:
		winProFunc415(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  REGISTER_BACK_BUTTON  :
		winProFunc463(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case REGISTER_OK_BUTTON:
	    winProFunc460(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  REGISTER_STUSORT_DOWNTEXT :
		winProFunc456(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  REGISTER_DEPARTMENT_DOWNTEXT :
		winProFunc459(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case STUDENT_INFORMATION:
		winProFunc111(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_CLASS  :
		winProFunc112(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case STUDENT_SCORES :
		winProFunc113(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_HELP  :
		winProFunc114(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_ABOUT  :
		winProFunc115(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_INFORMATION_MY_INFO  :
		winProFunc121(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_INFORMATION_EDIT_INFO  :
		winProFunc122(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case STUDENT_INFORMATION_EXIT  :
		winProFunc123(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case STUDENT_INFORMATION_LOGIN :
		winProFunc130(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case STUDENT_CLASS_TABLE  :
		winProFunc124(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case STUDENT_CLASS_TEACHER  :
		winProFunc125(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_CLASS_CHOOSE  :
		winProFunc126(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_SCORES_MYSCORE  :
		winProFunc127(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_HELP_HELP_INFO  :
		winProFunc128(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_ABOUT_THIS_SYSTEM  :
		winProFunc129(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_INFORMATION_EDITBASEINFO :
		winProFunc141(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  STUDENT_EDIT_OKBUTTON:
		winProFunc149(pstCurrWindow,pstMSG,pstMOUSE);
		break;
     case   MANAGER_INFORMATION :
		winProFunc311(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_CLASS  :
		winProFunc312(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  MANAGER_DEPARTMENT:
		winProFunc313(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_HELP  :
		winProFunc314(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_ABOUT :
		winProFunc315(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case MANAGER_INFORMATION_EDIT  :
		winProFunc321(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_INFORMATION_SEARCH:
		winProFunc322(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_INFORMATION_LOGIN:
		winProFunc330(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  MANAGER_INFORMATION_EXIT :
		winProFunc323(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case MANAGER_INFORMATION_EDIT_OK_BUTTON:
		winProFunc364(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  MANAGER_CLASS_NEW  :
		winProFunc325(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case    MANAGER_CLASS_SHOW    :
		winProFunc326(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case    MANAGER_CLASS_EDIT :
		winProFunc327(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_DEPARTMENT_NEW :
		winProFunc324(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   MANAGER_HELP_HELP_INFO :
		winProFunc328(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  MANAGER_ABOUT_THIS_SYSTEM :
		winProFunc329(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case MANAGER_DEPARTMENT_NEW_OK_BUTTON:
		winProFunc367(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case MANAGER_CLASS_NEW_TIMEWEEK:
		winProFunc373(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case MANAGER_CLASS_NEW_TIMERANK:
		winProFunc374(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case MANAGER_CLASS_NEW_OK:
		winProFunc375(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	
	case  355  :
		winProFunc355(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	}
	return TRUE;
}
int  windowPro2(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE)
{    
	unsigned long int idToSwitch = pstCurrWindow->nMenuID;
	if (TRUE == pstCurrWindow->nHaveFather )
	{
		idToSwitch =  pstCurrWindow->nFatherID;
	}
	switch (idToSwitch)
	{
	case  STUDENT_INFORMATION_EDITPASSWORD  :
		winProFunc143(pstCurrWindow,pstMSG,pstMOUSE);
		break;
    case  STUDENT_EDIT_PASSWORDOK  :
		winProFunc153(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case TEACHER_INFORMATION  :
		winProFunc211(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case TEACHER_CLASS:
		winProFunc212(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_SCORES   :
		winProFunc213(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_HELP :
		winProFunc214(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_ABOUT  :
		winProFunc215(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   TEACHER_INFORMATION_MYINFO  :
		winProFunc221(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   TEACHER_INFORMATION_EDIT  :
		winProFunc222(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   TEACHER_INFORMATION_EXIT :
		winProFunc223(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_CLASS_MYCLASS  :
		winProFunc224(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   TEACHER_CLASS_STU   :
		winProFunc225(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_CLASS_EDIT  :
		winProFunc226(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_SCORES_INPUT :
		winProFunc227(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case   TEACHER_HELP_HELP_INFO :
		winProFunc228(pstCurrWindow,pstMSG,pstMOUSE);
		break;
	case  TEACHER_ABOUT_ABOUT :
		winProFunc229(pstCurrWindow,pstMSG,pstMOUSE);
		break;

	}
	return TRUE ;
}

