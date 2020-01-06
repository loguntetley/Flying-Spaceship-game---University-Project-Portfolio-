#include "CameraMovement.h"

void CameraMovement::cameraUpDown()
{
	//code here

}

void CameraMovement::processCamera() {

	cameraUpDown();
	//need all the calls here to hand the camera (up down left right and rotate (roll))
}

void CameraMovement::hudOverlay()
{
	glPushMatrix();


	glPopMatrix();
}

void CameraMovement::moveForward() { glTranslatef(xPos, yPos, zPos + 1.0f); }

void CameraMovement::moveBackward() { glTranslatef(xPos, yPos, zPos - 1.0f); }

void CameraMovement::moveUpward() { glTranslatef(xPos, yPos - 1.0f, zPos); }

void CameraMovement::moveDownward() { glTranslatef(xPos, yPos + 1.0f, zPos); }

void CameraMovement::moveLeft() { glTranslatef(xPos + 1.0f, yPos, zPos); }

void CameraMovement::moveRight() { glTranslatef(xPos - 1.0f, yPos, zPos);  }

void CameraMovement::rotateClockwise() { glRotatef(angle, xPos + 1.0f, yPos, zPos); }

void CameraMovement::rotateAntiClockwise() { glRotatef(angle, xPos - 1.0f, yPos, zPos); }

void CameraMovement::rotateYLeft() { glRotatef(angle, xPos, yPos, zPos - 1.0f); }

void CameraMovement::rotateYRight() { glRotatef(angle, xPos, yPos, zPos + 1.0f); }

void CameraMovement::rotateOnPointLeft() { glRotatef(angle, xPos, yPos - 1.0f, zPos); }

void CameraMovement::rotateOnPointRight() { glRotatef(angle, xPos, yPos + 1.0f, zPos); }

void CameraMovement::resetRotation() { glTranslatef(xPos - xPos, yPos - yPos, zPos - zPos); }
