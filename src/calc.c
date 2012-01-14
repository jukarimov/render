#include "defs.h"

int duplicat(int A, int B, int C, int len, int vno)
{
	int i;
	for (i=0; i < len; i++) {
		if (
		    (TRIANG_LIST[vno][i][0] == A &&
		     TRIANG_LIST[vno][i][1] == C &&
		     TRIANG_LIST[vno][i][2] == B) ||

		    (TRIANG_LIST[vno][i][0] == B &&
		     TRIANG_LIST[vno][i][1] == C &&
		     TRIANG_LIST[vno][i][2] == A) ||

		    (TRIANG_LIST[vno][i][0] == B &&
		     TRIANG_LIST[vno][i][1] == A &&
		     TRIANG_LIST[vno][i][2] == C) ||

		    (TRIANG_LIST[vno][i][0] == C &&
		     TRIANG_LIST[vno][i][1] == B &&
		     TRIANG_LIST[vno][i][2] == A) ||

		    (TRIANG_LIST[vno][i][0] == C &&
		     TRIANG_LIST[vno][i][1] == A &&
		     TRIANG_LIST[vno][i][2] == B)
		   )
		{
			//printf("Duplicats:\n1) %d %d %d\n2) %d %d %d\n", A, B, C,
			//	TRIANG_LIST[i][0], TRIANG_LIST[i][1], TRIANG_LIST[i][2]);

			return 1;
		}
	}

	return 0;
}

int vertex_filter(int A, int B, int C, int len, int vno)
{
	/* exclude 0, 1, 1 ...*/
	if (A == B || A == C || B == C)
		return -1;

	/* exclude 0, 2, 1 if 0, 1, 2 or 1, 2, 0, was previously*/
	if (duplicat(A, B, C, len, vno))
		return -1;

	return 0;
}

void make_triangles_around(int pivot, int vlist[], int nverts)
{
/*
	puts("(Generating triangles...");
	printf("%d vertices (%d triangs)\n", nverts, nverts * (nverts - 1) / 2);
*/
	assert(nverts > 0);
	int vno = pivot;
	int i, j;
	int triangs = 0;
	for (i=0; i < nverts; i++)
	{
		for (j=0; j < nverts; j++)
		{
			int A = pivot;
			int B = vlist[i];
			int C = vlist[j];

			if (vertex_filter(A, B, C, triangs, vno) == 0)
			{
				TRIANG_LIST[vno][triangs][0] = A;
				TRIANG_LIST[vno][triangs][1] = B;
				TRIANG_LIST[vno][triangs][2] = C;
/*				
				printf("[vertex no: %d] (A) %f %f %f\n", A,
									body->vertex[A].x,
									body->vertex[A].y,
									body->vertex[A].z
				);

				printf("[vertex no: %d] (B) %f %f %f\n", B,
									body->vertex[B].x,
									body->vertex[B].y,
									body->vertex[B].z
				);

				printf("[vertex no: %d] (C) %f %f %f\n", C,
									body->vertex[C].x,
									body->vertex[C].y,
									body->vertex[C].z
				);
*/
				triangs++;
//				puts("--------8<--->8-------");
			}
		}
	}
//	printf("Created %d triangles)\n", triangs);
	TRIANG_LEN[vno] = triangs;
}

double get_vertices_offset(int a, int b)
{
	if (a >= body->vertices || a < 0) {
		fprintf(stderr, "Bad vertex 'a' given: %d\n", a);
		return -1;
	}

	if (b >= body->vertices || b < 0) {
		fprintf(stderr, "Bad vertex 'b' given %d\n", b);
		return -1;
	}

	double diffab, diffx, diffy, diffz;

	diffx = body->vertex[a].x - body->vertex[b].x;
	diffy = body->vertex[a].y - body->vertex[b].y;
	diffz = body->vertex[a].z - body->vertex[b].z;

	diffab = sqrt(	diffx*diffx +
			diffy*diffy +
			diffz*diffz
	);

	return diffab;
}

int compar(const void *d1, const void *d2) 
{
	double a, b;

	a = *(double const *) d1;
	b = *(double const *) d2;
	
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	
	return -1;
}

int uniq(double dlist[], int nvert, double v)
{
	int i;
	for (i=0; i < nvert; i++) {
		if (v == dlist[i])
			return 0;
	}
	return 1;
}

void get_closest_range_from(int fromvert, double *range)
{
	int nverts = body->vertices;
	double dlist[nverts+1];
	int i, j = 0;
	for (i=0; i < nverts; i++) {

		double dist = get_vertices_offset(fromvert, i);

		if (!dist)
			continue;

		if (uniq(dlist, j, dist)) {
			dlist[j++] = dist;
		}
	}

	qsort(&dlist, j, sizeof(double), compar);

	if (j != 0)
	{
		if (j > 1) {
			*range = dlist[1];
		}
		else if (j == 1) {
			fprintf(stderr, "WARNING: Only one range found\n");
			*range = dlist[0];
		}
	}
	else {
		fprintf(stderr, "WARNING: NO RANGES found\n");
		*range = -1;
		exit(-1);
	}
}

void select_vertices_in_range_from(int vlist[], double range, int fromvert, int *count)
{
	int i, j, n;
	n = body->vertices;
	j = 0;
	for (i=0; i < n; i++) {
		if (get_vertices_offset(fromvert, i) <= range)
			vlist[j++] = i;
	}
	*count = j;
}
