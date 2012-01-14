#include "defs.h"

void parse_vertices(char *filein)
{
	fprintf(stderr, "Parsing vertices from \"%s\"\n", filein);

	if (!freopen(filein, "r", stdin)) {
		fprintf(stderr, "Err, Failed to open \"%s\"\n", filein);
		exit(-1);
	}

	int n = 0;
	/*TODO implement linked-list instead */
	char line[MAX_VERTEX][80];
	char str[80];
	while (readln(str) != -1) {
		if (str[0] == '#')
			continue;
		/*TODO input sanity checks here */
		strcpy(line[n], str);
		++n;
	}
	fclose(stdin);

	fprintf(stderr, "%d lines read\n", n);

	if (body == NULL) {
		fprintf(stderr, "Err, body undefined!\n");
		exit(-1);
	}

	body->vertices = n;
	
	char **XYZ;
	XYZ = (char **)malloc(3);
	XYZ[0] = (char *)malloc(20);
	XYZ[1] = (char *)malloc(20);
	XYZ[2] = (char *)malloc(20);


	int i;
	for (i=0; i < body->vertices; i++) {

		split(line[i], XYZ, '\t');

		body->vertex[i].x = atof(XYZ[0]);
		body->vertex[i].y = atof(XYZ[1]);
		body->vertex[i].z = atof(XYZ[2]);

	}
}

