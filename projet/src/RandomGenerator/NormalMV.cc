/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */


#include "NormalMV.h"

NormalMV::NormalMV(VecnD<double> mu, Matrix33 sigma)
: mu(mu), sigma(sigma), ns(0,1)
{
	//todo: check if the matrix is symmetric positively definite before applying Cholesky factorisation. See also inside Matrix33 class.
	//In fact, if we do things empirically, we can directly pass A and remove the factorisation step.
	A=sigma.cholesky();
}

VecnD<double> NormalMV::getValue() const
{
	VecnD<double> z(mu.dim());
	for (int i=0; i<mu.dim(); ++i) z[i]=ns.getValue();
	return (mu+A*z);
}

void NormalMV::setParameters(VecnD<double> mu, Matrix33 sigma)
{
	this->mu=mu;
	this->sigma=sigma;
}
