#include "WorldSetUp.h"

void WorldSetUp::drawSphere(GLdouble radius, GLint slices, GLint stacks, GLint image, GLfloat xPos, GLfloat yPos, GLfloat zPos, GLint texDirection, GLfloat rotationSpeed)//, GLfloat xScale, GLfloat yScale, GLfloat zScale)
{
	sphere = gluNewQuadric();
	glPushMatrix();
	if (texDirection == 0) { gluQuadricOrientation(sphere, GLU_INSIDE); }	
	if (texDirection == 1) { gluQuadricOrientation(sphere, GLU_OUTSIDE); }
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	glTranslatef(xPos, yPos, zPos);
	glRotatef(180.0f, 90.0f, rotationSpeed, 0.0f);
	glBindTexture(GL_TEXTURE_2D, image);
	gluSphere(sphere, radius, slices, stacks);
	glPopMatrix();
}


void WorldSetUp::drawTorus(GLint image, GLfloat rotationSpeed)
{
	torus = gluNewQuadric();
	glPushMatrix();
	gluQuadricTexture(torus, TRUE);
	glBindTexture(GL_TEXTURE_2D, image);
	glRotatef(180.0f, 90.0f, rotationSpeed, rotationSpeed);
	gluPartialDisk(torus, 15.00, 20.00, 10, 1, 0, 360);
	/*glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(180.0f, 90.0f, rotationSpeed, rotationSpeed);
	//glBindTexture(GL_TEXTURE_2D, image);
	glutSolidTorus(2.00, 20.00, 5, 10); 
	glColor3f(1.0f, 1.0f, 1.0f);*/
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
	//glutSwapBuffers();
}

void WorldSetUp::drawIcosahedron(GLfloat rotationSpeed)
{
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, 0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(180.0f, 90.0f, rotationSpeed, 0.0f);
	glScalef(5.0f, 5.0f, 5.0f);
	glutSolidIcosahedron();
	glColor3f(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void WorldSetUp::drawSpinningCrystal(GLint image, GLfloat rotationSpeed)
{
	drawIcosahedron(-rotationSpeed);
	drawTorus(image, rotationSpeed);
}

