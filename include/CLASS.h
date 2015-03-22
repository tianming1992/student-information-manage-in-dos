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
#ifndef  _CLASS_H_
#define  _CLASS_H_
#define  _MAX_INPUT_INFO_LENGTH_  35


#include "CONMICRO.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>


typedef struct tagClass{
 char acClassId[ _MAX_INPUT_INFO_LENGTH_];
 char acClassName[_MAX_INPUT_INFO_LENGTH_];
 stTime classTime ;
 char acTeacherID[ _MAX_INPUT_INFO_LENGTH_];
 char acTeacnerName[ _MAX_INPUT_INFO_LENGTH_];
 char acPosition[ _MAX_INPUT_INFO_LENGTH_];
 char acDepart[ _MAX_INPUT_INFO_LENGTH_];
 struct tagClass* pstNextClass ;
}stClass;
/*get class list from file and return the header pointer */
 stClass*getClassListFromFile();
/*save the class list to file*/
void saveClassListToFile(stClass*);
int getClassListLength(stClass*);
void addClassToList(stClass*pstHeader , stClass*pstNodeToAdd);
stClass* findClassByID(stClass*pstHeader,stClass*pstNodeToFind );
stClass* findClassByDepartName(stClass*pstHeader,char*acInput);
void freeClassList(struct tagClass*pstClassHeader);
#endif