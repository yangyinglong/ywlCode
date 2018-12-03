// 学生管理系统
#include<stdio.h>    
#include<string.h>

struct Student
{
	char idNumber[50];
	char name[50];
	char sex[2];	
};

//定义学生数量
int counts = 0;

void printHead();
void add(struct Student stu[100]);         //增加一条记录
void delete(struct Student stu[100]);      //删除一条记录
void search(struct Student stu[100]);      //根据性别查询符合条件的所有学生的信息并打印出来
void printall(struct Student stu[100]);    //打印所有学生信息



int main()
{
	struct Student stu[100];
	char order;
	int sign = 1;
	while(sign == 1) 
	{
		printf("a-add\nd-delete\nf-search\np-printall\nq-exit\n");
		printf("please enter your order:");
		scanf("%c", &order);
		switch(order)
		{
			case 'a': add();        //增加一条记录
			
				
			case 'd': delete();     //根据学号删除一条记录


			case 'f': search();     //根据性别查询符合条件的所有学生的信息并打印出来


			case 'p': printall();   //打印所有学生信息


			case 'q': break;        //退出系统

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

void search()
{




}

void printall()
{





}