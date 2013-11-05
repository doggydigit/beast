/*
 * EPFL
 * Projets en informatique pour SV
 * Projet 2013-2014
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "../VecnD/VecnD.h"

#include <string>
#include <vector>
#include <map>
#include <utility>

#include "../GUI/Dessinable.h"

class ObjLoader: public Dessinable
{
	private:
		std::vector<VecnD<double> > vertices;
		std::vector<VecnD<double> > normals;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > faces;
					// (vertices ids, normals ids)
		std::map<std::string, std::vector<double> > materials;
		std::map<int, std::string> facesMaterials;
		
		GLuint object;
		
		bool stored;
		bool loaded;
		
		std::string pathPrefix;
		
	public:
		ObjLoader();
		~ObjLoader();
		bool load(std::string filename, double alpha=255);
		void generateList();
		void draw();
		double alpha;
		
		bool hasLoaded();
	
};

#endif
