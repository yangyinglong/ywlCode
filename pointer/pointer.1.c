#include<stdio.h>

int main()
{
	int num = 9;
	int *ptr_num = &num;
	int *ptr_num2 = &*ptr_num;    //将指针*ptr_num 的地址存放在*ptr_num2中
	printf("%the address of num is :%p\t%x\n",ptr_num,&num );  //%p 指针占位符  %x十六进制占位符
	
	printf("*ptr_num = %d\n",*ptr_num2);

	*ptr_num = 9999;   //使用指针修改变量值
	printf("*ptr_num = %d\n",*ptr_num);

	return 0;
}