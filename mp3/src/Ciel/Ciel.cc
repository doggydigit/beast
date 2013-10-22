#include "Ciel.h"

Ciel::Ciel()
{}

void Ciel::dessine(wxPaintEvent& event)
{
	GLUquadric* quadrique=gluNewQuadric();
	gluQuadricDrawStyle(quadrique, GLU_LINE);
	gluSphere(quadrique, 200, 20, 20);
	
	gluDeleteQuadric(quadrique);
}
