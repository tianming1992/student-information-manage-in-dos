/*****************************************************************************
Copyright (c) 2010, zoutianming&daiqian. All rights reserved.
------------------------------------------------------------------------------
student.c
Module Name: file & list
Date Created:  2010-10-22
Author: zoutianming&daiqian
Description: class file and list opeartion .  

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
#include "CLASS.h"

/*****************************************************************************
Func Name:getClassListFromFile
Date Created: 2010-10-22
Author: zoutianming
Description: get class list from file
Input: void
Return: stClass*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
stClass*getClassListFromFile()
{
	/*the length of the list saved in file*/
	long lListLength = EMPTY_FILE;
	/* constructor the head pointer*/
	stClass*pHeader = (stClass*)calloc(1,sizeof(stClass));
	stClass*pFileData = (stClass*)calloc(1,sizeof(stClass));
	FILE *fp;
	stClass*pTemp = pHeader;
	if (NULL == pHeader)
	{
		printf("memory overflow in constructor user list! exit now\n");
		getch();
		exit(1);
	}
	if(access("class.dat",0))
	{
		fp = fopen("class.dat","wb+");
		if ( NULL == fp)
		{
			printf("open file wrong  exit now\n");
			getch();
			exit(1);
		}
		lListLength=0;
		fwrite(&lListLength,sizeof(long),1,fp);
	}
	else
	{   
		fp=fopen("class.dat","rb+");
		if (NULL == fp)
		{
			printf("open file wrong  exit now\n");
			getch();
			exit(1);
		}
	}

	/*get the length of the list in file*/
	rewind(fp);
	fread(&lListLength,sizeof(long),1,fp);    

	/*read data*/
	while (0 != lListLength)
	{   
		/*construct the node*/
		stClass*pNode = (stClass*)calloc(1,sizeof(stClass));
		if (NULL ==pNode)
		{
			printf("memory overflow in constructor user list! exit now\n");
			getch();
			exit(1);
		}
		fread(pFileData, sizeof(stClass), 1, fp);
		strcpy(pNode->acClassId,pFileData->acClassId);
		strcpy(pNode->acClassName,pFileData->acClassName);
		strcpy(pNode->acPosition,pFileData->acPosition);
		strcpy(pNode->acTeacherID,pFileData->acTeacherID);
		strcpy(pNode->acTeacnerName,pFileData->acTeacnerName);
		strcpy(pNode->acDepart,pNode->acDepart);
		pNode->classTime = pFileData->classTime ;
		printf("%d",pNode->classTime.nRank);//debug by tianming
	    pTemp->pstNextClass = pNode;
		pTemp=pTemp->pstNextClass;
		lListLength--;
	}
	pTemp->pstNextClass = NULL;
	free(pFileData);
	fclose(fp);
	return pHeader;
}

/*****************************************************************************
Func Name:saveClassListToFile
Date Created: 2010-10-22
Author: zoutianming
Description: save class list to file
Input:stClass*
Return: void 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
void saveClassListToFile(stClass*pHeader)
{
	FILE *fp;
	long lListLength = EMPTY_FILE;                                                                                    
	stClass*pTemp = pHeader->pstNextClass;
	stClass*pFile = (stClass*)calloc(1,sizeof(stClass));
	int i ;
	if ((fp=fopen("class.dat","wb+")) == NULL)
	{
		printf("open file wrong  exit now\n");
		getch();
		exit(1);
	}
	/*constructor a data area  */
	if (NULL == pFile)
	{
		printf("memory overflow in constructor user list! exit now\n");
		getch();
		exit(1);
	}
	/*get the length of the list */
	lListLength =  getClassListLength(pHeader);                                                                    
	rewind(fp);                                                                                                             
	fwrite(&lListLength,sizeof(long),1,fp);
	for (i = 0; i < lListLength; i++)   
	{
		strcpy(pFile->acClassId,pTemp->acClassId);
		strcpy(pFile->acClassName,pTemp->acClassName);
		strcpy(pFile->acPosition,pTemp->acPosition);
		strcpy(pFile->acTeacherID,pTemp->acTeacherID);
		strcpy(pFile->acTeacnerName,pTemp->acTeacnerName);
		strcpy(pFile->acDepart,pTemp->acDepart);
		pFile->classTime = pTemp->classTime ;
		pTemp = pTemp->pstNextClass;
		fwrite(pFile, sizeof(struct tagClass), 1, fp);
	}
	free(pFile);
	fclose(fp);
}

/*****************************************************************************
Func Name : getClassListLength
Date Created: 2010-10-22
Author: zoutianming
Description: get class list length  
Input:stClass* pstHeader
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int getClassListLength(stClass*pstHeader)
{
	stClass* pstTemp = pstHeader->pstNextClass ;
	int i =0 ;
	while (NULL != pstTemp)
	{
		pstTemp = pstTemp->pstNextClass ;
		i++ ;
	}
	return i ;
}

/*****************************************************************************
Func Name: addClassToList
Date Created: 2010-10-22
Author: zoutianming
Description: add a Class node to the class list
Input:stClass*pstHeader , stClass*pstNodeToAdd
Return: void 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
void addClassToList(stClass*pstHeader , stClass*pstNodeToAdd)
{
	stClass* pstTemp = pstHeader;   
	while(NULL != pstTemp->pstNextClass)
	{
		pstTemp = pstTemp->pstNextClass ;
	}
	pstTemp->pstNextClass = pstNodeToAdd;
	pstNodeToAdd->pstNextClass = NULL ;
}

/*****************************************************************************
Func Name:findClassByID
Date Created: 2010-10-22
Author: zoutianming
Description: find a class node from the list by it's class ID  
Input:stClass*pstHeader,stClass*pstNodeToFind
Return:stClass*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
stClass* findClassByID(stClass*pstHeader,stClass*pstNodeToFind )
{
   stClass* pstTemp = pstHeader->pstNextClass ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(pstNodeToFind->acClassId , pstTemp->acClassId))
		{
			return pstTemp ;
		}
		pstTemp = pstTemp->pstNextClass ;
	}
	return NULL ;
}

stClass* findClassByDepartName(stClass*pstHeader,char*acInput)
{
	stClass* pstTemp = pstHeader->pstNextClass ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(acInput , pstTemp->acDepart))
		{
			return pstTemp ;
		}
		pstTemp = pstTemp->pstNextClass ;
	}
	return NULL ;
}


void freeClassList(struct tagClass*pstClassHeader)
{
    struct tagClass* pstTemp = pstClassHeader ;
	struct tagClass*pstNodeToFree = pstClassHeader->pstNextClass ;
	while (NULL != pstNodeToFree)
	{
		pstTemp->pstNextClass = pstNodeToFree->pstNextClass;
		free(pstNodeToFree);
		pstNodeToFree = pstTemp->pstNextClass ;
	}
	free(pstTemp);
}