/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

//Runge-Kutta fourth-order method for second order equations

#ifndef RG4_H
#define RG4_H

#include "DiffEqSolver.h"
#include "DiffEqHolder.h"

class RG4: public DiffEqSolver
{
	public:
		RG4(double h);

		virtual std::vector<VecnD<double> > step(VecnD<double> x, VecnD<double> xp,double t, DiffEqHolder* deh);
	private:
		VecnD<double> k1;
		VecnD<double> k1p;
		VecnD<double> k2;
		VecnD<double> k2p;
		VecnD<double> k3;
		VecnD<double> k3p;
		VecnD<double> k4;
		VecnD<double> k4p;
};

#endif
