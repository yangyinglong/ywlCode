//输入一个数组，若无相同元素输出Yes,否则输出No
#include<stdio.h>

int main()
{
	int i, j, N, a[100];
	int flog = 1;
	scanf("%d", &N);
	for(i = 0; i < N; i ++)    //对数组进行输入
	{
		scanf("%d", &a[i]);
	}
	for(i = 0; i < N; i ++)
	{
		for(j = i + 1; j < N; j ++)
		{
			if(a[i] == a[j])
			{
				flog = 0;
				break;
			}		
		}
	}
	if(flog == 0)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
	return 0;
}