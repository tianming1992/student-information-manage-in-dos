#ifndef  _TEAMENU_H_
#define  _TEAMENU_H_

#include "mouse.h"
#include "initgra.h"
#include "message.h"
#include "WINDOW.H"
#include "page.h"
#include "MENUID.h"
#include "commenu.h"

void initTeacherMenuSys(struct tagWindow*pstCurrWindow,struct tagMOUSE*pstMOUSE,struct tagMessage*pstMSG);

/*   TEACHER_INFORMATION */
int  winProFunc211(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*   TEACHER_CLASS    */
int  winProFunc212(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*  TEACHER_SCORES  */
int  winProFunc213(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*  TEACHER_HELP   */
int  winProFunc214(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*   TEACHER_ABOUT */
int  winProFunc215(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*TEACHER_INFORMATION_MYINFO  :*/
int winProFunc221(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/* TEACHER_INFORMATION_EDIT  */
int winProFunc222(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*TEACHER_INFORMATION_EXIT:*/
int winProFunc223(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);


/* TEACHER_CLASS_MYCLASS  :*/
int winProFunc224(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/* TEACHER_CLASS_STU:*/
int winProFunc225(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*TEACHER_CLASS_EDIT */
int winProFunc226(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/* TEACHER_SCORES_INPUT */
int winProFunc227(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*TEACHER_HELP_HELP_INFO */
int winProFunc228(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*TEACHER_ABOUT_ABOUT */
int winProFunc229(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

#endif