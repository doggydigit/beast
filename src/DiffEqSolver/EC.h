/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

//Simple Euler-Cromer integration scheme for second-order equations. Unstable, only for illustration purposes.

#ifndef EC_H
#define EC_H

#include "DiffEqSolver.h"
#include "DiffEqHolder.h"

class EC: public DiffEqSolver
{
	public:
		EC(double h);
	
		virtual std::vector<VecnD<double> > step(VecnD<double> x, VecnD<double> xp, double t, DiffEqHolder* deh);
};

#endif
