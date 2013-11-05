#include "Flowers.h"

/*
Position Flowers::getPos()
    {
	return pos;
    }
*/

int Flowers::getQuantNec()
    {
	return quant_nect;
    }

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
