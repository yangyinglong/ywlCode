// 指针的学习，简单的指针操作

#include<stdio.h>

int main()
{
	int num1 = 1024;
	int num2 = 2048;
	int *ptr1;
	int *ptr2;
	ptr1 = &num1;
	ptr2 = &num2;
	printf("num1 = %d\t the adress of num1:%p\n",num1,ptr1);
	printf("num2 = %d\t the adress of num2:%p\n",num2,ptr2);

	return 0;
}