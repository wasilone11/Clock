#include "iGraphics.h"
#include<stdio.h>
#include<math.h>

int x = 300, y = 300, r = 20, s1=300, s2=490,m1=300,m2=485,h1=300,h2=480;
double angle1=0,angle2=0,angle3=0;
int hour,minute,second;
char i;

void secondhand()
    {
       angle1 +=.1047197551;
    }
void minutehand()
    {
    angle2 +=.1047197551;
    }

void hourhand()
    {
       angle3 +=.1047197551;
    }




void iDraw() {

	iClear();

    int h1=300+130*(sin(0.5235987756*hour+0.008726646*minute+angle3));
    int h2=300+130*(cos(0.5235987756*hour+0.008726646*minute+angle3));
    int m1=300+165*(sin(0.1047197551*minute+angle2));
    int m2=300+165*(cos(0.1047197551*minute+angle2));
    int s1=300+180*(sin(0.1047197551*second+angle1));
    int s2=300+180*(cos(0.1047197551*second+angle1));


	iSetColor(255,255,255);
	iText(258,600,"Hour Hand");
	iSetColor(253,06,06);
	iText(250,580,"Minute Hand");
	iSetColor(253,195,6);
	iText(250,560,"Second Hand");

    iSetColor(253,6,6);
    iFilledCircle(300,300,8);
    iSetColor(80,253,06);
    iCircle(300,300,220,300);
	iSetColor(253,06,204);
	iCircle(300, 300, 190,300);


	//iFilledRectangle(10, 30, 20, 20);
	iSetColor(06,06,253);
	iText(180, 30, "ANALOG CLOCK by ABDUL WASI LONE");
	iSetColor(0,255,255);
	iRectangle(50,50,500,500);
	iSetColor(253,195,06);
	iLine(300,300,s1,s2);
	iSetColor(253,06,06);
	iLine(300,300,m1,m2);
	iSetColor(255,255,255);
	iLine(300,300,h1,h2);



	iSetColor(400,400,0);
	iText(292,500,"12");
	iText(500,300,"3");
	iText(296,95,"6");
	iText(95,296,"9");
	iText(394,473.2,"1");
	iText(193,473.2,"11");
	iText(471.2,400,"2");
	iText(118.8,400,"10");
	iText(473.2,197,"4");
	iText(400,120.8,"5");
	iText(116.8,198,"8");
	iText(188,120.8,"7");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx , my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	printf("Do you want to see the current time ? (y/n)\n>>>>");
	scanf("%c",&i);
	switch(i)
	{
    case 'y':
    {
    time_t now;
	struct tm *timeinfo;
	time(&now);
	timeinfo=localtime(&now);
	hour=timeinfo->tm_hour;
	hour=hour%12;
	minute=timeinfo->tm_min;
	second=timeinfo->tm_sec;

	iSetTimer(1000,secondhand);
	iSetTimer(60000,minutehand);
	iSetTimer(720000,hourhand);
	iInitialize(599, 699, "CLOCK_WASI");
	break;

	}
	case 'n':
    {

	printf("Enter the hour = ");
	scanf("%d",&hour);
	printf("Enter the minute = ");
	scanf("%d",&minute);
    printf("Enter the second = ");
	scanf("%d",&second);

	iSetTimer(1000,secondhand);
	iSetTimer(60000,minutehand);
	iSetTimer(720000,hourhand);
	iInitialize(599,699, "CLOCK_WASI");
    break;

    }

	return 0;
    }
}

