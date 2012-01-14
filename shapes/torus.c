
void torus(void)
{
	freopen("torus.vertices.txt", "w", stdout);
	int n;
	double i, j;
	double x[3], y[3], z[3];
	double step = 5.0f;
	for(i=5.0f; i < 361.0f; i+=step) {

		for(j=5.0f; j < 361.0f; j+=step) {

			x[0] = cos(DEG2RAD * (i)) * (2.0f + cos(DEG2RAD * (j)));
			y[0] = sin(DEG2RAD * (i)) * (2.0f + cos(DEG2RAD * (j)));
			z[0] = sin(DEG2RAD * (j));

			printf("%f\t%f\t%f\n", x[0], y[0], z[0]);
/*
			x[1] = cos(DEG2RAD * (i-5)) * (2.0f + cos(DEG2RAD * (j)));
			y[1] = sin(DEG2RAD * (i-5)) * (2.0f + cos(DEG2RAD * (j)));
			z[1] = sin(DEG2RAD * (j));

			x[2] = cos(DEG2RAD * (i-5)) * (2.0f + cos(DEG2RAD * (j+5)));
			y[2] = sin(DEG2RAD * (i-5)) * (2.0f + cos(DEG2RAD * (j+5)));
			z[2] = sin(DEG2RAD * (j+5));


			glColor3f(1, 1, 1);
			glBegin(GL_TRIANGLES);


			for (n = 0; n < 3; n++)
				printf("%f\t%f\t%f\n", x[n], y[n], z[n]);

				glVertex3f(x[n], y[n], z[n]);

			glEnd();


			x[0] = cos(DEG2RAD * (i)) * (2.0f + cos(DEG2RAD * (j)));
			y[0] = sin(DEG2RAD * (i)) * (2.0f + cos(DEG2RAD * (j)));
			z[0] = sin(DEG2RAD * (j));

			x[1] = cos(DEG2RAD * (i)) * (2.0f + cos(DEG2RAD * (j+5)));
			y[1] = sin(DEG2RAD * (i)) * (2.0f + cos(DEG2RAD * (j+5)));
			z[1] = sin(DEG2RAD * (j+5));

			x[2] = cos(DEG2RAD * (i-5)) * (2.0f + cos(DEG2RAD * (j+5)));
			y[2] = sin(DEG2RAD * (i-5)) * (2.0f + cos(DEG2RAD * (j+5)));
			z[2] = sin(DEG2RAD * (j+5));


			glBegin(GL_TRIANGLES);


			for (n = 0; n < 3; n++)
				printf("%f\t%f\t%f\n", x[n], y[n], z[n]);

				glVertex3f(x[n], y[n], z[n]);

			glEnd();
			*/

		}
	}
}
