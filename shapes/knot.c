#include <stdio.h>
#include <math.h>

#define DEG2RAD 0.0174532925

#define cosx(deg) cos(DEG2RAD * deg)
#define sinx(deg) sin(DEG2RAD * deg)

void knot1(void)
{
	double i;
	double x, y, z;
	double step = 0.5f;

	for(i=0.0f; i < 361.0f; i+=step) {

		x = cosx(i) * (3 * cosx(i) + 2);
		y = 5 * cosx(i) * sinx(i);
		z = sinx(i) * (10 * cosx(i)*cosx(i) - 1);

		printf("%f\t%f\t%f\n", x, y, z);
	}

}

void knot2(void)
{
	double i;
	double x, y, z;
	double step = 0.5f;

	for(i=0.0f; i < 361.0f; i+=step) {

		x = (2 + cosx(2 * i)) * cosx(3 * i);
		y = (2 + cosx(2 * i)) * sinx(3 * i);
		z = sinx(2 * i);

		printf("%f\t%f\t%f\n", x, y, z);
	}
}

int main()
{
	knot2();
	return 0;
}
