#ifndef FLOWERS_H
#define FLOWERS_H

#include "../VecnD/VecnD.h"
#include "../Positionnable/Positionnable.h"
#include "../GUI/Dessinable.h"

using namespace std;

class Flowers : public Dessinable, Positionnable 	//vérifier
{
    public :
	//getters
	//Position getPos();
	int getQuantNec();
	int GatherNec(int m);

    private :
	//position
	//Position pos;
	
	//quantité nectar
	int quant_nect(1000);

};
#endif
