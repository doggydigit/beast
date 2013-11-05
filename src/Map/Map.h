#ifndef MAP_H
#define MAP_H

#include "../GUI/Dessinable.h"
#include "noiseutils.h"
#include <libnoise/noise.h>
#include "../GUI/wxIncludes"
#include <vector>
//#include <iostream>
//#include <cstdlib>
using namespace std;

// A COMPLETER
class Map : public Dessinable
{
public:
	enum mode{landscape = 1, pixel = 2, texture = 3, color = 4};
	
	Map(int a = 50, int b = 512, int c = 1, mode t = texture, mode d = landscape);
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
	
	GLuint* choseTexture(unsigned int i, unsigned int j);
		
	Gluint displayList;
	
	int taillePlan;
	int taillePerlin;
	int resolution;
	int cases;
	
	vector<vector<*float>> heightMap;
	
	// déclaration de la noiseMap que l'on veut construire
    // appelée ici myNoiseMap:
    utils::NoiseMap noiseMap;
    
	mode TexMode;
	mode DrawMode;
};
#endif
