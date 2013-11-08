/*
 * INFOSV3
 * Prototype projet 2011-2012
 */

#include "UniformBool.h"
#include <cstdlib>

UniformBool::UniformBool(double p)
: p(p), u(0,1.0/p)
{
	assert(p>=0 && p<=1);
}

bool UniformBool::getValue() const
{
	return (u.getValue()<1);
}
