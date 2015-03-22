#include "mouse.h"
#include "initgra.h"
#include "message.h"
#include "WINDOW.H"
#include "page.h"
#include "MENUSYS.h"

int main()
{
	stMOUSE* pstMOUSE;
	stMessage *pstMSG;
    initGra();
	initMOUSE(pstMOUSE);
	initMessage(pstMSG);
    stWindow* pstMenuHeader = initLoginMenuSystem(pstMOUSE);
    while (TRUE)
	{
		getEvent(pstMSG,pstMOUSE);
        Eventpro(pstMenuHeader,pstMSG,pstMOUSE);
	    if (RIGHTBUTTON == pstMSG->nButton)
		{
			printf("hehe");
			getch();
			break;
		}
	}
	freeList(pstMSG,pstMenuHeader);
	closegraph();
    return 0;
}