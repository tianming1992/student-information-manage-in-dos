#ifndef  _MENU_SYSTEM_
#define  _MENU_SYSTEM_

#include "mouse.h"
#include "initgra.h"
#include "message.h"
#include "WINDOW.H"
#include "page.h"
#include "MENUID.h"
#include "commenu.h"

#include "manmenu.h"
#include "STUMENU.h"
#include "teamenu.h"

stWindow* initLoginMenuSystem(stMOUSE*pstMouse) ;

int  Eventpro(struct tagWindow*pstHeader,struct tagMessage*pstMsg,struct tagMOUSE*);
int  windowPro(struct tagWindow*pstCurrWindow,struct tagMessage*,struct tagMOUSE*);
int  windowPro2(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);


/* LOGIN_LOGIN_BUTTON*/
int  winProFunc413(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*LOGIN_QUTI_BUTTON */
int  winProFunc414(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
 /*LOGIN_REGISTER_BUTTON */
int  winProFunc415(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/*register back button*/
int  winProFunc463(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
/* REGISTER_OK_BUTTON  460 */
int  winProFunc460(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
 /*REGISTER_STUSORT_DOWNTEXT 456*/
int  winProFunc456(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
 /*REGISTER_DEPARTMENT_DOWNTEXT */
int  winProFunc459(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);


int  winProFunc355(struct tagWindow*pstCurrWindow,struct tagMessage*pstMSG,struct tagMOUSE*pstMOUSE);

#endif