/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "wxIncludes"
#include "FenetreGL.h"
#include "FenetreStats.h"
#include "TextureManager.h"
#include "../Map/Map.h"
#include "../ParamsHandler/ParamsHandler.h"
#include <string>

class Application : public wxApp
{
	public:

		virtual ~Application() {};
		
		void closeAll();

		GLuint* getTexture(std::string fichier, bool mipmap=true);

		void draw();
		
		void rafraichir();
		
		void setStatusText(std::string s);
		
		Map* getMap();
		
		bool drawDebug;
		
		double getParameter(std::string section, std::string name);
		
		void reload();
		
	private:
	
		bool OnInit();
		
		TextureManager texturemanager;
		
		FenetreGL* fenetreGL;

	   // A DECOMMENTER LE MOMENT VENU
	    //FenetreStats* fenetreStats;
	
		 Map map;
		
		
		ParamsHandler ph;
};


DECLARE_APP(Application);


#endif
