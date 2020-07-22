#include<malloc.h>
#include<stdio.h>
#define MAX_VEX 50
typedef struct arcnode        /*定义表结点*/
{ 
    int adjvex;
    struct arcnode *next;
}ARCNODE;
typedef struct vexnode        /*定义头结点*/
{ 
    int vertex;
    ARCNODE *firstarc;
}VEXNODE;

VEXNODE adjlist[MAX_VEX];     /*定义表头向量adjlist*/
int creatadjlist()            /*建立邻接表*/
{
    ARCNODE *ptr;
    int arcnum,vexnum,k,v1,v2;
    printf("\n请输入顶点数和边数(输入格式为:顶点数,边数):");
    scanf("%d,%d",&vexnum,&arcnum);    /*输入图的顶点数和弧数(或边数)*/
    for(k=1;k<=vexnum;k++)
    {
        adjlist[k].firstarc=NULL;  /*邻接链表的adjlist数组各元素的链域赋初值*/
        adjlist[k].vertex=0;        /*各顶点的入度赋初值0*/
    }
    for(k=1;k<=arcnum;k++)       /*为adjlist数组的各元素分别建立各自的链表*/ 
    { 
        printf("v1,v2 = ");
        scanf("%d,%d",&v1,&v2);        /*输入弧<V1,V2 >*/
        ptr=(ARCNODE*)malloc(sizeof(ARCNODE)); 
/*给结点V1 的相邻结点V2 分配内存空间*/     
        ptr->adjvex=v2;
        ptr->next=adjlist[v1].firstarc;
        adjlist[v1].firstarc=ptr;              /*将相邻结点V2插入表头结点V1之后*/
        adjlist[v2].vertex++;                    /*顶点V2的入度加1*/
    }
    return(vexnum);
}

toposort(int n)                  /*拓扑排序算法,n为图中顶点的个数*/
{
   int queue[MAX_VEX];
   int front=0,rear=0; 
   int v,w,n1;
   ARCNODE *p; 
   n1=0;
   for(v=1;v<=n;v++)              /*循环检测入度为0的顶点并入队*/
   if(adjlist[v].vertex==0)  
   {
       rear=(rear+1)%MAX_VEX;
       queue[rear]=v;
   }
   printf("拓扑排序的结果: \n");
   while(front!=rear)
   {
       front=(front+1)%MAX_VEX;
       v=queue[front];
       printf("%d ",v);            /*输出入度为0的顶点并计数*/
       n1++;
       p=adjlist[v].firstarc;
       while(p!=NULL)              /*删除由顶点V出发的所有的弧*/
       {
           w=p->adjvex;
           adjlist[w].vertex--;           /*将邻接于顶点V的顶点的入度减1*/
           if(adjlist[w].vertex==0)       /*将入度为0的顶点入队*/
           {
               rear=(rear+1)%MAX_VEX;
               queue[rear]=w;
           }
           p=p->next;                   /*p指向下一个邻接于顶点V的顶点*/
       }
   }
   if(n1<n)           /*输出的顶点个数小于图的顶点个数，则拓扑排序失败*/
       printf("Not a set of partial order. \n");
}

main()                /*主程序*/
{ 
   int n;
   n=creatadjlist();  /*建立邻接表并返回顶点的个数*/
   toposort(n);       /*对于具有n个顶点的图进行拓扑排序*/
}
//
//程序运行结果（以图7.27（a）中的AOV网为例）：
//请输入顶点数和边数(输入格式为:顶点数,边数):7,9（回车）
//v1,v2 =1，3（回车）
//v1,v2 =1，4（回车）
//v1,v2 =2，3（回车）
//v1,v2 =2，5（回车）
//v1,v2 =3，5（回车）
//v1,v2 =4，5（回车）
//v1,v2 =4，6（回车）
//v1,v2 =5，6（回车）
//v1,v2 =5，7（回车）
//拓扑排序的结果:
//1	2	4	3	5	7	6
