#include "Map.h"
#include "../GUI/Application.h"
#include "../VecnD/VecnD.h"

Map::Map(int a,int b, int c, mode t, mode d): taillePlan(a), taillePerlin(b), resolution(c), TexMode(t), DrawMode(d)
{
	if (!hasStored()) 
	{
	   setDisplayList();
        } else drawStored();
	setCases();
	setNoiseMap();
	setHeightMap();
	if (!hasStored()) 
	{
	   setDisplayList();
	} //else drawStored();
	//setDisplayList();
}

Map::~Map()
{
	//glDeleteLists(displayList, 1);
}

void Map::draw()
{
	switch(TexMode)
	{
		case texture:

			break;
		
		case color:
			if (!hasStored()) 
			{
				setDisplayList();
			} else drawStored();
			/*
			glColor3ub(255,255,255);
			glEnable(GL_TEXTURE_2D);
			// texture est un GLuint
			glBindTexture(GL_TEXTURE_2D, texture);
			
			// dessin du plan ici
			
			glDisable(GL_TEXTURE_2D);*/
		}
}

void Map::setDisplayList()
{
	switch(DrawMode)
	{
		case landscape:

			beginStore();
			//glNewList(displayList, GL_Compile);
			glColor3ub(255,255,255);
			glEnable(GL_TEXTURE_2D);
			
				//glBegin(GL_QUADS);
				
				int y[cases];
				for(int i(0); i < cases; ++i)
				{
					y[i] = i*resolution;
				}
					for(int i(0); i < cases; ++i)
					{
						int x = i*resolution;
						for(int j(0); j < cases; ++j)
						{
							VecnD<double> c;
							c[1]=x;
							c[2]=y[i];
							c[3]=heightMap[i][j];
							//(x,y[i], heightMap[i][j]);
							switch (TexMode)
							{
								case texture:
									glColor3ub(255,255,255);
									glBindTexture(GL_TEXTURE_2D, choseTexture(heightMap[i][j]));
								break;
									
								case color:
									choseColor(heightMap[i][j]);
								break;
							}
							Utilities::drawCube(c, resolution, 4);
						}
					}
				//glEnd();
			VecnD<double> big(taillePlan/2, taillePlan/2, -taillePlan/2);
			Utilities::drawCube(big, taillePlan * 1.1, 1);
			glDisable(GL_TEXTURE_2D);
			//glEndList();
			endStore();
			break;
			
		/*case pixel:
			//idsasfhergbhe34ht79133eqhg
		break;*/
	}
}
	

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
	mapBuilder.SetDestSize(cases, cases);
 
        // on indique dans quelles limites physiques le créateur de map
        // va travailler pour  créer la noiseMap (vous pourrez garder les
        // mêmes valeurs dans votre implémentation
	mapBuilder.SetBounds(0, 5.0, 0, 5.0);

        // au final, on demande au créateur de map de faire son travail:
	mapBuilder.Build();
}

void Map::setHeightMap()
{
	heightMap.clear();
	vector<float> x(cases);
	heightMap.assign(cases, x);
	for(int i(0); i < cases; ++i)
	{
		for(int j(0); j < cases; ++j)
		{
			heightMap[i][j] = *noiseMap.GetConstSlabPtr(i,j);
		}
	}
}

void Map::setTaillePlan(int a)
{
	taillePlan = a;
}

void Map::setTaillPerlin(int a)
{
	taillePerlin = a;
}

void Map::setResolution(int a)
{
	resolution = a;
}

void Map::setCases()
{
	cases = taillePlan/resolution;
}

void Map::reset(int a, int b, int c)
{
	setTaillePlan(a);
	setTaillPerlin(b);
	setResolution(c);
	setNoiseMap();
	setHeightMap();
	setDisplayList();
}

GLuint Map::choseTexture(float a)
{		
		if(a < 1)
		{
			return *wxGetApp().getTexture("res/water.jpg");
		}else if(a < 1.4)
		{
			return *wxGetApp().getTexture("res/sand.jpg");
		}else if(a < 5)
		{
			return *wxGetApp().getTexture("res/grass.jpg");
		}else if(a < 7)
		{
			return *wxGetApp().getTexture("res/rock.jpg");
		}else if(a < 10)
		{
			return *wxGetApp().getTexture("res/mountain.jpg");
		}else if(a <= 12)
		{
			return *wxGetApp().getTexture("res/snow.jpg");
		}else{
			cerr << "You fucked up with the max of heightmap" << endl;
			GLuint wtf;
			return wtf;
		}	
}

void Map::choseColor(float a)
{
		if(a < 1)
		{
			glColor3ub(0,0,255);
		}else if(a < 1.4)
		{
			glColor3ub(240,240,60);
		}else if(a < 5)
		{
			glColor3ub(32,160,0);
		}else if(a < 7)
		{
			glColor3ub(128,128,128);
		}else if(a < 10)
		{
			glColor3ub(100,200,0);
		}else if(a <= 12)
		{
			glColor3ub(200,200,200);
		}else{
			cerr << "You fucked up with the max of heightmap" << endl;
		}
}
