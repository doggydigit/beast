/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef DIFFEQHOLDER_H
#define DIFFEQHOLDER_H

#include "../VecnD/VecnD.h"

class DiffEqHolder
{
	public:
		//Returns a vector with new position,speed
		virtual VecnD<double> f(VecnD<double> const& x, VecnD<double> const& xp, double t)=0;
};

#endif
