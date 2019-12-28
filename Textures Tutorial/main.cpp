//Windows includes - DO NOT EDIT AS LOTS OF INTERDEPENDENCE
#include <math.h>						
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>	//Needed for console output (debugging)
#include <gl/freeglut.h>
#include "3DExample1/Texture.h"
#include "3DExample1/Lighting.h"
#include "3DExample1/WorldSetUp.h"
#include "3DExample1/CameraMovement.h"
#include "3DExample1/KeyInput.h"
#include <iostream>

#ifdef WIN32
#include "gltools.h"
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include "glm.h"

#endif
using namespace std;
Texture t;
Lighting l;
WorldSetUp w;
CameraMovement c;
KeyInput k;


//we need these for the texture loader
//they are to do with the image format and size
GLint iWidth, iHeight, iComponents;
GLenum eFormat;
GLfloat zViewPoint = 400.0f, rotSpeed = 1.0f;
bool leftKeyPressed = false, rightKeyPressed = false, upKeyPressed = false, downKeyPressed = false;
/////GLUquadric* sphere;
// this is a pointer to memory where the image bytes will be held 
GLbyte *pBytes0;
//end of intialisation 
//------------------------------------//
void RenderScene(void)
{
	// Clear the window with current clearing colour
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    
// a test point OR use the unproject code on Blackboard to locate points in the world space
    //use for locating points in your view
   /* glEnable(GL_POINT_SMOOTH);
     glPointSize(10.0);
     glColor3f(1.0, 0.0, 0.0);
     glBegin(GL_POINTS);
     glVertex3f(0.0f, 0.0f, 100.0f);
     glEnd();
    */
	//////////////////////////////////////processCamera();
	w.drawSphere(400.0, 10, 10, 4, 0.0, 0.0, 0.0);
	w.drawSphere(30, 10, 10, 3, 0.0, 0.0, 0.0);
	//c.hudOverlay();
}

// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    //textures

    /////////GLuint texture;
    // allocate a texture name
    glGenTextures( 1, t.textures );
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// photoshop is a good converter to targa (TGA)
	//the gltLoadTGA method is found in gltools.cpp and is orignally from the OpenGL SuperBible book
	//there are quite a few ways of loading images
    // Load textures in a for loop
    glGenTextures(TEXTURE_COUNT, t.textures);
    //this puts the texture into OpenGL texture memory
 //   glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); - not defined so probably need to update GLEW - not needed here so ignore
    for(int iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
    {
        // Bind to next texture object
        glBindTexture(GL_TEXTURE_2D, t.textures[iLoop]);
        
        // Load texture data, set filter and wrap modes
        //note that gltLoadTGA is in the glm.cpp file and not a built-in openGL function
        pBytes0 = gltLoadTGA(t.textureFiles[iLoop],&iWidth, &iHeight,
                             &iComponents, &eFormat);
        
        glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes0);
        
            //set up texture parameters
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        //try these too
       // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
        // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        free(pBytes0);
    }
    
	//enable textures
    glEnable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);	// Hidden surface removal    
    glFrontFace(GL_CCW);// Counter clock-wise polygons face out
	glEnable(GL_CULL_FACE);		// Do not calculate inside

//    glCullFace(GL_FRONT_AND_BACK);
    
	// Enable lighting
//	glEnable(GL_LIGHTING);
	glEnable(GL_POINT_SMOOTH);
	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,l.whiteLightLessBright);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,l.redLight);
	glLightfv(GL_LIGHT0,GL_POSITION,l.lightPos);
	glEnable(GL_LIGHT0);

	// Enable colour tracking
	glEnable(GL_COLOR_MATERIAL);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
	// Black blue background
	glClearColor(0.0f, 0.0f, 0.03f, 1.0f );
}

void TimerFunc(int value)
{
    glutSwapBuffers();
    glutPostRedisplay();
    glutTimerFunc(25, TimerFunc, 1);
}

void ChangeSize(int w, int h)
{
    GLfloat fAspect;
    
    // Prevent a divide by zero
    if(h == 0)
        h = 1;
    
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    
    // Calculate aspect ratio of the window
    fAspect = (GLfloat)w/(GLfloat)h;
    
    // Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // field of view of 45 degrees, near and far planes 1.0 and 1000
    //that znear and zfar should typically have a ratio of 1000:1 to make sorting out z depth easier for the GPU
    gluPerspective(55.0f, fAspect, 1.0, 1000.0); //may need to make larger depending on project
    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    //pull the eye position back to view the scene
    gluLookAt(0.00,0.00, zViewPoint,//eye
              0.00,0.00,0.00,//centre
              0.00,1.00,0.00);//up
}

void processsArrowKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		//process here
		//leftKeyPressed = true;

	}
	if (key == GLUT_KEY_RIGHT)
	{
		//process here
		//rightKeyPressed = true;

	}
	if (key == GLUT_KEY_UP)
	{
		//process here
		//c.moveForward(upKeyPressed = true);
		//zViewPoint += 1.0f;
	}
	if (key == GLUT_KEY_DOWN)
	{
		//process here
		//c.moveBackward(downKeyPressed = true);
		zViewPoint -= 1.0f;
	}
}

void processKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		//set bool
		zViewPoint += 1.0f;
		break;
	case 's':
		//set bool
		zViewPoint -= 1.0f;
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

void playerInstructions()
{
	cout << "Welcome to a 3D Space Game designed in OpenGL with GLUT\n";
	cout << "The aim of the game is to move your first person character\n";
	cout << "through sace to collect the crystals within the spinning hoops\n";
	cout << endl;
	cout << "When all hoops have been collected the game will reset\n";
	cout << endl;
	cout << "Controls:\n";
	cout << endl;
	cout << "Left Arrow = Roll the Ship Left\n";
	cout << "Right Arrow = Roll the Ship Right\n";
	cout << "Up Arrow = Move the Ship Up\n";
	cout << "Left Arrow = Move the Ship Down\n";
	cout << "Q = Rotate the Ship Backwards\n";
	cout << "E = Rotate the Ship Forwards\n";
	cout << "S = Move the Ship Backwards\n";
	cout << "W = Move the Ship Forwards\n";
	cout << "D = Move the Ship Right\n";
	cout << "A = Move the Ship Left\n";
	cout << "Z = Rotate the Ship Left\n";
	cout << "X = Rotate the Ship Right\n";
	cout << "H = Turn the HUD/PFF\n";
}

int main(int argc, char* argv[])
{
	playerInstructions();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);// a 4:3 ratio
	glutCreateWindow("Textures Tutorial");
	glutSpecialFunc(processsArrowKeys);
	//glutSpecialUpFunc(keyGoneUP);
	glutKeyboardFunc(processKeys);
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
    glutTimerFunc(25, TimerFunc, 1);
	SetupRC();
	glutMainLoop();
	return 0;
}