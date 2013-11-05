#include "ParamsHandler.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include "../RapidXML/rapidxml.hpp"
#include "../GUI/Conversions.h"

using namespace rapidxml;
using namespace std;

void ParamsHandler::load(std::string filename)
{
	cout<<"Loading "<<filename<<endl;
	
	xml_document<> doc;
	
	//Ouverture fichier
	ifstream file(filename);
	vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	
	xml_node<>* root_node = doc.first_node("Parameters");
	
	for (xml_node<>* node(root_node->first_node()); node; node=node->next_sibling())
	{
		string section(node->name());
		for (xml_node<>* node2(node->first_node()); node2; node2=node2->next_sibling())
		{
			string name(node2->first_attribute("name")->value());
			params[node->name()][node2->first_attribute("name")->value()]=string2double(node2->value());
		}
	}
	for(auto s : params)
	{
		cout<<s.first<<endl;
		for(auto p : s.second)
		{
			cout<<"	"<<p.first<<" "<<p.second<<endl;
		}
	}
}
double ParamsHandler::get(string section, string name)
{
	return params[section][name];
}
