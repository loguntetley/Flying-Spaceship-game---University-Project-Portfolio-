#pragma once
#include <gl/freeglut.h>
//#include <vector>

class WorldSetUp
{
private:
	GLUquadricObj* sphere = NULL;
	GLUquadricObj* torus = NULL;

protected:
	GLuint mysphereID;
public:
	//vector<GLfloat> positions;
	//vector<GLfloat> positionGenerator();
	void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLint image, GLfloat xPos, GLfloat yPos, GLfloat zPos, GLint texDirection, GLfloat rotationSpeed);
	void drawTorus(GLint image, GLfloat rotationSpeed);
	void drawIcosahedron(GLfloat rotationSpeed);
	void drawSpinningCrystal(GLint image, GLfloat rotationSpeed);
};