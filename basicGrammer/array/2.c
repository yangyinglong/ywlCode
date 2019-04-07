	/*
	有一个数列：8，4，2, 1, 23, 344, 12
				循环输出数列的值
				求数列的和及均值
				猜数游戏：随意输入一个值，判断数列中是否包含该数
	*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

int main()
{
	//1.定义数组并初始化
	int nums[] = {8, 4, 2, 1, 23, 344, 12};
	int i;	      	//循环变量
	int sum = 0;  	//求和
	double avg;   	//求平均值
	int SearchNum;  //定义要查找的数字
	//2.循环输出
	printf("Please print the numbers of array: ");
	for (i = 0; i < 7; i ++)
	{
		printf("%d\t", nums[i]);
	}
	printf("\n");
	//3.求和及均值
	for (i = 0; i < 7; i ++)
	{
		sum += nums[i];
	}
	avg = sum / 7.0;
	//4.查找数字
	printf("Please enter the number you want to search: ");
	scanf("%d", &SearchNum);
	for (int i = 0; i < 7; i ++)
	{
		if (SearchNum == nums[i])
		{
			printf("Find it!\n");
			break;
		}
	}
	if (i == 7)
	{
		printf("Not find it!\n");
	}
	return 0;
}