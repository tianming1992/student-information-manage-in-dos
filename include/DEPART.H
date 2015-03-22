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
#ifndef  _DEPARTMENT_H_
#define  _DEPARTMENT_H_

#include "CONMICRO.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tagDepartment{
	char acDepartment[30];
	char acDepartID[30];
	struct tagDepartment* pstNextDepartment ;
}stDepartment;

/*get student list from file and return the header pointer */
struct tagDepartment* getDepartmentListFromFile();
/*save the student list to file*/
void saveDepartmentListToFile(struct tagDepartment* );
int getDepartmentListLength(struct tagDepartment* );
void addDepartmentToList(struct tagDepartment*pstHeader ,struct tagDepartment* pstNodeToAdd);
struct tagDepartment* findDepartmentByName(struct tagDepartment* pstHeader,struct tagDepartment* pstNodeToFind );
void freeDepartList(struct tagDepartment*pstDepartHeader);
#endif