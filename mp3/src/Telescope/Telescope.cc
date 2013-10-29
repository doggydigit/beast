#include "Telescope.h"

Telescope::Telescope()
{}

void Telescope::dessine(wxPaintEvent& event)
{
	GLUquadric* quadrique=gluNewQuadric();

	glPushMatrix();
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 1.75, 1.75, 1, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 0.0, 1.75, 30, 1);

	glPopMatrix();
	
	glTranslated(0, 0.0, 1.0);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 1, 1, 4, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 0.9, 1.75, 30, 1);
	glPopMatrix();
	
	glTranslated(0, 0.0, 4.0);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 1.75, 1.75, 3.0, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 0.9, 1.75, 30, 1);
	glPopMatrix();
	
	glTranslated(0, 0.0, 3.0);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 2.75, 2.75, 5, 20, 20);
		glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 1.74, 2.75, 30, 1);
	glPopMatrix();
	
	glTranslated(0, 0.0, 5.0);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 4.25, 4.25, 7.5, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 2.74, 4.25, 30, 1);
	glPopMatrix();
	
	glTranslated(0, 0.0, 7.50);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 5.75, 5.75, 11, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 4.24, 5.75, 30, 1);
	glPopMatrix();
	
	glTranslated(0, 0.0, 11.0);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 7, 7, 11, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 5.74, 7, 30, 1);
	glPopMatrix();
	
	glTranslated(0, 0.0, 11.0);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	gluCylinder(quadrique, 9, 9, 14, 20, 20);
	glColor4d(0.0, 1.0, 0.0, 0.0);
	gluDisk(quadrique, 6.9, 9, 30, 1);
	glPopMatrix();
	

	gluDeleteQuadric(quadrique);
	
	/*
	
	double dimensions[8][2];
	
	dimensions[0][0]=1.0;
	dimensions[0][1]=3.5;
	 
	dimensions[1][0]=4.0;
	dimensions[1][1]=2.0;
	 
	dimensions[2][0]=3.0;
	dimensions[2][1]=3.5;
	 
	dimensions[3][0]=5.0;
	dimensions[3][1]=5.5;
	 
	dimensions[4][0]=7.5;
	dimensions[4][1]=8.5;
	 
	dimensions[5][0]=11.0;
	dimensions[5][1]=11.5;
	 
	dimensions[6][0]=11;
	dimensions[6][1]=14;
	 
	dimensions[7][0]=14;
	dimensions[7][1]=18;
	
	GLUquadric* quadrique=gluNewQuadric();
	GLUquadric* quadrique2=gluNewQuadric();
	
	glPushMatrix();
	double r;
	for (unsigned int i(0); i<8; ++i)
	{
		dimensions[i][1]/=2.0;
		glColor4d(0.0, 1.0, 1.0, 1.0);
		gluCylinder(quadrique, dimensions[i][1], dimensions[i][1], dimensions[i][0], 20, 20);
		glColor4d(0.0, 1.0, 0.0, 0.0);
		if(i=0)
		{
			r = 0;
		}else{
			r = dimensions[i-1][1];
		}
		gluDisk(quadrique2, dimensions[i][1] - r, dimensions[i][1], 30, 1);
		glPopMatrix();
	}*/
}
