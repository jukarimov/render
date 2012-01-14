#include "defs.h"

void gl_display_body()
{
	int i;
	double x, y, z;

	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);

	for (i=0; i < body->vertices; i++)
	{
		x = body->vertex[i].x;
		y = body->vertex[i].y;
		z = body->vertex[i].z;
		
		glVertex3f(x, y, z);

		/*TODO numerate vertices for visial 
		glTranslatef(x+0.5, y+0.5, z+0.5);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char *)"0");*/
	}


	glEnd();

	if (RENDER_SOLID || RENDER_WIREFRAME)
	{
		glColor3f(0, 1, 0);
		if (RENDER_SOLID)
			glBegin(GL_TRIANGLES);
		else
			glBegin(GL_LINE_LOOP);

		int A, B, C;
		int j;
		for (j=0; j < body->vertices; j++)
		{
			for (i=0; i < TRIANG_LEN[j]; i++)
			{
			 A = TRIANG_LIST[j][i][0];
			 x = body->vertex[A].x;
			 y = body->vertex[A].y;
			 z = body->vertex[A].z;

			 glVertex3f(x, y, z);

			 B = TRIANG_LIST[j][i][1];
			 x = body->vertex[B].x;
			 y = body->vertex[B].y;
			 z = body->vertex[B].z;

			 glVertex3f(x, y, z);

			 C = TRIANG_LIST[j][i][2];
			 x = body->vertex[C].x;
			 y = body->vertex[C].y;
			 z = body->vertex[C].z;

			 glVertex3f(x, y, z);
			}
		}
		glEnd();
	}
}

/* Here's Where We Do All The Drawing
 *
 */
void gl_display_loop()
{
	// Clear The Screen And The Depth Buffer
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();	

/*
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
*/

	// Reset The View
	//glLoadIdentity();

	// Translate The The Current Position To Start Drawing
	glTranslatef(posx, posy, posz);

	/* Rotate by each axis */
	glRotatef(xrot, 1, 0, 0);
	glRotatef(yrot, 0, 1, 0);
	glRotatef(zrot, 0, 0, 1);

	// Increase xrot, yrot & zrot by xspeed, yspeed & zspeed
	if (FREE_ROT) {
		xrot += xspeed;
		yrot += yspeed;
		zrot += zspeed;
	}

	// Draw body from vertice input
	gl_display_body();

	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s [VERTEX DATA]\n", argv[0]);
		exit(-1);
	}

	do_init();

	body = (struct shape *)malloc(sizeof(struct shape));
	if (body == NULL) {
		fprintf(stderr, "Cannot malloc the body\n");
		exit(-1);
	}

	parse_vertices(argv[1]);
	/* ================================================================================ */

	int fromvert = 0;
	double range;
	int vlist[MAX_VERTEX];
	int len;

	for (; fromvert < body->vertices; fromvert++) {

		printf("Making triangles around vertex %d:\n", fromvert);

		get_closest_range_from(fromvert, &range);
		//printf("Two closest ranges from vertex %d are:\n%f\n%f\n", fromvert, r1, r2);

		select_vertices_in_range_from(vlist, range, fromvert, &len);
		//printf("%d vertices in range %f from vertex %d:\n", len, r1, fromvert);

/*
		int i, j;
		for (i=0, j=vlist[i]; i < len; i++, j=vlist[i])
		//printf("[vertex: %d] %f %f %f\n", vlist[i], 
		//	body->vertex[j].x, body->vertex[j].y, body->vertex[j].z);
*/
		make_triangles_around(fromvert, vlist, len);
	}

	/* */ 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 480);
	glutCreateWindow("3D shape render");

	gl_init();

	glutDisplayFunc(gl_display_loop);
	glutReshapeFunc(gl_resize);
	glutIdleFunc(gl_display_loop);

	glutKeyboardFunc(gl_get_butts);
	glutSpecialFunc(gl_get_more_butts);

	glutMainLoop();
	/* ================================================================================ */

	return 0;
}

