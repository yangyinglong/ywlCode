#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct mail
{
	char name[10];
	char phone[11];
	struct mail * pNext;
};

int main(int argc, char const *argv[])
{
	char pP;
	struct mail * pHead;
	struct mail * pTail;
	struct mail * pNew = (struct mail * )malloc(sizeof(struct mail));
	pHead = pNew;
	pTail = pNew;
	pNew->pNext = NULL;

	struct mail * pA = (struct mail * )malloc(sizeof(struct mail));
	strcpy(pA->name, "aaa");
	strcpy(pA->phone, "1111");
	pTail->pNext = pA;
	pA->pNext = NULL;
	pTail = pA;

	struct mail * pB = (struct mail * )malloc(sizeof(struct mail));
	strcpy(pB->name, "bbb");
	strcpy(pB->phone, "2222");
	pTail->pNext = pB;
	pB->pNext = NULL;
	pTail = pB;

	struct mail * pC = (struct mail * )malloc(sizeof(struct mail));
	strcpy(pC->name, "ccc");
	strcpy(pC->phone, "3333");
	pTail->pNext = pC;
	pC->pNext = NULL;
	pTail = pC;

	//用户输入name,在链表中进行查找，判断是否存在
	scanf("Please input the name you want search: %s", &pP);
	printf("%s\n", pP);
	struct mail * p1 = pHead;
	while(p1->pNext != NULL)
	{
		if(strcmp(p1->pNext->name, pP) = 0)
		{
			printf("Search success!\n");
			break;
		}
		else
		{
			p1 = p1->pNext;
		}
	}

	//遍历链表,并且打印链表
	struct mail * p1 = pHead;
	while (p1->pNext != NULL)
	{
		p1 = p1->pNext;
		printf("%s\t%s\n", p1->name, p1->phone);
	}

}