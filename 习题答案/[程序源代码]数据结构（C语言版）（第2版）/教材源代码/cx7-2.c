#define MAX_VEX  100         // 最大顶点数为100
#include <stdio.h> 
#include<malloc.h>
typedef struct node         // 定义表结点
{  
  int adjvex;                  // 邻接顶点域
  struct node *next;         // 指向下一个邻接顶点的指针域
  /*char  info;*/             //若为网图，要表示边上信息，则应增加一个数据域info
} ARCNODE; 
typedef struct vexnode           // 定义头结点
{  
  int vertex;                   // 顶点域
  ARCNODE *firstarc;          // 边表头指针
} VEXNODE;                       //VEXNODE是以邻接表方式存储的图类型

VEXNODE adjlist[MAX_VEX];      /*定义头结点数组*/  
int creatadjlist()              /*建立邻接表*/
{      
    ARCNODE *ptr;
    int arcnum,vexnum,k,v1,v2;
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");
    scanf("%d,%d",&vexnum,&arcnum);    /*输入图的顶点数和边数（弧数）*/ 
    for(k=1;k<=vexnum;k++)
    adjlist[k].firstarc=0;       /*为邻接链表的adjlist数组各元素的链域赋初值*/
    for(k=0;k<arcnum;k++)          /*为adjlist数组的各元素分别建立各自的链表*/
    {
     printf("v1,v2=");
     getchar();
     scanf("%d,%d",&v1,&v2);
     ptr=(ARCNODE*)malloc(sizeof(ARCNODE));  
/*给结点V1 的相邻接结点V2 分配内存空间*/
     ptr->adjvex=v2;     /*将顶点v2插入到链表中，使得结点插入后单链表仍然有序*/
     ptr->next=adjlist[v1].firstarc;
     adjlist[v1].firstarc=ptr;     /*将邻接点V2 插入表头结点V1 之后*/
                                        /*对于有向图，接下来的四行语句要删除*/   
     ptr=(ARCNODE*)malloc(sizeof(ARCNODE));  
/*给结点V2 的相邻接结点V1 分配内存空间*/
     ptr->adjvex=v1;    /*将顶点v1插入到链表中，使得结点插入后单链表仍然有序*/
     ptr->next=adjlist[v2].firstarc;
     adjlist[v2].firstarc=ptr; /*将邻接点V1 插入表头结点V2之后*/
  }
  return(vexnum);
}

main()                    /*主函数*/
{
int i,n;
ARCNODE *p;
n=creatadjlist();              /*建立邻接表并返回顶点个数*/
 printf("所建图的邻接表为:\n");
 for(i=1;i<=n;i++)             /*输出邻接表中个链表的信息*/
 {
   printf("%d==>",i);
   p=adjlist[i].firstarc;
   while(p!=NULL)
   {
     printf("---->%d",p->adjvex);
     p=p->next;
   }
   printf("\n");
 } 
}

/*程序运行结果（以图7.13（a）中的无向图G为例）：
请输入顶点数和边数(输入格式为:顶点数,边数): 4，5（回车）
v1,v2=1，2（回车）
v1,v2=1，3（回车）
v1,v2=1，4（回车）
v1,v2=2，3（回车）
v1,v2=3，4（回车）
所建图的邻接表为:
1==>---->4---->3---->2
2==>---->3---->1
3==>---->4---->2---->1
4==>---->3---->1*/ 
