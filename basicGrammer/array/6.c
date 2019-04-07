/*
7-2 计算个人所得税 分)
假设个人所得税为：税率×(工资−1600)。请编写程序计算应缴的所得税，其中税率定义为：
当工资不超过1600时，税率为0；
当工资在区间(1600, 2500]时，税率为5%；
当工资在区间(2500, 3500]时，税率为10%；
当工资在区间(3500, 4500]时，税率为15%；
当工资超过4500时，税率为20%。
*/

#include<stdio.h>
#include<math.h>

void taxRate(double m);

int main()
{
	double a;
	scanf("%lf", &a);
	taxRate(a);
	return 0;
}

void taxRate(double m)
{
	double n;
	if(m <= 1600)
	{
		n = 0.00;
	}
	else if (m > 1600 && m <= 2500)
	{
		n = (m - 1600) * 0.05;
	}
	else if(m > 2500 && m <= 3500)
	{
		n = (m - 1600) * 0.10;
	}
	else if(m > 3500 && m <= 4500)
	{
		n = (m - 1600) * 0.15;
	}
	else if(m > 4500)
	{
		n = (m - 1600) * 0.20;
	}
	printf("%.2lf\n", n);
}