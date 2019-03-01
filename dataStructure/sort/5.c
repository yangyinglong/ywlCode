// 归并排序，每个子序列合并后得到有序的序列

#include <stdlib.h>
#include <malloc.h>

int * merge_sort(int *a, int len)
{
    if(len <= 1)
    {
        int *res = malloc(sizeof(int));
        *res = *a;
        return res;
    }
 
    int mid = len / 2;
    int *left = merge_sort(a, mid);
    int *right = merge_sort(a+mid, len - mid);

    int *b = malloc(10*sizeof(int));
    int left_index = 0;
    int right_index = 0;
    int index = 0;
    while(mid-left_index > 0 && len-mid-right_index > 0)
    {
        if(*(left+left_index) > *(right+right_index))
        {
            b[index] = right[right_index];
            right_index++;
        }else{
            b[index] = left[left_index];
            left_index++;
        }
        index++;
    }
 
    while(mid-left_index > 0)
    {
        b[index++] = left[left_index++];
    }
    while(len-mid-right_index > 0)
    {
        b[index++] = right[right_index++];
    }
 
    if(left)
        free(left);
    if(right)
        free(right);
 
    return b;
}
 
int main()
{
    int a[] = {2, 5, 6, 3, 1, 4, 7, 9, 0, 8};
 
    int *res = merge_sort(a, sizeof(a)/sizeof(a[0]));
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
     
    if(res)
    free(res);
}
