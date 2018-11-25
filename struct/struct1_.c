//学生系统

#include<stdio.h>
#include<string.h>

//定义结构体
//只需要一个结构体Student: Idnumber, name, sex
struct Student
{
	char Idnumber[6];
	char name[6];
	int sex;
} 

//函数声明
void printHead();










/*
  在终端打印出
  ---------------------------------
  |IdNumber       |Name   |Sex    |
 */
void printHead()
{
	for (int i = 0; i < 33; ++i)
	{
		printf("-");
	}
	printf("\n");
	printf("|Idnumber\t|name\t|sex\t|\n");
	
}
