#ifndef  _MESSAGE_H_
#define   _MESSAGE_H_
#include "mouse.h"
#include <conio.h>
#include "depart.h"
#include "manger.h"
#include "student.h"
#include "TEACHER.h"
#include "CLASS.h"

typedef struct tagMessage{
	stPosition MOUSE_position;
	int nButton;
	int nKbhit;
	int nKeyInput;/*store the key value*/
	int nMouseMove;
	/*get the mouse and keyboard event and write it into this structure*/
	//void(*pfGetMsg)(struct tagMessage*,);
	 int nlogin ;
	 int nUserKind;
	 int nInitMenu ; 
     struct tagStudent * pstCurrStudent ;
	 struct tagTeacher* pstCurrTeacher ;
	 struct tagManger* pstCurrManger ;
	 struct tagStudent * pstStudentHeader ;
	 struct tagTeacher* pstTeacherHeader ;
	 struct tagManger* pstMangerHeader ;
	 struct tagClass* pstClassHeader ;
	 struct tagDepartment * pstDepartment ;
}stMessage;

/*get the mouse and keyboard event and write it into this structure*/
void getMsg(struct tagMessage*, stMOUSE*);
void getEvent(struct tagMessage*, stMOUSE*);
void initMessage(struct tagMessage*);

#endif