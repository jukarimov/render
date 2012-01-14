#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <assert.h>
// (M_PI / 180) 0.017453292519943295
#define DEG2RAD 0.0174532925

// (180 / M_PI)
#define RAD2DEG 57.295779513
#define MAX_VERTEX 10000

struct coord {
	double	x, y, z;
};

struct shape {
	struct coord vertex[MAX_VERTEX];
	int vertices;
};

struct shape *body;

/*TODO stick with KISS principle for now.
struct Triangle {
	struct coord A;
	struct coord B;
	struct coord C;
};

struct triangles {
	struct Triangle trs[MAX_VERTEX];
	int len;
};

struct triangles *TRGS;
*/
int TRIANG_LIST[MAX_VERTEX][1000][3];
int TRIANG_LEN[MAX_VERTEX];

// X, Y & Z Rotation
GLfloat xrot, yrot, zrot;

// X, Y & Z Spin Speed
GLfloat xspeed, yspeed, zspeed;

// X, Y & Z Position
GLfloat posx, posy, posz, posd;

double GSPEED;
double SPEED;

int FREE_ROT;
int RENDER_SOLID;
int RENDER_WIREFRAME;

int split(char *line, char **array, int del);
int readln(char *line);
void do_init();
void gl_get_butts(unsigned char key, int x, int y);
void gl_get_more_butts(int key, int x, int y);
void reset_body();
void gl_display_body();
void gl_display_loop(GLvoid);
void setup_vars();
void gl_init();
void gl_resize(int width, int height);
void parse_vertices(char *filein);

double get_vertices_offset(int a, int b);
void get_closest_range_from(int fromvert, double *range);
void select_vertices_in_range_from(int vlist[], double range, int fromvert, int *count);

int duplicat(int A, int B, int C, int len, int vno);
int vertex_filter(int A, int B, int C, int len, int vno);
void make_triangles_around(int pivot, int vlist[], int nverts);
