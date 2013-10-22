#include "Camera.h"

Camera::Camera(double R, double H, double V)
:r(R), hori(H), verti(V)
{}


void Camera::setVue()
{
	// place la caméra (fixe le point de vue)
	gluLookAt(r*sin(verti)*cos(hori), r*sin(verti)*sin(hori), r*cos(verti), // position (x, y, z) de la caméra
				0.0, 0.0, 0.0,	// point visé
				 0.0, 0.0, 1.0); /* vecteur representant la direction verticale
                               de la vue (non parallèle à la direction de
                               visée) */
}

double Camera::getR()
{
	return r;
}

void Camera::setR(double R)
{
	r = R;
}

double Camera::getHori()
{
	return hori;
}

void Camera::setHori(double H)
{
	hori = H;
}

double Camera::getVerti()
{
	return verti;
}

void Camera::setVerti(double V)
{
	if(V < 3 && V > 0.2)
	{
		verti = V;
	}else if(V >= 3)
	{
		verti  = 3;
	}else if(V <= 0.2)
	{
		verti = 0.2;
	}	
}
