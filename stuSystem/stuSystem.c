// 学生管理系统
#include<stdio.h>

void printHead();
void add();         //增加一条记录
void delete();      //删除一条记录

struct Student
{
	char idNumber[50];
	char name[50];
	int sex;	
};


int main()
{
	char order;
	int sign = 1;
	while(sign == 1) 
	{
		scanf("%c", &order);
		switch(order)
		{
			case 'a': add();   //增加一条记录
			
				
			case 'd': delete();  //根据学号删除一条记录


			case 'f':    //根据性别查询符合条件的所有学生的信息并打印出来


			case 'p':    //打印所有学生信息


			case 'q':    //退出系统

		}
	} 
	return 0;  
}


// 实现相应的函数


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

void add()
{




}

void delete()
{




}