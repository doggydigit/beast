#ifndef CIEL_H
#define CIEL_H

#include "../GUI/wxIncludes"
#include <string>
using namespace std;

class Ciel
{
	public:
		Ciel();
		void dessine(wxPaintEvent& event);
		void rotation();
		void setTexture(string texture);

	private:
		double angle;
		double vitesse;
		string texture;
};
#endif
