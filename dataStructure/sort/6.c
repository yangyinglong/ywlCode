// 折半查找
#include <stdio.h>

void split_lookup(int *a, int n, int target)
{
    int i = 0;
    int j = n-1;
    int index;
 
    while(i < j)
    {
        index = (i+j)/2;
 
        if(a[index] > target)
        {
            j = index - 1;
        }else if(a[index] < target)
        {
            i = index + 1;
        }else{
            printf("lookup success: index:%d value:%d\n", index, a[index]);
            return;
        }
    }
}
 
void split_lookup1(int *a, int start, int end, int target)
{
    if (start > end)
    {
        printf("not found!\n");
    }
    int index = (start + end) / 2;
    if (a[index] > target)
    {
        split_lookup1(a, start, index-1, target);
    }
    else if (a[index] < target)
    {
        split_lookup1(a, index+1, end, target);
    }
    else
    {
        printf("index: %d, value: %d\n", index, a[index]);
        return;
    }
}

int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    split_lookup1(a, 0, 6, 1);
    return 0;
}