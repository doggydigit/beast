/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */


#include "Normal.h"

#include <cmath>

namespace {
    // Use anonymous namespace to have ONE
    // engine for all objects.
    std::random_device rd;
    std::mt19937 engine(rd());
}

Normal::Normal(double mu, double sigma2)
: dist(mu, std::sqrt(sigma2))
{
	assert(sigma2>0);
}

double Normal::getValue() const
{
    return dist(engine);
}
