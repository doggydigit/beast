/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef FENETREGL_H
#define FENETREGL_H

#include "wxIncludes"
#include "VueOpenGL.h"
#include <wx/statusbr.h>

class FenetreGL: public wxFrame
{
	public:
		FenetreGL(wxString const& titre, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
		
		virtual ~FenetreGL();
		
		void rafraichir();
		
		void setStatusText(std::string s);
		
		void on3dTerrain(wxCommandEvent& event);
		void onPoints(wxCommandEvent& event);
		void onStartPause(wxCommandEvent& event);
		void onReload(wxCommandEvent& event);
	private:
		VueOpenGL* vueOpenGL;
		std::string statusText;
		
		wxMenu* simulationMenu;
		wxMenu* displayMenu;
		wxMenuBar* menuBar;
		
};
#endif
