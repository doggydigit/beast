#ifndef TELESCOPE_H
#define TELESCOPE_H

#include "../GUI/wxIncludes"

class Telescope
{
	public:
		Telescope();
		void dessine(wxPaintEvent& event);
		void rotateA(double x);
		void rotateB(double x);
	
		double a;
		double b;

		
};
#endif
