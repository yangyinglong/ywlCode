#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c, perimeter;
	float area, s;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if((a + b > c) && (a + c > b) && (b + c > a))
	{
		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		perimeter = a + b + c;
		printf("area = %.2lf, perimeter = %d\n", area, perimeter);
	}
	else
	{
		printf("These sides do not correspond to a valid triangle\n");
	}
	return 0;
}