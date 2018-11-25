//！阶乘

#include<stdio.h>
#include <math.h>

int main()
{
	int x, n;
	double top, bottom; 	//分子分母
	bottom = 1.0; //初始化
	double result;
	result = 0.0;

	printf("please enter the number x and n :");
	scanf("%d%d",&x,&n);

	for (int i = 1; i < n + 1; ++i)
	{
		top = pow(x, i);
		bottom = bottom * (i + 1);
		printf("top = %f, bottom = %f\n", top, bottom);
		result = result + top / bottom;
	}

	printf("result = %f\n", result);

	return 0;
}