//输入一个数组，然后反向输出

#include<stdio.h>

int main()
{
	int i;
	int a[]={1,3,5,7,9};
	for(i=4; i>=0; i--)
	{
		printf("%d%d ", i, a[i]);
		if(i == 0)     //与最后一行请按任意键继续分行
		{
			printf("\n");
		}
	}
	return 0;
}