#pragma once
#include <gl/freeglut.h>

class KeyInput
{
private:
	bool leftKeyPressed = false, rightKeyPressed = false, upKeyPressed = false, downKeyPressed = false;
protected:

public:
	//key handling - only one shown simplly as an example
	
	void processsArrowKeys(int key, int x, int y);
	void keyGoneUP(int key, int x, int y);
	void processKeys(unsigned char key, int x, int y);
};

