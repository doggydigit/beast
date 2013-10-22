#ifndef APPLICATION_H
#define APPLICATION_H

#include "wxIncludes"
#include "FenetreGL.h"
#include "../Telescope/Telescope.h"
#include "../Ciel/Ciel.h"

using namespace std;

class Application: public wxApp
{
	public:
	/*
		Application();
		~Application();
	*/	
		void dessine(wxPaintEvent& event);
		
	private:
	
		bool OnInit();
		FenetreGL* fenetreGL;
		Telescope telescope;
		Ciel ciel;
		
};
DECLARE_APP(Application);
#endif	
