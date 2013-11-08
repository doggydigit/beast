/*
 * INFOSV3
 * Prototype projet 2011-2012
 */

#include "Uniform.h"

#include <random>

namespace {
    // Use anonymous namespace to have ONE
    // engine for all objects.
    std::random_device rd;
    std::mt19937 engine(rd());
}

Uniform::Uniform(double a, double b)
: dist(a, b)
{
	assert(a<b);
}

double Uniform::getValue() const
{
    return dist(engine);
}
