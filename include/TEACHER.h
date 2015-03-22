#ifndef  _TEACHER_H_
#define   _TEACHER_H_

#include "CONMICRO.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tagTeaBaseInfo{
	char acName[35];
	char acUserName [35];
	char acTeaID[20];
	 char acPassWord[35];
	char acIdentifyCardID[20];
	char acBirthday[20];
	int nSex;
	char acTel[20];
	char acNation[20];
}stTeaBaseInfo;

typedef struct tagTeaSchoolInfo{
	int nTeaSort;
	char acSubject[35];
	char acClassID[20];
	char acDepartment[35];
	char acGraduateSchool[35];
	char acTeacherTime[20];
}stTeaSchoolInfo;

typedef struct tagTeacher{
	struct tagTeaBaseInfo   baseInfo;
	struct tagTeaSchoolInfo schoolInfo;
	struct tagTeacher* pstNextTeacher ;
}stTeacher;

/*get  teacher list from file and return the header pointer */
 stTeacher*getTeacherListFromFile();
/*save the teacher list to file*/
void saveTeacherListToFile( stTeacher*);
int getTeacherListLength(  stTeacher*);
void addTeacherToList( stTeacher*pstHeader , stTeacher*pstNodeToAdd);
stTeacher* findTeacherByID(stTeacher*pstHeader,stTeacher*pstNodeToFind );
stTeacher* findTeacherByUserName(stTeacher*pstHeader,char* );
int isSameTeacher(stTeacher*pstHeader, char*);
void freeTeacherList(struct tagTeacher*pstTeaHeader);
#endif