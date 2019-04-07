//输入一个数组，输出均值及大于均值的元素
#include<stdio.h>

int main()
{
	int i, n, a[10];
	int sum = 0;
	float av;
	scanf("%d", &n);
	if(n > 10 || n < 1)
	{
		printf("Invalid.");
	}
	else
	{
		for(i = 0; i < n; i ++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			//printf("%d\t", a[i]);
		}
		printf("\n");
		av = sum / n;
		printf("%.2f\n", av);
		for(i = 0; i < n; i++)
		{
			if(a[i] > av)
			{
				printf("%d\t", a[i]);
			}
		}
	}
	printf("\n");
	return 0;
}