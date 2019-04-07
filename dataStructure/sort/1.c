// 冒泡排序
#include <stdio.h>

void sort(int *a, int n)
{
	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

}

int main()
{
	int a[10] = {9, 7, 1, 4, 8, 10, 2, 5, 3, 6};
	sort(a, 10);
	for(int i = 0; i < 10; i++) 
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}