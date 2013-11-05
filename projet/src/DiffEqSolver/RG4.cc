#include "RG4.h"

RG4::RG4(double h)
:DiffEqSolver(h)
{
}

std::vector<VecnD<double> > RG4::step(VecnD<double> x, VecnD<double> xp,double t, DiffEqHolder* deh)
{
	k1=xp;
	k1p=deh->f(x,xp,t);
	k2=xp+h/2*k1p;
	k2p=deh->f(x+h/2*k1,xp+h/2*k1p,t);
	k3=xp+h/2*k2p;
	k3p=deh->f(x+h/2*k2,xp+h/2*k2p,t);
	k4=xp+h*k3p;
	k4p=deh->f(x+h/2*k3,xp+h/2*k3p,t+h);
	
	std::vector<VecnD<double> > v;
	
	v.push_back(x+h/6*(k1+2*k2+2*k3+k4));
	v.push_back(xp+h/6*(k1p+2*k2p+2*k3p+k4p));
	
	return v;
}
