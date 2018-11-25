//判断a,b,c三个数中的最大数

#include <stdio.h>
//#include <math.h>

int main()
{

 	int a, b, c, d;
	printf("please enter three numbers:\n");
	scanf("%d%d%d", &a, &b, &c);
	// if(a > b)
	// {
	// 	d = a;
	// 	//printf("d = %d\n",d);
	// }
	// else
	// {
	// 	d = b;
	// 	//printf("d = %d\n",d);
	// }

	// if(d > c)
	// {
	// 	//printf("d = %d\n",d);
	// }
	// else
	// {
	// 	d = c;
	// 	//printf("d = %d\n",c );
	// }

	int max;
	max = a > b ? a : b;  //如果a>b真，max = a,否则max = b
	max = max > c ? max : c;


	printf("max = %d\n",max);

	return 0;
}