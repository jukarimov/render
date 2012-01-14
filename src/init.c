#include "defs.h"

void do_init()
{
	xrot = 0;
	yrot = 0;
	zrot = 0;
	
	xspeed = 0;
	yspeed = 0;
	zspeed = 0;
	
	posx = 0;
	posy = 0;
	posz = 0.0f;
	posd = 5.0f;

	/* Motion speed */
	GSPEED = 0.05f;
	SPEED = 0.05f;

	FREE_ROT = 0;
	RENDER_SOLID = 0;
}

void reset_body()
{
	assert(body);
	int i;
	for (i=0; i < body->vertices; i++) {
		body->vertex[i].x = 0;
		body->vertex[i].y = 0;
		body->vertex[i].z = 0;
	}
	body->vertices = 0;
}
