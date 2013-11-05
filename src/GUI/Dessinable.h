/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef DESSINABLE_H
#define DESSINABLE_H

#include "wxIncludes"

class Dessinable
{
	public:
		Dessinable()
		: stored(false)
		{
			
		}
		
		virtual ~Dessinable() {};
		
		virtual void draw()=0;
		
		void beginStore()
		{
			if (!init)
			{
				displayList = glGenLists(1);
				init=true;
			}
			glNewList(displayList, GL_COMPILE);
		}
		
		void endStore()
		{
			glEndList();
			stored=true;
		}
		
		void drawStored()
		{
			glCallList(displayList);
		}
		
		bool hasStored() { return stored; }
		
	private:
	
		GLuint displayList;
		bool init;
		bool stored;
};

#endif
