#include "depart.h"
/*get student list from file and return the header pointer */
struct tagDepartment* getDepartmentListFromFile()
{
	/*the length of the list saved in file*/
	long lListLength = EMPTY_FILE;
	/* constructor the head pointer*/
    struct tagDepartment*pHeader = (struct tagDepartment*)calloc(1,sizeof(struct tagDepartment));
    struct tagDepartment*pFileData = (struct tagDepartment*)calloc(1,sizeof(struct tagDepartment));
	FILE *fp;
    struct tagDepartment *pTemp = pHeader;
	if (NULL == pHeader)
	{
		printf("memory overflow in constructor user list! exit now\n");
		getch();
		exit(1);
	}
	if(access("department.dat",0))
	{
		fp = fopen("department.dat","wb+");
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
		fp=fopen("department.dat","rb+");
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
		struct tagDepartment*pNode = (struct tagDepartment*)calloc(1,sizeof(struct tagDepartment));
		if (NULL ==pNode)
		{
			printf("memory overflow in constructor user list! exit now\n");
			getch();
			exit(1);
		}
		fread(pFileData, sizeof(struct tagDepartment), 1, fp);
		strcpy(pNode->acDepartID,pFileData->acDepartID);
		strcpy(pNode->acDepartment,pFileData->acDepartment);
		pTemp->pstNextDepartment = pNode;
		pTemp=pTemp->pstNextDepartment;
		lListLength--;
	}
	pTemp->pstNextDepartment = NULL;
	fclose(fp);
	return pHeader;
}

/*save the student list to file*/
void saveDepartmentListToFile(struct tagDepartment*pHeader )
{
	FILE *fp;
	long lListLength = EMPTY_FILE;                                                                                    
	struct tagDepartment*pTemp = pHeader->pstNextDepartment;
    struct tagDepartment* pFile = (struct tagDepartment*)calloc(1,sizeof(struct tagDepartment));
	int i ;
	if ((fp=fopen("department.dat","wb+")) == NULL)
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
	lListLength =  getDepartmentListLength(pHeader);                                                                    
	fwrite(&lListLength,sizeof(long),1,fp);
	
	for (i = 0; i < lListLength; i++)   
	{
		strcpy(pFile->acDepartID,pTemp->acDepartID);
        strcpy(pFile->acDepartment,pTemp->acDepartment);
		pTemp = pTemp->pstNextDepartment;
		fwrite(pFile, sizeof(struct tagDepartment), 1, fp);
	}
	
	free(pFile);
	fclose(fp);
}
int getDepartmentListLength(struct tagDepartment* pstHeader)
{
	struct tagDepartment* pstTemp = pstHeader->pstNextDepartment ;
	int i =0 ;
	while (NULL != pstTemp)
	{
		pstTemp = pstTemp->pstNextDepartment ;
		i++ ;
	}
	return i ;
}
void addDepartmentToList(struct tagDepartment*pstHeader ,struct tagDepartment* pstNodeToAdd)
{

	struct tagDepartment*pstTemp = pstHeader;   
	while(NULL != pstTemp->pstNextDepartment)
	{
		pstTemp = pstTemp->pstNextDepartment ;
	}
	pstTemp->pstNextDepartment = pstNodeToAdd;
	pstNodeToAdd->pstNextDepartment = NULL ;
}
struct tagDepartment* findDepartmentByName(struct tagDepartment* pstHeader,struct tagDepartment* pstNodeToFind )
{
	struct tagDepartment* pstTemp = pstHeader->pstNextDepartment ;
	while(NULL != pstTemp)
	{
		if (0 == strcmp(pstNodeToFind->acDepartment , pstTemp->acDepartment))
		{
			return pstTemp ;
		}
		pstTemp = pstTemp->pstNextDepartment ;
	}
	return NULL ;
}

void freeDepartList(struct tagDepartment*pstDepartHeader)
{
    struct tagDepartment* pstTemp =pstDepartHeader ;
	struct tagDepartment*pstNodeToFree =pstDepartHeader->pstNextDepartment ;
	while (NULL != pstNodeToFree)
	{
		pstTemp->pstNextDepartment = pstNodeToFree->pstNextDepartment;
		free(pstNodeToFree);
		pstNodeToFree = pstTemp->pstNextDepartment ;
	}
	free(pstTemp);
}