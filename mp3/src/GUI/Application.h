#ifndef APPLICATION_H
#define APPLICATION_H

#include "wxIncludes"
#include "FenetreGL.h"
#include "../Telescope/Telescope.h"

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
		
};
DECLARE_APP(Application);
#endif	
