#include "defs.h"

void gl_init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
/*
	// Set The Blending Function For Translucenposy
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	// This Will Clear The Background Color To Black
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Lights
	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Enables Clearing Of The Depth Buffer
	//glClearDepth(1);

	// The Type Of Depth Test To Do
	//glDepthFunc(GL_LESS);

	// Enables Depth Testing
	//glEnable(GL_DEPTH_TEST);

	GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };

	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);


	// Setup the view of the cube.
	glMatrixMode(GL_PROJECTION);

	gluPerspective(45.0f * posd, // field of view in degree
		1.0f, //(GLfloat)width/(GLfloat)height,
		0.1f,
		100.0f
	);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(posx, posy, posz,	// eye is at (0,0,5) 
		  0.0, 0.0, 0.0,	// center is at (0,0,0) 
		  0.0, 1.0, 0.0		// up is in positive Y direction
	);


	// Enables Smooth Color Shading
	glShadeModel(GL_SMOOTH);

	glEnable(GL_CULL_FACE);

	// Really Nice Perspective Calculations
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_CLIP_VOLUME_CLIPPING_HINT_EXT, GL_FASTEST);

	GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

	// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);	

	// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);

	// Position The Light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);

	// Enable Light One
	glEnable(GL_LIGHT1);
*/
}

// Resize And Initialize The GL Window
void gl_resize(int width, int height)
{
	// Prevent A Divide By Zero By
	if (height  ==  0)
			height = 1;


	// Reset The Current Viewport
	glViewport(0, 0, width, height);

	// Select The Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset The Projection Matrix
	glLoadIdentity();

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f * posd, // field of view in degree
		(GLfloat)width/(GLfloat)height,
		0.1f,
		100.0f
	);

		/* eye is at (0,0,5) */
	gluLookAt(posx, posy, posd,

		/* center is at (0,0,0) */
		0.0, 0.0, 0.0,

		/* up is in positive Y direction */
		0.0, 1.0, 0.0
	);

	// Select The Modelview Matrix
	glMatrixMode(GL_MODELVIEW);

	// Reset The Modelview Matrix
	glLoadIdentity();
}

