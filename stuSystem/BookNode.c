/*
双向链表的使用：图书管理
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BookNode
{
    char name[20];
    char author[20];
    float price;
    int num;
}

struct BLHead
{
    int len;

    struct BookNode *pstFirst;
}

int main(int argc, char *argv[])
{

    return 0;
}

/**
 创建一个节点
 */
struct BookNode *CreateBokNode(struct BookNode *BookData)
{
    struct BookNode *pstNode = NULL;
    pstNode = (struct BookNode *)mallo(sizeof(struct BookNode));
    if(NULL == pstNode)
    {
        return NULL;
    }
    if(NULL = BookData)
    {
        memset(pstNode, 0, sizeof(struct BookNode));
    }
    else 
    {
        memcpy(pstNode, 0, sizeof(struct BookNode));
        pstNode -> pstNext = NULL;
        pstNode -> pstPrev = NULL;
    }
    return pstNode;
}

/**
 销毁一个节点
 */
int DestroyBookNode(struct BookNode *pstNode)
{
    if(pstNode != NULL)
    {
        free(pstNode);
        pstNode = NULL;
    }

/**
 创建一个头结点，即一个空表
 */
struct BLHead *CreatBLHead()
{
    struct BLHead *pstNode = NULL;

    pstNode = (struct BLHead*)malloc(sizeof(struct BLHead));
    if(NULL == pstNode)
    {
        return NULL;
    }
    memset(pstNode, 0, sizeof(struct *BLHead));

    return pstNode;
}

/**
 销毁头节点，即整个链表被销毁
*/
int DestroyBLHead(struct BLHead *pstHead)
{
    struct BookNode *pstNode = NULL;
    struct BookNode *pstNext = NULL;
    if(NULL == pstHead)
    {
        return -1;
    }
    pstNode = pstHead -> pstfirst;
    while(pstNode != NULL)
    {
        pstNext = pstNode -> pstNext;
        DestroyBookNode(pstNode);
        pstNode = pstNext;
    }
    free(pstHead);
    pstHead = NULL;
    return 0;
}

/*
 插入:总是在链表的第一个位置插入
**/
int InsertNewNodeAtFirst(struct BLHead *pstHead, struct BookNode *pstNew)
{
    struct BookNode *pstNode = NULL;
    if(NULL == pstHead || NULL == pstNew)
    {
        return -1;
    }
    pstNode = pstHead -> pstFirst;
    pstHead -> pstFirst = pstNew;

    pstNew -> pstNext = pstNode;
    pstNew -> pstPrev = NULL;
    pstNode -> pstPrev = pstNew;
    return 0;
}

/*
 通过书名来查找
**/
struct BookNode *SearchNodeByName(struct BLHead *pstHead, char *name)
{
    struct BookNode *pstNode = NULL;
    if(NULL == pstHead || NULL == name)
    {
        return -1;
    }
    pstNode = pstHead ->pstFirst;
    while(pstNode != NULL)
    {
        if(strcmp(pstNode -> name, name) = 0)
        {
            break;
        }
        pstNode = pstNode -> pstNext;
    }
    return pstNode;
}

/*
 打印所有节点
**/
int PrintAllNode(struct BLHead *pstHead)
{
    struct BookNode *pstNode = NULL;
    if(NULL == pstHead)
    {
        return -1;
    }
    pstNode = pstHead -> pstFirst;
    while(pstNode != NULL)
    {
        printf("BookName: %s Author: %s Price: %.2f Num: %d\n",
                pstNode -> name,
                pstNode -> author,
                pstNode -> price,
                pstNode -> num);
        pstNode = pstNode -> pstNext;
    }
}