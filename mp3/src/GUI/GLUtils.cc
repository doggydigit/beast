#include "GLUtils.h"

void dessinerRepere()
{
	glBegin(GL_LINES);
	glLineWidth(10);
	glEnable(GL_LINE_SMOOTH);
	
	glColor3ub(0,255,0);
	glVertex3d(0,0,0);
	glVertex3d(0,100,0);
	
	glColor3ub(255,0,0);
	glVertex3d(0,0,0);
	glVertex3d(100,0,0);
	
	glColor3ub(0,0,255);
	glVertex3d(0,0,0);
	glVertex3d(0,0,100);
	
	glEnd();
}
