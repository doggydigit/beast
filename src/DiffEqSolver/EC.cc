#include "EC.h"

EC::EC(double h)
:DiffEqSolver(h)
{
}

std::vector<VecnD<double> > EC::step(VecnD<double> x, VecnD<double> xp,double t, DiffEqHolder* deh)
{
	//todo: store them as private members
	VecnD<double> xp2=xp+h*deh->f(x,xp,t);
	VecnD<double> x2=x+h*xp2;
	
	std::vector<VecnD<double> > v;
	v.push_back(x2);
	v.push_back(xp2);
	
	return v;
}
