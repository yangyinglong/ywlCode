/*
素数判断 
键盘输入一个正整数，要求判断该数是否为素数。
素数即质数，只能被1和它本身整除。
特别说明，1不是素数。如果是素数，输出“YES”，否则输出“NO”
*/
//方法一  （有小错误）
#include<stdio.h>
#include<math.h>

int suShu(long int i);

int main()
{
	long int a;
	scanf("%ld", &a);
	if(suShu(a) == 1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	return 0;
}

int suShu(long int i)
{
	int j;
	int flag = 0;
	for (j = 2; j <= sqrt(i); j ++)
	{
		if(i % j == 0 && i != 2)
		{
			flag = 1;       //不是素数
			break;
		}
	}
	return flag;
}


//方法二 （老师讲的）
/*
#include<stdio.h>
#include<math.h>

int pdzs(long int k);

int main()
{
	long int a;
	scanf("%ld", &a);
	if(pdzs(a) == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}

int pdzs(long int k)
{
	int i;
	for(i = 2; i <= sqrt(k); i ++)
	{
		if(k % i == 0)
		{
			break;
		}
	}
	if(i > sqrt(k) && k != 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
*/