/*****************************************************************************
Copyright (c) 2010, zoutianming&daiqian. All rights reserved.
------------------------------------------------------------------------------
student.c
Module Name: file & list
Date Created:  2010-10-22
Author: zoutianming&daiqian
Description: teacher file and list opeartion .  

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/

#include "TEACHER.h"

/*****************************************************************************
Func Name:getTeacherListFromFile
Date Created: 2010-10-22
Author: zoutianming
Description: get teacher list from file
Input: void
Return: struct tagTeacher*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
/*get  teacher list from file and return the header pointer */
 stTeacher*getTeacherListFromFile()
{
	/*the length of the list saved in file*/
	long lListLength = EMPTY_FILE;
	/* constructor the head pointer*/
	 stTeacher*pHeader = ( stTeacher*)calloc(1,sizeof( stTeacher));
	 stTeacher*pFileData = ( stTeacher*)calloc(1,sizeof( stTeacher));
	FILE *fp;
	 stTeacher*pTemp = pHeader->pstNextTeacher;
	if (NULL == pHeader)
	{
		printf("memory overflow in constructor user list! exit now\n");
		getch();
		exit(1);
	}
	if(access("teacher.dat",0))
	{
		fp = fopen("teacher.dat","wb+");
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
		fp=fopen("teacher.dat","rb+");
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
		 stTeacher*pNode = ( stTeacher*)calloc(1,sizeof( stTeacher));
		if (NULL ==pNode)
		{
			printf("memory overflow in constructor user list! exit now\n");
			getch();
			exit(1);
		}
		fread(pFileData, sizeof( stTeacher), 1, fp);
		pNode->baseInfo = pFileData->baseInfo;
		pNode->schoolInfo = pFileData->schoolInfo;
	
		pTemp->pstNextTeacher= pNode;
		pTemp=pTemp->pstNextTeacher;
		lListLength--;
	}
	pTemp->pstNextTeacher = NULL;
	fclose(fp);
	return pHeader;
}

 /*****************************************************************************
 Func Name:saveTeacherListToFile
 Date Created: 2010-10-22
 Author: zoutianming
 Description: save teacher list to file
 Input:struct tagTeacher*
 Return: void 

 ------------------------------------------------------------------------------
 Modification History
 DATE        NAME             DESCRIPTION
 --------------------------------------------------------------------------
 2010-10-22

 *****************************************************************************/
void saveTeacherListToFile( stTeacher* pHeader)
{
	FILE *fp;
	long lListLength = EMPTY_FILE;                                                                                    
	stTeacher*pTemp = pHeader;
    stTeacher* pFile = (stTeacher*)calloc(1,sizeof(stTeacher*));
	int i ;
	if ((fp=fopen("teacher.dat","wb+")) == NULL)
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
	lListLength =  getTeacherListLength(pHeader);                                                                    
	rewind(fp);                                                                                                             
	fwrite(&lListLength,sizeof(long),1,fp);
	for (i = 0; i < lListLength; i++)   
	{
		pFile->baseInfo = pTemp->baseInfo;
		pFile->schoolInfo = pTemp->schoolInfo;
	    pTemp = pTemp->pstNextTeacher;
		fwrite(pFile, sizeof(struct tagTeacher), 1, fp);
	}
	free(pFile);
	fclose(fp);
}

/*****************************************************************************
Func Name : getTeacherListLength
Date Created: 2010-10-22
Author: zoutianming
Description: get teacher list length  
Input:stTeacher* pstHeader
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int getTeacherListLength(  stTeacher*pstHeader)
{
	 stTeacher* pstTemp = pstHeader->pstNextTeacher ;
	int i =0 ;
	while (NULL != pstTemp)
	{
		pstTemp = pstTemp->pstNextTeacher ;
		i++ ;
	}
	return i ;
}

/*****************************************************************************
Func Name: addTeacherToList
Date Created: 2010-10-22
Author: zoutianming
Description: add a teacher node to the student list
Input: stTeacher*pstHeader , stTeacher*pstNodeToAdd
Return: void 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
void addTeacherToList( stTeacher*pstHeader , stTeacher*pstNodeToAdd)
{
	 stTeacher*  pstTemp = pstHeader;   
	while(NULL != pstTemp->pstNextTeacher)
	{
		pstTemp = pstTemp->pstNextTeacher ;
	}
	pstTemp->pstNextTeacher = pstNodeToAdd;
	pstNodeToAdd->pstNextTeacher = NULL ;
}

/*****************************************************************************
Func Name:findTeacherByID
Date Created: 2010-10-22
Author: zoutianming
Description: find a teacher node from the list by it's tea ID  
Input:stTeacher*pstHeader,stTeacher*pstNodeToFind
Return:stTeacher*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
stTeacher* findTeacherByID(stTeacher*pstHeader,stTeacher*pstNodeToFind )
{
   stTeacher* pstTemp = pstHeader->pstNextTeacher ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(pstNodeToFind->baseInfo.acTeaID, pstTemp->baseInfo.acTeaID))
		{
			return pstTemp ;
		}
		pstTemp = pstTemp->pstNextTeacher ;
	}
	return NULL ;
}

/*****************************************************************************
Func Name: findTeacherByUserName
Date Created: 2010-10-22
Author: zoutianming
Description: find a teacher node from the list by it's tea ID  
Input:stTeacher*pstHeader,stTeacher*pstNodeToFind
Return:struct tagStudent*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
stTeacher* findTeacherByUserName(stTeacher*pstHeader,char*acName)
{
	stTeacher* pstTemp = pstHeader->pstNextTeacher ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(acName, pstTemp->baseInfo.acUserName))
		{
			return pstTemp ;
		}
		pstTemp = pstTemp->pstNextTeacher ;
	}
	return NULL ;
}

int isSameTeacher(stTeacher*pstHeader, char*acInputName)
{
	stTeacher* pstTemp = pstHeader->pstNextTeacher ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(pstTemp->baseInfo.acUserName , acInputName))
		{
			return FALSE ;
		}
		pstTemp = pstTemp->pstNextTeacher ;
	}
	return TRUE ;
}

void freeTeacherList(struct tagTeacher*pstTeaHeader)
{
	struct tagTeacher* pstTemp = pstTeaHeader ;
	struct tagTeacher*pstNodeToFree = pstTeaHeader->pstNextTeacher ;
	while (NULL != pstNodeToFree)
	{
		pstTemp->pstNextTeacher = pstNodeToFree->pstNextTeacher;
		free(pstNodeToFree);
		pstNodeToFree = pstTemp->pstNextTeacher ;
	}
	free(pstTemp);
}