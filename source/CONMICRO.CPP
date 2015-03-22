#include "CONMICRO.h"

void initInfoHeader(struct tagInfoHeader*pstInfoHeader)
{ 
   pstInfoHeader->nLogin = FALSE ;
}

int check(char* acInput , int nLength)
{
    if ( nLength == strlen(acInput))
    {
		return TRUE ;
    }
	return FALSE ;
}
int checkJustNumber(char*acInput )
{  
	int nLength = strlen(acInput);
	int i=0 ;
    for (i = 0 ; i<nLength ; i++)
    {
		if (! (acInput[i] >= '0' && acInput[i] <= '9' ))
		{
			return FALSE ;
		}
    }
	return TRUE ;
}
int  checkJustChar(char*acInput)
{ 
	int nLength = strlen(acInput);
	int i=0 ;
	for (i = 0 ; i<nLength ; i++)
	{
		if (! (acInput[i] >= 'a' && acInput[i] <= 'Z' ))
		{
			return FALSE ;
		}
	}
	return TRUE ;  
}