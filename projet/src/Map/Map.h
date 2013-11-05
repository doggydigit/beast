#ifndef MAP_H
#define MAP_H

#include "../GUI/Dessinable.h"
#include "noiseutils.h"

// A COMPLETER
class Map : public Dessinable
{
public:
	
	Map(int a = 50, int b = 512, int c = 1);

	void renderMap();
	
	void setNoiseMap();
	void setHeightMap();
	
	void setTaillePlan(int a);
	void setTaillPerlin(int a);

	
private:
		
	int taillePlan;
	int taillePerlin;
	int resolution;
	
	vector<vector<double>> heightMap;
	
	// déclaration de la noiseMap que l'on veut construire
    // appelée ici myNoiseMap:
    utils::NoiseMap noiseMap;
};
#endif
