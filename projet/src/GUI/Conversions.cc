/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */
 
#include "Conversions.h"

#include <sstream>

wxString int2wxString(int i)
{
	wxString string = wxString()<<i;
	return string;
}
wxString string2wxString(std::string s)
{
	wxString retour(s.c_str(), wxConvUTF8);
	return retour;
}
std::string wxString2string(wxString s)
{
	std::string str = std::string(s.mb_str());
	return str;
}
//TODO: templates+error handling
std::string int2string(int i)
{
  std::ostringstream oss;
  oss<<i;
  return oss.str();
}
std::string double2string(double d)
{
	std::ostringstream oss;
	oss<<d;
	return oss.str();
}
double string2double(std::string s)
{
   std::istringstream i(s);
   double r;
   i >> r;
   return r;
}
int string2int(std::string s)
{
   std::istringstream i(s);
   int r;
   i >> r;
   return r;
}

