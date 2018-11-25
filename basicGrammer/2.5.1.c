// 3*3矩阵，求元素之和，找出最小的元素的行列
#include <stdio.h>

int main()
{
	int a[3][3];			//定义3*3的数组
	int sum = 0;
	int min_i, min_j;		//定义标记符，标记最小数所在的行列
	min_i = min_j = 0;

	for (int i = 0; i < 3; ++i)
	{
		printf("Please enter %d num: ", i);
		for (int j = 0; j < 3; ++j)
		{
			scanf("%d", &a[i][j]);			
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", a[i][j]);	
		}
		printf("\n");
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			sum = sum + a[i][j];
			if (a[i][j] < a[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	printf("sum = %d, min = (%d, %d)\n", sum, min_i, min_j);

	return 0;
}