#include "Telescope.h"

Telescope::Telescope()
{}

void Telescope::dessine(wxPaintEvent& event)
{
	GLUquadric* quadrique=gluNewQuadric();
	gluCylinder(quadrique, 2, 2, 3, 20, 20);
	gluDeleteQuadric(quadrique);
}
