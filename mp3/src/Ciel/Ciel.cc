#include "Ciel.h"
#include "../GUI/Application.h"

Ciel::Ciel():vitesse(2)
{
	//setTexture("sol.jpg");
}

void Ciel::dessine(wxPaintEvent& event)
{
	glRotated(-angle,0,0,1);
	glEnable(GL_TEXTURE_2D);
	GLUquadric* quadrique=gluNewQuadric();
	glColor4d(255.0, 255.0, 255.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("res/sky1.jpg"));
	
	gluQuadricDrawStyle(quadrique, GLU_FILL);
	gluQuadricTexture(quadrique,GL_TRUE);
	gluSphere(quadrique, 800, 20, 20);
	
	gluDeleteQuadric(quadrique);
}

void Ciel::rotation()
{
	angle += vitesse;
}
void Ciel::setTexture(string texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture(texture));
}
