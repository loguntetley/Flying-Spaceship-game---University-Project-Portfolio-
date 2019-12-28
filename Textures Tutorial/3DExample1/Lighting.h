#pragma once
#include <gl/freeglut.h>
class Lighting
{
private:
	//for lighting if you want to experiment with these
	GLfloat mKa[4] = { 0.11f,0.06f,0.11f,1.0f }; //ambient
	GLfloat mKd[4] = { 0.43f,0.47f,0.54f,1.0f }; //diffuse
	GLfloat mKs[4] = { 1.0f,1.0f,1.0f,1.0f }; //specular
	GLfloat mKe[4] = { 0.5f,0.5f,0.0f,1.0f }; //emission
protected:

public:
	// Useful lighting colour values
	GLfloat whiteLightBright[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat redLight[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat whiteLightLessBright[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat lightPos[4] = { 100.0f, 100.0f, 50.0f, 1.0f };
};

