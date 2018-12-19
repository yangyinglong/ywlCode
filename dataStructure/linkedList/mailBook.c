// 链表实现通讯录
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>

typedef struct mail
{
	char name[10];
	char phone[12];
	struct mail * pNext;
};

struct mail * createList();
void insertMail(struct mail * pHead, char * name, char * phone);
void deleteMail(struct mail * pHead, char * name);
void printList(struct mail * pHead);

int main()
{
	char * name1 = "zhao";
	char * name2 = "han";
	char * name3 = "zzho";
	char * name4 = "an";
	char * phone1 = "111";
	struct mail * pMailBook = createList();
	printList(pMailBook);
	printf("\n");
	insertMail(pMailBook, name1, phone1);
	insertMail(pMailBook, name2, phone1);
	insertMail(pMailBook, name3, phone1);
	insertMail(pMailBook, name4, phone1);
	insertMail(pMailBook, name3, phone1);
	printList(pMailBook);
	printf("\n");
	deleteMail(pMailBook, name3);
	printList(pMailBook);
	printf("\n");
	deleteMail(pMailBook, name3);
	printList(pMailBook);
	printf("\n");
	deleteMail(pMailBook, name1);
	printList(pMailBook);
	return 0;

}

struct mail * createList()
{
	struct mail * pHead = (struct mail *)malloc(sizeof(struct mail));
	struct mail * pTail = pHead;
	pTail->pNext = NULL;
	for (int i = 0; i < 1; ++i)
	{
		struct mail * pNew = (struct mail *)malloc(sizeof(struct mail));
		strcat(pNew->name, "cang");
		strcpy(pNew->phone, "15968161237");
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

// 增加一个
void insertMail(struct mail * pHead, char * name, char * phone)
{
	struct mail * pMail = (struct mail *)malloc(sizeof(struct mail));
	strcpy(pMail->name, name);
	strcpy(pMail->phone, phone);

	struct mail * pPreviousMail = pHead;
	struct mail * pNextMail = pHead->pNext;

	if (strcmp(name, pNextMail->name) < 0)
	{
		pMail->pNext = pNextMail;
		pPreviousMail->pNext = pMail;
		return;
	}
	if (strcmp(name, pNextMail->name) == 0)
	{
		printf("%s hava already exist!\n", name);
		return;
	}

	pPreviousMail = pNextMail;
	pNextMail = pNextMail->pNext;
	while(NULL != pNextMail)
	{
		if (strcmp(name, pPreviousMail->name) > 0 && strcmp(name, pNextMail->name) < 0)
		{
			pMail->pNext = pNextMail;
			pPreviousMail->pNext = pMail;
			return;
		}
		if (strcmp(name, pNextMail->name) == 0)
		{
			printf("%s hava already exist!\n", name);
			return;
		}
		pPreviousMail = pNextMail;
		pNextMail = pNextMail->pNext;
	}
	pMail->pNext = pNextMail;
	pPreviousMail->pNext = pMail;
	return;

}

// 删除一个
void deleteMail(struct mail * pHead, char * name)
{
	struct mail * pPreviousMail = pHead;
	struct mail * pMail = pHead->pNext;
	while(NULL != pMail)
	{
		if (strcmp(pMail->name, name) == 0)
		{
			pPreviousMail->pNext = pMail->pNext;
			printf("delete %s success\n", name);
			free(pMail);
			return;
		}
		pPreviousMail = pPreviousMail->pNext;
		pMail = pMail->pNext;
	}
	printf("no one name %s", name);
	return;
}


void printList(struct mail * pHead)
{
	struct mail * pMail = pHead->pNext;
	printf("\tMailBook\n");
	while(NULL != pMail) 
	{
		printf("name: %s\tphone: %s\n", pMail->name, pMail->phone);
		pMail = pMail->pNext;
	}
	return;
}