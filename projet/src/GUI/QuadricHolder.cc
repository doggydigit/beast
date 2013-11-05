#include "QuadricHolder.h"

//Warning: if this is not coded properly, you'll get random seg faults or invalid pointers on quit.

QuadricHolder::QuadricHolder()
: quadric(0)
{
}
//Don't do that in a constructor, since OpenGL won't necessarily have already been initialized
GLUquadric* QuadricHolder::getQuadric()
{
	if (quadric==0) quadric=gluNewQuadric();
	return quadric;
}
QuadricHolder::~QuadricHolder()
{
	if (quadric!=0) gluDeleteQuadric(quadric);
}
