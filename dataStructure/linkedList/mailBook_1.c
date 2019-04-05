#include <stdio.h>
#include <malloc.h>

typedef struct mail
{
	char name[10];
	char phone[11];
	struct mail * pNext;
};



int main(int argc, char const *argv[])
{
	// 初始化
	struct mail * pHead;
	struct mail * pTail;
	struct mail * pNew = (struct mail *)malloc(sizeof(struct mail));
	pHead = pNew;
	pTail = pNew;
	pNew->pNext = NULL;

	// 加入一个节点
	// 1 申请内存空间
	struct mail * pA = (struct mail *)malloc(sizeof(struct mail));
	// 2 初始化内存空间
	strcpy(pA->name, "aaa");
	strcpy(pA->phone, "1111");
	pTail->pNext = pA;
	pA->pNext = NULL;
	pTail = pA;

	// 再加入一个
	struct mail * pB = (struct mail *)malloc(sizeof(struct mail));
	strcpy(pB->name, "bbb");
	strcpy(pB->phone, "2222");
	pTail->pNext = pB;
	pB->pNext = NULL;
	pTail = pB;

	// 再加入一个
	struct mail * pD = (struct mail *)malloc(sizeof(struct mail));
	strcpy(pD->name, "ddd");
	strcpy(pD->phone, "4444");
	pTail->pNext = pD;
	pD->pNext = NULL;
	pTail = pD;

	// 插入正确的位置
	struct mail * pC = (struct mail *)malloc(sizeof(struct mail));
	strcpy(pC->name, "ccc");
	strcpy(pC->phone, "3333");
	// 1. 申明一个指针，指向头结点
	struct mail * p1 = pHead;
	// 情况一：插入的节点比第一个节点小
	if (strcmp(p1->pNext->name, pC->name) > 0)
	{
		pC->pNext = p1->pNext;
		p1->pNext = pC;
	}
	// 情况三：插入的节点在第一个节点之后，最后一个节点之前
	p1 = p1->pNext;
	while (p1->pNext != NULL)
	{
		if (strcmp(p1->name, pC->name) <= 0 && strcmp(p1->pNext->name, pC->name) > 0)
		{
			pC->pNext = p1->pNext;
			p1->pNext = pC;
			break;
		}
		else
		{
			p1 = p1->pNext;
		}
	}
	// 情况二：插入的节点比最后一个节点大
	if (strcmp(pTail->name, pC->name) < 0)
	{if (strcmp(pTail->name, pC->name) < 0)
	{
		pTail->pNext = pC;
		pC->pNext = NULL;
		pTail = pC;
	}
		pTail->pNext = pC;
		pC->pNext = NULL;
		pTail = pC;
	}
	


	// 遍历链表
	// 1. 申明一个指针，指向头结点
	struct mail * p2 = pHead;
	while(p2->pNext != NULL)
	{
		p2 = p2->pNext;
		printf("%s\t%s\n", p2->name, p2->phone);

	}


	return 0;
}