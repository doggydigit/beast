/*
 * INFOSV3
 * Prototype projet 2011-2012
 */

#ifndef UNIFORMBOOL_H
#define UNIFORMBOOL_H

#include "RandomGenerator.h"
#include "Uniform.h"
#include <cassert>

class UniformBool: public RandomGenerator
{
	private:
		double p;
		Uniform u;
		
	public:
		UniformBool(double p);
	
		bool getValue() const;
};

#endif
