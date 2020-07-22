#define MAX_VEX  100   // 最大顶点数为100
#include <stdio.h> 
#include<malloc.h>
typedef struct node       // 定义表结点
{  
  int adjvex;            // 邻接顶点域
  struct node *next;      // 指向下一个邻接顶点的指针域
  /*char   info;*/       //若为网图，要表示边上信息，则应增加一个数据域info
 }ARCNODE; 
       
typedef struct vexnode     // 定义头结点
{  
  int vertex;             // 顶点域
  ARCNODE * firstarc;   // 边表头指针
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

void bfs(int v)   /*从某顶点V出发按广度优先搜索进行图的遍历*/
{
 int queue[MAX_VEX];
 int front=0,rear=1;
 ARCNODE *p;
 p=adjlist[v].firstarc;
 printf("%d   ",v);   /*访问初始顶点*/
 adjlist[v].vertex=1;
 queue[rear]=v;
 while(front!=rear)
{
  front=(front+1)%MAX_VEX;
  v=queue[front];      /*按访问次序依次出队*/
  p=adjlist[v].firstarc;   /*查找V的邻接点*/
  while(p!=NULL)
  {
   if(adjlist[p->adjvex].vertex==0)
	{
	  adjlist[p->adjvex].vertex=1;
	  printf("%d   ",p->adjvex);   /*访问该点并使之入队*/
	  rear=(rear+1)%MAX_VEX;
     queue[rear]=p->adjvex;
	}
	p=p->next;   /*查找V的下一邻接点 */
  }
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
 printf("输入广度优先搜索起始顶点v:");
 scanf("%d",&v);
 printf("图的广度优先搜索序列BFS :");
 bfs(v);
}

程序运行结果（以图7.20（a）中的无向图为例）：
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
输入广度优先搜索起始顶点v: 1（回车）
图的广度优先搜索序列BFS :1  3  2  7  6  5  4  8 
/*==========再运行一次的结果========*/
请输入顶点数和边数(输入格式为:顶点数,边数): 8，9（回车）
v1,v2=8，5（回车）
v1,v2=8，4（回车）
v1,v2=7，6（回车）
v1,v2=7，3（回车）
v1,v2=6，3（回车）
v1,v2=5，2（回车）
v1,v2=4，2（回车）
v1,v2=3，1（回车）
v1,v2=2，1（回车）
所建图的邻接表为:
1==>---->2---->3
2==>---->1---->4---->5
3==>---->1---->6---->7
4==>---->2---->8
5==>---->2---->8
6==>---->3---->7
7==>---->3---->6
8==>---->4---->5
输入广度优先搜索起始顶点v: 1（回车）
图的广度优先搜索序列BFS :1  2  3  4  5  6  7  8 
