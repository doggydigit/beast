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
    
    Camera camera;
     
    static int attributelist[3];
 
};
#endif
