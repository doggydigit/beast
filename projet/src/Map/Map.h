#ifndef MAP_H
#define MAP_H

#include "../GUI/Dessinable.h"
#include "noiseutils.h"

// A COMPLETER
class Map : public Dessinable
{
public:
	
	Map(int a = 50, int b = 512, int c = 1);
	virtual ~Map();
	
	void draw();
	void setDisplayList();
	
	void setNoiseMap();
	void setHeightMap();
	
	void setTaillePlan(int a);
	void setTaillPerlin(int a);
	void setResolution(int a);
	void setCases();
	
	void reset(int a =50, int b = 512, int c = 1);

	
private:
		
	Gluint displayList;
	
	int taillePlan;
	int taillePerlin;
	int resolution;
	int cases;
	
	vector<vector<*float>> heightMap;
	
	// déclaration de la noiseMap que l'on veut construire
    // appelée ici myNoiseMap:
    utils::NoiseMap noiseMap;
};
#endif
