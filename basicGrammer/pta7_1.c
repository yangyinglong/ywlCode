//选择排序法
#include<stdio.h>

int main()
{
	int i,j, k, n, tmp, a[10];
	scanf("%d", &n);    //输入数组元素个数
	for(i = 0; i < n; i ++)    //对数组进行输入
		{
			scanf("%d", &a[i]);
		}
	for(i = 0; i < n-1; i ++)
    {
        k = i;
        for(j = i + 1; j < n; j ++)
        {
            if(a[k] > a[j])
            {
                k = j;
            }
        }
		if(k != i)
		{
		    tmp = a[k];
		    a[k] = a[i];
		    a[i] = tmp;
		}
    }
    for(i = 0; i < n; i++)   //将排序好后的数列输出
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}