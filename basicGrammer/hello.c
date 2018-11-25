#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 3;
	int j = 2;
	int c = i / j;
	double d = i * 1.0 / j;

	printf("%d, %f\n", c, d);
	
	return 0;
}
