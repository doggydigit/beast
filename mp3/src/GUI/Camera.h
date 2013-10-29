#ifndef CAMERA_H
#define CAMERA_H

#include "wxIncludes"

class Camera
{
	public:
		Camera(double R = 100 , double H = 0.7, double V = 1);
		
		void setVue();
		
		double getR();
		void setR(double R);
		double getHori();
		void setHori(double H);
		double getVerti();
		void setVerti(double V);
	private:
		double r;
		double hori;
		double verti;
		
};
#endif
