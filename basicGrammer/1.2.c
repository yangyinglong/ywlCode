//求解方程 y = 3 * x *x + 2 * x - 1（x < -5）
       // y = x * sin(x) + 2 * x * x  (x >= -5 and x <= 5)  

#include <stdio.h>
#include <math.h>
int main()
{
	float x, y;
	printf("please enter a number x =");
	scanf("%f",&x);

	// if else 要紧凑，中间不要有空行，一般一个函数
	/* 开头定义所有要用到的变量，然后初始化赋值，然后可以加一个空行
	   代码块与代码块之间可以加一个换行，比如两个 for 循环之间，比如1.4代码 */
	if(x < -5)
	{
		y = 3 * x *x + 2 * x - 1;
		// printf("y = %f\n",y);
	}

	else if(x >= -5 and x <= 5)
	{
		y = x * sin(x) + 2 * x * x;
		// printf("y = %f\n",y);
	}

	else
	{
		y = sqrt(x - 5) + log10(x);
		// printf("y = %f\n",y);
	}
	printf("y = %f\n",y);

	return 0;







}