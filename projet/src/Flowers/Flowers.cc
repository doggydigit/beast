#include "Flowers.h"

//constructor/destructor
Flowers::Flowers(Position P, int N(1000)): pos(P), quant_nect(N)
    {
	//initialisation de ObjLoader
	if (!ol.hasLoaded()) ol.load("res/flower.obj");
	cout<<"hello sweetie"<<endl;
    }
Flowers::~Flowers()
    {
	cout<<"RIP beautiful one"<<endl;
    }

//getters
Position Flowers::getPos()
    {
	return pos;
    }

int Flowers::getQuantNec()
    {
	return quant_nect;
    }

//function : gather pollen
int Flowers::GatherNec(int m)
    {
	if(quant_nect>=m)
	    {
		quant_nect -= m;
		return m;
	    }
	else
	    {
		int n = quant_nect;
		quant_nect = 0;
		cout<<"no more pollen !"<<endl;	//histoire de tester
		return n;
	    }
    }

//Dessine
void Flowers::dessine(wxPaintEvent& event)
    {
	glPushMatrix();
	//dessin de la fleur
	//glTranslated(pos...........)
	o1.draw();
	//eventually glScaled and glTranslated
    }
