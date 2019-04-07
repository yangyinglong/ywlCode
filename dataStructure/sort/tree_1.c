#include <stdio.h>
#include <malloc.h>
#define MaxSize 1000
 
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
 
void LongestPath(BiTree bt)
{
	BiTree p = bt, l[MaxSize], s[MaxSize]; //l, s是栈，元素是二叉树结点指针，l中保留当前最长路径中的结点
	int i,top = 0, tag[MaxSize], longest = 0;
	while (p || top >0)
	{
		while (p)
		{
			s[++top] = p;
			tag[top] = 0;
			p = p->lchild;
		} //沿左分枝向下
		if (tag[top] == 1)    //当前结点的右分枝已遍历
		{
			if (!s[top]->lchild && !s[top]->rchild)  //只有到叶子结点时，才查看路径长度
				if (top>longest)
				{
					for (i = 1; i <= top; i++)
						l[i] = s[i];
					longest = top;
					top--;
				}//保留当前最长路径到l栈，记住最高栈顶指针，退栈
		}
		else if (top>0)
		{
			tag[top] = 1;
			p = s[top]->rchild;
		}   //沿右子分枝向下
	}//while(p!=null||top>0)
	int k = 0;
	for (k = 0; k < longest; k++)
	{
		printf("%d ", l[k]->data);
	}
}//结束LongestPath

void PreOrder(BiTNode * head)
{
	if (head == NULL)
		return;
	printf("---%d ", head->data);
	PreOrder(head->lchild);
	PreOrder(head->rchild);
}


void main()
{
	BiTNode * A = (malloc)(sizeof(BiTNode));
	BiTNode * B = (malloc)(sizeof(BiTNode));
	BiTNode * C = (malloc)(sizeof(BiTNode));
	BiTNode * D = (malloc)(sizeof(BiTNode));
	BiTNode * E = (malloc)(sizeof(BiTNode));
	BiTNode * F = (malloc)(sizeof(BiTNode));
	A->data = 1;
	B->data = 2;
	C->data = 3;
	D->data = 4;
	E->data = 5;
	F->data = 6;
	A->lchild = B;
	A->rchild = C;
	B->lchild = D;
	B->rchild = NULL;
	C->lchild = E;
	C->rchild = NULL;
	D->lchild = F;
	D->rchild = NULL;
	E->rchild = NULL;
	E->lchild = NULL;
	F->rchild = NULL;
	F->lchild = NULL;
	PreOrder(A);
	// LongestPath(A);


}