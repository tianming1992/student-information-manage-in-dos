#include "message.h"

void initMessage(struct tagMessage*pstMSG)
{
   pstMSG->pstStudentHeader = getStudentListFromFile();
   pstMSG->pstTeacherHeader = getTeacherListFromFile();
   pstMSG->pstMangerHeader = getMangerFromFile();
   pstMSG->pstClassHeader = getClassListFromFile();
   pstMSG->pstDepartment = getDepartmentListFromFile();
   pstMSG->pstCurrManger = NULL;
   pstMSG->pstCurrStudent = NULL;
   pstMSG->pstCurrTeacher = NULL;
   pstMSG->nlogin = FALSE ;
   pstMSG->nUserKind = FALSE;
   pstMSG->nInitMenu = FALSE ;
   
}

void getMsg(struct tagMessage*pstMSG, stMOUSE* pstMOUSE)
{    
	  pstMSG->MOUSE_position.nX=pstMOUSE->currPosition.nX;
	  pstMSG->MOUSE_position.nY=pstMOUSE->currPosition.nY;
	  pstMSG->nButton=-1;
	  pstMSG->nMouseMove=pstMOUSE->pfisMove(pstMOUSE);
	  if (kbhit())
	  {
		  pstMSG->nKeyInput=getch();
		  pstMSG->nKbhit=TRUE;
	  }
	  else
	  {
		  pstMSG->nKbhit=FALSE;
		  pstMSG->nKeyInput=-1;
	  }
	  /*to avoid the same mouse hit status*/
	  if (pstMOUSE->nAvoidSameStatus == pstMOUSE->nButton)
	  {
		  return ;
	  }
	  else 
	  {
		  pstMOUSE->nAvoidSameStatus = pstMOUSE->nButton;
		  pstMSG->nButton =pstMOUSE->nButton;
	  }
}

void getEvent(struct tagMessage* pstMSG, stMOUSE*pstMOUSE)
{
	pstMOUSE->pfGetMouseStatus(pstMOUSE);
	getMsg(pstMSG,pstMOUSE);
}