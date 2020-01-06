#include "Hud.h"
#include "Texture.h"

Texture ht;

void Hud::resetPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void Hud::displayText(GLfloat x, GLfloat y, GLint r, GLint g, GLint b, const char* string, bool stroke) {
	GLint j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (GLint i = 0; i < j; i++)
	{
		if (stroke)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);
		}
		else
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
		}

	}
}

void Hud::drawFrameRate()
{
	//this draws the framerate on the screen - useful for testing animation
	frame++;
	timeTot = glutGet(GLUT_ELAPSED_TIME);
	if (timeTot - timebase > 1000)
	{
		sprintf_s(frameRate, "FPS: %4.2f", frame * 1000.0 / (timeTot - timebase));

		timebase = timeTot;
		frame = 0;
	}

	//set the text to white
	glColor3f(1.0f, 1.0f, 1.0f);

	//this stop the text being affected by the current tranformation by reseting it
	glLoadIdentity();
	displayText(-0.95f, 0.9f, 0.0f, 1.0f, 1.0f, frameRate, false);
}

void Hud::drawText(GLint value, string text, GLfloat red, GLfloat green, GLfloat blue, GLfloat xPos, GLfloat yPos)
{
	glColor3f(red, green, blue);
	glRasterPos2f(xPos, yPos);
	//updates the score value
	string newText = text + to_string(value);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(newText.c_str()));
}


//sets up the orthographics projection for 2D overlay
void Hud::setOrthographicProjection()
{
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save the previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, Wwidth, 0, Wheight);
	// invert the y axis, down is positive
	glScalef(1, -1, 1);
	// mover the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -Wheight, 0);
	//set for drawing again
	glMatrixMode(GL_MODELVIEW);
}

void Hud::load2DOverlay(GLint collectedCytstals, GLint xShipPos, GLint yShipPos, GLint zShipPos, GLint xShipRot, GLint yShipRot, GLint zShipRot)
{
	//draw the 2D overlay
	glPushMatrix();
	glLoadIdentity();
	setOrthographicProjection();
	//ht.drawQuad(ht.textures[0], 0.5f, 0.5f, 0.5f);
	drawFrameRate();
	drawText(collectedCytstals, "Cystals Collected: ", 0.0f, 1.0f, 0.0f, -0.97f, -0.95f);
	drawText(xShipPos, "Ship Position X: ", 1.0f, 0.0f, 0.0f, -0.97f, -0.8f);
	drawText(yShipPos, "Ship Position Y: ", 0.0f, 1.0f, 0.0f, -0.97f, -0.725f);
	drawText(zShipPos, "Ship Position Z: ", 0.0f, 0.0f, 1.0f, -0.97f, -0.65f);
	drawText(xShipRot, "Ship Rotation X: ", 1.0f, 1.0f, 1.0f, -0.97f, -0.5f);
	drawText(yShipRot, "Ship Rotation Y: ", 1.0f, 1.0f, 1.0f, -0.97f, -0.425f);
	drawText(zShipRot, "Ship Rotation Z: ", 1.0f, 1.0f, 1.0f, -0.97f, -0.35f);
	glBindTexture(GL_TEXTURE_2D, 2);
	glBegin(GL_QUADS);
	//glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.9, -0.9, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0);
	glVertex3f(0.9, 0.9, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.9, 0.9, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.9, -0.9, 0.0);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	resetPerspectiveProjection();
	//glutSwapBuffers();
}