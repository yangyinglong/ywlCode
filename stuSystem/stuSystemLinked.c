/*
 单向链表的使用：学生管理系统
 **/
/*
 1、打印文件头部 PrintHead()
 2、打印所有有效学生信息（节点）PrintAllNode(struct PLHead * pstHead)
 3、打印一个符合条件的学生信息(在按学号查找时使用) PrintOneNode(struct Student *pstNode)
 4、根据学号查询一个学生 SearchNodeById(struct PLHead *pstHead, char *idNumber)
 5、
 增加：
 1、创建一个空的数据链表作为头节点 CreatePLHead()

 新函数：
 memcpy(memory copy的缩写)函数：
 memcpy(pstNew, pstData, sizeof(struct Student));   
 //memcpy函数是将pstData从开始位置拷贝sizeof个字节的数据到pstNew
		
**/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//定义一个学生结构体
struct Student     
{
	char idNumber[6];
	char name[10];
	int sex;
	char adminName[10];
	struct Student * pstNext;   //用来存储下一学生的地址
	int status;             //没有用
};

struct PLHead
{
	int len;
	struct Student *pstFirst;
};

FILE * fpStu;

void PrintHead();
int PrintAllNode(struct PLHead * pstHead);
void PrintOneNode(struct Student *pstNode);
void inputCharArr(char charArr[], int len);
struct PLHead * CreatePLHead();
// int DestoryPLHead(struct PLHead * pstHead);  //销毁整个数据链表
struct Student * CreateNewNode(struct Student * pstData);
int Judge(struct PLHead *pstHead, struct Student *pstNew);
int InsertStudentAtTail(struct PLHead * pstHead, struct Student * pstNewNode);
int RemoveStudent(struct PLHead * pstHead, struct Student * pstNewNode);
int DestoryNode(struct Student * pstNode);
struct Student *SearchNodeById(struct PLHead *pstHead, char *idNumber);



int main(int argc, char const *argv[])
{
	struct PLHead *pstHead = CreatePLHead();   //创建一个数据链表
	struct Student *pstNew = NULL;        //pstNew 作为新节点，用来存储新插入的节点
	struct Student *pstTemp = NULL;   
	struct Student NodeData = {""};          //定义一个节点的变量， //在新插入节点的时候用来存储新节点的内容
	

	char idNumber[6];
	char name[10];
	char adminName[10];
	int sex; 
	char order;          //用来输入命令
	int sign = 1;        //作为循环继续1或退出0的标记
	int judge = 0;
	printf("a-addStu\td-delete\tf-searchStu\ts-searchStuById\tp-printAll\tq-exit\n");
	while(sign == 1) 
	{
		printf("please enter an order:");
		scanf("%c", &order);
		getchar();    //用来在输入命令后清除缓冲
		switch(order)
		{
			case 'a':    //增加一条学生记录
				printf("please input an idNumber endwith enter: ");
				inputCharArr(NodeData.idNumber, 6);
				printf("please input a name endwith enter: ");
				inputCharArr(NodeData.name, 10);
				printf("please input an adminName endwith enter: ");
				inputCharArr(NodeData.adminName, 10);
				printf("please input a sex(0 or 1) endwith enter: ");
				scanf("%d", &sex);
				while(getchar() != '\n');
				pstNew = CreateNewNode(&NodeData);  
				// Judge(pstHead, pstNew); 
				judge = Judge(pstHead, pstNew);
				if(1 == judge)
				{
					InsertStudentAtTail(pstHead, pstNew);
				}
				else
				{
					printf("The student has already exist");
				}
				// InsertStudentAtTail(pstHead, pstNew);
				break;
			case 'd':       //根据学号删除一条记录(使该学生的状态stastu==0)
				printf("please input an idNumber endwith enter: ");
				inputCharArr(idNumber, 6);
				while(getchar() != '\n');
				pstTemp = SearchNodeById(pstHead,idNumber);
				if(NULL == pstTemp)
				{
					PrintHead();
					printf("|	  no this student !  	|\n");
				}
				else
				{
					RemoveStudent(pstHead, pstTemp);
					printf("%s has been removed\n",pstTemp -> idNumber);
					DestoryNode(pstTemp);
				}

			case 's':
				printf("please input an idNumber endwith enter: ");
				inputCharArr(idNumber, 6);
				while(getchar() != '\n');
				pstTemp = SearchNodeById(pstHead,idNumber);
				if(NULL == pstTemp)
				{
					PrintHead();
					printf("|	  no this student !  	|\n");
				}
				else
				{
					PrintOneNode(pstTemp);

					// RemoveStudent(pstHead, pstTemp);
					// printf("%s has been removed\n",pstTemp -> idNumber);
					// DestoryNode(pstTemp);
				}
			case 'p':       //打印所有学生信息
				PrintAllNode(pstHead);
				break;        
			case 'q':       //保存修改后的学生信息并退出系统
				// writeFile(students, stuNum);                      
				printf("Students save success!\nBye\n");
				sign = 0;
				break;       
			default:        //如果命令输入错误就进行提示
				printf("please choose the true order!\n");
				printf("a-addStu\td-delete\tf-searchStu\ts-searchStuById\tp-printAll\tq-exit\n");
				break;

		}
	}







	// strcpy(NodeData.idNumber, "0001");
	// strcpy(NodeData.name, "Make");
	// sex = 1;
	// strcpy(NodeData.adminName, "Zhang");
	// pstNew = CreateNewNode(&NodeData);       //将新的变量赋值给新的节点
	// InsertStudentAtTail(pstHead, pstNew);    //将新的节点插入到链表的尾部
	

	// strcpy(NodeData.idNumber, "0002");
	// strcpy(NodeData.name, "Jone");
	// sex = 1;
	// strcpy(NodeData.adminName, "Zhang");
	// pstNew = CreateNewNode(&NodeData);       //将新的变量赋值给新的节点
	// InsertStudentAtTail(pstHead, pstNew);    //将新的节点插入到链表的尾部
	

	// strcpy(NodeData.idNumber, "0003");
	// strcpy(NodeData.name, "July");
	// sex = 1;
	// strcpy(NodeData.adminName, "Zhang");
	// pstNew = CreateNewNode(&NodeData);       //将新的变量赋值给新的节点
	// InsertStudentAtTail(pstHead, pstNew);    //将新的节点插入到链表的尾部
	// PrintAllNode(pstHead);


	// pstTemp = SearchNodeById(pstHead,"0002");
	// if(NULL == pstTemp)
	// {
	// 	PrintHead();
	// 	printf("|	  no this student !  	|\n");
	// }
	// else
	// {
	// 	PrintOneNode(pstTemp);

		// RemoveStudent(pstHead, pstTemp);
		// printf("%s has been removed\n",pstTemp -> idNumber);
		// DestoryNode(pstTemp);
	// }
		
	// PrintAllNode(pstHead);



	return 0;
}




/*
  在终端打印出
  ---------------------------------
  |idNumber       |Name   |Sex    |
 */
void PrintHead()
{
	for (int i = 0; i < 33; ++i)
	{
		printf("-");
	}
	printf("\n");
	printf("|IdNum\t|Name\t|Sex\t|Admin\t|\n");	
}

//将所有的节点都打印出来
int PrintAllNode(struct PLHead * pstHead)
{
	PrintHead();
	struct Student *pstNode = NULL;
	if(NULL == pstHead)
	{
		return -1;
	}
	pstNode = pstHead ->pstFirst;
	while(pstNode != NULL)
	{
		for (int i = 0; i < 33; ++i)
		{
			printf("-");
		}
		printf("\n|");
		printf("%s\t", pstNode->idNumber);
		printf("|");
		printf("%s\t", pstNode->name);
		printf("|");
		printf("%d\t", pstNode->sex);
		printf("|");
		printf("%s\t", pstNode->adminName);
		printf("|\n");
		pstNode = pstNode -> pstNext;
	}
	for (int i = 0; i < 33; ++i)
	{
		printf("-");
	}
	printf("\n");
	return 0;
}

//打印一个学生的信息(在按学号查找时用到)
void PrintOneNode(struct Student *pstNode)
{
	PrintHead();
	// struct Student *pstNode = NULL;

	for (int j = 0; j < 33; ++j)
	{
		printf("-");			
	}
	printf("\n|");
	printf("%s\t", pstNode->idNumber);
	printf("|");
	printf("%s\t", pstNode->name);
	printf("|");
	printf("%d\t", pstNode->sex);
	printf("|");
	printf("%s\t", pstNode->adminName);
	printf("|\n");
	
	for (int j = 0; j < 33; ++j)
	{
		printf("-");			
	}
	printf("\n");
	return;
}

//先创建一个数据链表，作为头节点
struct PLHead * CreatePLHead()
{
	struct PLHead * pstNew = NULL;
	pstNew = (struct PLHead *)malloc(sizeof(struct PLHead));
	if(NULL == pstNew)
	{
		printf("Error malloc failed\n");
		return NULL;
	}	
	memset(pstNew, 0, sizeof(struct PLHead));	
	return pstNew;
}

//销毁整个数据链表，一般不会使用
int DestoryPLHead(struct PLHead * pstHead)
{
	struct Student * pstNode = NULL;
	struct Student * pstNext = NULL;
	if (NULL == pstHead)
	{
		return -1;
	}
	pstNode = pstHead->pstFirst;
	while (pstNode != NULL)
	{
		pstNext = pstNode->pstNext;
		DestoryNode(pstNode);
		pstNode = pstNext;
	}
	return 0;
}

//创建一个新的节点
struct Student *CreateNewNode(struct Student * pstData)
{
	struct Student * pstNew = NULL;
	pstNew = (struct Student *)malloc(sizeof(struct Student));
	if(NULL == pstNew)
	{
		printf("Error malloc failed\n");
		return NULL;
	}
	if(pstData != NULL)
	{
		memcpy(pstNew, pstData, sizeof(struct Student));   //memcpy函数是将pstData从开始位置拷贝sizeof个字节的数据到pstNew
		pstNew->pstNext = NULL;}
	else
	{
		memset(pstNew, 0, sizeof(struct Student));
	}
	return pstNew;
}

//插入新的节点后判断该学生信息是否已存在
int Judge(struct PLHead * pstHead, struct Student *pstNew)
{
	struct Student *pstNode = NULL;
	pstNode = pstHead -> pstFirst;
	if(strcmp(pstNode -> idNumber,pstNew -> idNumber) != 0)
	{
		pstNode = pstNode -> pstNext;
		if(pstNode == NULL)
		{
			return 0;
		}
	}
	else
	{
		return 1;
		// InsertStudentAtTail(pstHead, pstNew);
	}
}

//在尾部增加一条学生信息
int InsertStudentAtTail(struct PLHead * pstHead, struct Student * pstNewNode)
{
	struct Student *pstLast = NULL;
	if(NULL == pstHead || NULL == pstNewNode)		//先判断输入参数是否合法
	{
		return -1;
	}
	pstLast = pstHead -> pstFirst;
	while(pstLast != NULL)
	{
		if(NULL == pstLast -> pstNext)
		{
			break;
		}
		pstLast = pstLast -> pstNext;
	}
	if(pstLast == NULL)
	{
		pstHead -> pstFirst = pstNewNode;
	}
	else
	{
		pstLast -> pstNext = pstNewNode;
	}
	pstNewNode -> pstNext = NULL;
	pstHead -> len ++;
	return 0;
}

//移除一个节点

int RemoveStudent(struct PLHead * pstHead, struct Student * pstNode)
{
	struct Student *pstPrev = NULL;       //pstPrev 用来保存被移除节点的前一个节点的地址
	struct Student *pstTemp = NULL;	      //pstTemp 用来保存第一个节点的地址
	if(NULL == pstHead || NULL == pstNode)       //先判断输入参数是否合法
	{
		return -1;
	}
	pstTemp = pstHead -> pstFirst;
	if(NULL == pstTemp)        //头节点为空，说明该链表为空，则无法进行移除操作
	{
		return -1;             
	}
	if(pstTemp == pstNode)      //当被移除节点正好为第一个节点
	{
		pstHead -> pstFirst = pstNode ->pstNext;
		pstNode ->pstNext = NULL;
	}
	else 
	{
		while(pstTemp != NULL)      //当被移除节点不是第一个节点的时候，通过遍历的方法找到被移除节点
		{
			if(pstTemp ->pstNext == pstNode)
			{
				pstPrev = pstTemp;
				break;
			}
			pstTemp = pstTemp -> pstNext;    //pstTemp 指向下一个节点
		}
		if(NULL == pstPrev)
		{
			return -1;
		}
		else
		{
			pstPrev -> pstNext = pstNode -> pstNext;
			pstNode -> pstNext = NULL;
		}
	}
	pstHead -> len --;      //移除成功后，表中元素少一，所以表长减一
	return 0;
} 

//销毁一个节点,即彻底删除一个学生数据
int DestoryNode(struct Student * pstNode)
{
	if(pstNode != NULL)
	{
		free(pstNode);      //释放该节点所占的空间
	}
	return 0;
}

//按学号查找一个学生
struct Student *SearchNodeById(struct PLHead *pstHead, char *idNumber)
{
	struct Student *pstNode = NULL;

	if(NULL == pstHead || NULL == idNumber)        //先判断参数是否正确
	{
		return NULL;
	}

	pstNode = pstHead -> pstFirst;
	while(pstNode != NULL)
	{
		if(strcmp(pstNode ->idNumber, idNumber) == 0)
		{
			break;
		}
		pstNode = pstNode -> pstNext;
	}
	return pstNode;
}


//定义输入函数，
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
 * 读取打开文件中的内容
 */
// int readFile(struct PLHead * pstHead)
// {
// 	int len = 0;
// 	fpStu = fopen("studentNode.txt", "r");
// 	if (fpStu == NULL)
// 	{
// 		printf("FILE stuFile.txt open FAIL\n");
// 		return 0;
// 	}
// 	fseek(fpStu, 0L, SEEK_SET);
// 	while (!feof(fpStu)) 
// 	{
// 		fscanf(fpStu, "%s%s%d%s", pstHead.idNumber, pstHead.name, &pstHead.sex, pstHead.adminName);
// 		pstHead -> len ++;
// 	}
// 	fclose(fpStu);
// 	return len;
// }

/**
 *对学生系统中的内容修改后进行保存
 */
// void writeFile(struct PLHead * pstHead, int len)      //这个长度应该怎么引入
// {
// 	fpStu = fopen("studentNode.txt", "w");
// 	struct Student *pstNode = NULL;
// 	int j = 0;
// 	if (fpStu == NULL)
// 	{
// 		printf("FILE stuFile.txt open FAIL\n");
// 		return;
// 	}
// 	pstNode = pstHead -> pstFirst;
// 	for (int i = 0; i < len - 1; ++ i)
// 	{
// 		j += 1;
// 		if(j != 1)
// 		{
// 			fprintf(fpStu,"\n");
// 		}
// 		fprintf(fpStu, "%s\t%s\t%d\t%s", pstNode -> idNumber, pstNode -> name, pstNode -> sex, pstNode -> adminName);
// 		pstNode = pstNode -> pstNext;
// 	}
// 	if(students[len - 1].status == 1)
// 		{
// 			fprintf(fpStu,"\n");
// 			fprintf(fpStu, "%s\t%s\t%d\t%s", students[len - 1].idNumber, students[stuNum - 1].name, students[stuNum - 1].sex, students[stuNum - 1].status, students[stuNum - 1].adminName);
// 		}	
// 	fclose(fpStu);
// 	return;
// }








/*

//增加一条学生信息
void addStu(struct Student * pHead, char * idNumber, char * name, int sex, char adminName)
{
	struct Student * pStudent = (struct Student *)malloc(sizeof(struct Student));
	strcpy(pStudent->idNumber, idNumber);
	strcpy(pStudent->name, name);
	strcpy(pStudent->sex, sex);
	strcpy(pStudent->adminName, adminName);
	struct Student * pPreviousStudent = pHead;
	struct Student * pNextStudent = pHead->pNext;
	if (pNextStudent == NULL)
	{
		pStudent->pNext = pNextStudent;
		pPreviousStudent->pNext = pStudent;
		return;
	}
	if (strcmp(idNumber, pNextMail->idNumber) < 0)
	{
		pStudent->pNext = pNextStudent;
		pPreviousStudent->pNext = pStudent;
		return;
	}
	if (strcmp(idNumber, pNextMail->idNumber) == 0)
	{
		printf("%s hava already exist!\n", idNumber);
		return;
	}
}
*/