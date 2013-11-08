/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef NORMALMV_H
#define NORMALMV_H

#include "RandomGenerator.h"

#include "../VecnD/VecnD.h"
#include "../Matrix33/Matrix33.h"

#include "Normal.h"

#include <math.h>
#include <cassert>

class NormalMV: public RandomGenerator
{
	private:
	
		VecnD<double> mu;
		Matrix33 sigma;
		Matrix33 A;
	
		Normal ns;
	
	public:
	
		NormalMV(VecnD<double> mu, Matrix33 sigma);
	
		VecnD<double> getValue() const;
	
		void setParameters(VecnD<double> mu, Matrix33 sigma);
};

#endif
