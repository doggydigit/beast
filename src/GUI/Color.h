/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef COLOR_H
#define COLOR_H

#include "wxIncludes"

class Color
{
	public:
	
		Color(double r, double g, double b);
		
		void setGLColor() const;
		
		friend std::ostream& operator<<(std::ostream& stream, const Color& c);
		
		double getRed(); double getGreen(); double getBlue(); //Ou alors avec un tableau...
		void setColor(double r, double g, double b);
		
	private:
		double r;
		double g;
		double b;
};

#endif
