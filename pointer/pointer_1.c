// 指针的学习，简单的指针操作

#include <stdio.h>
int main() 
{
	int *ptr_num;
	int num = 10;
	int a = 20;

	ptr_num = &num;			// & 是取地址符
	*ptr_num = a;			// * 是地址所指向的值
	printf("num = %d\n", *ptr_num);
	printf("address_1 = %x\n", ptr_num);
	printf("address_2 = %x\n", ++ptr_num);
	printf("address_2 = %x\n", ++ptr_num);

	return 0;
}