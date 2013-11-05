#include "ObjLoader.h"

#include "../GUI/Conversions.h"
#include "../GUI/wxIncludes"

#include <iostream>
#include <fstream>

#include <boost/tokenizer.hpp>

#include <wx/stdpaths.h>
#include <wx/filename.h>

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

#define DEBUG

ObjLoader::ObjLoader()
: stored(false), loaded(false)
{
}
ObjLoader::~ObjLoader()
{
	glDeleteLists(object, 1);
}
bool ObjLoader::load(std::string filename, double alpha)
{
	//Has to be done there, not in the constructor
	wxFileName dirname(wxStandardPaths::Get().GetExecutablePath());
	dirname.RemoveLastDir();
	std::string pathPrefix=wxString2string(dirname.GetPath())+'/';
	
	this->alpha=alpha;
	
	std::string line;
	std::ifstream file;

	
	file.open((pathPrefix+filename).c_str());
	
	if(!file.is_open())
	{
		std::cerr<<"Fichier "+pathPrefix+filename+" introuvable."<<std::endl;
		return false;
	}

	while (file.good())
	{
		getline(file,line);
		//Vertice
		if (line.substr(0,2)=="v ")
		{
			VecnD<double> vertice(0);
			tokenizer tokens(line.substr(2), boost::char_separator<char>(" "));
			for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
			vertice.addComponent(string2double(*tok_iter));
			if(vertice.dim()!=3) return false;
			vertices.push_back(vertice);
		}
		else if (line.substr(0,3)=="vn ")
		{
			VecnD<double> normal(0);
			tokenizer tokens(line.substr(2), boost::char_separator<char>(" "));
			for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
			normal.addComponent(string2double(*tok_iter));
			if(normal.dim()!=3) return false;
			normals.push_back(normal);
		}
		//Face
		else if (line.substr(0,2)=="f ")
		{		
			std::pair<std::vector<int>, std::vector<int> > face;
			std::string s=line.substr(2);
			tokenizer groupstokens(s, boost::char_separator<char>(" "));
			for (tokenizer::iterator tok_iter = groupstokens.begin(); tok_iter != groupstokens.end(); ++tok_iter)
			{
				tokenizer verticestokens(*tok_iter, boost::char_separator<char>("/"));
				tokenizer::iterator tok_iter2=verticestokens.begin();
				
				face.first.push_back(string2int(*tok_iter2));
				if (distance(verticestokens.begin (), verticestokens.end())==3)
				{
					tok_iter2++; tok_iter2++;
					face.second.push_back(string2int(*tok_iter2));
				}
				else
				{
					tok_iter2++;
					face.second.push_back(string2int(*tok_iter2));
				}
			}
			faces.push_back(face);

		}
		//Material
		else if (line.substr(0,7)=="mtllib ")
		{
			std::ifstream materialFile;
			std::string filename=pathPrefix+"res/"+line.substr(7);
			materialFile.open(filename.c_str());
			if (!materialFile.is_open())
			{
				std::cerr<<"Fichier "+filename+" introuvable."<<std::endl;
				return false;
			}
			std::string matline;
			while (materialFile.good())
			{
				getline(materialFile,matline);
				if (matline.substr(0,7)=="newmtl ")
				{
					std::string matname=matline.substr(7);
					//Not general, Ka has to be in second position
					getline(materialFile,matline);
					getline(materialFile,matline);
					std::vector<double> color;
					std::string s=matline.substr(3);
					tokenizer tokens(s, boost::char_separator<char>(" "));
					for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
					{
						color.push_back(string2double(*tok_iter));
					}
					materials.insert(std::pair<std::string,std::vector<double> >(matname,color) );

				}
			}
		}
		else if (line.substr(0,7)=="usemtl ")
		{
			facesMaterials.insert(std::pair<int, std::string>(faces.size(), line.substr(7)));
		}
		
	}
	file.close();
	
	#ifdef DEBUG
	std::cout<<filename<<std::endl;
	std::cout<<"Loaded :"<<std::endl;
	std::cout<<vertices.size()<<" vertices"<<std::endl;
	std::cout<<normals.size()<<" normals"<<std::endl;
	std::cout<<faces.size()<<" faces"<<std::endl;
	std::cout<<materials.size()<<" materials"<<std::endl;
	#endif
	
	loaded=true;

	return true;
}
void ObjLoader::draw()
{
	if (!stored)
	{
		//OpenGL has to be initialized to allocate the memory
		object=glGenLists(1);
		generateList();
		stored=true;
	}
	glCallList(object);
}
void ObjLoader::generateList()
{
	std::cout<<"Storing..."<<std::endl;
	//We use Display Lists to improve performance A LOT
	glNewList(object, GL_COMPILE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe
	glColor3ub(255,255,255);
	int facesnb=faces.size();
	for (int i=0; i<facesnb; ++i)
	{
		int pointsnb=faces[i].first.size();
		//Draw the face
		if (facesMaterials.count(i)>0)
		{
			std::vector<double> color=materials[facesMaterials[i]];
			glColor4d(color[0],color[1],color[2], alpha/255.0);
		}
		
		glBegin(GL_POLYGON);
		for (int j=0; j<pointsnb; ++j)
		{
			int verticeid=faces[i].first[j]-1;
			int normalid=faces[i].second[j]-1;
			
			if (normals.size()>0) glNormal3d(normals[normalid][0],normals[normalid][1], normals[normalid][2]);
			
			glVertex3d(vertices[verticeid][0],vertices[verticeid][1],vertices[verticeid][2]);
		}
		glEnd();
	}
	glEndList();
}

bool ObjLoader::hasLoaded()
{
	return loaded;
}
