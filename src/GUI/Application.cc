/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "Application.h"
#include "Conversions.h"

using namespace std;

bool Application::OnInit()
{

	fenetreGL=new FenetreGL(wxT("Bees"),wxSize(800, 600));
	//A DECOMMENTER LE MOMENT VENU
	//fenetreStats=new FenetreStats();
 	

	//fenetreStats->Show();
	
	SetTopWindow(fenetreGL);

	ph.load("parameters.xml");
	
	return (fenetreGL!=0);
}
Map* Application::getMap()
{
	return &map;
}
void Application::closeAll()
{
	//A DECOMMENTER LE MOMENT VENU
	//fenetreStats->Close();
}

GLuint* Application::getTexture(std::string fichier, bool mipmap)
{
	return texturemanager.getTexture(fichier, mipmap);
}

void Application::draw()
{
	// foonctionnalité de dessin de la Map à coder
	map.draw();

}


void Application::rafraichir()
{
	fenetreGL->rafraichir();
}
double Application::getParameter(string section, string name)
{
	return ph.get(section, name);
}
void Application::reload()
{
	ph.load("parameters.xml");
	// fonctionnalité permettant de supprimer toutes les ruches
	//map.reload();
}

IMPLEMENT_APP_NO_MAIN(Application)
//IMPLEMENT_APP(Application);
