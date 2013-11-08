/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include "wxIncludes"

#include "Camera.h"

class VueOpenGL: public wxGLCanvas
{
public:
	VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
	
	void InitOpenGL();
	
private:
	void draw(wxPaintEvent& event);
	void dessinerRepere(unsigned int alpha=255);
	
	void appuiTouche(wxKeyEvent& event);
	void mouvementSouris(wxMouseEvent& event);
	void clicSouris(wxMouseEvent& event);
	void moletteSouris(wxMouseEvent& event);
	
	int lxSouris;
	int lySouris;
	
	/*double r;
	double theta;
	double phi;*/
	Camera camera;
	
	static int attributelist[3];

};
#endif
