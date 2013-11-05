/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "FenetreGL.h"

#include "Application.h"

#include "Conversions.h"



FenetreGL::FenetreGL(wxString const& titre, wxSize const& taille, wxPoint const& position)
:wxFrame(0, wxID_ANY, titre, position, taille, wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX)),
vueOpenGL(new VueOpenGL(this))
{

	Center();
	Show(true);
	vueOpenGL->InitOpenGL(); //Attention à l'ordre !
	
	//Menus
	displayMenu=new wxMenu();
	wxWindowID terrain3DId=NewControlId();
    displayMenu->Append(terrain3DId, _("Activer/désactive terrain 3D\tt"));
    wxWindowID pointsId=NewControlId();
    displayMenu->Append(pointsId, _("Activer/désactive affichage points\tp"));
	
    simulationMenu=new wxMenu();
	wxWindowID startPauseId=NewControlId();
    simulationMenu->Append(startPauseId, _("&Start/Pause"));
    wxWindowID reloadId=NewControlId();
    simulationMenu->Append(reloadId, _("&Recharger\tr"));

    menuBar=new wxMenuBar();
    menuBar->Append(simulationMenu, _("&Simulation"));
    //menuBar->Append(XMLMenu, _("&XML"));
    menuBar->Append(displayMenu, _("&Affichage"));

    SetMenuBar(menuBar);
    
    Connect(terrain3DId,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FenetreGL::on3dTerrain));
    Connect(pointsId,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FenetreGL::onPoints));
	Connect(startPauseId,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FenetreGL::onStartPause));
	Connect(reloadId,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FenetreGL::onReload));

	CreateStatusBar(1);	
}
FenetreGL::~FenetreGL()
{
	//On doit demander la fermeture des autres fenêtres sinon seg fault.
	wxGetApp().closeAll();
	Close(true);
}
void FenetreGL::rafraichir()
{
	vueOpenGL->Refresh(false);
	
	SetStatusText(string2wxString(statusText), 0);
}
void FenetreGL::on3dTerrain(wxCommandEvent& event)
{
	//A REMPLIR
}
void FenetreGL::onPoints(wxCommandEvent& event)
{
	// A REMPLIR
}
void FenetreGL::setStatusText(std::string s)
{
	statusText=s;
	SetStatusText(string2wxString(statusText), 0);
}
void FenetreGL::onReload(wxCommandEvent& event)
{
	wxGetApp().reload();
}

void FenetreGL::onStartPause(wxCommandEvent& event)
{
	// A PROGRAMMER en cas de besoin
	//wxGetApp().pause();
}
