#ifndef FenetreGL_H
#define FenetreGL_H

#include "wxIncludes"
#include "VueOpenGL.h"



using namespace std;

class FenetreGL: public wxFrame
{
	public:
        FenetreGL(wxString titre, wxSize taille);
		//~FenetreGL();
		void rafraichir();
	private:
		VueOpenGL* vueopengl;
};

#endif	
