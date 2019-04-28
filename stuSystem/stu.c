#include <stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct student                        //学生信息存储结构
{
    char no[11];                              //学号
    char name[15];                            //姓名
    int score[3];                             //成绩
    int sum;                                  //总分
    float average;                            //平均分
    int order;                                //按成绩排序
    struct student *next;
} student;

int Menu_select();                            //菜单
struct student *Create(student *head);        //建立
void Print(student *head);                    //打印
struct student *Compute(student *head);       //计算
struct student *Append(student *head);        //追加
struct student *Del(student *head);           //删除
struct student *Insert(student *head);        //插入
struct student *change(student *head);        //修改
void Search(student *head);                   //查找
void Save(student *head);                     //保存文件
struct student *Load(student *head);          //读取文件
struct student *Sort(student *head);
int main()
{
    student *head=NULL;
    while(1)
    {
        switch(Menu_select())
        {
        case 1:
            head=Create(head);
            break;
        case 2:
            Print(head);
            break;
        case 3:
            head=Compute(head);
            break;
        case 4:
            head=Append(head);
            break;
        case 5:
            head=Del(head);
            break;
        case 6:
            head=Insert(head);
            break;
        case 7:
            Search(head);
            break;
        case 8:
            head=change(head);
            break;
        case 9:
            Save(head);
            break;
        case 10:
            head=Load(head);
            break;
        case 11:
            head=Sort(head);
            break;
        case 12:
            exit(0);
        }
    }
    return 0;
}
/*****************************菜单****************************/
int Menu_select()
{
    int choice;
    printf("***************************mune***************\n");
    printf("                        1  add               \n");
    printf("                        2  print               \n");
    printf("                        3  jisuan              \n");
    printf("                        4  addto               \n");
    printf("                        5  delete               \n");
    printf("                        6  charu              \n");
    printf("                        7  Search               \n");
    printf("                        8  change               \n");
    printf("                        9  Save               \n");
    printf("                        10 read               \n");
    printf("                        11 paixu              \n");
    printf("                        12 exit               \n");
    printf("Enter your choice(0-11):");
    scanf("%d",&choice);
    return choice;
}
/*****************************建立链表************************/
struct student *Create(student *head)        //ok
{
    student *p,*q;;
    head=(student *)malloc(sizeof(student));
    head->next=NULL;
    q=head;
    while(1)
    {
        p=(student*)malloc(sizeof(student));
        printf("please enter idNumber:");
        scanf("%s",p->no);
        if(p->no[0]=='@')
        {
            free(p);
            break;
        }
        printf("please enter mane:");
        scanf("%s",p->name);
        printf("please enter math:");
        scanf("%d",&p->score[0]);
        printf("please enter English:");
        scanf("%d",&p->score[1]);
        printf("please enter Node:");
        scanf("%d",&p->score[2]);
        p->sum=0;
        p->average=0;
        p->order=0;
        q->next=p;
        q=p;
    }
    q->next=NULL;
    return head;
}
/*****************************打印****************************/
void Print(student *head)              //ok
{
    student *p=head;
    printf("id  name  math  English  Node    zong  pingjun  paiming\n");
    while(p->next)
    {
        p=p->next;
        printf("%s      %s    %d    %d    %d          %d    %.2f   %d  \n",p->no,p->name,p->score[0],p->score[1],p->score[2],p->sum,p->average,p->order);
    }
}
/*****************************计算****************************/
struct student *Compute(student *head)//OK
{
    student *p=head->next;
    while(p)
    {
        p->sum=p->score[0]+p->score[1]+p->score[2];
        p->average=p->sum/3.0;
        p=p->next;
    }
    return head;
}
/*****************************追加****************************/
struct student *Append(student *head)//OK
{
    student *p,*q=head,*t;
    p=(student*)malloc(sizeof(student));
    printf("please enter a student:\n");
    printf("id:");
    scanf("%s",p->no);
    printf("name:");
    scanf("%s",p->name);
    printf("math:");
    scanf("%d",&p->score[0]);
    printf("English:");
    scanf("%d",&p->score[1]);
    printf("Node:");
    scanf("%d",&p->score[2]);
    p->sum=0;
    p->average=0;
    p->order=0;
    while(q)
    {
        t=q;
        q=q->next;
    }
    t->next=p;
    t=p;
    t->next=NULL;
    return head;
}
/*****************************删除****************************/
struct student *Del(student *head) //OK
{
    char number[11];
    student *p=head,*q;
    printf("id to delete:");
    scanf("%s",number);
    while(p->next&&strcmp(number,p->no))
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    return head;
}
/*****************************插入****************************/
struct student *Insert(student *head)  //ok
{
    char no[11];
    student *p,*q=head,*t;
    printf("enter add student place：");
    scanf("%s",no);
    p=(student *)malloc(sizeof(student));
    printf("enter:\n");
    printf("id:");
    scanf("%s",p->no);
    printf("name:");
    scanf("%s",p->name);
    printf("math:");
    scanf("%d",&p->score[0]);
    printf("English:");
    scanf("%d",&p->score[1]);
    printf("Node:");
    scanf("%d",&p->score[2]);
    p->sum=0;
    p->average=0;
    p->order=0;
    while(q->next&&strcmp(q->next->no,no))
    {
        q=q->next;
        t=q;
    }
    p->next=t->next;
    t->next=p;
    return head;
}
/****************************修改*****************************/
struct student *change(student *head)   //ok
{
    char no[11];
    student *q=head->next;
    printf("id in change:");
    scanf("%s",no);
    while(q&&strcmp(q->no,no))
    {
        q=q->next;
    }
    printf("id:");
    scanf("%s",q->no);
    printf("name:");
    scanf("%s",q->name);
    printf("math:");
    scanf("%d",&q->score[0]);
    printf("English:");
    scanf("%d",&q->score[1]);
    printf("Node:");
    scanf("%d",&q->score[2]);
    return head;
};
/****************************查找*****************************/
void Search(student *head)               //ok
{
    char no[15];
    student *p=head->next;
    printf("id in search:");
    scanf("%s",no);
    while(p&&strcmp(no,p->no))
        p=p->next;
    printf("id  name  math  English  Node    zong  pingjun  paiming\n");
    printf("%s        %s        %d      %d      %d          %d      %.2f           %d  \n",p->no,p->name,p->score[0],p->score[1],p->score[2],p->sum,p->average,p->order);
}
/****************************文件保存*************************/
void Save(student *head)                 //ok
{
    FILE *fp;
    if((fp=fopen("S.txt","w"))==NULL)
    {
        printf("FILE stuFile.txt open FAIL\n");
        getchar();
        exit(1);
    }

    student *p=head->next;
    while(p)
    {
        fprintf(fp,"%s %s %d %d %d %d %f %d\n",p->no,p->name,p->score[0],p->score[1],p->score[2],p->sum,p->average,p->order);
        p=p->next;
    }
    fclose(fp);
}
/****************************文件读取*************************/
struct student *Load(student *head)      //ok
{
    head=(student*)malloc(sizeof(student));
    head->next=NULL;
    FILE *fp;
    if((fp=fopen("S.txt","r"))==NULL)
    {
        printf("FILE stuFile.txt open FAIL\n");
        getchar();
        exit(1);
    }
    student *p=(student*)malloc(sizeof(student));
    student *t;
    head->next=p;
    while(fscanf(fp,"%s%s%d%d%d%d%f%d",p->no,p->name,&p->score[0],&p->score[1],&p->score[2],&p->sum,&p->average,&p->order)==8)
    {
        t=p;
        p=(student*)malloc(sizeof(student));
        t->next=p;
    }
    free(p);
    t->next=NULL;
    fclose(fp);
    return head;
}
/****************************排序*****************************/
struct student *Sort(student *head)
{
    int i=1;
    student *q, *s, *pre ,*p,*a;
    p=head->next;
    q=p->next;
    p->next=NULL;
    while(q)
    {
        s=q;
        q=q->next;
        pre=head;
        p=head->next;
        while(p!=NULL && p->sum > s->sum)
        {
            pre=p;
            p=p->next;
        }
        s->next=p;
        pre->next=s;
    }
    a=head->next;
    while(a)
    {
        a->order=i++;
        a=a->next;
    }
    return head;
}