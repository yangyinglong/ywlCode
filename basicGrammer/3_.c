// 输入三个数a,b,c，求出三者最大的赋值给max

#include <stdio.h>

int main()
{
	double a, b, c;
	double max;

	a = 1.908;
	b = 10.097;
	c = 9.009;

	max = a > b ? a : b;
	max = max > c ? max : c;
	
	printf("%lf\n", max);
	return 0;
}