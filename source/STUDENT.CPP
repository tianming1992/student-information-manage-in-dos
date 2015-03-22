/*****************************************************************************
Copyright (c) 2010, zoutianming&daiqian. All rights reserved.
------------------------------------------------------------------------------
student.c
Module Name: file & list
Date Created:  2010-10-22
Author: zoutianming&daiqian
Description: student file and list opeartion .  

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
#include "STUDENT.H"

/*****************************************************************************
Func Name:getStudentListFromFile
Date Created: 2010-10-22
Author: zoutianming
Description: get student list from file
Input: void
Return: struct tagStudent*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
struct tagStudent*getStudentListFromFile()
{  
	/*the length of the list saved in file*/
	long lListLength = EMPTY_FILE;
	/* constructor the head pointer*/
	struct tagStudent*pHeader = (struct tagStudent*)calloc(1,sizeof(struct tagStudent));
	struct tagStudent *pFileData = (struct tagStudent*)calloc(1,sizeof(struct tagStudent));
	FILE *fp;
	struct tagStudent *pTemp = pHeader;
	if (NULL == pHeader)
	{
		printf("memory overflow in constructor user list! exit now\n");
		getch();
		exit(1);
	}
	if(access("student.dat",0))
	{
		fp = fopen("student.dat","wb+");
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
		fp=fopen("student.dat","rb+");
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
		struct tagStudent*pNode = (struct tagStudent*)calloc(1,sizeof(struct tagStudent));
		if (NULL ==pNode)
		{
			printf("memory overflow in constructor user list! exit now\n");
			getch();
			exit(1);
		}
		fread(pFileData, sizeof(struct tagStudent), 1, fp);
		pNode->baseInfo = pFileData->baseInfo;
		pNode->schoolInfo = pFileData->schoolInfo;
		pNode->classAndScore = pFileData->classAndScore;
	    pTemp->pstNextStudent = pNode;
		pTemp=pTemp->pstNextStudent;
		lListLength--;
	}
	pTemp->pstNextStudent = NULL;
	fclose(fp);
	return pHeader;
}
/*****************************************************************************
Func Name:saveStudentListToFile
Date Created: 2010-10-22
Author: zoutianming
Description: save student list to file
Input:struct tagStudent*
Return: void 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
void  saveStudentListToFile(struct tagStudent* pHeader)                              
{
	FILE *fp;
	long lListLength = EMPTY_FILE;                                                                                    
	struct tagStudent *pTemp = pHeader->pstNextStudent;
   struct tagStudent* pFile = (struct tagStudent*)calloc(1,sizeof(struct tagStudent));
   int i ;
	if ((fp=fopen("student.dat","wb+")) == NULL)
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
	lListLength =  getStudentListLength(pHeader);                                                                    
	rewind(fp);                                                                                                             
	fwrite(&lListLength,sizeof(long),1,fp);
	for (i = 0; i < lListLength; i++)   
	{
		pFile->baseInfo = pTemp->baseInfo;
		pFile->schoolInfo = pTemp->schoolInfo;
		pFile->classAndScore=pTemp->classAndScore;
		pTemp = pTemp->pstNextStudent;
		fwrite(pFile, sizeof(struct tagStudent), 1, fp);
	}                                                                                                           
	free(pFile);
	fclose(fp);
}

/*****************************************************************************
Func Name : getStudentListLength
Date Created: 2010-10-22
Author: zoutianming
Description: get student list length  
Input:stStudent* pstHeader
Return: int 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int getStudentListLength(stStudent* pstHeader)
{ 
	stStudent * pstTemp = pstHeader->pstNextStudent ;
	int i =0 ;
    while (NULL != pstTemp)
    {
		pstTemp = pstTemp->pstNextStudent ;
		i++ ;
    }
	return i ;
}

/*****************************************************************************
Func Name: addStudentToList
Date Created: 2010-10-22
Author: zoutianming
Description: add a student node to the student list
Input:struct tagStudent*pstHeader , struct tagStudent*pstNodeToAdd
Return: void 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
void addStudentToList(struct tagStudent*pstHeader , struct tagStudent*pstNodeToAdd)
{
   stStudent * pstTemp = pstHeader;   
   while(NULL != pstTemp->pstNextStudent)
   {
	   pstTemp = pstTemp->pstNextStudent ;
   }
   pstTemp->pstNextStudent = pstNodeToAdd;
   pstNodeToAdd->pstNextStudent = NULL ;
}

/*****************************************************************************
Func Name:findStudentByID
Date Created: 2010-10-22
Author: zoutianming
Description: find a student node from the list by it's stu ID  
Input:struct tagStudent*pstHeader,struct tagStudent*pstNodeToFind 
Return:struct tagStudent*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
struct tagStudent* findStudentByID(struct tagStudent*pstHeader,struct tagStudent*pstNodeToFind )
{
     stStudent * pstTemp = pstHeader->pstNextStudent ;
	 while(NULL != pstTemp)
	 {
		 if (0 == strcmp(pstNodeToFind->baseInfo.acStuID , pstTemp->baseInfo.acStuID))
		 {
			 return pstTemp ;
		 }
		 pstTemp = pstTemp->pstNextStudent ;
	 }
	 return NULL ;
}

/*****************************************************************************
Func Name:findStudentByUserName
Date Created: 2010-10-22
Author: zoutianming
Description: find a student node from the list by it's user name  
Input:struct tagStudent*pstHeader,struct tagStudent*pstNodeToFind 
Return:struct tagStudent*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
struct tagStudent* findStudentByUserName(struct tagStudent*pstHeader,char*acName )
{
	stStudent * pstTemp = pstHeader->pstNextStudent ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(acName , pstTemp->baseInfo.acUserName))
		{
			return pstTemp ;
		}
		pstTemp = pstTemp->pstNextStudent ;
	}
	return NULL ;
}

/*****************************************************************************
Func Name:isSameStudent
Date Created: 2010-10-22
Author: zoutianming
Description: find si there is a same student in the sudent list  
Input:struct tagStudent*pstHeader , char* 
Return:struct tagStudent*

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/
int isSameStudent(struct tagStudent*pstHeader , char*acInputName)
{
	stStudent * pstTemp = pstHeader->pstNextStudent ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(pstTemp->baseInfo.acUserName , acInputName))
		{
			return FALSE ;
		}
		pstTemp = pstTemp->pstNextStudent ;
	}
	return TRUE ;
}

void freeStudentList(struct tagStudent*pstStuHeader)
{
   stStudent * pstTemp = pstStuHeader ;
   stStudent * pstNodeToFree = pstStuHeader->pstNextStudent ;
   while (NULL != pstNodeToFree)
   {
	   pstTemp->pstNextStudent = pstNodeToFree->pstNextStudent ;
       free(pstNodeToFree);
	   pstNodeToFree = pstTemp->pstNextStudent ;
   }
   free(pstTemp);
}