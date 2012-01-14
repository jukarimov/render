#include "defs.h"

void gl_get_butts(unsigned char key, int x, int y)
{
	switch (key) {
	case '-':
		posz -= GSPEED;	   // Move Object Away From Viewer
		break;

	case '=':
		posz += GSPEED;	   // Move Object Towards Viewer
		break;

	case 'W':
		posy += GSPEED;	  // Move Object Up
		break;

	case 'S':
		posy -= GSPEED;	  // Move Object Down
		break;

	case 'D':
		posx += GSPEED;	  // Move Object Right
		break;

	case 'A':
		posx -= GSPEED;	  // Move Object Left
		break;

	/* Rotation by X, Y, Z axises */
	case 'U':
		zrot -= GSPEED * 20;
		break;

	case 'J':
		zrot += GSPEED * 20;
		break;

	case 'I':
		yrot -= GSPEED * 20;
		break;

	case 'K':
		yrot += GSPEED * 20;
		break;

	case 'O':
		xrot -= GSPEED * 20;
		break;

	case 'L':
		xrot += GSPEED * 20;
		break;

	case 'B':
		puts("Free Rotation Disabled");
		FREE_ROT = 0;
		xspeed = yspeed = zspeed = SPEED = 0.0f;
		break;

	case 'M':
		puts("Free Rotation Enabled");
		FREE_ROT = 1;
		xspeed = yspeed = zspeed = SPEED = GSPEED;
		break;

	case 'T':
		if (RENDER_SOLID == 0) {
			puts("Solid view enabled");
			RENDER_SOLID = 1;
			RENDER_WIREFRAME = 0;
		}
		else {
			puts("Wireframe view enabled");
			RENDER_SOLID = 0;
			RENDER_WIREFRAME = 1;
		}
		break;

	// Escape key is pressed
	case 27:
		fprintf(stderr, "Bye, world\n");
		exit(0);
		break;

	default:
		fprintf(stderr, "Err, unknown key: `%c'\n", key);
		break;
	}
}

void gl_get_more_butts(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_PAGE_UP:
			zspeed += SPEED;
			break;

	case GLUT_KEY_PAGE_DOWN:
			zspeed -= SPEED;
			break;

	case GLUT_KEY_DOWN:
			xspeed += SPEED;
			break;

	case GLUT_KEY_UP:
			xspeed -= SPEED;
			break;

	case GLUT_KEY_RIGHT:
			yspeed += SPEED;
			break;

	case GLUT_KEY_LEFT:
			yspeed -= SPEED;
			break;

	default:
			break;
	}
}

