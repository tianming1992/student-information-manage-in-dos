#ifndef  _STUMENU_H_
#define   _STUMENU_H_
#include "mouse.h"
#include "initgra.h"
#include "message.h"
#include "WINDOW.H"
#include "page.h"
#include "MENUID.h"
#include "commenu.h"

void initStudentMenuSys(struct tagWindow*pstCurrWindow,struct tagMOUSE*pstMOUSE,struct tagMessage*pstMSG);

int  backtostuinit(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*STUDENT_INFORMATION*/
int  winProFunc111(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*STUDENT_CLASS */
int  winProFunc112(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*STUDENT_SCORES*/
int  winProFunc113(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*STUDENT_HELP*/
int  winProFunc114(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*STUDENT_ABOUT*/
int  winProFunc115(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/* STUDENT_INFORMATION_MY_INFO */
int  winProFunc121(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/* STUDENT_INFORMATION_EDIT_INFO*/
int winProFunc122(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*STUDENT_INFORMATION_EXIT */
int winProFunc123(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/* STUDENT_INFORMATION_LOGIN */ 
int winProFunc130(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*STUDENT_CLASS_TABLE */
int winProFunc124(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*STUDENT_CLASS_TEACHER*/
int winProFunc125(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/* STUDENT_CLASS_CHOOSE*/
int winProFunc126(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);

/*STUDENT_SCORES_MYSCORE */
int winProFunc127(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*STUDENT_HELP_HELP_INFO */
int winProFunc128(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*  STUDENT_ABOUT_THIS_SYSTEM*/
int winProFunc129(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*#define   STUDENT_INFORMATION_EDITBASEINFO 141*/
int winProFunc141(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*#define   STUDENT_EDIT_OKBUTTON   149*/
int winProFunc149(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*#define   STUDENT_INFORMATION_EDITSCHOOLINFO 142*/
int winProFunc142(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*#define   STUDENT_INFORMATION_EDITPASSWORD 143*/
int winProFunc143(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
/*#define   STUDENT_EDIT_PASSWORDOK  153*/
int winProFunc153(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
#endif