#include "Ciel.h"
#include "../GUI/Application.h"

Ciel::Ciel():vitesse(0.02)
{
	//setTexture("sol.jpg");
}

void Ciel::dessine(wxPaintEvent& event)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("GUI/texture/sol.jpg"));
	GLUquadric* quadrique=gluNewQuadric();
	gluQuadricDrawStyle(quadrique, GLU_LINE);
	gluSphere(quadrique, 200, 20, 20);
	
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
