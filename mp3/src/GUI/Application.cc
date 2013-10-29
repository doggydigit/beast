#include "Application.h"

Application::Application()
{
	timer=new wxTimer(this);
	timer->Start(50);
	Connect(wxEVT_TIMER, wxTimerEventHandler(Application::rotateSky));
}

//Application::~Application(){}

bool Application::OnInit()
{
    //On alloue la fenêtre
    fenetreGL=new FenetreGL(wxT("Fenetre OpenGL"),wxSize(640, 480));
     
    //Définie comme fenêtre principale
    SetTopWindow(fenetreGL);
     
    //La fonction doit retourner true si elle s'est bien initialisée
    //Si le pointeur est nul, la fenêtre n'a pas pu s'initialiser!
    return (fenetreGL!=0);
}

void Application::dessine(wxPaintEvent& event)
{
	telescope.dessine(event);
	ciel.dessine(event);
}

GLuint* Application::getTexture(string fichier, bool mipmap)
{
    return texturemanager.getTexture(fichier, mipmap);
}

void Application::rotateSky(wxTimerEvent& event)
{
	ciel.rotation();
	fresh();
}

void Application::fresh(){
	fenetreGL->rafraichir();
}

//Remplacement du main
IMPLEMENT_APP(Application);
