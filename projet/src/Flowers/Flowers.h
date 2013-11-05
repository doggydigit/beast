#ifndef FLOWERS_H
#define FLOWERS_H

#include "../VecnD/VecnD.h"
#include "../Positionnable/Positionnable.h"
#include "../GUI/Dessinable.h"

using namespace std;

class Flowers : public Dessinable, Positionnable 	//vérifier
{
    public :
	//constructor, destructor
	Flowers(Position P, int N);
	~Flowers();

	//getters
	Position getPos();
	int getQuantNec();

	//function : gather pollen
	int GatherNec(int m);

    private :
	//position
	Position pos;
	
	//quantité nectar
	int quant_nect;

};
#endif
