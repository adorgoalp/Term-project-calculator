# include "iGraphics.h"

/*
	function iDraw() is called again and again by the system.
*/


void mydelay(int milliseconds)
{
	for(int i=0;i<milliseconds*1000;i++);
}

int posx=100,posy=100;
int radius=25;
int win_h=600,win_w=800;
int boxw=100,boxh=30;
int boxx=400,boxy=5;
int rotation=1;
int dx=1,dy=1;
int movebox;
int x_before;
int box_vx;

int ballhitbox=0;
int turn=0;
void boxhitball();
void iDraw()
{
	mydelay(100);
	iClear();
	
	//check if hit upper wall
	boxhitball();
	if(turn==0 || ballhitbox==0)
	{
		if(posy+radius>=win_h)
		{
			//change direction of motion
			dy = -dy;
		} //now check for hitting lower wall
		else if(posy-radius<=0)
		{
			dy = -dy;
		}
		else if(posx+radius>=win_w)
		{
			dx = -dx;
		}
		else if(posx-radius<=0)
		{
			dx = -dx;
		}
		
		posx=posx+dx;
		posy=posy+dy;
	}


	
	
	iFilledCircle(posx,posy,radius);
	iFilledRectangle(boxx,boxy,boxw,boxh);




	//place your drawing codes here
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/


void boxhitball()
{
	if(  (posy-radius)<=boxy+boxh  && (boxx-radius<=posx && posx<=boxx+boxw+radius)  )
	{
		ballhitbox=1;
		printf("ball Hit the box %d\n",ballhitbox);
	}
	else 
	{
		//printf("ball did not hit");
		ballhitbox=0;
	}
}


void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("Inside");
	int step;
	turn++;
	if(movebox==1)
	{
		//printf("Moving box..");
		step=mx-x_before;
		//printf("%d ",step);
		x_before=mx;
		boxx = boxx + step;
		if(ballhitbox==1)
		{
			posx = posx + step;
			dy = -dy;
			ballhitbox=0;
			posy += 10;
		}
	
	}
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
		if( boxx<=mx && mx<=boxx+boxw && boxy<=my && my<=boxy+boxh)
		{
			printf("Hit box\n");
			movebox=1;
			x_before=mx;
		}
		//printf("Entered");

	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//place your codes here
		//check if mouse is on the
		//printf("Exit");
		movebox=0;
	
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
int step=10;
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	else if(key =='a')
	{
		boxx=boxx-step;
	}
	else if(key=='s')
	{
		boxx=boxx+step;
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	printf("sukarna");
	iInitialize(win_w, win_h, "demooo");
	return 0;
}
