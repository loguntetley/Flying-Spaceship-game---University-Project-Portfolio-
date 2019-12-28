#pragma once
#include <gl/freeglut.h>

class CameraMovement
{
private:

protected:

public:
	GLfloat zMovement = 0;
	void hudOverlay();
	void cameraUpDown();
	void processCamera();
	void moveForward(bool kepPressedUp);
	void moveBackward(bool kepPressedUp);
};

