// 快速排序

#include<stdio.h>

void sort(int *a, int left, int right)
{
    int key = a[left];
    int i = left;
    int j = right;
    int tmp;
 
    if(left < right)
    {
        while(i < j)
        {
            // 从右往左扫描,将找到小的a[j]和key进行对换
            while(i < j && a[j] >= key)
            {
                j--;
            }
            // a[i]是基准元素与a[j]对调
            if(i < j)
            {
                a[i] = a[j];
                a[j] = key;
            }
            while(i < j && a[i] <= key)
            {
                i++;
            }
 
            // a[j]是基准点,将基准点再与a[i]对调
            if(i < j)
            {
                a[j] = a[i];
                a[i] = key;
            }
        }
        sort(a, left, i-1);
        sort(a, j+1, right);
    }
}

int main()
{
	int a[10] = {9, 7, 1, 4, 8, 10, 2, 5, 3, 6};
	sort(a, 0, 9);
	for(int i = 0; i < 10; i++) 
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}