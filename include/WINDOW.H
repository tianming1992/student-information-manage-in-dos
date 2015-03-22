/*****************************************************************************
Copyright (c) 2010, zoutianming&daiqian. All rights reserved.
------------------------------------------------------------------------------
window.h
Module Name: menu
Date Created:  2010-10-22
Author: zoutianming&daiqian
Description: based menu system modules 

------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------
2010-10-22

*****************************************************************************/

#ifndef  _WINDOW_H_
#define  _WINDOW_H_
#include "position.h"
#include "initgra.h"
#include "CONMICRO.h"
#include "message.h"
#include <dos.h>
#include <graphics.h>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <bios.h>

#define  TITLE_LENGTH 50
#define  TEXTDIALOG   0
#define  BUTTON    1
#define  DOWN_MENU_HEADER     2
#define  DOWN_MENU_BODY    3
#define  DOWN_TEXT_DIALOG 4
#define  WARNING_WINDOW  5
#define  RIGHT_BUTTON_MENU 6  
#define  CHOOSE_CIRCLE   7
#define  PASSWORD_DIALOG 8 
#define  NO_WINDOW_PRO_STOP_CHECK  -1
#define  NO_WINDOW_PRO_CONTINUE_CHECK    -2
#define  NO_WINDOW_ACTION_CONTINUE_CHECK -3
#define  MENU_RESTORE_BACKGROUND  -4
#define DIALOG_MOVE_CURSOR -5

#define  MAX_DIALOG_SHOW_LENGTH  50
#define  MAX_INPUT_LENGTH  31
#define  BACKSPACE 8
#define  ENTER 13
#define  BK_COLOR  BLUE

#define  BUTTON_COLOR 24
#define  BUTTON_COLOR_LIGHT 7
#define  BUTTON_COLOR_DARK  8
#define  BUTTON_LENGTH 50
#define  BUTTON_HEIGHT 25

#define  DOWN_MENU_BODY_LENGTH   200
#define  DOWN_MENU_BODY_HEIGHT    25

#define  TEXT_DIALOG_LENGTH  250

typedef  struct tagWindow{
	stPosition top;
	stPosition bottom;
    stPosition mousePositionWhenLeftKit;
	int nLength;
	int nHeight;
	int nHaveFather ;
	int nFatherID;
	unsigned long  int nLayTime;
	/*identify this window's ID in this system*/
	unsigned long int nMenuID;
	/*identify the kind of the window object*/
	int nKind;
	int nDraw;
	int nStartMove;
	char acTitle[TITLE_LENGTH];
	/*when window object is a  text dialog, keep the string inputed in this character array*/
	char acInputTextDialog[MAX_INPUT_LENGTH];
	/*when window object is a  text dialog, keep the string length  inputed in this character array*/
	int nTextLength;
	/*identify the window is or not active*/
	int nActive;
	int nPress;
	int nGetInputText;
	int nMenuDown;
	int nCheckEvent;
	unsigned int** storecolor; 
	void *pImage;
	int nSaveImage;
	struct tagWindow*pNextWindow;
	struct tagWindow*pLastWindow;

	/*draw the window object*/
	void (*pfDrawWindow)(struct tagWindow*);
	void (*pfGetText)(struct tagWindow*,char*);
	int  (*pfEventSelfAction)(struct tagWindow*,struct tagMessage*,struct tagMOUSE*);
	int (*pfIsMouseInside)(struct tagWindow*,struct tagMessage*);
   void (*pfShowTextDialogCursor)(struct tagWindow*);
   void (*pfSaveImage)(struct tagWindow* );
   void (*pfPutImage)(struct tagWindow* );
  }stWindow;



int  textDialogEventSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int isMouseInside(struct tagWindow*,struct tagMessage*);
struct tagWindow* getNewWindow(int nX,int nY,int nLength,int nHeight,int nKind,unsigned long int nMenuID,char* pacTitle);
void drawWindow(struct tagWindow*);

void showTextDialogCursor(struct tagWindow*);

void drawTextDialog(int ,int ,int,int ,char*);
void drawButton(struct tagWindow*);
void drawDownMenuHeader(struct tagWindow*);
void drawDownMenuBody(struct tagWindow*);
void drawDownTextDialog(struct tagWindow*);
void drawWarningWindow(struct tagWindow*);
void drawChooseCircleWindow(struct tagWindow*);
void drawPassWordDialog(struct tagWindow*);
void drawarning(int x,int y,char s[]);

void saveImage(struct tagWindow* );
void putImage(struct tagWindow* );

int  eventSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*);
int  buttonEventSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  DownMenuHeaderSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  downMenuBodySelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  downTextDialogSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  warningWindowSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  rightButtonMenuSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  chooseCircleSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);
int  passWordDialogSelfAction(struct tagWindow*pstCurrWindow,struct tagMessage*pstMsg,struct tagMOUSE*pstMOUSE);

void fillRectangle(int nX,int nY,int nLength,int nHeight,int nColor );
int isAPositionInARectangle(int nTopx,int nTopy,int nBottomx,int nBottomy,stPosition currPosition);
void moveBall(int,int,int,int);

void getPixel(unsigned int **storeColor,struct tagWindow*pstCurrWindow);
void putPixel(unsigned int **storeColor,struct tagWindow*pstCurrWindow);

#endif