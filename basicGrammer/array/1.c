/*
	动态录入第i个学生的成绩
*/
#include<stdio.h>
#include<stdlib.h>
#define N 5

int main()
{
	//动态录入
	double score[N];
	int i;   //循环变量
	//使用循环操作数组时，要注意：一个循环尽量只做一件事
	for(i = 0; i < N; i ++)
	{
		printf("please enter the %d student's score: ", i + 1);
		scanf("%lf", &score[i]);
	}
	//用这个for循环进行输出
	for(i = 0; i < N; i ++)
	{
		printf("The %d student's score is %.2lf\n", i + 1, score[i]);
	}
	return 0;
}