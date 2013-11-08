///*
 //* EPFL
 //* Projets en informatique pour SV
 //* Prototype projet 2013
 //* Roger Küng, Corentin Perret, Jamila Sam
 //*/

//#include "FenetreStats.h"
//#include "GrapheGL.h"
//#include "../constants.h"
//#include "Application.h"
//#include "Conversions.h"
//#include "../Hive/Hive.h"

//using namespace std;

//FenetreStats::FenetreStats()
//: wxFrame(0, wxID_ANY, wxT("Graphes"), wxDefaultPosition, wxSize(400, 310), wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxRESIZE_BOX | wxCLOSE_BOX)),
  //panel(new wxPanel(this)), groups(3)
 //,listeStats(new wxComboBox(panel, wxID_ANY, wxT(""), wxPoint(10,210), wxSize(300, 28), 0, 0, wxCB_READONLY | wxCB_DROPDOWN))
//{
	////Graphe
	////Exemple avec 2 champs:
	//graphe=new GrapheGL(panel, 2, groups);
	////------------------------------
	
	////Echelles pour les différentes statistiques
	////Exemple:
	//graphe->setScale(0, 20000, 0);
	//graphe->setScale(1, 100, 1);
	////------------------------------
	//Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FenetreStats::selectionStat));
	
	//populateDefaultList();

	////Timer Update
	//wxWindowID updateTimerID=NewControlId();
	//updateTimer=new wxTimer(this, updateTimerID);
	//Connect(updateTimerID, wxEVT_TIMER, wxTimerEventHandler(FenetreStats::feedGraph));
	//updateTimer->Start(100);

//}
//void FenetreStats::populateDefaultList()
//{
	////Liste des statistiques dans le menu
	////Exemple:
	//listeStats->Append(wxT("Stat 1"));
	//listeStats->Append(wxT("Stat 2"));
	//listeStats->SetValue(wxT("Stat 1"));
	////------------------------------
//}

//void FenetreStats::feedGraph(wxTimerEvent& event)
//{
	////Appeler graphe->feed ici avec les données
	////Exemple:
	//double data(0);
	//graphe->feed(data, 0, 0);
	//graphe->feed(data, 1, 0);
	//graphe->feed(data, 1, 1);
	////------------------------------
//}

//void FenetreStats::selectionStat(wxCommandEvent& event)
//{
	//int stat(listeStats->GetCurrentSelection());
	//graphe->setField(stat);
//}
