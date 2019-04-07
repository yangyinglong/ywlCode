//斐波那契数列
//F(1)=1，F(2)=1, F(3)=2,F(n)=F(n-1)+F(n-2)（n>=4，n∈N*）

#include<stdio.h>

int main()
{
	int n;
	int a(12) = {1, 1, 2};
	//int a(1) == 1, a(2) == 1, a(3) == 2;
	// a(2) == 1;
	// a(3) == 2;
	for(n = 4; n <= 12; n ++)
	{
		a(n) = a(n - 1) + a(n - 2);
		printf("%d\t", a(n))
	}


	return 0;
}