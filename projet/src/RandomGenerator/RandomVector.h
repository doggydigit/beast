/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

// "Random" unit vector

#ifndef RANDOMVECTOR_H
#define RANDOMVECTOR_H

#include "RandomGenerator.h"

#include "Uniform.h"

#include "../VecnD/VecnD.h"

#include <math.h>
#include <cassert>

#define PI 3.14159265

class RandomVector: public RandomGenerator
{
	private:
	
			Uniform rtheta;
			Uniform rphi;
	
	public:
		RandomVector();
		VecnD<double> getValue() const;
};

#endif
