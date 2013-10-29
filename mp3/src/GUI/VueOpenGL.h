#ifndef VUEOPENGL_H
#define VUEOPENGL_H
 

#include "Camera.h"
 
class VueOpenGL: public wxGLCanvas
{
public:
    VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
     
    void InitOpenGL();
     
private:
    void dessine(wxPaintEvent& event);
    void dessineSol(double taille);
    void appuiTouche(wxKeyEvent& event);
	void mouseDown(wxMouseEvent& event);
    void mouseUp(wxMouseEvent& event);
    void mouseMove(wxMouseEvent& event);
    
    int mx;
    int my;
    wxImage cursor;
    Camera camera;
     
    static int attributelist[3];
 
};
#endif
