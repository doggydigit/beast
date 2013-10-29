#include "VueOpenGL.h"
#include "GLUtils.h"
#include "Application.h"
 
int VueOpenGL::attributelist[3] = {WX_GL_DEPTH_SIZE,16,0};
 
VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
:wxGLCanvas(parent, wxID_ANY, position, taille, wxSUNKEN_BORDER, wxT(""), VueOpenGL::attributelist)
{
	/*
	wxImageHandler * jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	wxBitmap bitmap;
	wxString string = "texture/click.jpeg"
	if(!(bitmap.LoadFile(string, wxBITMAP_TYPE_JPEG)))
	{
		cout << "fail" << endl;
	} 
	cursor = bitmap.ConvertToImage();
    wx.SetCursor(wx.CursorFromImage(cursor));*/
    Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine)); // a definir???
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler
(VueOpenGL::appuiTouche));
    Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(VueOpenGL::mouseDown));
    Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(VueOpenGL::mouseUp));
}

void VueOpenGL::InitOpenGL()
{
	/*
	cout << wxMouseEvent::GetPosition(mx,my) << endl;
	cout << wxMouseEvent::GetWheelRotation() << endl;
	*/
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
	
	
	/*
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
	*/
	
	
	wxGetApp().dessine(event);
	
	
	// Finalement, envoi du dessin à l écran
    glFlush();
    SwapBuffers();
}

void VueOpenGL::dessineSol(double taille)
{
	glEnable(GL_TEXTURE_2D);
	GLUquadric* quadrique=gluNewQuadric();
	glColor4d(255.0, 255.0, 255.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("res/sol.jpg"));
	
	gluQuadricDrawStyle(quadrique, GLU_FILL);
	gluQuadricTexture(quadrique,GL_TRUE);
	glTranslated(0, 0.0, -100.0);
	gluSphere(quadrique, 100, 20, 20);
	
	gluDeleteQuadric(quadrique);
	/*
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("res/sol.jpg"));
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glTexCoord2d(0,0);
	glVertex3d(-taille,-taille,0);
	glTexCoord2d(1,0);
	glVertex3d(-taille,taille,0);
	glTexCoord2d(1,1);
	glVertex3d(taille,taille,0);
	glTexCoord2d(0,1);
	glVertex3d(taille,-taille,0);
 
glEnd();*/
glDisable(GL_TEXTURE_2D);
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

void VueOpenGL::mouseDown(wxMouseEvent& event)
{
	mx = event.GetX();
	my = event.GetY();
	Connect(wxEVT_MOTION, wxMouseEventHandler(VueOpenGL::mouseMove));
}

void VueOpenGL::mouseUp(wxMouseEvent& event)
{
	Disconnect(wxEVT_MOTION, wxMouseEventHandler(VueOpenGL::mouseMove));
}

void VueOpenGL::mouseMove(wxMouseEvent& event)
{
	camera.setHori(camera.getHori() + 0.01*(mx - event.GetX()));
	camera.setVerti(camera.getVerti() + 0.01*(my - event.GetY()));
	mx = event.GetX();
	my = event.GetY();
	Refresh(false);
}
