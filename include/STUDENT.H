/*****************************************************************************
Copyright (c) 2010, zoutianming&daiqian. All rights reserved.
------------------------------------------------------------------------------
student.h
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
#ifndef  _STUDENT_H_
#define   _STUDENT_H_

#include "CONMICRO.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tagStuBaseInfo{
	char acName[35];
	char acUserName[35];
    char acPassWord[35];
	char acStuID[35];
	char acIdentifyCardID[35];
	char acBirthday[35];
	int  nSex;
	char acNation[35];
	char acTel[35];
}stStuBaseInfo;

typedef struct tagStuSchoolInfo{
	int nStuSort;
	char acMajor[35];
	char acClassID[35];
	char acDepartment[35];
	char nGrade[20];
}stStuSchoolInfo;

typedef struct tagMyClassAndScore{
	char acClassName[10][35];
	float fScore[10];
}stMyClassAndScore;

typedef struct tagStudent{
	struct tagStuBaseInfo  baseInfo;
	struct tagStuSchoolInfo schoolInfo;
	struct tagMyClassAndScore  classAndScore;
	struct tagStudent* pstNextStudent ;
}stStudent;

/*get student list from file and return the header pointer */
struct tagStudent*getStudentListFromFile();
/*save the student list to file*/
void saveStudentListToFile(struct tagStudent*);
int getStudentListLength(struct tagStudent*);
void addStudentToList(struct tagStudent*pstHeader , struct tagStudent*pstNodeToAdd);
struct tagStudent* findStudentByID(struct tagStudent*pstHeader,struct tagStudent*pstNodeToFind );
struct tagStudent* findStudentByUserName(struct tagStudent*pstHeader,char* );
int isSameStudent(struct tagStudent*pstHeader , char*);
void freeStudentList(struct tagStudent*);
#endif