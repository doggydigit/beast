/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */
 
#ifndef DIFFEQSOLVER_H
#define DIFFEQSOLVER_H

#include "../VecnD/VecnD.h"
#include "DiffEqHolder.h"
#include <vector>

class DiffEqSolver
{
	protected:
		double h; //timestep
	public:
		DiffEqSolver(double h);
		virtual std::vector<VecnD<double> > step(VecnD<double> x, VecnD<double> xp, double t, DiffEqHolder* deh)=0;
};

#endif
