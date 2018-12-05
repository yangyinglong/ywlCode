// 学生管理系统
#include<stdio.h>    
#include<string.h>

#define MAX_STU_NUM 20

//定义一个学生结构体
struct Student     
{
	char idNumber[6];
	char name[10];
	int sex;
	int status;	
};

FILE * fpStu;    //定义一个指向文件的指针fpStu

//对所使用到的函数进行声明
//void printHead();
int readFile(struct Student students[]);       //读取文件
void writeFile(struct Student students[], int stuNum);   //写入文件（将文件中修改过的内容写入文件）
int addStu(struct Student students[], int stuNum, struct Student stu);        //增加一条学生记录
void deleteStu(struct Student students[], char idNumber[], int stuNum);       //删除一条学生记录(使该学生的状态stastus==0)
int searchStu(struct Student students[], int stuNum, struct Student resultStus[], int sex);    //根据性别查询符合条件的所有学生的信息并打印出来
void printAll(struct Student students[], int stuNum);    //打印所有学生信息(包括状态stastus==0的学生)



int main()
{
	struct Student students[MAX_STU_NUM];
	struct Student resultStus[MAX_STU_NUM];
	char order;       //定义一个字符型变量order来接收要执行的命令
	int sign = 1;     //作为循环继续或退出的标志
	int stuNum = 0;   //定义学生数量，存放学生总数
	char idNumber[6];  
	int resultNum;    //定义学生数量，存放符合条件的学生数量
	stuNum = readFile(students); 

	struct Student stu = {"00003", "Jhon", 1, 1};
	strcpy(idNumber, "00002");

	while(sign == 1) 
	{
		printf("a-addStu\td-delete\tf-searchStu\tp-printAll\tq-exit\n");
		printf("please enter an order:");
		scanf("%c", &order);
		getchar();    //用来在输入命令后清除缓冲
		switch(order)
		{
			case 'a':       //增加一条记录
				stuNum = addStu(students, stuNum, stu);   	
				break;        			
			case 'd':       //根据学号删除一条记录(使该学生的状态stastu==0)
				deleteStu(students, idNumber, stuNum);    
				break;        
			case 'f':       //根据性别查询符合条件的所有学生的信息并打印出来
				resultNum = searchStu(students, stuNum, resultStus, 0);
				printAll(resultStus, resultNum);
				break;        
			case 'p':       //打印所有学生信息
				printAll(students, stuNum);
				break;        
			case 'q':       //保存修改后的学生信息并退出系统
				writeFile(students, stuNum);                      
				printf("Students save success!\nBye\n");
				sign = 0;
				break;       
			default:        //如果命令输入错误就进行提示
				printf("please choose the true order!\n");
				break;
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



void printAll(struct Student students[], int stuNum)
{
	struct Student * pStu;
	for (int i = 0; i < stuNum; ++i)
	{
		pStu = &students[i];
		if (pStu->status == 0)
		{
			continue;	 
		}
		for (int j = 0; j < 33; ++j)
		{
			printf("-");			
		}
		printf("\n|");
		printf("%s\t", pStu->idNumber);
		printf("|");
		printf("%s\t", pStu->name);
		printf("|");
		printf("%d\t", pStu->sex);
		printf("|\n");
	}
	for (int j = 0; j < 33; ++j)
	{
		printf("-");			
	}
	printf("\n");
	return;
}

int readFile(struct Student students[])
{
	int stuNum = 0;
	fpStu = fopen("students.txt", "r");
	if (fpStu == NULL)
	{
		printf("FILE stuFile.txt open FAIL\n");
		return 0;
	}
	fseek(fpStu, 0L, SEEK_SET);
	while (!feof(fpStu)) 
	{
		fscanf(fpStu, "%s%s%d%d", students[stuNum].idNumber, students[stuNum].name, &students[stuNum].sex, &students[stuNum].status);
		stuNum ++;
	}
	fclose(fpStu);
	return stuNum;
}

void writeFile(struct Student students[], int stuNum)
{
	fpStu = fopen("students.txt", "w");
	if (fpStu == NULL)
	{
		printf("FILE stuFile.txt open FAIL\n");
		return;
	}
	for (int i = 0; i < stuNum - 1; ++i)
	{
		fprintf(fpStu, "%s\t%s\t%d\t%d\n", students[i].idNumber, students[i].name, students[i].sex, students[i].status);
	}
	fprintf(fpStu, "%s\t%s\t%d\t%d", students[stuNum - 1].idNumber, students[stuNum - 1].name, students[stuNum - 1].sex, students[stuNum - 1].status);
	fclose(fpStu);
	return;
}

int addStu(struct Student students[], int stuNum, struct Student stu)
{
	if (stuNum + 1 > MAX_STU_NUM - 1)
	{
		printf("students had max, stu add fail\n");
		return stuNum;
	}
	students[stuNum] = stu;
	stuNum ++;
	printf("student add success!\n");
	return stuNum;
}

void deleteStu(struct Student students[], char idNumber[], int stuNum)
{
	struct Student * pStu;
	int flag = 0;
	for(int i = 0; i < stuNum; ++i)
	{
		pStu = &students[i];
		if(strcmp(idNumber, pStu->idNumber) == 0 && pStu->status == 1)
		{
			pStu->status = 0;
			printf("delete success\n");
			flag = 1;
			return;
		}
	}
	if(flag == 0)
	{
		printf("no this student\n");
		return;
	}
	return;
}

int searchStu(struct Student students[], int stuNum, struct Student resultStus[], int sex)
{
	struct Student * pStu;
	int index = 0;
	for(int i = 0; i < stuNum; ++i)
	{
		pStu = &students[i];
		if(pStu->sex == sex && pStu->status == 1)
		{
			resultStus[index] = students[i];  
			index ++;            
		}
	}

	return index;
}