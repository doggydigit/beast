/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef NORMAL_H
#define NORMAL_H

#include "RandomGenerator.h"

#include <cassert>
#include <random>

class Normal: public RandomGenerator
{
	private:
        mutable std::normal_distribution<> dist; // either getValue is non const or this var is mutable
	public:
		Normal(double mu, double sigma2);
		
		double getValue() const;
};

#endif
