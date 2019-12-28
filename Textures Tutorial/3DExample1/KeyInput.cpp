#include "KeyInput.h"
#include "CameraMovement.h"

CameraMovement kcm;

void KeyInput::processsArrowKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		//process here
		leftKeyPressed = true;
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		//process here
		rightKeyPressed = true;
	
	}
	if (key == GLUT_KEY_UP)
	{
		//process here
		kcm.moveForward(upKeyPressed = true);
	}
	if (key == GLUT_KEY_DOWN)
	{
		//process here
		kcm.moveBackward(upKeyPressed = true);
	}
}

void KeyInput::keyGoneUP(int key, int x, int y)
{
	//keys has been relasaed - used for resetting a boolean linked to a key being pressed - just one example here
	switch (key) {
	case GLUT_KEY_LEFT:
		leftKeyPressed = false;
		break;
	case GLUT_KEY_RIGHT:
		rightKeyPressed = false;
		break;
	case GLUT_KEY_UP:
		upKeyPressed = false;
		break;
	case GLUT_KEY_DOWN:
		downKeyPressed = false;
		break;
	}

}

void KeyInput::processKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		//set bool
		break;
	case 's':
		//set bool
		break;
	case 'a':
		//set bool
		break;
	case 'd':
		//set bool
		break;
	case ',':
		//set bool
		break;
	case '.':
		//set bool
		break;
	}
}