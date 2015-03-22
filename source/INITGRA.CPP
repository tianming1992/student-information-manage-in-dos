#include"INITGRA.H"
#include<graphics.h>
#include<io.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<bios.h>
#include<mem.h>
#include<fcntl.h>
#include<stdlib.h>
#include<conio.h>
#define VGA256 0x13
#define TEXT_MODE 0x03

void initGra()
     {
       int GD=DETECT,GM;
	    union REGS inregs,outregs;
       registerbgidriver(EGAVGA_driver);
       registerbgifont(small_font);
       registerbgifont(sansserif_font);
       registerbgifont(gothic_font);
       initgraph(&GD,&GM,"");
	   settextjustify(LEFT_TEXT,TOP_TEXT);

	 
	   /*inregs.h.ah=0;
	   inregs.h.al=(unsigned char)VGA256;
	   int86(0x10,&inregs,&outregs);*/
	 }