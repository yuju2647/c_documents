#include<stdio.h>
#define MAX_VEX 50
int creatcost(int cost[][MAX_VEX]) /*建立图的邻接矩阵,cost数组表示图的邻接矩阵*/
{
    int vexnum,arcnum,i,j,k,v1,v2,w;   /*输入图的顶点数和弧数(或边数)*/
    printf("\n请输入顶点数和边数(输入格式为:顶点数,边数): ");
    scanf("%d,%d",&vexnum,&arcnum); 
    for(i=1;i<=vexnum;i++)
        for(j=1;j<=vexnum;j++)
            cost[i][j]=9999;          /*设9999代表无限大*/
    for(k=1;k<=arcnum;k++) 
    { 
        printf("v1,v2,w = ");
        scanf("%d,%d,%d",&v1,&v2,&w);  /*输入所有边或所有弧的一对顶点V1,V2 */
        cost[v1][v2]=w; 
    } 
    return(vexnum);
}

void dijkstra(int cost[][MAX_VEX],int vexnum) 
/*Dijkstra算法求从源点出发的最短路径*/
{ 
   int path[MAX_VEX],s[MAX_VEX],dist[MAX_VEX],i,j,w,v,min,v1;
   /*S数组用于记录顶点V是否已经确定了最短路径,S[V]=1,顶点V已经确定了最短路径,S[V]=0,顶点V尚未确定最短路径。dist数组表示当前求出的从V1 到Vi 的最短路径。path是路径数组,其中path[i]表示从源点到顶点Vi之间的最短路径上Vi的前驱顶点,如有路径(v1,v3,v5),则path[5]=3*/
   printf("输入源点 v1 : ");
   scanf("%d",&v1);                      /*输入源点V1 */
   for(i=1;i<=vexnum;i++)
   {
       dist[i]=cost[v1][i];    /*初始时,从源点V1到各顶点的最短路径为相应弧上的权*/
       s[i]=0;               /*初始化*/
       if(cost[v1][i]<9999)
         path[i]=v1;        /*初始化,path记录当前最短路径,即顶点的直接前趋*/
   }
   s[v1]=1;                     /*将源点加入S集合中*/
   for(i=1;i<=vexnum;i++)
   {
       min=9999;                      /*本例设各边上的权值均小于9999*/
       for(j=1;j<=vexnum;j++)          /*从S集合外找出距离源点最近的顶点w*/
         if((s[j]==0)&&(dist[j]<min))
          {
            min=dist[j];
            w=j;
          }
       s[w]=1;                  /*将w加入S集合,即w已是求出最短路径的顶点*/
       for(v=1;v<=vexnum;v++)      /*根据w修改dist[]*/
        if(s[v]==0)                   /*修改未加入的顶点的路径长度*/
          if(dist[w]+cost[w][v]<dist[v])
           {
             dist[v]=dist[w]+cost[w][v]; /*修改V-S集合中各顶点的最短路径长度*/
             path[v]=w;             /*修改V-S集合中各顶点的最短路径*/
           }
    }
    printf("源点1到其他各顶点的路径与值：\n",v1);
     for(i=2;i<=vexnum;i++)      /*输出从某源点到其他各顶点的最短路径*/
       if(s[i]==1)
        {
            w=i;
            while(w!=v1)
            {
                printf("%d<--",w);
                w=path[w];        /*通过找到前驱顶点,反向输出最短路径*/
            }
            printf("%d",w);
            printf("   %d\n",dist[i]);
        }
        else
        {
            printf("%d<--%d",i,v1);
	    printf("   9999\n");         /*不存在路径时,路径长度设为9999*/
        }
}

main()                          /*主程序*/
{
    int vexnum;
    int cost[MAX_VEX][MAX_VEX];
    vexnum=creatcost(cost);     /*建立图的邻接矩阵*/
    dijkstra(cost,vexnum);
}
程序运行结果（以图7.25中的图为例）：
请输入顶点数和边数(输入格式为:顶点数,边数): 6,11（回车）
v1,v2,w = 1，2，50（回车）
v1,v2,w = 1，3，10（回车）
v1,v2,w = 1，5，45（回车）
v1,v2,w = 2，3，15（回车）
v1,v2,w = 2，5，10（回车）
v1,v2,w = 3，1，20（回车）
v1,v2,w = 3，4，15（回车）
v1,v2,w = 4，2，20（回车）
v1,v2,w = 4，5，35（回车）
v1,v2,w = 5，4，30（回车）
v1,v2,w = 6，4，3 （回车）
输入源点v1 : 1（回车）
源点1到其他各顶点的路径与值 :
2<--4<--3<--1   45
3<--1   10
4<--3<--1   25
5<--1   45
6<--1   9999
