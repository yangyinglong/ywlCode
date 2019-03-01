// 引用和指针的区别

#include <stdio.h>
#include <stdlib.h>


void swap_int(int * a, int * b)
{
	printf("before swap_int &a = %d\n", a);
	printf("before swap_int &b = %d\n", b);
	int * temp = a;
	a = b;
	b = temp;
	printf("swap_int a = %d\n", *a);
	printf("swap_int b = %d\n", *b);
	printf("after swap_int &a = %d\n", a);
	printf("after swap_int &b = %d\n", b);
}


void swap_int_1(int &a, int &b)
{
	printf("before swap_int &a = %d\n", &a);
	printf("before swap_int &b = %d\n", &b);
	int temp;
	temp = a;
	a = b;
	b = a;
	printf("swap_int a = %d\n", a);
	printf("swap_int b = %d\n", b);
	printf("after swap_int &a = %d\n", &a);
	printf("after swap_int &b = %d\n", &b);
}

int main() 
{
	int a = 1, b = 2;

	printf("&a = %d\n", &a);
	printf("&b = %d\n", &b);

	// swap_int(&a, &b);
	swap_int_1(a, b);


	printf("a = %d, b = %d\n", a, b);
	printf("&a = %d\n", &a);
	printf("&b = %d\n", &b);
	return 0;
}