#pragma once
#include <gl/freeglut.h>
class Texture
{
private:
#define TEXTURE_HUD 0
#define TEXTURE_JUPITER 1
#define TEXTURE_STARFIELD 2
#define TEXTURE_COUNT 3
protected:
	
public:
	//below is simply a character array to hold the file names
	//note that you may need to replace the below with the full directory root depending on where you put your image files
	//if you put them where the exe is then you just need the name as below - THESE IMAGES  ARE IN THE DEBUG FOLDER, YOU CAN ADD ANY NEW ONES THERE 
	const char* textureFiles[TEXTURE_COUNT] = { "hud.tga", "jupiterC.tga","starField.tga" };
	GLuint textures[TEXTURE_COUNT];
	GLuint texture;
	void drawTexturedQuad(int image);
	//void drawHud();
	//void drawJupiter();
};

