#pragma once
#include <gl/freeglut.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Hud
{
private:

protected:

public:
	//used for the framerate
	GLint frame = 0, timeTot = 0, timebase = 0, Wwidth, Wheight;
	char frameRate[12];

	void resetPerspectiveProjection();
	void displayText(GLfloat x, GLfloat y, GLint r, GLint g, GLint b, const char* string, bool stroke);
	void drawFrameRate();
	void drawText(GLint value, string text, GLfloat red, GLfloat green, GLfloat blue, GLfloat xPos, GLfloat yPos);
	void setOrthographicProjection();
	void load2DOverlay(GLint collectedCytstals, GLint xShipPos, GLint yShipPos, GLint zShipPos, GLint xShipRot, GLint yShipRot, GLint zShipRot);

};

