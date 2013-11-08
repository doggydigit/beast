/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "wxIncludes"

class Camera: public wxEvtHandler
{
	public:
	
		Camera();
		
		void setVue() const;
		
		void resetVue();
		
		double getR() const;
		double getPhi() const;
		double getTheta() const;
		
		void setR(double r);
		void setPhi(double phi);
		void setTheta(double theta);
		
		void setRotate(bool state);
		
		void rotate(wxTimerEvent& event);
	
	private:
	
		double r;
		double phi;
		double theta;
		
		void restreindre();
		
		wxTimer* timerRotate;
	
};

#endif
