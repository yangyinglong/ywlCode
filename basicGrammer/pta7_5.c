//删除数组中重复元素后输出
#include<stdio.h>

int main()
{
	int i, j, n, a[10];
	scanf("%d", &n);  
	for(i = 0; i < n; i ++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i ++)
	{
		for(j = i + 1; j < n; j ++)
		{
			if(a[i] == a[j])
			{
				a[j] = 0;
			}
		}
	}
	for (i = 0; i < n; i ++)
	{
		if(a[i] == 0)
		{
			continue;
		}
		else
		{
			printf("%d\t", a[i]);
		}
	}
	printf("\n");

	return 0;
}