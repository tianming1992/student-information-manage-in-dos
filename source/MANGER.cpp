#include "MANGER.H"

stManger* getMangerFromFile()
{
	FILE *fp;
	struct tagManger* pstManger;
	if((pstManger=(struct tagManger*)malloc(1*sizeof(struct tagManger)))==NULL)
	{
		printf("NO ENOUGH MEMORY");
		exit(1);
	}
	if ((fp=fopen( MANGER_FILE_POSITION,"r"))==NULL)
	{
		strcpy(pstManger->acName,"ADMIN");
	    strcpy(pstManger->acPassWord,"1234");
		fp=fopen( MANGER_FILE_POSITION,"w");
	    fwrite( pstManger,sizeof(stManger),1,fp);
	    fclose(fp);
	}
	fp=fopen( MANGER_FILE_POSITION,"r");
	fread(pstManger,sizeof(stManger),1,fp);
	fclose(fp);
	return pstManger;
}

stManger* saveMangerToFile(stManger*pstManger)
{   
    FILE *fp;
	fp=fopen( MANGER_FILE_POSITION,"w");
	fwrite( pstManger,sizeof(stManger),1,fp);
	fclose(fp);
}