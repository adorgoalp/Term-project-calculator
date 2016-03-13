#include "iGraphics.h"

/*
	function iDraw() is called again and again by the system.
*/
/*
void myDrawEllipse(int cx,int cy,int a,int b)
{
	double angle=0;
	double PI=3.14156;

	for(angle=0;angle<2*PI;angle=angle+0.1)
	{
		double x,y;
		x = a*cos(angle);
		y = b*sin(angle);
		iPoint(x+cx,y+cy,1);
	}
}

void DrawCurve()
{
	double PI=3.14156;
	double x,y;
	for(x=0;x<2*PI;x=x+.01)
	{
		 y = sin(x);
		 iSetcolor(26/255.0,201/255.0,17/255.0);
		iPoint(x*100,y*100+400,1);
		
		y = cos(x);
		iSetcolor(43/255.0,46/255.0,173/255.0);
		iPoint(x*100,y*100+400,1);
	}
}*/
int cx=400;
int cy=400;
int r=50;

/*void mydelay(int ms)
{
	for(int i=0;i<ms*10000;i++)
	{
		double x;
		double y;
		x*y/x*x*x;
	}
}

int max=400;
int dy=0;
double v=0;
double g=9.8;
int y=0;
int dh=5;
int dir=1;*/
int x,y;

void iDraw()
{
	iClear();
	iSetcolor(1.0,0.0,0.0);
	iFilledCircle(x,y,50);
	//iFilledCircle(cx,cy,r);
	//cx++;;
	
	/*if( dir==2 && v>=0 )
	{
		dir = 1;
		v = 0;
	}

	dy = v * dh  + 0.5 * g * dh * dh;
	v = v  + g * dh;

	cy = cy - dy;

	if( dir==1 && cy -r <=0 ) 
	{
		v = - v;
		dir = 2;
		g = g + 0.0002;
	}

	mydelay(100);*/
}

void iPassiveMouseMove(int mx,int my)
{
	x=mx;
	y=my;
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/



void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("Inside");
	//x = mx;
	//y = my;
	
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//check if mouse is on the
		//x = mx;
		//y = my;

	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//place your codes here
		//check if mouse is on the
	
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	if(key=='a')
	{
		cx = cx - 5;
	}
	if(key=='d') cx = cx + 5;
	
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	iInitialize(800,600,"iGraphics");
	return 0;
}
