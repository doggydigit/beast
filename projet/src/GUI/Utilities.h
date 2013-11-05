/*
 * EPFL
 * Projets en informatique pour SV
 * Projet 2013-2014
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#include "../VecnD/VecnD.h"
#include "../Map/noiseutils.h"

namespace Utilities
{
	void drawPlane(VecnDd center, double side);
	void drawCube(VecnDd center, double size, double vscale=0);
	void GLTextureFromElevations(utils::NoiseMap& heights, GLuint& texture, int heightmapSize);
}
