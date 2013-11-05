/*
 * EPFL
 * Projets en informatique pour SV
 * Prototype projet 2012-2013
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "wxIncludes"
#include <map>

class TextureManager
{
	public:
		TextureManager();
		~TextureManager();
		void chargerTexture(std::string fichier, bool mipmap=false);
		GLuint* getTexture(std::string fichier, bool mipmap=false);
	private:
		std::map<std::string, GLuint> textures;
};

#endif
