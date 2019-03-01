#include<stdio.h>
#include<stdlib.h>

typedef struct Bitnode{
    int data;
    struct Bitnode *lchild,*rchild;
}Bitnode;

void BST_insert(Bitnode **T,int key){
    if(*T==NULL){
        *T = (Bitnode*)malloc(sizeof(Bitnode));
        (*T)->data = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;

    }
    if(key==((*T)->data)){
        return;
    }
    else if(key<((*T)->data)){
        BST_insert(&((*T)->lchild),key);
    }
    else{
        BST_insert(&((*T)->rchild),key);
    }

}

void preorder(Bitnode *T){
    if(T!=NULL){
            printf(" %d \n",T->data);
            preorder(T->lchild);
            preorder(T->rchild);
    }
}

void levelorder(Bitnode *T){
    int rear = -1,front = -1;
    Bitnode *Queue[10];
    Queue[++rear] = T;
    Bitnode *p;

    while(front<rear){
          p = Queue[++front];
          printf(" %d ",p->data);
          if(p->lchild){
                Queue[++rear] = p->lchild;
          }
          if(p->rchild){
                Queue[++rear] = p->rchild;
          }

    }

}

void leftview(Bitnode *T){
    int rear = -1,front = -1,last = 0;
    Bitnode *Queue[10];
    int i;
    for(i=0;i<10;i++){
        Queue[i] =NULL;
    }
    Queue[++rear] = T;
    Bitnode *p;
    Bitnode *q;
    printf(" %d ",T->data);
    while(front<rear){
          p = Queue[++front];
          //printf(" %d ",p->data);
          if(p->lchild){
                Queue[++rear] = p->lchild;
          }
          if(p->rchild){
                Queue[++rear] = p->rchild;
          }

          if(front==last){
                q = Queue[++front];
                printf(" %d ",q->data);
                front--;
                last = rear;
          }
    }

}

int main(){
    Bitnode *T=NULL;
    int a[8] = {5,2,1,3,4,7,6,8};
    int i = 0;
    while(i<8){
        BST_insert(&T,a[i]);
        i++;
    }
    leftview(T);

}
