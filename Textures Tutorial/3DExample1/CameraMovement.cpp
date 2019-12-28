#include "CameraMovement.h"
#include "Texture.h"
//#include "KeyInput.h"
Texture cmt;
//KeyInput cmk;

void CameraMovement::cameraUpDown()
{
	//code here

}
// Called to draw scene
void CameraMovement::processCamera() {

	cameraUpDown();
	//need all the calls here to hand the camera (up down left right and rotate (roll))
}

void CameraMovement::hudOverlay()
{
	glPushMatrix();


	glPopMatrix();
}

void CameraMovement::moveForward(bool keyPressedUp) 
{
	if (keyPressedUp == true)
	{
		zMovement = 1;
	}
	else
	{
		zMovement = 0;
	}
}

void CameraMovement::moveBackward(bool keyPressedUp)
{
	if (keyPressedUp == true)
	{
		zMovement = -1;
	}
	else
	{
		zMovement = 0;
	}
}