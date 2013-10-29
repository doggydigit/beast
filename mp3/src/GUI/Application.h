#ifndef APPLICATION_H
#define APPLICATION_H

#include "wxIncludes"
#include "FenetreGL.h"
#include "../Telescope/Telescope.h"
#include "../Ciel/Ciel.h"
#include "TextureManager.h"

using namespace std;

class Application: public wxApp
{
	public:
	
		Application();
		//~Application();	
		void dessine(wxPaintEvent& event);
		GLuint* getTexture(string fichier, bool mipmap=true);
		
	private:
		void rotateSky(wxTimerEvent& event);
		void fresh();
		void mouseDown(wxMouseEvent& event);
		void mouseUp(wxMouseEvent& event);
		void mouseMove(wxMouseEvent& event);
	
		bool OnInit();
		FenetreGL* fenetreGL;
		Telescope telescope;
		Ciel ciel;
		TextureManager texturemanager;
		wxTimer* timer;
		double mx;
		double my;
		
};
DECLARE_APP(Application);
#endif	
