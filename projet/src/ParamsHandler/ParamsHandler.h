/*
 * EPFL
 * Projets en informatique pour SV
 * Projet 2013-2014
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef PARAMSHANDLER_H
#define PARAMSHANDLER_H

#include <string>
#include <map>

class ParamsHandler
{
	public:
		void load(std::string filename);
		double get(std::string section, std::string name);
	private:
		std::map<std::string, std::map<std::string,double> > params;
};

#endif
