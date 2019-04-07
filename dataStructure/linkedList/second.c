#include<stdio.h>

//函数声明
void PrintName();
void PrintLoves();
void PrintSomething();

int main()
{
	PrintName();   //函数调用
	PrintLove();
	PrintSomething();
	return 0;
}

//函数定义
void PrintName()
{
	printf("Chanshu ");
	return;
}

void PrintLoves()
{
	printf("loves ");
	return;
}

void PrintSomething()
{
	printf("C-language\n");
	return;
}