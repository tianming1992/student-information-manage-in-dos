#ifndef  _COMMENU_H_
#define   _COMMENU_H_

#include "mouse.h"
#include "initgra.h"
#include "message.h"
#include "WINDOW.H"
#include "page.h"
#include "MENUID.h"

int  addMenuToSystemList(stWindow*pstMenuHeader,stWindow*pstWindowToAdd);
void freeMenuList(struct tagWindow*);
void freeList(struct tagMessage* , struct tagWindow* );
int deleteOneNodeFromList(struct tagWindow*pstMenuHeader , int nMenuID);
stWindow*getMenuHeader(stWindow*pstCurrWindow);
stWindow*deleteCurrReturnLast(stWindow*pstCurrWindow);
stWindow*findNodeByID(stWindow*pstCurrWindow,unsigned long int );
void disableButThisWin(stWindow*pstCurrWindow);
void ableAllWin(stWindow*pstCurrWindow);
void deleteAllNodeButHeader(stWindow*pstCurrWindow);
void cleardevice();

int winDownTextDiaologPro(struct tagWindow*,struct tagMessage*,struct tagMOUSE*,char[][MAX_DIALOG_SHOW_LENGTH]);
int  winProWarningButton(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
int winProWarning(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
int Allert(struct tagWindow*,struct tagMOUSE*,char acWarn[]);
#endif