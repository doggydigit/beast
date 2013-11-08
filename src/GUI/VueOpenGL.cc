/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "VueOpenGL.h"
#include "Application.h"
//#include "../tests/TestCollider.h"

int VueOpenGL::attributelist[3] = {WX_GL_DEPTH_SIZE,16,0};

VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
:wxGLCanvas(parent, wxID_ANY, position, taille,  wxSUNKEN_BORDER, wxT(""), VueOpenGL::attributelist)
//,r(6), phi(75), theta(31)
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::draw));
	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(VueOpenGL::appuiTouche));

	Connect(wxEVT_MOTION, wxMouseEventHandler(VueOpenGL::mouvementSouris));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(VueOpenGL::clicSouris));
	Connect(wxEVT_LEFT_UP, wxMouseEventHandler(VueOpenGL::clicSouris));
	Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(VueOpenGL::clicSouris));
	Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(VueOpenGL::clicSouris));
	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(VueOpenGL::appuiTouche));
	Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(VueOpenGL::moletteSouris));

	//Un curseur adapté
	SetCursor(wxCURSOR_SIZENESW);

}

void VueOpenGL::InitOpenGL()
{
	SetCurrent();

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(65.0, 4./3., 1.0, 300.0);
	
	glClearColor(97/255.0, 101/255.0, 91/255.0, 1.0);
	//glClearColor(0, 0, 0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	//camera.setRotate(true);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat light_position[] = { 0, 0, 10.0, 0.0 };
	
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 0.1 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 0.1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1);
	
	GLfloat white[4] = { 1.0, 1.0, 1.0, 1.0 };
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	
	glEnable(GL_COLOR_MATERIAL);


}
void VueOpenGL::draw(wxPaintEvent& event)
{
	if (!GetContext()) return;
	SetCurrent();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLoadIdentity();

	camera.setVue();

	/*gluLookAt(r, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	glRotated(theta, 0.0,1.0,0.0);
	glRotated(-phi, 0.0,0.0,1.0);*/

	dessinerRepere();

	wxGetApp().draw();

	glFlush();
	SwapBuffers();
}
void VueOpenGL::dessinerRepere(unsigned int alpha)
{
	//On met les paramètres actuels sur la pile
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glEnable(GL_LINE_SMOOTH); //Lignes anti-aliasées
	glLineWidth(2); //Epaisseur

	glBegin(GL_LINES);
	//Axe x
	glColor4ub(255,0,0,alpha); //Rouge
	glVertex3d(0,0,0);
	glVertex3d(1,0,0);
	//Axe y
	glColor4ub(0,255,0,alpha); //Vert
	glVertex3d(0,0,0);
	glVertex3d(0,1,0);
	//Axe z
	glColor4ub(0,0,255,alpha); //Bleu
	glVertex3d(0,0,0);
	glVertex3d(0,0,1);
	glEnd();

	//Et on restore les paramètres précédents
	glPopAttrib();
}

void VueOpenGL::appuiTouche(wxKeyEvent& event)
{
	switch(event.GetKeyCode())
	{
		case WXK_SPACE:
		camera.resetVue();
		break;
		//...
	}
	Refresh(false);
}
void VueOpenGL::mouvementSouris(wxMouseEvent& event)
{
	if (event.RightIsDown())
	{
		int x(0), y(0);
		event.GetPosition(&x,&y);

		camera.setTheta(camera.getTheta()-(lySouris-y));
		camera.setPhi(camera.getPhi()+(lxSouris-x));

		event.GetPosition(&lxSouris,&lySouris);
		Refresh(false);
	}
}
void VueOpenGL::clicSouris(wxMouseEvent& event)
{
	event.GetPosition(&lxSouris,&lySouris);
}
void VueOpenGL::moletteSouris(wxMouseEvent& event)
{
	camera.setR(camera.getR()-event.GetWheelRotation()/60.0);
	Refresh(false);
}


/*
void VueOpenGL::appuiTouche(wxKeyEvent& event)
{
	switch(event.GetKeyCode())
	{
		case WXK_LEFT:
		phi--;
		break;
		case WXK_RIGHT:
		phi++;
		break;
		case WXK_UP:
		theta++;
		break;
		case WXK_DOWN:
		theta--;
		break;
		case 'W': //Attention
		r--;
		break;
		case 'S':
		r++;
		break;
	}
	Refresh(false);
}*/
