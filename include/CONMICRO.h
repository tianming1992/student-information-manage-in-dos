#ifndef  _CONMICRO_H_
#define  _CONMICRO_H_
#define  TRUE  1
#define  FALSE 0
#define  EMPTY_FILE 0
#define  BOY  0
#define  GIRL 1
#define FIRST_CLASS_MENU 5

#define STUDENT 1
#define TEACHER 2
#define MANAGER 3

#include<string.h>

typedef struct tagInfoHeader{
	int nLogin ;
}stInfoHeader;

typedef struct tagTime{
	int nWeek ;
	int nRank ;
}stTime;

void  initInfoHeader(struct tagInfoHeader*);

int check(char* acInput , int nLength);
int checkJustNumber(char*acInput );
int  checkJustChar(char*acInput);

#endif