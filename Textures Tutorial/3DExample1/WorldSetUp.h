#pragma once
#include <gl/freeglut.h>
class WorldSetUp
{
private:
	GLUquadricObj* sphere = NULL;
protected:

public:
	void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLint image, GLfloat xPos, GLfloat yPos, GLfloat zPos);

};