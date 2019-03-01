// 插入排序呢
#include <stdio.h>


void sort(int *a, int n)
{
	int get;
	for (int i = 1; i < n; ++i)
	{
		int j = i-1;
		get = a[i];
		while(j >= 0 && a[j] > get)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = get;
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