// 归并排序

#include<stdio.h>
#include <malloc.h>

void *sort(int *a, int len)
{
	if (len <= 1)
	{
		int *res = malloc(sizeof(int));
        *res = *a;
        return res;
	}
	int mid = len/2;
	int *left_a = sort(a, mid);
	int *right_a = sort(a+mid, len-mid);

	int *b = malloc(10*sizeof(int));
	int left_index = 0;
	int right_index = 0;
	int index = 0;

	while(mid-left_index>0 && len-mid-right_index>0)
	{
		if (*(left_a+left_index) > *(right_a+right_index))
		{
			b[index] = right_a[right_index];
			right_index++;
		}
		else
		{
			b[index] = left_a[left_index];
			left_index++;
		}
		index++;
	}
	while (mid-left_index>0)
	{
		b[index] = left_a[left_index];
		left_index++;
		index++;
	}
	while (len-mid-right_index>0)
	{
		b[index] = right_a[right_index];
		right_index++;
		index++;
	}

	free(left_a);
	free(right_a);
	return b;
}

int main()
{
	int a[] = {2, 5, 6, 3, 1, 4, 7, 9, 0, 8};
 
    int *res = sort(a, sizeof(a)/sizeof(a[0]));
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
     
    if(res)
    free(res);
	return 0;
}