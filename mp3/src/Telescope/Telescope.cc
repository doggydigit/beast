#include "Telescope.h"
#include "../GUI/Application.h"

Telescope::Telescope()
{}

void Telescope::dessine(wxPaintEvent& event)
{
	glPushMatrix();
	GLUquadric* quadrique=gluNewQuadric();

	glTranslated(0, 0.0, 100.0);
	
	glTranslated(0,0,9);
	glColor4d(255.0, 255.0, 255.0, 0.0);
	gluQuadricTexture(quadrique,GL_TRUE);
	gluSphere(quadrique, 10, 20, 20);

	glTranslated(0,0,15);
	gluSphere(quadrique, 7, 20, 20);
	
	glTranslated(0,0,10);
	gluSphere(quadrique, 5, 20, 20);
	
	glTranslated(0,0,4);
	glColor4d(0,0,0,0);
	gluDisk(quadrique, 0.0, 6, 30, 1);
	gluCylinder(quadrique, 3, 3, 4, 20, 20);
	
	glTranslated(0,0,4);
	gluDisk(quadrique, 0.0, 3, 30, 1);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("res/metal.jpg"));
	glColor4d(255.0, 255.0, 255.0, 0.0);
	
	glTranslated(5*cos(a),5*sin(a),-5.5);
	glRotated(90+b,0,1,0);
	//glRotated(a*360/6,0,0,1);
	gluCylinder(quadrique, 1.75, 1.75, 1, 20, 20);
	gluDisk(quadrique, 0.0, 1.75, 30, 1);
	//glPopMatrix();

	glTranslated(0, 0.0, 1.0);
	gluCylinder(quadrique, 1, 1, 4, 20, 20);
	gluDisk(quadrique, 0.9, 1.75, 30, 1);
	//glPopMatrix();
	
	glTranslated(0, 0.0, 4.0);
	gluCylinder(quadrique, 1.75, 1.75, 3.0, 20, 20);
	gluDisk(quadrique, 0.9, 1.75, 30, 1);
	
	glTranslated(0, 0.0, 3.0);
	gluCylinder(quadrique, 2.75, 2.75, 5, 20, 20);
	gluDisk(quadrique, 1.74, 2.75, 30, 1);
	//glPopMatrix();
	
	glTranslated(0, 0.0, 5.0);
	gluCylinder(quadrique, 4.25, 4.25, 7.5, 20, 20);
	gluDisk(quadrique, 2.74, 4.25, 30, 1);
	//glPopMatrix();
	
	glTranslated(0, 0.0, 7.50);
	gluCylinder(quadrique, 5.75, 5.75, 11, 20, 20);
	gluDisk(quadrique, 4.24, 5.75, 30, 1);
	//glPopMatrix();
	
	glTranslated(0, 0.0, 11.0);
	gluCylinder(quadrique, 7, 7, 11, 20, 20);
	gluDisk(quadrique, 5.74, 7, 30, 1);
	//glPopMatrix();
	
	glTranslated(0, 0.0, 11.0);
	gluCylinder(quadrique, 9, 9, 14, 20, 20);
	gluDisk(quadrique, 6.9, 9, 30, 1);
	//glPopMatrix();
	
	glTranslated(0, 0.0, 14.0);
	gluDisk(quadrique, 7, 9, 30, 1);
	//glPopMatrix();
	
	glEnable(GL_CLIP_PLANE0);
	double d[4]={0,0,1,-7.5};
	glTranslated(0, 0.0, -8.0);
	glColor4d(0.0, 0.0, 0.0, 0.0);
	gluSphere(quadrique, 10.5, 20, 20);
	glClipPlane(GL_CLIP_PLANE0, d);
	//glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	
	//glRotated(90-b,0,-1,0);
	//glRotated(a*360/6,0,0,1);
	glPopMatrix();
	gluDeleteQuadric(quadrique);
	glDisable(GL_TEXTURE_2D);
	
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

void Telescope::rotateA(double x)
{
	a += x;
}

void Telescope::rotateB(double x)
{
	if(b<=40 && b>=-220)
	{
		b += x;
		cout << b<<endl;
	}else if(b>40)
	{
		b = 39;
	}else if(b<-220)
	{
		b = -219;
	}
}








