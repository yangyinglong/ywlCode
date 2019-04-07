// 链表分为单链表、双向链表、循环链表等
// 链表分为头指针链表和头结点链表.
// 下面编写头结点单链表相关的操作:链表的添加、删除、链表转置
 
// 链表的转置:将旧的链表从头位置取下一个节点,然后以头插法的方式追加到新的链表上.直到将旧的链表的节点全部取完. 这种方式是最简单的.

#include <stdio.h>
#include <malloc.h>

typedef struct LinkNode
{
	int number;
	struct LinkNode *next;
}LinkNode;

LinkNode *list_init()
{
	LinkNode *start = (LinkNode*)malloc(sizeof(LinkNode));
	start->next = NULL;
	return start;
}

void *list_add(LinkNode *start, int number)
{
	LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
	node->number = number;
	node->next = start->next;
	start->next = node;
}

void list_print(LinkNode *start)
{
	LinkNode *p = start->next;
	while(p)
	{
		printf("%d ", p->number);
		p = p->next;
	}
	printf("\n");
}

LinkNode *list_search(LinkNode *start, int target)
{
	LinkNode *p = start->next;
	while(p)
	{
		if (p->number == target)
		{	
			return p;			 
		}
		p = p->next;
	}
	return NULL;

}

void list_destory(LinkNode *start)
{
	LinkNode *p = start->next;
	while(p)
	{
		start->next = p->next;
		free(p);
		p = start->next;
	}
	free(start);
}

void list_del(LinkNode *start, LinkNode *node)
{
	LinkNode *p = start->next;
	LinkNode *q = start;
	while(p)
	{
		if (p->number == node->number)
		{
			q->next = p->next;
			free(p);
			return;
		}
		p = p->next;
		q = q->next;
	}
}

LinkNode *list_pop(LinkNode *start)
{
	LinkNode *p = start->next;
	if (p)
	{
		start->next = p->next;
		return p;
	}
	return NULL;
}

void *list_push(LinkNode *start, LinkNode *node)
{
	node->next = start->next;
	start->next = node;
}

LinkNode *list_transp(LinkNode *start)
{
	LinkNode *new_start = list_init();
	LinkNode *p;
	while((p=list_pop(start)) != NULL)
	{
		list_push(new_start, p);
	}
	return new_start;
}

int main()
{
	LinkNode *start = list_init();
    list_add(start, 1);
    list_add(start, 2);
    list_add(start, 3);
    list_add(start, 4);
    list_add(start, 5);
    list_print(start);
    LinkNode *node = list_search(start, 3);
    printf("target = %d\n", node->number);
    LinkNode *del_node = (LinkNode*)malloc(sizeof(LinkNode));
    del_node->number = 3;
    del_node->next = NULL;
    printf("---------------\n");
    list_del(start, del_node);
    list_print(start);
    list_push(start, del_node);
    list_print(start);
    LinkNode *transp = list_transp(start);
    list_print(transp);
    list_destory(start);
	return 0;
}