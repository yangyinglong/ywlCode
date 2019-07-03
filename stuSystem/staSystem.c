// 员工管理系统

#include <stdio.h>    
#include <string.h>
#include <stdlib.h>

#define MAX_STA_NUM 20

//定义一个员工结构体
struct Staff
{
	char idNumber[6];
	char name[20];
	char degree[20];
	char position[20];
	int income;
	char phoneNum[20];
	int status;
};


FILE * fpSta;    //定义一个指向文件的指针fpSta

//函数声明
void mune();
void searchMune();
void printHead();
void printOne(struct Staff * pRSta);
void printAll(struct Staff staffs[], int staNum);    //打印所有员工信息(包括状态stastas==0的员工)
int readFile(struct Staff staffs[]);       //读取文件
void writeFile(struct Staff staffs[], int staNum);   //写入文件（将文件中修改后的内容写入文件）
void writeSta(struct Staff * pSta, FILE * fp);
int addSta(struct Staff staffs[], int staNum, struct Staff sta);        //增加一条员工记录
void deleteSta(struct Staff staffs[], char idNumber[], int staNum);       //删除一条员工记录(使该员工的状态stastas==0)
int searchAll(struct Staff staffs[], int staNum, char idNumber[], char name[], char degree[], char position[], int income, struct Staff resultStas[]);
int searchStaById(struct Staff staffs[], int staNum, char idNumber[], struct Staff * pRSta);
int searchStaByName(struct Staff staffs[], int staNum, char name[], struct Staff * pRSta);
int searchStaByDegree(struct Staff staffs[], int staNum, char degree[], struct Staff * pRSta);
int searchStaByPosition(struct Staff staffs[], int staNum, char position[], struct Staff * pRSta);
int searchStaByIncome(struct Staff staffs[], int staNum, struct Staff resultStus[], int income);
void inputCharArr(char charArr[], int len);
struct Staff initSta(char idNumber[], char name[], char degree[], char position[], int income, char phoneNum[]);
void reviseSta(struct Staff staffs[], int staNum, char idNumber[], char name[], char degree[], char position[], int income, char phoneNum[], struct Staff * pRSta);

int main()
{
	struct Staff staffs[MAX_STA_NUM];
	struct Staff resultStas[MAX_STA_NUM];
	char order;       //定义一个字符型变量order来接收主菜单执行的命令
	int sign = 1;     //作为循环继续或退出的标志
	int staNum = 0;   //定义员工数量，存放员工总数
	char idNumber[6];
	char name[20];
	char degree[20];
	char position[20];
	int income;
	char phoneNum[20];
	int resultNum;    //定义员工数量，存放符合条件的员工数量
	struct Staff sta;      //struct Staff(员工结构体)类型的变量sta
	// char mark;
	struct Staff * pRSta;
	staNum = readFile(staffs); 	//从文件中读取员工数量

	mune();
	while(sign == 1) 
	{
		printf("please enter an order:");
		scanf("%c", &order);
		getchar();    //用来在输入命令后清除缓冲
		switch(order)
		{
			case 'a':       //增加一条记录
				printf("please input an idNumber endwith enter: ");
				inputCharArr(idNumber, 6);
				printf("please input a name endwith enter: ");
				inputCharArr(name, 20);
				printf("please input a degree endwith enter: ");
				inputCharArr(degree, 20);
				printf("please input a position endwith enter: ");
				inputCharArr(position, 20);
				printf("please input a phoneNum endwith enter: ");
				inputCharArr(phoneNum, 20);
				printf("please input a income endwith enter: ");
				scanf("%d", &income);
				while(getchar() != '\n');          //用来在输入命令后清除缓冲
				sta = initSta(idNumber, name, degree, position, income, phoneNum);
				staNum = addSta(staffs, staNum, sta);   	
				break; 
			case 'c':   //清屏
				system("cls");
				mune();
				break;
			// case 'r':
			// 	// reviseSta(staffs, staNum, idNumber, name, degree, position, income, phoneNum, &sta);
			// 	resultNum = searchStaByIncome(staffs, staNum, resultStas, income);
			// 	printAll(resultStas, resultNum);

			// 	printf("please input an idNumber endwith enter: ");
			// 	inputCharArr(idNumber, 6);
			// 	while(getchar() != '\n');
			// 	resultNum = searchStaById(staffs, staNum, idNumber, &sta);
			// 	printf("please input a name endwith enter: ");
			// 	inputCharArr(name, 20);
			// 	printf("please input a degree endwith enter: ");
			// 	inputCharArr(degree, 20);
			// 	printf("please input a position endwith enter: ");
			// 	inputCharArr(position, 20);
			// 	printf("please input a phoneNum endwith enter: ");
			// 	inputCharArr(phoneNum, 20);
			// 	printf("please input a income endwith enter: ");
			// 	scanf("%d", &income);
			// 	while(getchar() != '\n'); 
			// 	idNumber = reviseAll(staffs, resultNum);
			// 	sta = initSta(idNumber, name, degree, position, income, phoneNum);  
			// 	staNum = addSta(staffs, staNum, sta);

				break;  			
			case 'd':       //根据编号删除一条记录(使该员工的状态stasta==0)
				printf("please input an idNumber endwith enter: ");
				inputCharArr(idNumber, 6);
				deleteSta(staffs, idNumber, staNum);    
				break;         
			case 's':
				searchMune();
				resultNum = searchAll(staffs, staNum, idNumber, name, degree, position, income, resultStas);
				if(resultNum == 0)
				{
					printHead();
					printf("|	  no this staff !  	 |\n");
				}
				else 
				{
					printAll(resultStas, resultNum);
				}			
				break; 
			case 'p':       //打印所有员工信息
				printAll(staffs, staNum);
				break;        
			case 'q':       //保存修改后的员工信息并退出系统
				writeFile(staffs, staNum);                      
				printf("staffs save success!\nBye\n");
				sign = 0;
				break;       
			default:        //如果命令输入错误就进行提示
				printf("please choose the true order!\n");
				mune();
				break;
		}
	} 
	return 0;  
}


// 定义相应的函数

//打印菜单
void mune()
{
	printf("***     Welcome to Staff System     ***\n");
	printf("***          a -- add               ***\n");     //增加
	printf("***          r -- revise            ***\n");     //修改-按编号查找然后修改编号以外的信息
	printf("***          d -- delete            ***\n");     //删除-按员工编号
	printf("***          s -- search            ***\n");     //按编号查询
	printf("***          g -- gothrough         ***\n"); 	 //浏览员工信息
	printf("***          c -- cleanScreem       ***\n"); 	 //清屏
	printf("***          q -- exit              ***\n"); 	 //退出职工系统
	printf("***************************************\n");
}

//信息查询菜单
void searchMune()
{
	printf("***************************************\n");
	printf("****please chose the way you search****\n");
	printf("   1 -- byIdNumber    4 -- byPosition  \n");
	printf("   2 -- byName        5 -- byIncome    \n");
	printf("   3 -- byDegree      6 -- clean       \n");
	printf("   0 -- exit                           \n");
	printf("***************************************\n");
}

//打印头部
void printHead()
{
	for (int i = 0; i < 50; ++i)
	{
		printf("-");
	}
	printf("\n");
	printf("|IdNum\t|Name\t|Degree\t|Pos\t|income\t|Phone\t|\n");		
}

//打印所有有效员工的信息（状态为1）
void printAll(struct Staff staffs[], int staNum)    //void类型的函数printAll中传入了struct Stadent类型的staffs和int类型的staNum这两个参数
{
	printHead();
	struct Staff * pSta;       //定义一个struct Stadent类型的指针pSta
	
	if (staNum == 0)
	{
		for (int j = 0; j < 50; ++j)
		{
			printf("-");			
		}
		printf("\n|	   no this staff !   |\n");
		return;
	}
	for (int i = 0; i < staNum; ++i)
	{
		pSta = &staffs[i];        
		if (pSta->status == 0)
		{
			continue;	 
		}
		for (int j = 0; j < 50; ++j)
		{
			printf("-");			
		}
		printf("\n|");
		printf("%s\t", pSta->idNumber);
		printf("|");
		printf("%s\t", pSta->name);
		printf("|");
		printf("%s\t", pSta->degree);
		printf("|");
		printf("%s\t", pSta->position);
		printf("|");
		printf("%d\t", pSta->income);
		printf("|");
		printf("%s\t", pSta->phoneNum);
		printf("|\n");

	}
	for (int j = 0; j < 50; ++j)
	{
		printf("-");			
	}
	printf("\n");
	return;
}


//打印一个员工的信息（在查询时用到）
void printOne(struct Staff * pRSta)
{
	printHead();
	for (int j = 0; j < 50; ++j)
	{
		printf("-");			
	}
	printf("\n|");
	printf("%s\t", pRSta->idNumber);
	printf("|");
	printf("%s\t", pRSta->name);
	printf("|");
	printf("%s\t", pRSta->degree);
	printf("|");
	printf("%s\t", pRSta->position);
	printf("|");
	printf("%d\t", pRSta->income);
	printf("|");
	printf("%s\t", pRSta->phoneNum);
	printf("|\n");
	for (int j = 0; j < 50; ++j)
	{
		printf("-");			
	}
	printf("\n");
	return;
}

//读取打开文件中的内容
int readFile(struct Staff staffs[])
{
	int staNum = 0;
	fpSta = fopen("staff.txt", "r");
	if (fpSta == NULL)
	{
		printf("FILE staFile.txt open FAIL\n");
		return 0;
	}
	fseek(fpSta, 0L, SEEK_SET);
	while (!feof(fpSta)) 
	{
		fscanf(fpSta, "%s%s%s%s%d%s%d", staffs[staNum].idNumber, staffs[staNum].name, staffs[staNum].degree, staffs[staNum].position, &staffs[staNum].income, staffs[staNum].phoneNum, &staffs[staNum].status);
		staNum ++;
	}
	fclose(fpSta);
	return staNum;
}

//将员工信息写入文件
void writeFile(struct Staff staffs[], int staNum)
{
	fpSta = fopen("staff.txt", "w");
	int j = 0;
	if (fpSta == NULL)
	{
		printf("FILE staFile.txt open FAIL\n");
		return;
	}
	for (int i = 0; i < staNum - 1; ++ i)
	{
		if(staffs[i].status == 1)
		{
			j += 1;
			if(j != 1)
			{
				fprintf(fpSta,"\n");
			}
			fprintf(fpSta, "%s\t%s\t%s\t%s\t%d\t%s\t%d", staffs[i].idNumber, staffs[i].name, staffs[i].degree, staffs[i].position, staffs[i].income, staffs[i].phoneNum, staffs[i].status);
		}
	}
	if(staffs[staNum - 1].status == 1)
		{
			fprintf(fpSta,"\n");
			fprintf(fpSta, "%s\t%s\t%s\t%s\t%d\t%s\t%d", staffs[staNum - 1].idNumber, staffs[staNum - 1].name, staffs[staNum - 1].degree, staffs[staNum - 1].position, staffs[staNum - 1].income, staffs[staNum - 1].phoneNum, staffs[staNum - 1].status);
		}	
	fclose(fpSta);
	return;
}

/**
 * 将单个员工的信息写入指定文件（在按编号删除员工信息时用到）
 */
void writeSta(struct Staff * pSta, FILE * fp)
{
	// fpSta = fopen("deleteSta.txt", "a+");
	if (fp == NULL)
	{
		printf("FILE deleteSta.txt open FAIL\n");
		return;
	}
	fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%d\n", pSta->idNumber, pSta->name, pSta->degree, pSta->position, pSta->income, pSta->phoneNum, pSta->status);
	fclose(fp);
	return;
}

//增加一个员工
int addSta(struct Staff staffs[], int staNum, struct Staff sta)
{
	struct Staff * pSta;
	if (staNum + 1 > MAX_STA_NUM - 1)
	{
		printf("staffs had max, sta add fail\n");
		return staNum;
	}
	for(int i = 0; i < staNum; ++i)
	{
		pSta = &staffs[i];
		if(strcmp(sta.idNumber, staffs[i].idNumber) == 0 && pSta->status == 1)
		{
			printf("The staff already exist!\n");
			return staNum;
		}
	}
	staffs[staNum] = sta;
	fpSta = fopen("staff.txt", "a+");
	writeSta(&sta, fpSta);
	staNum ++;
	printf("The staff add success!\n");
	return staNum;
}

/**
 * 按编号删除一个员工并将其信息保存到指定的文件中
 */
void deleteSta(struct Staff staffs[], char idNumber[], int staNum)
{
	struct Staff * pSta;
	for(int i = 0; i < staNum; ++i)
	{
		pSta = &staffs[i];
		if(strcmp(idNumber, pSta->idNumber) == 0 && pSta->status == 1)
		{
			pSta->status = 0;
			fpSta = fopen("deleteSta.txt", "a+");
			writeSta(pSta, fpSta);
			printf("delete success\n");
			return;
		}
	}
	printf("no this staff\n");
	return;
}


//输入函数
void inputCharArr(char charArr[], int len)
{
	char c;
	int index = 0;
	while((c = getchar()) != '\n');
	printf("please input:");
	while((c = getchar()) != '\n' && index < len - 1)
	{
		charArr[index] = c;
		index ++;
	}
	charArr[index] = '\0';
	while((c = getchar()) != '\n');
}

/**
 * 初始化员工信息
 */
struct Staff initSta(char idNumber[], char name[], char degree[], char position[], int income, char phoneNum[])
{
	struct Staff sta;
	strcpy(sta.idNumber, idNumber);
	strcpy(sta.name, name);
	strcpy(sta.degree, degree);
	strcpy(sta.position, position);
	strcpy(sta.phoneNum, phoneNum);
	sta.income = income;
	sta.status = 1;
	return sta;
};

//查询(通过编号、姓名、学历、职位、工资)
int searchAll(struct Staff staffs[], int staNum, char idNumber[], char name[], char degree[], char position[], int income, struct Staff resultStas[])
{
	int index = 0;
	int choose;
	printf("please enter you search way: ");
	scanf("%d", &choose);
	while(getchar() != '\n');
	if(choose == 1)
	{
		index = searchStaById(staffs, staNum, idNumber, resultStas);	
	}
	else if(choose == 2)
	{
		index = searchStaByName(staffs, staNum, name, resultStas);
	}
	else if(choose == 3)
	{
		index = searchStaByDegree(staffs, staNum, degree, resultStas);
	}
	else if(choose == 4)
	{
		index = searchStaByPosition(staffs, staNum, position, resultStas);
	}
	else if(choose == 5)            //按工资查询段查询
	{
		index = searchStaByIncome(staffs, staNum, resultStas, income);
	}
	// else if(choose == 6)
	// {
	// 	system("cls");
	// }
	// else if(choose == 0)
	// {
	// 	return -1;
	// }
	return index; 
}

//按编号查询员工信息
int searchStaById(struct Staff staffs[], int staNum, char idNumber[], struct Staff resultStas[])
{
	int index = 0;
	printf("please input an idNumber endwith enter: ");
	inputCharArr(idNumber, 6);
	while(getchar() != '\n');
	for(int i = 0; i < staNum; ++i)
	{
		if(strcmp(idNumber,  staffs[i].idNumber) == 0 && staffs[i].status == 1)
		{
			resultStas[index] = staffs[i];  
			index ++;
		}   
	}
	return index;
}

//按姓名查找员工信息
int searchStaByName(struct Staff staffs[], int staNum, char name[], struct Staff resultStas[])
{
	int index = 0;
	printf("please input a name endwith enter: ");
	inputCharArr(name, 20);
	while(getchar() != '\n');
	for(int i = 0; i < staNum; ++i)
	{
		if(strcmp(name, staffs[i].name) == 0 && staffs[i].status == 1)
		{
			resultStas[index] = staffs[i];  
			index ++;
		}   
	}
	return index;
}

//按学历查找员工信息
int searchStaByDegree(struct Staff staffs[], int staNum, char degree[], struct Staff resultStas[])
{
	int index = 0;
	printf("please input a degree endwith enter: ");
	inputCharArr(degree, 20);
	while(getchar() != '\n');
	for(int i = 0; i < staNum; ++i)
	{
		if(strcmp(degree, staffs[i].degree) == 0 && staffs[i].status == 1)
		{            
			resultStas[index] = staffs[i];  
			index ++;
		}   
	}
	return index;
}

//按职位查找员工信息
int searchStaByPosition(struct Staff staffs[], int staNum, char position[], struct Staff resultStas[])
{
	int index = 0;
	printf("please input a position endwith enter: ");
	inputCharArr(position, 20);
	while(getchar() != '\n');
	for(int i = 0; i < staNum; ++i)
	{
		if(strcmp(position, staffs[i].position) == 0 && staffs[i].status == 1)
		{
			resultStas[index] = staffs[i];  
			index ++;
		}   
	}
	return index;
}

//按工资段查找
int searchStaByIncome(struct Staff staffs[], int staNum, struct Staff resultStas[], int income)
{
	struct Staff * pSta;
	int index = 0;
	char mark;
	printf("please input a income endwith enter: ");
	scanf("%s", &mark);
	scanf("%d", &income);
	while(getchar() != '\n');
	if(mark == '>')
	{
		for(int i = 0; i < staNum; ++i)
		{
			pSta = &staffs[i];
			if(pSta->income > income && pSta->status == 1)
			{
				resultStas[index] = staffs[i];  
				index ++;            
			}
		}
	}
	else if(mark == '<')
	{
		for(int i = 0; i < staNum; ++i)
		{
			pSta = &staffs[i];
			if(pSta->income < income && pSta->status == 1)
			{
				resultStas[index] = staffs[i];  
				index ++;            
			}
		}
	}
	else if(mark == '=')
	{
		for(int i = 0; i < staNum; ++i)
		{
			pSta = &staffs[i];
			if(pSta->income == income && pSta->status == 1)
			{
				resultStas[index] = staffs[i];  
				index ++;            
			}
		}
	}	
	printf("gongziduan: %c%d\n", mark, income);
	printf("number    : %d\n", index);
	return index;
}

//按编号查询并修改除编号以外的信息
void reviseSta(struct Staff staffs[], int staNum, char idNumber[], char name[], char degree[], char position[], int income, char phoneNum[], struct Staff * pRSta)
{
	int resultNum;
	// struct Staff * pSta;
	struct Staff sta;
	// pSta = &staffs[i];
	printf("please enter an idNumber you want to revise: ");
	inputCharArr(idNumber, 6);
	resultNum = searchStaById(staffs, staNum, idNumber, &sta);
	if(resultNum == 1)
	{
		printf("please input a name endwith enter: ");
		inputCharArr(name, 20);
		printf("please input a degree endwith enter: ");
		inputCharArr(degree, 20);
		printf("please input a position endwith enter: ");
		inputCharArr(position, 20);
		printf("please input a phoneNum endwith enter: ");
		inputCharArr(phoneNum, 20);
		printf("please input a income endwith enter: ");
		scanf("%d", &income);
		while(getchar() != '\n');          //用来在输入命令后清除缓冲
		sta = initSta(idNumber, name, degree, position, income, phoneNum);
		// staNum = addSta(staffs, staNum, sta);
		staffs[staNum] = sta;
		fpSta = fopen("staff.txt", "a+");
		writeSta(&sta, fpSta);	
	}
	return;
}


//将员工信息的录入进行改进
// void putIn(char idNumber[], char name[], char degree[], char position[], int income, char phoneNum[])
// {
// 	printf("please input an idNumber endwith enter: ");
// 	inputCharArr(idNumber, 6);
// 	printf("please input a name endwith enter: ");
// 	inputCharArr(name, 20);
// 	printf("please input a degree endwith enter: ");
// 	inputCharArr(degree, 20);
// 	printf("please input a position endwith enter: ");
// 	inputCharArr(position, 20);
// 	printf("please input a phoneNum endwith enter: ");
// 	inputCharArr(phoneNum, 20);
// 	printf("please input a income endwith enter: ");
// 	scanf("%d", &income);
// }









