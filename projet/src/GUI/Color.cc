/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "Color.h"

Color::Color(double r, double g, double b)
: r(r), g(g), b(b)
{
	assert(r>=0 && g>=0 &&  b>=0 && r<=255 && g<=255 && b<=255);
}

void Color::setGLColor() const
{
	glColor3ub(r,g,b);
}

double Color::getRed() { return r; }
double Color::getGreen() { return g; }
double Color::getBlue() { return b; }
void Color::setColor(double r, double g, double b) { this->r=r; this->g=g; this->b=b; }

std::ostream& operator<<(std::ostream& stream, const Color& c)
{
		stream<<"Color "<<c.r<<","<<c.g<<","<<c.b<<std::endl;;
		return stream;
}
