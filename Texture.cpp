#include "Texture.h"

void Texture::drawTexturedQuad(int image)
{
	//add some lighting normals for each vertex
	//draw the texture on the front
	glEnable(GL_TEXTURE_2D);
	// glFrontFace(GL_CW); //use glFrontFace(GL_CW) to texture the other side - not needed here as we set this elsewhere
	glColor3f(0.8, 0.8, 0.8);
	glEnable(GL_TEXTURE_2D);
	//bind the texture 
	glBindTexture(GL_TEXTURE_2D, textures[image]);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-50.0, 0.0, 100.0);
	glTexCoord3f(1.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 100.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(50.0, 100.0, 100.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-50.0, 100.0, 100.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Texture::drawQuad(int image, GLfloat xScale, GLfloat yScale, GLfloat zScale)
{
	glPushMatrix();
	//rotate the quad slightly
	//glRotatef(15.0, 0.0, 1.0, 0.0);
	glScalef(xScale, yScale, zScale);
	drawTexturedQuad(image);
	glPopMatrix();
}
/*
void Texture::drawJupiter()
{
	glPushMatrix();
	//rotate and then translate the quad 
	glTranslatef(0.0, -100.0, 0.0);
	//try setting to -185.0 to see the back of the quad
	glRotatef(-15.0, 0.0, 1.0, 0.0);
	drawTexturedQuad(TEXTURE_JUPITER);
	glPopMatrix();
}*/