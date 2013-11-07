#include "Utilities.h"

void Utilities::drawPlane(VecnDd center, double side)
{
	glPushMatrix();
	
	glTranslated(center[0],center[1],center[2]);
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex2f(0,0);
		
	glTexCoord2d(1,0);
	glVertex2f(0,side);
		
	glTexCoord2d(1,1);
	glVertex2f(side,side);
		
	glTexCoord2d(0,1);
	glVertex2f(side,0);
	
	glEnd();
	glPopMatrix();
}

void Utilities::drawCube(VecnDd center, double size, double vscale)
{
	//Un peu long, du fait qu'il faille avoir des normales correctes si on veut un bon rendu. Les cubes généré par glut n'ont pas de normales.	
	glPushMatrix();
	
	glTranslated(center[0],center[1],center[2]);
	glScaled(size,size,size);
	
	glTranslated(0,0,size/2);
	glScaled(1,1,vscale);
	glTranslated(0,0,-size/2);
	
	static GLfloat n[6][3] ={
		{-1.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{0.0, -1.0, 0.0},
		{0.0, 0.0, 1.0},
		{0.0, 0.0, -1.0}};
	static GLint faces[6][4] ={
		{0, 1, 2, 3},
		{3, 2, 6, 7},
		{7, 6, 5, 4},
		{4, 5, 1, 0},
		{5, 6, 2, 1},
		{7, 4, 0, 3}};

	GLfloat v[8][3];
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
	
	for (int i(0); i<5; i++)
	{
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glTexCoord2d(0,0);
		glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2d(0,1);
		glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2d(1,1);
		glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2d(1,0);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
	glPopMatrix();
}

void Utilities::GLTextureFromElevations(utils::NoiseMap& heights, GLuint& texture, int heightmapSize)
{
	//Rendu de la heightmap en image
	utils::RendererImage renderer;
	utils::Image image;
	renderer.SetSourceNoiseMap(heights);
	renderer.SetDestImage(image);
	renderer.Render();
	
	//Pour enregistrer l'image en bmp
	//utils::WriterBMP writer;
	//writer.SetSourceImage (image);
	//writer.SetDestFilename ("tutorial.bmp");
	//writer.WriteDestFile ();
	
	//Transformation en image au format GL_RGB8, afin de l'afficher en texture
	int imageDimensions(heightmapSize*heightmapSize*3);
	GLubyte imagedata[imageDimensions];//Image de la heightMap au format GL_RGB8 (généré)
	int i(0);
	for (int x(0); x<heightmapSize; x++)
	{
		for (int y(0); y<heightmapSize; y++)
		{
			const utils::Color* color(image.GetConstSlabPtr(x,y));
			imagedata[i]=color->red;
			imagedata[i+1]=color->green;
			imagedata[i+2]=color->blue;
			i=i+3;
		}
	}
	//Génération de la texture OpenGL
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, heightmapSize, heightmapSize, 0, GL_RGB, GL_UNSIGNED_BYTE, imagedata);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
