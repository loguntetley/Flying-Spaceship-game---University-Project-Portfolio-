#include "WorldSetUp.h"
//#include "Texture.h"

//Texture wsut;
void WorldSetUp::drawSphere(GLdouble radius, GLint slices, GLint stacks, GLint image, GLfloat xPos, GLfloat yPos, GLfloat zPos)
{
	sphere = gluNewQuadric();
	glPushMatrix();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	glTranslatef(xPos, yPos, zPos);
	glBindTexture(GL_TEXTURE_2D, image);
	gluSphere(sphere, radius, slices, stacks);
	glPopMatrix();
}