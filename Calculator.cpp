/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************************************       Term project           *****************************************************/
/**********************************************************        CALCULATOR            *****************************************************/
/**********************************************************            by                *****************************************************/
/**********************************************************   Ifta Noor Mahmood (ADOR)   *****************************************************/
/**********************************************************          1005027             *****************************************************/
/**********************************************************       Submitted to:          *****************************************************/
/**********************************************************       Sumaiya Iqbal          *****************************************************/
/**********************************************************     Lecturer,CSE,BUET        *****************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
# include "iGraphics.h"
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define MAX 200

int buttonwd = 35;
int buttonhg = 25;
int spaceH = 12;
int spaceV = 10;
int dx = 0;
int dy = 0;
int count = 10;
int one = 0;
int two = 0;
int three = 0;
int four = 0;
int five = 0;
int six = 0;
int seven = 0;
int eight = 0;
int nine = 0;
int zero = 0;
int dzero = 0;
int plus = 0;
int minus = 0; 
int mult = 0;
int divi = 0; 
int point = 0;
int equal = 0;
int shiftLeft = 15;
int shiftUp = 5;
int shiftRight = 5;
int shiftDown = 12;

int standard=1;
int scientific=0;



int view=0;
int help=0; 
int gap=4;

int mem=0;
double memory=0;
int memoryState=0;

int about=0;
int hhelp=0;

int col=0;
int color=0;
int colorB=1;
int colorG=0;
int colorO=0;


int calculationStart =0;
char input[MAX];
int i = 0;
int j = 0;
int k = 0;
int error=0;
int clear = 0;



void drawBasicStructure()
{
	iSetColor(98,98,98);
	if(scientific==1)
		iFilledRectangle(140, 140,520,295);
	else if(standard==1)
		iFilledRectangle(140, 140,270,295);
	

	if(colorB==1)
		iSetColor(4,83,226);//blue
	else if(colorG==1)
		iSetColor(14,165,3);//Green
	else if(colorO==1)
		iSetColor(255,181,2);//orange
	if(scientific==1)
		iFilledRectangle(150, 150,500,275); //button base
	else if(standard==1)
		iFilledRectangle(150, 150,250,275); //button base
	if(scientific==1)
	{
		iSetColor(0,0,0);
		iLine(400,150,400,425);
	}
	iSetColor(239,249,255);
	if(standard==1)
		iFilledRectangle(165,340,220,45); //calculation area
	else if(scientific==1)
		iFilledRectangle(165,340,470,45); //calculation area


	if(colorB==1)
		iSetColor(34,114,254);//blue
	else if(colorG==1)
		iSetColor(17,182,5);//green
	else if(colorO==1)
		iSetColor(253,199,69);//orange
	if(scientific==1)
		iFilledRectangle(150,400,500,25);// menubar
	else if(standard==1)
		iFilledRectangle(150,400,250,25);// menubar

	iSetColor(0,0,0);
	if(scientific==1)
		iRectangle(150,150,500,275);
	else if(standard==1)
		iRectangle(150, 150,250,275);

}


void drawMenu()
{
	//View
	iSetColor(0,0,0);
	iRectangle(150,400,42,25);
	iSetColor(0,0,0);
	iText(156,410,"View",GLUT_BITMAP_HELVETICA_12);
	
	//Help
	iSetColor(0,0,0);
	iRectangle(192,400,42,25);
	iSetColor(0,0,0);
	iText(198,410,"Help",GLUT_BITMAP_HELVETICA_12);
	
	//Color
	iSetColor(0,0,0);
	iRectangle(150+42*2,400,42,25);
	iSetColor(0,0,0);
	iText(240,410,"Color",GLUT_BITMAP_HELVETICA_12);
}

void drawViewMenu()
{
	if(colorB==1)
		iSetColor(34,114,254);//blue
	else if(colorG==1)
		iSetColor(17,182,5);//green
	else if(colorO==1)
		iSetColor(253,199,69);//orange
	iFilledRectangle(150,350,100,50);
	iSetColor(186,186,239);
	iLine(165,400-gap,165,350+gap);// |

	iSetColor(186,186,239);
	iLine(165+gap,375,250-gap,375);//_

	iSetColor(0,0,0);
	iText(175,385,"Standerd",GLUT_BITMAP_HELVETICA_12);
	iSetColor(0,0,0);
	iText(175,360,"Scientific",GLUT_BITMAP_HELVETICA_12);
}

void drawHelpMenu()
{
	if(colorB==1)
		iSetColor(34,114,254);//blue
	else if(colorG==1)
		iSetColor(17,182,5);//green
	else if(colorO==1)
		iSetColor(253,199,69);//green
	iFilledRectangle(192,350,75,50);
	iSetColor(186,186,239);
	iLine(207,400-gap,207,350+gap);  // |

	iSetColor(186,186,239);
	iLine(207+gap,375,267-gap,375); // _

	iSetColor(0,0,0);
	iText(217,385,"Help",GLUT_BITMAP_HELVETICA_12);
	iSetColor(0,0,0);
	iText(217,360,"About",GLUT_BITMAP_HELVETICA_12);
}

void drawColorMenu()
{
	if(colorB==1)
		iSetColor(34,114,254);//blue
	else if(colorG==1)
		iSetColor(17,182,5);//green
	else if(colorO==1)
		iSetColor(253,199,69);//orange
	iFilledRectangle(150+42*2,325,75,75);
	iSetColor(186,186,239);
	iLine(150+42*2+15,400-gap,150+42*2+15,325+gap); // |

	iSetColor(186,186,239);
	iLine(249+gap,375,304,375); //__
	iLine(249+gap,350,304,350); //__
	iSetColor(0,0,0);
	iText(252,385,"Blue",GLUT_BITMAP_HELVETICA_12);
	iText(252,360,"Green",GLUT_BITMAP_HELVETICA_12);
	iText(252,335,"Orange",GLUT_BITMAP_HELVETICA_12);
}


void showHelp()
{
	if(colorB==1)//Blue
	{
		iShowBMP(0,0,"Photo\\helpB.bmp");
	}
	else if(colorG==1)//Green
	{
		iShowBMP(0,0,"Photo\\helpG.bmp");
	}
	else if(colorO==1)//Orange
	{
		iShowBMP(0,0,"Photo\\helpO.bmp");
	}
	iSetColor(255,255,255);
	iText(20,20,"Press Enter to return....");
}

void showAbout()
{
	
	if(colorB==1)
	{
		iShowBMP(0,0,"Photo\\aboutB.bmp");
	}
	else if(colorG==1)
	{
		iShowBMP(0,0,"Photo\\aboutG.bmp");
	}

	else if(colorO==1)
	{
		iShowBMP(0,0,"Photo\\aboutO.bmp");
	}
	iSetColor(255,255,255);
	iText(20,20,"Press Enter to return....");
}
void drawBoxBorder()
{
	iSetColor(0,0,0);
	if(scientific==1)
	{
		iLine(150,400,650,400);
		iRectangle(165,340,470,45);
	}
	else if(standard==1)
	{
		iLine(150,400,400,400);
		iRectangle(165,340,220,45);
	}
}

void drawKeypad()
{
	//row 1
	iSetColor(239,249,255);
	iFilledRectangle(165 + (0*spaceH) + (0*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (0*spaceH) + (0*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, "0",GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (1*spaceH) + (1*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (1*spaceH) + (1*buttonwd) + 13, 165 + (0*spaceV) + (0*buttonhg) + 10, ".", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (2*spaceH) + (2*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (2*spaceH) + (2*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, "+", GLUT_BITMAP_9_BY_15);
	if(col==0)
		iSetColor(239,249,255);
	else
		iSetColor(34,114,254);
	iFilledRectangle(165 + (3*spaceH) + (3*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (3*spaceH) + (3*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, "=", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (4*spaceH) + (4*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (4*spaceH) + (4*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, "MC", GLUT_BITMAP_9_BY_15);




	//row 2
	iSetColor(239,249,255);
	iFilledRectangle(165 + (0*spaceH) + (0*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (0*spaceH) + (0*buttonwd) + 12, 165 + (1*spaceV) + (1*buttonhg) + 8, "1", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (1*spaceH) + (1*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (1*spaceH) + (1*buttonwd) + 12, 165 + (1*spaceV) + (1*buttonhg) + 8, "2", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (2*spaceH) + (2*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (2*spaceH) + (2*buttonwd) + 12, 165 + (1*spaceV) + (1*buttonhg) + 8, "3", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (3*spaceH) + (3*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (3*spaceH) + (3*buttonwd) + 12, 165 + (1*spaceV) + (1*buttonhg) + 8, "-", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (4*spaceH) + (4*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (1*spaceV) + (1*buttonhg) + 8, "MR", GLUT_BITMAP_9_BY_15);




	//row 3
	iSetColor(239,249,255);
	iFilledRectangle(165 + (0*spaceH) + (0*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165+ (0*spaceH) + (0*buttonwd) + 12, 165 + (2*spaceV) + (2*buttonhg) + 8, "4", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (1*spaceH) + (1*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (1*spaceH) + (1*buttonwd) + 12, 165 + (2*spaceV) + (2*buttonhg) + 8, "5", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (2*spaceH) + (2*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (2*spaceH) + (2*buttonwd) + 12, 165 + (2*spaceV) + (2*buttonhg) + 8, "6", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (3*spaceH) + (3*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (3*spaceH) + (3*buttonwd) + 12, 165 + (2*spaceV) + (2*buttonhg) + 8, "x", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (4*spaceH) + (4*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (2*spaceV) + (2*buttonhg) + 8, "M-", GLUT_BITMAP_9_BY_15);



	//row 4
	iSetColor(239,249,255);
	iFilledRectangle(165 + (0*spaceH) + (0*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (0*spaceH) + (0*buttonwd) + 12, 165 + (3*spaceV) + (3*buttonhg) + 8, "7", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (1*spaceH) + (1*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (1*spaceH) + (1*buttonwd) + 12, 165 + (3*spaceV) + (3*buttonhg) + 8, "8", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (2*spaceH) + (2*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (2*spaceH) + (2*buttonwd) + 12, 165 + (3*spaceV) + (3*buttonhg) + 8, "9", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (3*spaceH) + (3*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (3*spaceH) + (3*buttonwd) + 12, 165 + (3*spaceV) + (3*buttonhg) + 8, "/", GLUT_BITMAP_9_BY_15);
	iSetColor(239,249,255);
	iFilledRectangle(165 + (4*spaceH) + (4*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (3*spaceV) + (3*buttonhg) + 8, "M+", GLUT_BITMAP_9_BY_15);



	//row 5
	iSetColor(239,249,255);
	iFilledRectangle(165 + (0*spaceH) + (0*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (0*spaceH) + (0*buttonwd) + 12, 165 + (4*spaceV) + (4*buttonhg) + 8, "C", GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(165 + (1*spaceH) + (1*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (1*spaceH) + (1*buttonwd) + 12-gap*2, 165 + (4*spaceV) + (4*buttonhg) + 8, "DEL", GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(165 + (2*spaceH) + (2*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (2*spaceH) + (2*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8, "/x", GLUT_BITMAP_9_BY_15);
	iSetColor(0,0,0);
	iLine(165 + (2*spaceH) + (2*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8+gap,165 + (2*spaceH) + (2*buttonwd) + 12-2, 165 + (4*spaceV) + (4*buttonhg) + 8);


	iSetColor(239,249,255);
	iFilledRectangle(165 + (3*spaceH) + (3*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (3*spaceH) + (3*buttonwd) + 12, 165 + (4*spaceV) + (4*buttonhg) + 8, "%", GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(165 + (4*spaceH) + (4*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(165 + (4*spaceH) + (4*buttonwd) + 8, 165 + (4*spaceV) + (4*buttonhg) + 8, "Off", GLUT_BITMAP_HELVETICA_10);


	if(scientific==1)
	{
	//row 6
	iSetColor(239,249,255);
	iFilledRectangle(415 + (0*spaceH) + (0*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (0*spaceH) + (0*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, "Pi",GLUT_BITMAP_9_BY_15);


	iSetColor(239,249,255);
	iFilledRectangle(415 + (1*spaceH) + (1*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (1*spaceH) + (1*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, "g",GLUT_BITMAP_9_BY_15);


	iSetColor(239,249,255);
	iFilledRectangle(415 + (2*spaceH) + (2*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (2*spaceH) + (2*buttonwd) + 12-gap*2, 165 + (0*spaceV) + (0*buttonhg) + 8, "EXP",GLUT_BITMAP_9_BY_15);


	iSetColor(239,249,255);
	iFilledRectangle(415 + (3*spaceH) + (3*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, " ", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (4*spaceH) + (4*buttonwd), 165 + (0*spaceV) + (0*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 12, 165 + (0*spaceV) + (0*buttonhg) + 8, " ",GLUT_BITMAP_9_BY_15);
	
	
	//row 7
	iSetColor(239,249,255);
	iFilledRectangle(415 + (0*spaceH) + (0*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (0*spaceH) + (0*buttonwd) + 12-gap, 165 + (1*spaceV) + (1*buttonhg) + 8, " ", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (1*spaceH) + (1*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (1*spaceH) + (1*buttonwd) + 12-gap, 165 + (1*spaceV) + (1*buttonhg) + 8, " ", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (2*spaceH) + (2*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (2*spaceH) + (2*buttonwd) + 12-gap, 165 + (1*spaceV) + (1*buttonhg) + 8, " ", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (3*spaceH) + (3*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12-gap, 165 + (1*spaceV) + (1*buttonhg) + 8, " ", GLUT_BITMAP_HELVETICA_10);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12+gap*2, 165 + (1*spaceV) + (1*buttonhg) + 8+gap, " ", GLUT_BITMAP_HELVETICA_10);


	iSetColor(239,249,255);
	iFilledRectangle(415 + (4*spaceH) + (4*buttonwd), 165 + (1*spaceV) + (1*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (1*spaceV) + (1*buttonhg) + 8, " ", GLUT_BITMAP_HELVETICA_10);

	

	//row8
	iSetColor(239,249,255);
	iFilledRectangle(415 + (0*spaceH) + (0*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (0*spaceH) + (0*buttonwd) + 12-gap*2, 165 + (2*spaceV) + (2*buttonhg) + 8, "nCr",GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (1*spaceH) + (1*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (1*spaceH) + (1*buttonwd) + 12-gap*2, 165 + (2*spaceV) + (2*buttonhg) + 8, "nPr",GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (2*spaceH) + (2*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (2*spaceH) + (2*buttonwd) + 12-gap, 165 + (2*spaceV) + (2*buttonhg) + 8, "x!",GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (3*spaceH) + (3*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12-gap*2, 165 + (2*spaceV) + (2*buttonhg) + 8, "1/x",GLUT_BITMAP_9_BY_15);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (4*spaceH) + (4*buttonwd), 165 + (2*spaceV) + (2*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (2*spaceV) + (2*buttonhg) + 8, "X",GLUT_BITMAP_9_BY_15);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 14+gap, 165 + (2*spaceV) + (2*buttonhg) + 8+gap*2, " y", GLUT_BITMAP_HELVETICA_10);


	//row9
	iSetColor(239,249,255);
	iFilledRectangle(415 + (0*spaceH) + (0*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (0*spaceH) + (0*buttonwd) + 12-gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8, "Sin", GLUT_BITMAP_HELVETICA_10);
	iSetColor(0,0,0);
	iText(415 + (0*spaceH) + (0*buttonwd) + 12+gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8+gap, "-1", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (1*spaceH) + (1*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (1*spaceH) + (1*buttonwd) + 12-gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8, "Cos", GLUT_BITMAP_HELVETICA_10);
	iSetColor(0,0,0);
	iText(415 + (1*spaceH) + (1*buttonwd) + 12+gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8+gap, "-1", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (2*spaceH) + (2*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (2*spaceH) + (2*buttonwd) + 12-gap, 165 + (3*spaceV) + (3*buttonhg) + 8, "Tan", GLUT_BITMAP_HELVETICA_10);
	iSetColor(0,0,0);
	iText(415 + (2*spaceH) + (2*buttonwd) + 12+gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8+gap, "-1", GLUT_BITMAP_HELVETICA_10);


	iSetColor(239,249,255);
	iFilledRectangle(415 + (3*spaceH) + (3*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12-gap, 165 + (3*spaceV) + (3*buttonhg) + 8, "10", GLUT_BITMAP_HELVETICA_10);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12+gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8+gap*2, "x", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (4*spaceH) + (4*buttonwd), 165 + (3*spaceV) + (3*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (3*spaceV) + (3*buttonhg) + 8, "e",GLUT_BITMAP_9_BY_15);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 12+gap*2, 165 + (3*spaceV) + (3*buttonhg) + 8+gap*2, "x", GLUT_BITMAP_HELVETICA_10);


	//row 10
	iSetColor(239,249,255);
	iFilledRectangle(415 + (0*spaceH) + (0*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (0*spaceH) + (0*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8, "Sin", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (1*spaceH) + (1*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (1*spaceH) + (1*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8, "Cos", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (2*spaceH) + (2*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (2*spaceH) + (2*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8, "Tan", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (3*spaceH) + (3*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (3*spaceH) + (3*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8, "Log", GLUT_BITMAP_HELVETICA_10);

	iSetColor(239,249,255);
	iFilledRectangle(415 + (4*spaceH) + (4*buttonwd), 165 + (4*spaceV) + (4*buttonhg), buttonwd, buttonhg);
	iSetColor(0,0,0);
	iText(415 + (4*spaceH) + (4*buttonwd) + 12-gap, 165 + (4*spaceV) + (4*buttonhg) + 8, "ln", GLUT_BITMAP_HELVETICA_10);

	}

}

void drawDefaultDisplay()
{
	iSetColor(0,0,0);
	drawBoxBorder();
	iText(170, 345, "0", GLUT_BITMAP_HELVETICA_18);
}

void drawCalculation()
{
	drawDefaultDisplay();
	iText(165 + shiftRight, 400 - 15 - shiftDown, input, GLUT_BITMAP_HELVETICA_12);
}

void errorPrint(int j)
{
	iSetColor(239,249,255);
	iFilledRectangle(165,340, 220, 45);
	drawBoxBorder();
	if(j==1)
		iText(170,345, "CANNOT BE DIVIDED BY ZERO", GLUT_BITMAP_HELVETICA_12);
	else if(j==2)
		iText(170,345, "MATH ERROR!", GLUT_BITMAP_HELVETICA_18);
	else if(j==3)
		iText(170,345, "SYNTEX ERROR!", GLUT_BITMAP_HELVETICA_18);
}


double f[50];
char ch[60]={};
char eq[200]={};
char ans[8];
void distribution(char*);
void doCalculation(char*);
void leftShift(int);
void charLeftShift(int);

int x=0,y=0;

void strLeftShift(int i)
{
    for(i;i<50;i++)
    {
        eq[i]=eq[i+1];
    }
}

void simplify()
{
    int v=0;
    for(v=0;v<(int)strlen(eq);v++)
    {
        if(eq[v]=='r')
        {
            strLeftShift(v+3);
            strLeftShift(v+2);
            strLeftShift(v+1);
        }
		if(eq[v]=='i')
        {
            strLeftShift(v+2);
            strLeftShift(v+1);
        }
		if(eq[v]=='s')
        {
            strLeftShift(v+2);
            strLeftShift(v+1);
        }
		if(eq[v]=='c')
        {
            strLeftShift(v+2);
            strLeftShift(v+1);
        }
		if(eq[v]=='t')
        {
            strLeftShift(v+2);
            strLeftShift(v+1);
        }
		if(eq[v]=='L')
        {
            strLeftShift(v+2);
            strLeftShift(v+1);
        }
		if(eq[v]=='l')
        {
            strLeftShift(v+1);
        }

		/*****************Invers************************/
		if(eq[v]=='a' && eq[v+1]=='S')
        {
            strLeftShift(v+3);
            strLeftShift(v+2);
			strLeftShift(v);
        }
		if(eq[v]=='a' && eq[v+1]=='C')
        {
            strLeftShift(v+3);
            strLeftShift(v+2);
			strLeftShift(v+1);
        }
		if(eq[v]=='a' && eq[v+1]=='T')
        {
            strLeftShift(v+3);
            strLeftShift(v+2);
			strLeftShift(v);
        }
		if(eq[v]=='K' && eq[v+1]=='L')
        {
            strLeftShift(v+3);
            strLeftShift(v+2);
			strLeftShift(v+1);
        }
		if(eq[v]=='k' && eq[v+1]=='l')
        {
            strLeftShift(v+2);
			strLeftShift(v+1);
        }
    }
}

void errorCheak()
{
	int i=0;
	for(i;i<(int)strlen(ch);i++)
	{
		if(ch[i]=='/' && f[i+1]==0)
		{
			error=1;
		}
		else if(ch[i]=='t' && f[i]==90)
		{	error=2;
		}
		else if((ch[i]=='S' ||ch[i]=='a') && (f[i]>1 || f[i]<-1))
		{	
			error=2;
		}
		else if((ch[i]=='L' ||ch [i]=='l') && f[i]<=0)
		{
			error=2;
		}
	}
	for(i=0;i<(int)strlen(eq);i++)
	{
		if(eq[i]=='r' && eq[i+1]=='-')
			error=2;
	}
}


void distribution()     // This function takes a input string and put the numbers in a double array(global)
                            // and put the oparators in a charecter array(global).
{
    int u=0,v=0,i=0;
    double j=0.0;
	simplify();
	puts(eq);
    //l=strlen(eq);  //This is to remove last = in the input string
    //eq[l-1]='\0';
	//puts(eq);


	if(eq[0]=='r' ||eq[0]=='i' || eq[0]=='s' || eq[0]=='c' || eq[0]=='t' || eq[0]=='L' || eq[0]=='l' || eq[0]=='S' || eq[0]=='a' || eq[0]=='T' || eq[0]=='K' || eq[0]=='k' || eq[0]=='C' || eq[0]=='P'|| eq[0]=='!')
	{
		ch[0]=eq[0];
		u++;
		x++;
	}
    for(u=0;u<(int)strlen(eq);u++)
    {
        if(eq[u]>=48 && eq[u]<=57)
        {
            i=i*10;
            i=i+(eq[u]-48);
            if(eq[u+1]=='+' || eq[u+1]=='-' || eq[u+1]=='*' || eq[u+1]=='/' || eq[u+1]=='%' || eq[u+1]=='^'|| eq[u+1]=='C'|| eq[u+1]=='P'|| eq[u+1]=='!'|| eq[u+1]=='\0')
            {
                f[y]=i;
				//printf("\n%lf",f[y]);
                ch[x]=eq[u+1];
				if(eq[u+1]=='!')
				{
					ch[x+1]=eq[u+2];
					x++;
					u++;
				}
				/*if(!(eq[u+2]>='0' && eq[u+2]<='9') || eq[u+2]!='.')
				{
					ch[x+1]=eq[u+2];
					x++;
					u++;
				}*/
				if(eq[u+2]=='r')
				{
					ch[x+1]='r';
					x++;
					u++;
				}
				else if(eq[u+2]=='i')
				{
					ch[x+1]='i';
					x++;
					u++;
				}
				else if(eq[u+2]=='s')
				{
					ch[x+1]='s';
					x++;
					u++;
				}
				else if(eq[u+2]=='c')
				{
					ch[x+1]='c';
					x++;
					u++;
				}
				else if(eq[u+2]=='t')
				{
					ch[x+1]='t';
					x++;
					u++;
				}
				else if(eq[u+2]=='L')
				{
					ch[x+1]='L';
					x++;
					u++;
				}
				else if(eq[u+2]=='l')
				{
					ch[x+1]='l';
					x++;
					u++;
				}
				else if(eq[u+2]=='S')
				{
					ch[x+1]='S';
					x++;
					u++;
				}
				else if(eq[u+2]=='a')
				{
					ch[x+1]='a';
					x++;
					u++;
				}
				else if(eq[u+2]=='T')
				{
					ch[x+1]='T';
					x++;
					u++;
				}
				else if(eq[u+2]=='K')
				{
					ch[x+1]='K';
					x++;
					u++;
				}else if(eq[u+2]=='k')
				{
					ch[x+1]='k';
					x++;
					u++;
				}
				//ch[x+1]='\0';
				puts(ch);
                y++;
                x++;
				u++;
                i=0;
            }
        }
        if(eq[u]=='.')
        {
            for(v=1;;v++,u++)
            {
                j=j+((eq[u+1]-48)/(pow(10.0,v)));
                if(eq[u+2]=='+' || eq[u+2]=='-' || eq[u+2]=='*' || eq[u+2]=='/' ||eq[u+2]=='%' || eq[u+1]=='^'|| eq[u+1]=='C'|| eq[u+1]=='P'|| eq[u+2]=='\0')
                {
                    f[y]=i+j;
                    i=0;
                    j=0.0;
                    ch[x]=eq[u+2];
					if(eq[u+3]=='r')
					{
						ch[x+1]='r';
						x++;
						u++;
					}
					else if(eq[u+3]=='i')
					{
						ch[x+1]='i';
						x++;
						u++;
					}
					else if(eq[u+3]=='s')
					{
						ch[x+1]='s';
						x++;
						u++;
					}
					else if(eq[u+3]=='c')
					{
						ch[x+1]='c';
						x++;
						u++;
					}
					else if(eq[u+3]=='t')
					{
						ch[x+1]='t';
						x++;
						u++;
					}
					else if(eq[u+3]=='L')
					{
						ch[x+1]='L';
						x++;
						u++;
					}
					else if(eq[u+3]=='l')
					{
						ch[x+1]='l';
						x++;
						u++;
					}
					else if(eq[u+3]=='S')
					{
						ch[x+1]='S';
						x++;
						u++;
					}
					else if(eq[u+3]=='a')
					{
						ch[x+1]='a';
						x++;
						u++;
					}
					else if(eq[u+3]=='T')
					{
						ch[x+1]='T';
						x++;
						u++;
					}
					else if(eq[u+3]=='K')
					{
						ch[x+1]='K';
						x++;
						u++;
					}
					else if(eq[u+3]=='k')
					{
						ch[x+1]='k';
						x++;
						u++;
					}
					x++;
                    y++;
                    u=u+2;
                    break;
                }
            }
        }


    }

	//for(u=0;u<10;u++)
		//printf(" %.2lf",f[u]);
	puts(ch);

}


void leftShift(int i)
{
    for(i;i<29;i++)
    {
        f[i]=f[i+1];
    }
    f[29]=0.0;
}
void charLeftShift(int i)
{
    for(i;i<20;i++)
    {
        ch[i]=ch[i+1];

    }
}

int factorial(int n)
{
    int q,fac=1;
    if(n!=0)
    {
        for(q=n;q>=1;q--)
            fac=fac*q;
        return fac;
    }

    else
        return 1;
}
int nPr(int n,int r)
{
      int x,y,z;
      x=factorial(n);
      y=factorial(n-r);
      z=x/y;
      return z;
}

int nCr(int n, int r)
{
      int x,y,z;
      x=nPr(n,r);
      y=factorial(r);
      z=x/y;
      return z;
}

void removeZero()
{
	int l;
	l=strlen(ans)-1;
	for(l;l>0;l--)
	{
		if(ans[l]=='0')
		{
			ans[l]='\0';
			if(ans[l-1]!='0')
				break;
		}
	}
	for(l=0;l<(int)strlen(ans);l++)
	{
		if(ans[l]=='.' && ans[l+1]=='\0')
			ans[l]='\0';
	}
}


void doCalculation(char*str)
{
    int i,k;
    double a,b,result=0.0;
	for(k=0;k<(int)strlen(str);k++)
		eq[k]=str[k];
	eq[k+1]='\0';
    distribution();
	errorCheak();
	puts(ch);

	//Percentage
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='%')
        {
            a=f[i];
            f[i]=a/100;
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }


	//root
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='r')
        {
            a=f[i];
            f[i]=pow(a,.5);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }
	//invers
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='i')
        {
            a=f[i];
            f[i]=1/a;
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }

	//Sin
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='s')
        {
            a=f[i];
			a=(a*3.141592653589)/180;
            f[i]=sin(a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }

	//Cos
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='c')
        {
            a=f[i];
            a=(a*3.141592653589)/180;
            f[i]=cos(a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }

	//Tan
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='t')
        {
            a=f[i];
            a=(a*3.141592653589)/180;
            f[i]=tan(a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }
	//ln
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='l')
        {
            a=f[i];
            f[i]=log(a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }
	//Log
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='L')
        {
            a=f[i];
            f[i]=log10(a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }

	 /********************************************************************************************/
	/********************************************INVERS******************************************/
   /********************************************************************************************/
	//aSin
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='S')
        {
            a=f[i];
			a=asin(a);
            f[i]=a*180/3.141592653589;
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }

	//aCos
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='a')
        {
            a=f[i];
            a=acos(a);
            f[i]=a*180/3.141592653589;
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }

	//aTan
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='T')
        {
            a=f[i];
            a=atan(a);
            f[i]=a*180/3.141592653589;
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }
	//kln
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='k')
        {
            a=f[i];
            f[i]=pow(2.718281828459,a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }
	//KLog
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='K')
        {
            a=f[i];
            f[i]=pow(10.0,a);
            charLeftShift(i);
            if(i==0)
            {
                i=-1;
            }
            else i--;
        }
    }
	

	for(i=0;i<(int)strlen(ch);i++)  //nCr
    {
        if(ch[i]=='C')
        {
            a=f[i];
            b=f[i+1];
            f[i]=nCr(a,b);
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else 
				i--;
        }
    }

	for(i=0;i<(int)strlen(ch);i++)  // nPr
    {
        if(ch[i]=='P')
        {
            a=f[i];
            b=f[i+1];
            f[i]=nPr(a,b);
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else 
				i--;
        }
    }

	for(i=0;i<(int)strlen(ch);i++)  // !
    {
        if(ch[i]=='!')
        {
            a=f[i];
            f[i]=factorial(a);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else 
				i--;
        }
    }

	//x to the power y
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='^')
        {
            a=(f[i])*1.0;
            b=f[i+1];
            f[i]=pow(a,b);
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else 
				i--;
        }
    }



    
	for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='/')
        {
            a=f[i];
            b=f[i+1];
            f[i]=a/b;
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else 
				i--;
        }
    }
    for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='*')
        {
            a=f[i];
            b=f[i+1];
            f[i]=a*b;
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else 
				i--;
        }
    }
    for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
            a=f[i];
            b=f[i+1];
            f[i]=a-b;
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else
				i--;
        }
    }
    for(i=0;i<(int)strlen(ch);i++)
    {
        if(ch[i]=='+')
        {
            a=f[i];
            b=f[i+1];
            f[i]=a+b;
            leftShift(i+1);
            charLeftShift(i);
            if(i==0)
                i=-1;
            else
				i--;
        }
    }
	if(scientific==1)
		sprintf(ans,"%g",f[0]);
	else if(standard==1)
	{
		sprintf(ans,"%lf",f[0]);
		removeZero();
	}
	
}


void printResult()
{
	int l;
	l=strlen(ans);
	iSetColor(239,249,255);
	if(standard==1)
		iFilledRectangle(165,340, 220,30);
	else if(scientific==1)
		iFilledRectangle(165,340, 470,30);
	drawBoxBorder();
	iText(170,345,ans, GLUT_BITMAP_HELVETICA_18);
}

void iDraw()
{
	iClear();
	if(colorB==1)
		iShowBMP(0,0,"Photo\\blue.bmp");
	else if(colorG==1)
		iShowBMP(0,0,"Photo\\green.bmp");
	else if(colorO==1)
		iShowBMP(0,0,"Photo\\orange.bmp");
	//iShowBMP(0,0,"Photo\\Background_1.bmp");
	drawBasicStructure();
	drawMenu();
	drawBoxBorder();
	drawKeypad();
	drawDefaultDisplay(); 
	drawCalculation();
	if( (input[0] == '+') || (input[0]=='*') || (input[0]=='!') || (input[0]=='^') || (input[0]=='C') || (input[0]=='P') || (input[0]=='%') || (input[0]=='/'))
	{
		//iSetColor(239,249,255);
		//iFilledRectangle(15, hg - 25 - 60, wd - 15 - 15, 45);
		errorPrint(3);
	}
	else if(error)
	{
		errorPrint(error);
	}
	else if(clear == 1)
	{
		iSetColor(239,249,255);
		drawDefaultDisplay();
	}
	else if(equal == 1 || mem==1)
	{
		printResult();
	}

	if(memoryState==1 && standard==1)
		iText(370,345,"M",GLUT_BITMAP_HELVETICA_10);
	else if(memoryState==1 && scientific==1)
		iText(620,345,"M",GLUT_BITMAP_HELVETICA_10);

	if(view==1)
	{
		help=0;
		drawViewMenu();
	}
	else if(help==1)
	{
		view=0;
		drawHelpMenu();
	}
	else if(hhelp==1)
	{
		view=0;
		help=0;
		showHelp();
	}
	else if(about==1)
	{
		view=0;
		help=0;
		hhelp=0;
		showAbout();
	}
	else if(color==1)
	{
		drawColorMenu();
	}
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("(%d,%d)\n",mx,my);
		if(mx>=(165 + (4*spaceH) + (4*buttonwd)) && mx<=(165 + (4*spaceH) + (5*buttonwd)) && my>=(165 + (4*spaceV) + (4*buttonhg))&& my <=(165 + (4*spaceV) + (5*buttonhg)))
		{
			printf("OFF\n");
			exit(0);
		}
		if((mx >= 165 + (0*spaceH) + (0*buttonwd)) && (mx <= 165 + (0*spaceH) + (0*buttonwd) + buttonwd) && (my >= 165 + (0*spaceV) + (0*buttonhg)) && (my <= 165 + (0*spaceV) + (0*buttonhg) + buttonhg))
		{
			zero = 1;
			input[i] = '0';
			input[i + 1] = '\0';
			i++;
			printf("\nzero");
		}
		if((mx >= 165 + (0*spaceH) + (0*buttonwd)) && (mx <= 165 + (0*spaceH) + (0*buttonwd) + buttonwd) && (my >= 165 + (1*spaceV) + (1*buttonhg)) && (my <= 165 + (1*spaceV) + (1*buttonhg) + buttonhg))
		{
			one = 1;
			input[i] = '1';
			input[i + 1] = '\0';
			i++;
			printf("\none");
		}
		if((mx >= 165 + (1*spaceH) + (1*buttonwd)) && (mx <= 165 + (1*spaceH) + (1*buttonwd) + buttonwd) && (my >= 165 + (1*spaceV) + (1*buttonhg)) && (my <= 165 + (1*spaceV) + (1*buttonhg) + buttonhg))
		{
			two = 1;
			input[i] = '2';
			input[i + 1] = '\0';
			i++;
			printf("\ntwo");
		}
		if((mx >= 165 + (2*spaceH) + (2*buttonwd)) && (mx <= 165 + (2*spaceH) + (2*buttonwd) + buttonwd) && (my >= 165 + (1*spaceV) + (1*buttonhg)) && (my <= 165 + (1*spaceV) + (1*buttonhg) + buttonhg))
		{
			three = 1;
			input[i] = '3';
			input[i + 1] = '\0';
			i++;
			printf("\nthree");
		}
		if((mx >= 165 + (0*spaceH) + (0*buttonwd)) && (mx <= 165 + (0*spaceH) + (0*buttonwd) + buttonwd) && (my >= 165 + (2*spaceV) + (2*buttonhg)) && (my <= 165 + (2*spaceV) + (2*buttonhg) + buttonhg))
		{
			four = 1;
			input[i] = '4';
			input[i + 1] = '\0';
			i++;
			printf("\nfour");
		}
		if((mx >= 165 + (1*spaceH) + (1*buttonwd)) && (mx <= 165 + (1*spaceH) + (1*buttonwd) + buttonwd) && (my >= 165 + (2*spaceV) + (2*buttonhg)) && (my <= 165 + (2*spaceV) + (2*buttonhg) + buttonhg))
		{
			five = 1;
			input[i] = '5';
			input[i + 1] = '\0';
			i++;
			printf("\nfive");
		}
		if((mx >= 165 + (2*spaceH) + (2*buttonwd)) && (mx <= 165 + (2*spaceH) + (2*buttonwd) + buttonwd) && (my >= 165 + (2*spaceV) + (2*buttonhg)) && (my <= 165 + (2*spaceV) + (2*buttonhg) + buttonhg))
		{
			six = 1;
			input[i] = '6';
			input[i + 1] = '\0';
			i++;
			printf("\nsix");
		}
		if((mx >= 165 + (0*spaceH) + (0*buttonwd)) && (mx <= 165 + (0*spaceH) + (0*buttonwd) + buttonwd) && (my >= 165 + (3*spaceV) + (3*buttonhg)) && (my <= 165 + (3*spaceV) + (3*buttonhg) + buttonhg))
		{
			seven = 1;
			input[i] = '7';
			input[i + 1] = '\0';
			i++;
			printf("\nseven");
		}
		if((mx >= 165 + (1*spaceH) + (1*buttonwd)) && (mx <= 165 + (1*spaceH) + (1*buttonwd) + buttonwd) && (my >= 165 + (3*spaceV) + (3*buttonhg)) && (my <= 165 + (3*spaceV) + (3*buttonhg) + buttonhg))
		{
			eight = 1;
			input[i] = '8';
			input[i + 1] = '\0';
			i++;
			printf("\neight");
		}
		if((mx >= 165 + (2*spaceH) + (2*buttonwd)) && (mx <= 165 + (2*spaceH) + (2*buttonwd) + buttonwd) && (my >= 165 + (3*spaceV) + (3*buttonhg)) && (my <= 165 + (3*spaceV) + (3*buttonhg) + buttonhg))
		{
			nine = 1;
			input[i] = '9';
			input[i + 1] = '\0';
			i++;
			printf("\nnine");
		}
		if((mx >= 165 + (2*spaceH) + (2*buttonwd)) && (mx <= 165 + (2*spaceH) + (2*buttonwd) + buttonwd) && (my >= 165 + (0*spaceV) + (0*buttonhg)) && (my <= 165 + (0*spaceV) + (0*buttonhg) + buttonhg))
		{
			plus = 1;
			input[i] = '+';
			input[i + 1] = '\0';
			i++;
			printf("\nplus");
		}
		if((mx >= 165 + (3*spaceH) + (3*buttonwd)) && (mx <= 165 + (3*spaceH) + (3*buttonwd) + buttonwd) && (my >= 165 + (1*spaceV) + (1*buttonhg)) && (my <= 165 + (1*spaceV) + (1*buttonhg) + buttonhg))
		{
			if(i==0)
			{
				input[i]='0';
				input[i+1]='-';
				i=i+2;
			}
			else
			{
				minus = 1;
				input[i] = '-';
				input[i + 1] = '\0';
				i++;
			}
			printf("\nminus");
		}
		if((mx >= 165 + (3*spaceH) + (3*buttonwd)) && (mx <= 165 + (3*spaceH) + (3*buttonwd) + buttonwd) && (my >= 165 + (2*spaceV) + (2*buttonhg)) && (my <= 165 + (2*spaceV) + (2*buttonhg) + buttonhg))
		{
			minus = 1;
			input[i] = '*';
			input[i + 1] = '\0';
			i++;
			printf("\nmult");
		}
		if((mx >= 165 + (3*spaceH) + (3*buttonwd)) && (mx <= 165 + (3*spaceH) + (3*buttonwd) + buttonwd) && (my >= 165 + (3*spaceV) + (3*buttonhg)) && (my <= 165 + (3*spaceV) + (3*buttonhg) + buttonhg))
		{
			divi= 1;
			input[i] = '/';
			input[i + 1] = '\0';
			i++;
			printf("\ndiv");
		}
		if((mx >= 165 + (3*spaceH) + (3*buttonwd)) && (mx <= 165 + (3*spaceH) + (3*buttonwd) + buttonwd) && (my >= 165 + (0*spaceV) + (0*buttonhg)) && (my <= 165 + (0*spaceV) + (0*buttonhg) + buttonhg))
		{
			equal = 1;
			col=1;
			doCalculation(input);
			printf("\nequal");
		}
		/****************************************************************************************************/
		/******************************************    MEMORY    ********************************************/
		/****************************************************************************************************/
		if((mx >= 165 + (4*spaceH) + (4*buttonwd)) && (mx <= 165 + (4*spaceH) + (4*buttonwd) + buttonwd) && (my >= 165 + (3*spaceV) + (3*buttonhg)) && (my <= 165 + (3*spaceV) + (3*buttonhg) + buttonhg))
		{
			memoryState= 1;
			doCalculation(input);
			mem=1;
			memory=memory+atof(ans);
			printf("\nmemory +");
		}
		if((mx >= 165 + (4*spaceH) + (4*buttonwd)) && (mx <= 165 + (4*spaceH) + (4*buttonwd) + buttonwd) && (my >= 165 + (2*spaceV) + (2*buttonhg)) && (my <= 165 + (2*spaceV) + (2*buttonhg) + buttonhg))
		{
			memoryState= 1;
			mem=0;
			doCalculation(input);
			memory=memory-atof(ans);
			printf("\nmemory -");
		}
		if((mx >= 165 + (4*spaceH) + (4*buttonwd)) && (mx <= 165 + (4*spaceH) + (4*buttonwd) + buttonwd) && (my >= 165 + (1*spaceV) + (1*buttonhg)) && (my <= 165 + (1*spaceV) + (1*buttonhg) + buttonhg))
		{
			memoryState= 1;
			mem=1;
			doCalculation(input);
			sprintf(ans,"%g",memory);
			printf("\nmemory return");
		}

		if((mx >= 165 + (4*spaceH) + (4*buttonwd)) && (mx <= 165 + (4*spaceH) + (4*buttonwd) + buttonwd) && (my >= 165 + (0*spaceV) + (0*buttonhg)) && (my <= 165 + (0*spaceV) + (0*buttonhg) + buttonhg))
		{
			memoryState= 0;
			mem=0;
			doCalculation(input);
			memory=0;
			printf("\nmemory clean");
		}






		//Delete
		if((mx >= 165 + (1*spaceH) + (1*buttonwd)) && (mx <= 165 + (1*spaceH) + (1*buttonwd) + buttonwd) && (my >= 165 + (4*spaceV) + (4*buttonhg)) && (my <= 165 + (4*spaceV) + (4*buttonhg) + buttonhg))
		{
			input[i-1]='\0';
			i--;
			printf("\nDel");
		}

		//Percentage
		if((mx >= 165 + (3*spaceH) + (3*buttonwd)) && (mx <= 165 + (3*spaceH) + (3*buttonwd) + buttonwd) && (my >= 165 + (4*spaceV) + (4*buttonhg)) && (my <= 165 + (4*spaceV) + (4*buttonhg) + buttonhg))
		{
			input[i]='%';
			i++;
			printf("\nRoot");
		}
		//root
		if((mx >= 165 + (2*spaceH) + (2*buttonwd)) && (mx <= 165 + (2*spaceH) + (2*buttonwd) + buttonwd) && (my >= 165 + (4*spaceV) + (4*buttonhg)) && (my <= 165 + (4*spaceV) + (4*buttonhg) + buttonhg))
		{
			input[i]='r';
			input[i+1]='o';
			input[i+2]='o';
			input[i+3]='t';
			i=i+4;
			printf("\nRoot");
		}
		/***************************************************************************************************************/
		/***********************************************      SCIENTIFIC     *******************************************/
		/***************************************************************************************************************/
		
		//sin
		if(mx>= 415 + (0*spaceH) + (0*buttonwd) && mx<= 415 + (0*spaceH) + (0*buttonwd)+buttonwd && my>= 165 + (4*spaceV) + (4*buttonhg) && my<= 165 + (4*spaceV) + (4*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='s';
			input[i+1]='i';
			input[i+2]='n';
			i=i+3;
			printf("\nSin");
		
		}
		//cos
		if(mx>= 415 + (1*spaceH) + (1*buttonwd) && mx<= 415 + (1*spaceH) + (1*buttonwd)+buttonwd && my>= 165 + (4*spaceV) + (4*buttonhg) && my<= 165 + (4*spaceV) + (4*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='c';
			input[i+1]='o';
			input[i+2]='s';
			i=i+3;
			printf("\nCos");
		}
		//tan
		if(mx>= 415 + (2*spaceH) + (2*buttonwd) && mx<= 415 + (2*spaceH) + (2*buttonwd)+buttonwd && my>= 165 + (4*spaceV) + (4*buttonhg) && my<= 165 + (4*spaceV) + (4*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='t';
			input[i+1]='a';
			input[i+2]='n';
			i=i+3;
			printf("\nTan");
		}
		//Log
		if(mx>= 415 + (3*spaceH) + (3*buttonwd) && mx<= 415 + (3*spaceH) + (3*buttonwd)+buttonwd && my>= 165 + (4*spaceV) + (4*buttonhg) && my<= 165 + (4*spaceV) + (4*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='L';
			input[i+1]='o';
			input[i+2]='g';
			i=i+3;
			printf("\nLog");
		}
		//ln
		if(mx>= 415 + (4*spaceH) + (4*buttonwd) && mx<= 415 + (4*spaceH) + (4*buttonwd)+buttonwd && my>= 165 + (4*spaceV) + (4*buttonhg) && my<= 165 + (4*spaceV) + (4*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='l';
			input[i+1]='n';
			i=i+2;
			printf("\nln");
		}

		/****************************************************************************************************/
		/**********************************            INVERS           *************************************/
		/****************************************************************************************************/

		//asin
		if(mx>= 415 + (0*spaceH) + (0*buttonwd) && mx<= 415 + (0*spaceH) + (0*buttonwd)+buttonwd && my>= 165 + (3*spaceV) + (3*buttonhg) && my<= 165 + (3*spaceV) + (3*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='a';
			input[i+1]='S';
			input[i+2]='i';
			input[i+3]='n';
			i=i+4;
			printf("\naSin");
		
		}
		//acos
		if(mx>= 415 + (1*spaceH) + (1*buttonwd) && mx<= 415 + (1*spaceH) + (1*buttonwd)+buttonwd && my>= 165 + (3*spaceV) + (3*buttonhg) && my<= 165 + (3*spaceV) + (3*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='a';
			input[i+1]='C';
			input[i+2]='o';
			input[i+3]='s';
			i=i+4;
			printf("\naCos");
		}
		//atan
		if(mx>= 415 + (2*spaceH) + (2*buttonwd) && mx<= 415 + (2*spaceH) + (2*buttonwd)+buttonwd && my>= 165 + (3*spaceV) + (3*buttonhg) && my<= 165 + (3*spaceV) + (3*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='a';
			input[i+1]='T';
			input[i+2]='a';
			input[i+3]='n';
			i=i+4;
			printf("\naTan");
		}
		//KLog
		if(mx>= 415 + (3*spaceH) + (3*buttonwd) && mx<= 415 + (3*spaceH) + (3*buttonwd)+buttonwd && my>= 165 + (3*spaceV) + (3*buttonhg) && my<= 165 + (3*spaceV) + (3*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='K';
			input[i+1]='L';
			input[i+2]='o';
			input[i+3]='g';
			i=i+4;
			printf("\nKLog");
		}
		//kln
		if(mx>= 415 + (4*spaceH) + (4*buttonwd) && mx<= 415 + (4*spaceH) + (4*buttonwd)+buttonwd && my>= 165 + (3*spaceV) + (3*buttonhg) && my<= 165 + (3*spaceV) + (3*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='k';
			input[i+1]='l';
			input[i+2]='n';
			i=i+3;
			printf("\nkln");
		}
		/*****************************************************************************************************/
		/***********************        Permutation+Combination+Power         ********************************/
		/****************************************************************************************************/
		//nCr
		if(mx>= 415 + (0*spaceH) + (0*buttonwd) && mx<= 415 + (0*spaceH) + (0*buttonwd)+buttonwd && my>= 165 + (2*spaceV) + (2*buttonhg) && my<= 165 + (2*spaceV) + (2*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='C';
			i++;
			printf("\nnCr");
		
		}
		//nPr
		if(mx>= 415 + (1*spaceH) + (1*buttonwd) && mx<= 415 + (1*spaceH) + (1*buttonwd)+buttonwd && my>= 165 + (2*spaceV) + (2*buttonhg) && my<= 165 + (2*spaceV) + (2*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='P';
			i++;
			printf("\nnPr");
		}
		//!
		if(mx>= 415 + (2*spaceH) + (2*buttonwd) && mx<= 415 + (2*spaceH) + (2*buttonwd)+buttonwd && my>= 165 + (2*spaceV) + (2*buttonhg) && my<= 165 + (2*spaceV) + (2*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='!';
			i++;
			printf("\nFactorial");
		}
		//inv
		if(mx>= 415 + (3*spaceH) + (3*buttonwd) && mx<= 415 + (3*spaceH) + (3*buttonwd)+buttonwd && my>= 165 + (2*spaceV) + (2*buttonhg) && my<= 165 + (2*spaceV) + (2*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='i';
			input[i+1]='n';
			input[i+2]='v';
			i=i+3;
			printf("\ninv");
		}
		//X^y
		if(mx>= 415 + (4*spaceH) + (4*buttonwd) && mx<= 415 + (4*spaceH) + (4*buttonwd)+buttonwd && my>= 165 + (2*spaceV) + (2*buttonhg) && my<= 165 + (2*spaceV) + (2*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='^';
			i++;
			printf("\nkln");
		}
		/********************************************************************************/
		/*******************              CONSTANTS             *************************/
		/********************************************************************************/
		//Pi
		if(mx>= 415 + (0*spaceH) + (0*buttonwd) && mx<= 415 + (0*spaceH) + (0*buttonwd)+buttonwd && my>= 165 + (0*spaceV) + (0*buttonhg) && my<= 165 + (0*spaceV) + (0*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='3';
			input[i+1]='.';
			input[i+2]='1';
			input[i+3]='4';
			i=i+4;
			printf("\nPi");
		
		}
		//g
		if(mx>= 415 + (1*spaceH) + (1*buttonwd) && mx<= 415 + (1*spaceH) + (1*buttonwd)+buttonwd && my>= 165 + (0*spaceV) + (0*buttonhg) && my<= 165 + (0*spaceV) + (0*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='9';
			input[i+1]='.';
			input[i+2]='8';
			i=i+3;
			printf("\ng");
		}
		if(mx>= 415 + (2*spaceH) + (2*buttonwd) && mx<= 415 + (2*spaceH) + (2*buttonwd)+buttonwd && my>= 165 + (0*spaceV) + (0*buttonhg) && my<= 165 + (0*spaceV) + (0*buttonhg)+ buttonhg && scientific==1)
		{
			input[i]='*';
			input[i+1]='1';
			input[i+2]='0';
			input[i+3]='^';
			i=i+4;
			printf("\nEXP");
		}




		//CLEAR
		if((mx >= 165 + (0*spaceH) + (0*buttonwd)) && (mx <= 165 + (0*spaceH) + (0*buttonwd) + buttonwd) && (my >= 165 + (4*spaceV) + (4*buttonhg)) && (my <= 165 + (4*spaceV) + (4*buttonhg) + buttonhg))
		{
			clear = 1;
			i = 0;
			error=0;
			for(k=0;k<MAX;k++)
			{
				input[k] = '\0';
				eq[k]='\0';
			}
			for(k=0;k<8;k++)
				ans[k]='\0';
			for(k=0;k<50;k++)
			{
				f[k]=0.0;
			}
			for(k=0;k<20;k++)
				ch[k]='\0';
			x=0;
			y=0;
			equal=0;
			clear=0;
			printf("\nclear");
		}
		
		
		//View
		if(mx>=150 && mx<=192 && my>=400 && my<=425)
		{
			view=1;
			help=0;
			color=0;
		}
		if(mx>=150 && mx<=250 && my>=375 && my<=400 && view==1)
		{
			scientific=0;
			standard=1;
			view=0;
			printf("ADOR\t");
		}
		if(mx>=150 && mx<=250 && my>=350 && my<=375 && view==1)
		{
			standard=0;
			scientific=1;
			view=0;
			printf("OVI\t");
		}
		//Help
		if(mx>=192 && mx<=234 && my>=400 && my<=425 )
		{
			help=1;
			view=0;
			color=0;
			
		}
		if(mx>=192 && mx<=267 && my<=400 && my>=375 && help==1)
		{
			help=0;
			view=0;
			hhelp=1;
		}
		if(mx>=192 && mx<=267 && my<=375 && my>=350 && help==1)
		{
			help=0;
			view=0;
			hhelp=0;
			about=1;
		}
		if(mx>42+42 && mx<=300 && my>=0 && my<=350)
		{
			help=0;
			view=0;
			hhelp=0;
			about=0;
		}
		
		
		
		//point
		if(mx>=(165 + (1*spaceH) + (1*buttonwd)) && mx<=(165 + (1*spaceH) + (1*buttonwd)+buttonwd) && my >=(165 + (0*spaceV) + (0*buttonhg)) && my <=(165 + (0*spaceV) + (0*buttonhg)+buttonhg))
		{
			point = 1;
			input[i] = '.';
			input[i + 1] = '\0';
			i++;
			printf("\npoint");
		}
		//color
		if(mx>=234 && mx<=276 && my>=400 && my<=425)
		{
			help=0;
			view=0;
			hhelp=0;
			about=0;
			color=1;
		}
		if(mx>=234 && mx<=234+75 && my>=375 && my<=400 && color==1)
		{
			colorB=1;
			colorG=0;
			colorO=0;
			color=0;
		}
		if(mx>=234 && mx<=234+75 && my>=350 && my<=375 && color==1)
		{
			colorB=0;
			colorG=1;
			colorO=0;
			color=0;
		}
		if(mx>=234 && mx<=234+75 && my>=325 && my<=350 && color==1)
		{
			colorB=0;
			colorG=0;
			colorO=1;
			color=0;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if((mx >= 165 + (3*spaceH) + (3*buttonwd)) && (mx <= 165 + (3*spaceH) + (3*buttonwd) + buttonwd) && (my >= 165 + (0*spaceV) + (0*buttonhg)) && (my <= 165 + (0*spaceV) + (0*buttonhg) + buttonhg))
		{
			col=0;
		}
	}
}

void iKeyboard(unsigned char key)
{
	if(key == '0')
	{
		zero = 1;
		input[i] = '0';
		input[i + 1] = '\0';
		i++;
		printf("\nzero");
	}
	if(key == '1')
	{
		one = 1;
		input[i] = '1';
		input[i + 1] = '\0';
		i++;
		printf("\none");
	}
	if(key == '2')
	{
		two = 1;
		input[i] = '2';
		input[i + 1] = '\0';
		i++;
		printf("\ntwo");
	}
	if(key == '3')
	{
		three = 1;
		input[i] = '3';
		input[i + 1] = '\0';
		i++;
		printf("\nthree");
	}
	if(key == '4')
	{
		four = 1;
		input[i] = '4';
		input[i + 1] = '\0';
		i++;
		printf("\nfour");
	}
	if(key == '5')
	{
		five = 1;
		input[i] = '5';
		input[i + 1] = '\0';
		i++;
		printf("\nfive");
	}
	if(key == '6')
	{
		six = 1;
		input[i] = '6';
		input[i + 1] = '\0';
		i++;
		printf("\nsix");

	}
	if(key == '7')
	{
		seven = 1;
		input[i] = '7';
		input[i + 1] = '\0';
		i++;
		printf("\nseven");
	}
	if(key == '8')
	{
		eight = 1;
		input[i] = '8';
		input[i + 1] = '\0';
		i++;
		printf("\neight");
	}
	if(key == '9')
	{
		nine = 1;
		input[i] = '9';
		input[i + 1] = '\0';
		i++;
		printf("\nnine");
	}
	if(key == '+')
	{
		plus = 1;
		input[i] = '+';
		input[i + 1] = '\0';
		i++;
		printf("\nplus");
	}
	if(key == '-')
	{
		if(i==0)
		{
			input[i]='0';
			input[i+1]='-';
			i=i+2;
		}
		else
		{
			minus = 1;
			input[i] = '-';
			input[i + 1] = '\0';
			i++;
		}
		printf("\nminus");
	}
	if(key == '*')
	{
		mult = 1;
		input[i] = '*';
		input[i + 1] = '\0';
		i++;
		printf("\nmult");
	}
	if(key == '/')
	{
		divi = 1;
		input[i] = '/';
		input[i + 1] = '\0';
		i++;
		printf("\ndiv");
	}
	if(key == '=' || key == '\r')
	{
		equal = 1;
		doCalculation(input);
		printf("\nequal");
	}
	if(key == ' ')
	{
		clear = 1;
		i = 0;
		error=0;
		for(k=0;k<MAX;k++)
		{
			input[k] = '\0';
			eq[k]='\0';
		}
		for(k=0;k<8;k++)
			ans[k]='\0';
		for(k=0;k<50;k++)
		{
			f[k]=0.0;
		}
		for(k=0;k<20;k++)
			ch[k]='\0';
		x=0;
		y=0;
		equal=0;
		clear=0;
		printf("\nclear");
	}
	if(key=='\r')
	{
		help=0;
		about=0;
		hhelp=0;
	}
	if(key == '.')
	{
		point = 1;
		input[i] = '.';
		input[i + 1] = '\0';
		i++;
		printf("\npoint");
	}
	if(key == '\b')
	{
		input[i-1]='\0';
		i--;
		printf("\nDel");
	}
	if(key=='s' && scientific==1)
	{	input[i]='s';
		input[i+1]='i';
		input[i+2]='n';
		i=i+3;
		printf("\nSin");
	
	}
	if(key=='c' && scientific==1)
	{
		input[i]='c';
		input[i+1]='o';
		input[i+2]='s';
		i=i+3;
		printf("\nCos");
	}
	if(key=='t' && scientific==1)
	{
		input[i]='t';
		input[i+1]='a';
		input[i+2]='n';
		i=i+3;
		printf("\nTan");
	}
	if(key=='S' && scientific==1)
	{
		input[i]='a';
		input[i+1]='S';
		input[i+2]='i';
		input[i+3]='n';
		i=i+4;
		printf("\naSin");
	}
	if(key=='C' && scientific==1)
	{
		input[i]='a';
		input[i+1]='C';
		input[i+2]='o';
		input[i+3]='s';
		i=i+4;
		printf("\naCos");
	}
	if(key=='T' && scientific==1)
	{
		input[i]='a';
		input[i+1]='T';
		input[i+2]='a';
		input[i+3]='n';
		i=i+4;
		printf("\naTan");
	}
	if(key=='L' && scientific==1)
	{
		input[i]='L';
		input[i+1]='o';
		input[i+2]='g';
		i=i+3;
		printf("\nLog");
	}
	if(key=='l' && scientific==1)
	{
		input[i]='l';
		input[i+1]='n';
		i=i+2;
		printf("\nln");
	}
	if(key=='K' && scientific==1)
	{
		input[i]='K';
		input[i+1]='L';
		input[i+2]='o';
		input[i+3]='g';
		i=i+4;
		printf("\nKLog");
	}
	if(key=='k' && scientific==1)
	{
		input[i]='k';
		input[i+1]='l';
		input[i+2]='n';
		i=i+3;
		printf("\nkln");
	}
	if(key=='i' && scientific==1)
	{
		input[i]='i';
		input[i+1]='n';
		input[i+2]='v';
		i=i+3;
		printf("\ninvers");
	}
	if(key=='r' && scientific==1)
	{
		input[i]='r';
		input[i+1]='o';
		input[i+2]='o';
		input[i+3]='t';
		i=i+4;
		printf("\nRoot");	
	}
	if(key=='f' && scientific==1)
	{
		input[i]='!';
		i++;
		printf("\nFactorial");
	}
	if(key=='^' && scientific==1)
	{
		input[i]='^';
		i++;
		printf("\nkln");
	}
	if(key=='o' && scientific==1)
	{
		input[i]='C';
		i++;
		printf("\nnCr");
	}
	if(key=='p' && scientific==1)
	{
		input[i]='P';
		i++;
		printf("\nnPr");
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

int main()
{ 
	PlaySound("sounds/welcome",NULL,SND_ASYNC);
	iInitialize(800,600, "CALCULATOR");
	return 0;
}	