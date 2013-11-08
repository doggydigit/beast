/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "Positionnable.h"

Positionnable::Positionnable(VecnD<double> position)
: position(position)
{
	assert(position.dim()==3);
	
	lastBounce=new wxTimer(this, 0);
}
Positionnable::~Positionnable()
{
	lastBounce->Stop();
}
Positionnable::Positionnable(const Positionnable& p)
: position(p.position), speed(p.speed)
{
	lastBounce=new wxTimer(this, 0);
}
VecnD<double> Positionnable::getPosition()
{
	return position;
}
void Positionnable::setPosition(VecnD<double> pos)
{
	position=pos;
}

void Positionnable::setOpenGLPosition()
{
	glTranslated(position[0],position[1],position[2]);
}

void Positionnable::bounce()
{
	if(lastBounce->IsRunning()) return;
	speed=-speed;
	lastBounce->Start(10,true); //Juste pour éviter des situations de bounce infini
}

VecnD<double> Positionnable::getSpeed()
{
	return speed;
}
void Positionnable::setSpeed(VecnD<double> sp)
{
	speed=sp;
}
