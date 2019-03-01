// 选择排序

#include <stdio.h>


void sort(int *a, int n)
{
    int i, j, tmp;
 
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
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