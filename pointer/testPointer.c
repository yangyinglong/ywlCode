//

#include <stdio.h>
#include <math.h>


void my_power(double x, int y, double *pow);      //引用my_power函数


int main()
{
	double xx = 2.5;                  
	int yy = 3;
	double * pPow;            //为函数定义实参xx,yy,*pPow

	pPow = &xx;

	printf("%lf\n", *pPow);

	my_power(xx, yy, pPow);

	printf("%lf\n", *pPow);

	return 0;
}


void my_power(double x, int y, double * pow)     //自定义一个my_power函数  x,y，*pow分别为该函数的虚参
{
	double d = 1.0;

	for (int i = 0; i < y; ++i)
	{
		d = d * x;                //用for循环表示d = pow(x,y)
	}

	*pow = d;

	return;        //void 类型返回为空
}