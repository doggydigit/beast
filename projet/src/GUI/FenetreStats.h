/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */


#ifndef FENETRESTATS_H
#define FENETRESTATS_H

#include <vector>

#include "wxIncludes"

class GrapheGL;

class FenetreStats: public wxFrame
{
	
	public:
	
		FenetreStats();
		virtual ~FenetreStats() {}

	private:
	
		wxPanel* panel;
		wxComboBox* listeStats;

		GrapheGL* graphe;
	
		void selectionStat(wxCommandEvent& event);
		
		void populateDefaultList();
		void feedGraph(wxTimerEvent& event);
		
		wxTimer* updateTimer;
		
		unsigned int groups;

};

#endif
