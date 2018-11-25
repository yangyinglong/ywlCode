//输入的数组，输出逆序   如a[1]=1,a[2]=3,a[3]=5,a[4]=7,a[5]=9,
                    //则输出a[1]=9,a[2]=7,a[3]=5,a[4]=3,a[5]=1

#include <stdio.h>

int main()
{
	int a[5];
	int temp;

	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &a[i]);     //先完成对数组的输入
	}
   
	for (int i = 0; i < 5; ++i)    //对数组进行输出
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = 0; i < 5/2; ++i)
	{
		temp = a[i];
		a[i] = a[4-i];
		a[4-i] = temp;           //a[1]中元素和a[5]中元素进行交换，a[2]和a[4]同上
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%d %d ", i,a[i]);     //对进行过逆序的元素进行输出
	}
	printf("\n");

	return 0;
}