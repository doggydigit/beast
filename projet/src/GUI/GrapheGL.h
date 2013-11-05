#ifndef GRAPHEGL_H
#define GRAPHEGL_H

#include <list>
#include <vector>

#include "wxIncludes"

#include "Color.h"

class Systeme;

//Permet d'afficher des mêmes paramètres numériques variant en fonction du temps pour un ensemble d'objets.
//400 données sont gardées en mémoire pour chaque paramètre de chaque objet.
//On choisit le paramètre affiché. Les valeurs pour les différents objets sont dessinées avec différentes couleurs.
//Chaque paramètre possède sa propre échelle d'affichage et on peut dessiner des lignes horizontales pour chacun d'eux.

class GrapheGL : public wxGLCanvas
{
	public:
 	
		//Nombre de paramètres fields et nombre d'objets objects
		GrapheGL(wxWindow* parent, unsigned int fields, unsigned int objects);

		virtual ~GrapheGL();
		
		//Ajoute une donnée data pour le paramètre field et l'objet object
		void feed(double data, unsigned int field, unsigned int object);
		
		//Supprime toutes les lignes horizontales et les données
		void clear();
		
		//Règle l'échèle du paramètre id
		void setScale(double min, double max, int id);
		
		//Ajout une ligne horizontale de couleur c à la hauteur height
		void addLine(double height, Color c);
		
		//Choisit le paramètre affiché
		void setField(unsigned int id);
		
 
	protected:
	
		void dessine(wxIdleEvent& event);
		
	private:
	
		void drawData();
		
		//Convertir une donnée data en pixels selon l'échelle du paramètre id
		double scale(double data, unsigned int id);
		
		//Ensemble des données des paramètres pour les objets
		std::vector<std::vector<std::list<double> > > dataHist;
		
		std::vector<std::pair <double, Color> > lines; //Lignes horizontales pour chacune des données
		
		std::vector<std::pair <double, double> > scales; //Echelles pour chacune des données
		
		unsigned int field; //Paramètre actuel
		
		std::vector<Color> colors; //Couleur pour le dessin de chacun des objets

};

#endif
