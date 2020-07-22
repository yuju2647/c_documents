#define MAX_VEX  100   // 最大顶点数为100
#include <stdio.h> 
#include<malloc.h>
typedef struct node       // 定义表结点
{  
  int adjvex;            // 邻接顶点域
  struct node *next;      // 指向下一个邻接顶点的指针域
  /*char   info;*/      //若为网图，要表示边上信息，则应增加一个数据域info
 }ARCNODE; 
       
typedef struct vexnode    // 定义头结点
{  
  int vertex;           // 顶点域
  ARCNODE *firstarc;   // 边表头指针
}VEXNODE;            // VEXNODE是以邻接表方式存储的图类型

VEXNODE adjlist[MAX_VEX];   /*定义头结点数组*/  
int creatadjlist()                 /*建立邻接表*/
{      
    ARCNODE *ptr;
    int arcnum,vexnum,k,v1,v2;
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");
    scanf("%d,%d",&vexnum,&arcnum);   /*输入图的顶点数和边数（弧数）*/
    for(k=1;k<=vexnum;k++)
    adjlist[k].firstarc=0;          /*为邻接链表的adjlist数组各元素的链域赋初值*/
    for(k=0;k<arcnum;k++)        /*为adjlist数组的各元素分别建立各自的链表*/
    {
     printf("v1,v2=");
     scanf("%d,%d",&v1,&v2);
     ptr=(ARCNODE*)malloc(sizeof(ARCNODE));
/*给结点V1 的相邻接结点V2 分配内存空间*/
     ptr->adjvex=v2;    /*将顶点v2插入到链表中，使得结点插入后单链表仍然有序*/
     ptr->next=adjlist[v1].firstarc;
     adjlist[v1].firstarc=ptr; /*将邻接点V2 插入表头结点V1 之后*/
	                                      /*对于有向图，接下来的四行语句要删除*/   
     ptr=(ARCNODE*)malloc(sizeof(ARCNODE));  
/*给结点V2 的相邻接结点V1 分配内存空间*/
     ptr->adjvex=v1;    /*将顶点v1插入到链表中，使得结点插入后单链表仍然有序*/
     ptr->next=adjlist[v2].firstarc;
     adjlist[v2].firstarc=ptr;    /*将邻接点V1 插入表头结点V2之后*/
  }
  return(vexnum);
}

void dfs(int v)
{
int w;
ARCNODE *p;
p= adjlist[v].firstarc;
printf("%d   ",v);  /*输出访问顶点*/
adjlist[v].vertex=1;  /*顶点标志域置1，表明已经访问过*/
while(p!=NULL)
{
w=p->adjvex;   /*取出顶点V的某邻接点的序号*/
if(adjlist[w].vertex==0)
dfs(w);   /*如果该定点未访问过则递归调用，从该顶点出发，沿着它的各邻接点向下搜索*/
  p=p->next;
 }
}

main()                    /*主函数*/
{
 int i,n,v;
 ARCNODE *p;
 n=creatadjlist();           /*建立邻接表并返回顶点个数*/
 printf("所建图的邻接表为:\n");
 for(i=1;i<=n;i++)          /*输出邻接表中个链表的信息*/
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
 printf("输入深度优先搜索起始顶点v:");
 scanf("%d",&v);
 printf("图的深度优先搜索序列DFS :");
 dfs(v);
}

程序运行结果（以图7.17（a）中的无向图为例）：
请输入顶点数和边数(输入格式为:顶点数,边数): 8，9（回车）
v1,v2=1，2（回车）
v1,v2=1，3（回车）
v1,v2=2，4（回车）
v1,v2=2，5（回车）
v1,v2=3，6（回车）
v1,v2=3，7（回车）
v1,v2=6，7（回车）
v1,v2=4，8（回车）
v1,v2=5，8（回车）
所建图的邻接表为:
1==>---->3---->2
2==>---->5---->4---->1
3==>---->7---->6---->1
4==>---->8---->2
5==>---->8---->2
6==>---->7---->3
7==>---->6---->3
8==>---->5---->4
输入深度优先搜索起始顶点v: 1（回车）
图的深度优先搜索序列DFS :1  3  7  6  2  5  8  4
