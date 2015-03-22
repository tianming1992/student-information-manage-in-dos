#ifndef   _MANGER_H_
#define   _MANGER_H_

#include "CONMICRO.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_NAME_LENGTH  35
#define MAX_PASSWORD_LENGTH  35
#define MANGER_FILE_POSITION  "manger.dat"

typedef struct tagManger{
	char acName[MAX_NAME_LENGTH];
    char acPassWord[MAX_PASSWORD_LENGTH];
}stManger;

stManger* getMangerFromFile();
stManger* saveMangerToFile(stManger*);

#endif

