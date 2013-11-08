/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef QUADRICHOLDER_H
#define QUADRICHOLDER_H

#include "wxIncludes"

class QuadricHolder
{
	public:
		QuadricHolder();
		GLUquadric* getQuadric();
		virtual ~QuadricHolder();
		
	protected:
		GLUquadric* quadric;
};

#endif
