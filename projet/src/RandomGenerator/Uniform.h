/*
 * INFOSV3
 * Prototype projet 2011-2012
 */

#ifndef UNIFORM_H
#define UNIFORM_H

#include "RandomGenerator.h"

#include <cassert>
#include <random>

class Uniform: public RandomGenerator
{
	private:
        mutable std::uniform_real_distribution<> dist; // either getValue is non const or this var is mutable

	public:
		Uniform(double a, double b);
	
		double getValue() const;
};

#endif
