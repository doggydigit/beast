#include "VueOpenGL.h"
#include "GLUtils.h"
#include "Application.h"
 
int VueOpenGL::attributelist[3] = {WX_GL_DEPTH_SIZE,16,0};
 
VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
:wxGLCanvas(parent, wxID_ANY, position, taille, wxSUNKEN_BORDER, wxT(""), VueOpenGL::attributelist)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine)); // a definir???
}

void VueOpenGL::InitOpenGL()
{
	//indique que les instructions OpenGL s'adressent au contexte
	// OpenGL courant
	SetCurrent();
	 
	// Active la gestion de la profondeur
	glEnable(GL_DEPTH_TEST);
	 
	// Fixe la perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, 4./3., 1.0, 1000.0);
	 
	// fixe le fond d'écran à noir
	glClearColor(0.0, 0.0, 0.0, 1.0);
	 
	// prépare à travailler sur le modèle  
	// (données de l'application)
	glMatrixMode(GL_MODELVIEW);
}

void VueOpenGL::dessine(wxPaintEvent& event)
{
    // indique que le code est relatif au contexte OPenGL courant
    SetCurrent();
     //initialise les données liées à la gestion de la profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
    // initialise GL_MODELVIEW
    // place le repère en (0,0,0)
    glLoadIdentity();
 
    // place la caméra (fixe le point de vue)
	camera.setVue();
	
	//repere
	dessinerRepere();
                  
    //dessine un sol
    dessineSol(100);
     
    //Commandes de dessin ici
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(VueOpenGL::appuiTouche));
    
    /*
     * SPhere
    glColor4d(0.0, 0.0, 1.0, 1.0);
    GLUquadric* quadrique=gluNewQuadric();
    gluQuadricDrawStyle(quadrique, GLU_LINE);
    gluSphere(quadrique, 1, 20, 20);
	gluDeleteQuadric(quadrique);
	*/
	
	
/*
	glBegin(GL_QUADS);
 
	glEnable(GL_LINE_SMOOTH);
	glColor3ub(255,0,0);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(1,1,-1);
	 
	glColor3ub(0,255,0);
	glVertex3d(1,-1,1);
	glVertex3d(1,1,1);
	glVertex3d(1,1,-1);
	glVertex3d(1,-1,-1);
	 
	glColor3ub(0,255,255);
	glVertex3d(1,-1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(-1,-1,-1);
	glVertex3d(1,-1,-1);
	 
	glColor3ub(255,255,0);
	glVertex3d(-1,-1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	 
	glColor3ub(0,0,255);
	glVertex3d(1,-1,1);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,-1,1);
	 
	glColor3ub(255,0,255);
	glVertex3d(1,-1,-1);
	glVertex3d(1,1,-1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	 
	glEnd();
	*/
	
	GLUquadric* quadrique=gluNewQuadric();
	
	glPushMatrix();
	glColor4d(0.0, 0.0, 1.0, 1.0);
	gluQuadricDrawStyle(quadrique, GLU_LINE);
    gluSphere(quadrique, 10, 20, 20);
    glPopMatrix();
    
	glRotated(-(90-1),0,0,1);
	glTranslated(0,30,0);
	glColor4d(0.0, 1.0, 1.0, 0.0);
	gluQuadricDrawStyle(quadrique, GLU_LINE);
	glPopMatrix();
	
	//Dessin de la planète verte ici
	glRotated(-(90-1),0,0,1);
	glTranslated(0,15,0);
	glColor4d(0.0, 1.0, 0.0, 1.0);
	gluQuadricDrawStyle(quadrique, GLU_LINE);
	gluSphere(quadrique, 10, 20, 20);
	//Dessin de la planète orange ici
	glPopMatrix();
	
	
	
	wxGetApp().dessine(event);
	
	
	// Finalement, envoi du dessin à l écran
    glFlush();
    SwapBuffers();
}

void VueOpenGL::dessineSol(double taille)
{
	glBegin(GL_QUADS);
 
	glColor3ub(255,0,0);
	glVertex3d(0,0,0);
	glVertex3d(100,0,0);
	glVertex3d(100,100,0);
	glVertex3d(0,100,0);
 
glEnd();
}

void VueOpenGL::appuiTouche(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
         // décrémente l'angle phi de la caméra lorsque l'on appuie sur la flèche gauche
        case WXK_LEFT:
            camera.setHori(camera.getHori() - 0.1);
            break;
        // incrémente l'angle phi de la caméra lorsque l'on appuie sur la flèche droite      
        case WXK_RIGHT:
             camera.setHori(camera.getHori() + 0.1);
             break;
        // décrémente l'angle theta de la caméra lorsque l'on appuie sur la flèche haut       
        case WXK_UP:
            camera.setVerti(camera.getVerti() - 0.1);
            break;
        // incrémente l'angle theta de éa caméra lorsque l'on appuie sur la flèche bas     
        case WXK_DOWN:
            camera.setVerti(camera.getVerti() + 0.1);
            break;
        // diminue le rayon de la  caméra si on appuie sur 'W'
        case 'W': //Attention
            camera.setR(camera.getR() - 1);
            break;
        // augmente le rayon de la caméra si on appuie sur 'S'
        case 'S':
            camera.setR(camera.getR() + 1);
            break;
    }
    Refresh(false);
}
