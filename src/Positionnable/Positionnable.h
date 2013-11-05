/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef POSITIONNABLE_H
#define POSITIONNABLE_H

#include "../VecnD/VecnD.h"
#include "../GUI/wxIncludes"

class Positionnable: public wxEvtHandler
{
	protected:
	
		VecnD<double> position;
		VecnD<double> speed;
		
	public:
	
		Positionnable(VecnD<double> position);
		
		virtual ~Positionnable();
		
		Positionnable(const Positionnable& p);
		
		VecnD<double> getPosition();
		void setPosition(VecnD<double> pos);
		
		VecnD<double> getSpeed();
		void setSpeed(VecnD<double> sp);
		
		void bounce();
		
		void setOpenGLPosition();
		
	private:
	
		wxTimer* lastBounce;
};

#endif
