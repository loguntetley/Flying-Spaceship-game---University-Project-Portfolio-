#pragma once
#include <gl/freeglut.h>

class CameraMovement
{
private:
	GLfloat xPos = 0.0f, yPos = 0.0f, zPos = 0.0f, angle = 1.0f;
protected:
	
public:
	GLdouble eyeX = 0.0, eyeY = 0.0, eyeZ = 100.0, centreX = 0.0, centreY = 0.0, centreZ = 0.0, upX = 0.0, upY = 1.0, upZ = 0.0;
	bool leftKeyPressed = false, rightKeyPressed = false, upKeyPressed = false, downKeyPressed = false, wKeyPressed = false,sKeyPressed = false, aKeyPressed = false, dKeyPressed = false, zKeyPressed = false, xKeyPressed = false, cKeyPressed = false, vKeyPressed = false, rKeyPressed = false, hKeyPressed = false;
	void hudOverlay();
	void cameraUpDown();
	void processCamera();
	void moveForward();
	void moveBackward();
	void moveUpward();
	void moveDownward();
	void moveLeft();
	void moveRight();
	void rotateClockwise();
	void rotateAntiClockwise();
	void rotateYLeft();
	void rotateYRight();
	void rotateOnPointLeft();
	void rotateOnPointRight();
	void resetRotation(); // fix this
};

