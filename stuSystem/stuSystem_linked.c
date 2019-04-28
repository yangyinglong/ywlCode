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

void printHead();
int PrintAllNode(struct PLHead * pstHead);
struct PLHead * CreatePLHead();
int DestoryPLHead(struct PLHead * pstHead);
struct Student * CreateNewNode(struct Student * pstDate);
int DestoryNode(struct Student * pstNode);
int InsertStudentAtTail(struct PLHead * pstHead, struct Student * pstNewNode);
int RemoveStudent(struct PLHead * pstHead, struct Student * pstNewNode);
struct Student *SearchNodeById(struct PLHead *pstHead, char *idNumber);


int main(int argc, char const *argv[])
{
	int sex = 0;
	struct PLHead *pstHead = CreatePLHead();
	struct Student *pstNew = NULL;        //pstNew 作为新节点，用来存储新插入的节点
	struct Student NodeData = {""};          //定义一个节点的变量， //在新插入节点的时候用来存储新节点的内容

	// strcpy(NodeData.idNumber, "0001");
	// strcpy(NodeData.name, "Make");
	// sex = 1;
	// strcpy(NodeData.adminName, "Zhang");
	pstNew = CreateNewNode(&NodeData);       //将新的变量赋值给新的节点
	InsertStudentAtTail(pstHead, pstNew);    //将新的节点插入到链表的尾部



	char order;          //用来输入命令
	int sign = 1;        //作为循环继续1或退出0的标记
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
			inputCharArr(idNumber, 6);
			printf("please input a name endwith enter: ");
			inputCharArr(name, 10);
			printf("please input an adminName endwith enter: ");
			inputCharArr(adminName, 10);
			printf("please input a sex(0 or 1) endwith enter: ");
			scanf("%d", &sex);

		}
	}
	return 0;
}




/*
  在终端打印出
  ---------------------------------
  |idNumber       |Name   |Sex    |
 */
void printHead()
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
	printHead();
	struct Student *pstNode = NULL;
	if(NULL == pstHead)
	{
		return -1;
	}
	pstNode = pstHead ->pstFirst;
	while(pstNode != NULL)
	{
		printf("-");
		printf("\n|");
		printf("%s\t", pstNode->idNumber);
		printf("|");
		printf("%s\t", pstNode->name);
		printf("|");
		printf("%d\t", pstNode->sex);
		printf("|");
		printf("%s\t", pstNode->adminName);
		printf("|\n");
	}
	printf("-");
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
		DestoryNode(pstNode);pstNode = pstNext;
	}
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
// 		fscanf(fpStu, "%s%s%d%d%s", students[stuNum].idNumber, students[stuNum].name, &students[stuNum].sex, &students[stuNum].status, students[stuNum].adminName);
// 		pstHead -> len ++;
// 	}
// 	fclose(fpStu);
// 	return len;
// }


//创建一个节点
struct Student * CreateNewNode(struct Student * pstDate)
{
	struct Student * pstNew = NULL;
	pstNew = (struct Student *)malloc(sizeof(struct Student));
	if(NULL == pstNew)
	{
		printf("Error malloc failed\n");
		return NULL;
	}
	if(pstDate != NULL)
	{
		memcpy(pstNew, pstDate, sizeof(struct Student));
		pstNew->pstNext = NULL;}
	else
	{
		memset(pstNew, 0, sizeof(struct Student));
	}
	return pstNew;
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


int InsertStudentAtTail(struct PLHead * pstHead, struct Student * pstNewNode)
{
	struct Student *pstLast = NULL;
	if(NULL == pstHead || NULL == pstNewNode)		//先判断输入参数是否合法
	{
		return -1;
	}
	pstLast = pstHead -> pstFirst;
	while(pstLast = NULL)
	{
		if(NULL = pstLast -> pstNext)
		{
			break;
		}
		pstLast = pstLast -> pstNext;
	}
	if(pstLast = NULL)
	{
		pstHead -> pstFirst = pstNewNode;
	}
	else
	{
		pstLast -> pstNext = pstNewNode;
	}
	pstNode -> pstNext = NULL;
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
		if(NULL = pstPrev)
		{
			return -1;
		}
		else
		{
			pstPrev -> pstNext = pstNode -> pstNext;
			pstNode -> pstNext = NULL;
		}
	}
	pstHead = len --;      //移除成功后，表中元素少一，所以表长减一
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