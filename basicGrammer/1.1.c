//求一元二次方程是否有根

#include <stdio.h>

int main()
{
	int a, b, c, d;
	printf("please enter three numbers:\n");
	// scanf("%d\n",&a);
	// scanf("%d\n",&b);
	/* 不用回车符 */
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);

	d = b*b-4*a*c;
	printf("%d\n",d);

	if(d > 0) 
	{
		printf("have two different roots\n");
	}
	else if(0 == d) 
	{
		printf("have two same roots\n");
	}	
	else
	{
		printf("no root\n");
	}
	
	return 0;
}