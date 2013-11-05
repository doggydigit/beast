/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "Camera.h"
#include <math.h>

#define DEFAULT_R 94
#define DEFAULT_THETA 30
#define DEFAULT_PHI -46

Camera::Camera()
:r(DEFAULT_R), theta(DEFAULT_THETA), phi(DEFAULT_PHI)
{
	timerRotate=new wxTimer(this, 3);
	
	Connect(3, wxEVT_TIMER, wxTimerEventHandler(Camera::rotate));
}
double Camera::getR() const
{
	return r;
}
double Camera::getPhi() const
{
	return phi;
}
double Camera::getTheta() const
{
	return theta;
}
	
void Camera::setR(double r)
{
	this->r=r;
	restreindre();
}
void Camera::setPhi(double phi)
{
	this->phi=phi;
	restreindre();
}
void Camera::setTheta(double theta)
{
	this->theta=theta;
	restreindre();
}

void Camera::setVue() const
{
	gluLookAt(r, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	
	
	glRotated(theta, 0.0,1.0,0.0);
	glRotated(-phi, 0.0,0.0,1.0);
	
	glTranslated(0,0,-4);
	
	//glTranslated(0,-20,0);
	
	//std::cout<<r<<" "<<theta<<" "<<phi<<std::endl;
	
}

void Camera::resetVue()
{
	r=DEFAULT_R;
	theta=DEFAULT_THETA;
	phi=DEFAULT_PHI;
}

void Camera::setRotate(bool state)
{
	if (state) timerRotate->Start(50);
	else timerRotate->Stop();
}

void Camera::rotate(wxTimerEvent& event)
{
	phi+=1;
}

void Camera::restreindre()
{
	/*if (theta<10) theta=10;
	if (theta>170) theta=10;*/
}
