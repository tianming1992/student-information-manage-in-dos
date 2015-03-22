#ifndef  _MANMENU_H_
#define  _MANMENU_H_
#include "mouse.h"
#include "initgra.h"
#include "message.h"
#include "WINDOW.H"
#include "page.h"
#include "MENUID.h"
#include "commenu.h"

void initMangerMenuSys(stWindow*pstCurrWindow , stMOUSE*pstMOUSE ,stMessage*pstMSG);

int  backtoinit(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*    MANAGER_INFORMATION */
int  winProFunc311(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*   MANAGER_CLASS   */
int  winProFunc312(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*MANAGER_SCORES */
int  winProFunc313(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*  MANAGER_HELP  */
int  winProFunc314(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*   MANAGER_ABOUT */
int  winProFunc315(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_INFORMATION_EDIT  :*/
int winProFunc321(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_INFORMATION_SEARCH:*/
int winProFunc322(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*MANAGER_INFORMATION_LOGIN:*/
int winProFunc330(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_INFORMATION_EXIT :*/
int winProFunc323(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_CLASS_NEW  :*/
int winProFunc325(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_CLASS_SHOW    :*/
int winProFunc326(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_CLASS_EDIT :*/
int winProFunc327(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_DEPARTMENT_NEW :*/
int winProFunc324(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_HELP_HELP_INFO :*/
int winProFunc328(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_ABOUT_THIS_SYSTEM :*/
int winProFunc329(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_INFORMATION_EDIT_OK_BUTTON*/
int winProFunc364(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_DEPARTMENT_NEW_OK_BUTTON*/
int winProFunc367(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_CLASS_NEW_TIMEWEEK 373*/
int winProFunc373(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

/*MANAGER_CLASS_NEW_TIMERANK 374*/
int  winProFunc374(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);

 /*MANAGER_CLASS_NEW_OK 375*/
int winProFunc375(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*MANAGER_CLASS_NEW_OK 375*/
int winProFunc375(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);
#endif


