#ifndef FLOWERS_H
#define FLOWERS_H

#include "../VecnD/VecnD.h"
#include "../Positionnable/Positionnable.h"
#include "../GUI/Dessinable.h"
#include "../ObjLoader/ObjLoader.h"

using namespace std;

class Flowers : public Dessinable, Positionnable 	//vérifier
{
    public :
	//constructor, destructor
	Flowers(const Positionnable *p, int n=1000);
	~Flowers();

	//getters
	Positionnable getPos();
	int getQuantNec();

	//function : gather pollen
	int GatherNec(int);

	//Dessine
	void dessine(wxPaintEvent& event);

    private :
	//position
	Positionnable pos;
	
	//quantité nectar
	int quant_nect;

	//ObjectLoader
	ObjLoader o1;


};
#endif
