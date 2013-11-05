#include "Map.h"

Map::Map(int a,int b, int c): taillePlan(a), taillePerlin(b), resolution(c)
{
	
}
/*
void Map::renderMap()
{
	utils::RendererImage renderer;
	utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();
}*/

void Map::setNoiseMap()
{
        // déclaration d'une instance du module permettant de 
        // générer la noiseMap en utilisant le bruit de Perlin:
	module::Perlin perlinModule;
        
        //déclaration d'un créateur de map
	utils::NoiseMapBuilderPlane mapBuilder;

        // on indique que le créateur de map va travailler avec le module de Perlin
	mapBuilder.SetSourceModule(perlinModule);

        // on indique que le créateur de map va créer le résultat dans myNoiseMap
	mapBuilder.SetDestNoiseMap(noiseMap);
    
        // on indique la taille de la noiseMap
	mapBuilder.SetDestSize(taille, taille);
 
        // on indique dans quelles limites physiques le créateur de map
        // va travailler pour  créer la noiseMap (vous pourrez garder les
        // mêmes valeurs dans votre implémentation
	mapBuilder.SetBounds(0, 5.0, 0, 5.0);

        // au final, on demande au créateur de map de faire son travail:
	mapBuilder.Build();
}

void Map::setHeightMap()
{
	heightMap.clear;
	heightMap.assign(taillePlan, vector<double>(taillPlan));
	for(int i(0); i < taillePlan; ++i)
	{
		for(int j(0); j < taillePlan; ++j)
		{
			
	
}

void Map::setTaillePlan(int a)
{
	taillePlan = a;
}

void Map::setTaillPerlin(int a)
{
	taillePerlin = a;
}
