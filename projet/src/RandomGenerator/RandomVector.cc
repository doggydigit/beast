/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */


#include "RandomVector.h"


RandomVector::RandomVector()
:rtheta(-PI,PI), rphi(0,2*PI)
{
	
}

VecnD<double> RandomVector::getValue() const
{
	double theta(rtheta.getValue());
	double phi(rphi.getValue());
	return VecnD<double>(sin(phi)*cos(theta), cos(phi)*cos(theta), sin(theta));
}
