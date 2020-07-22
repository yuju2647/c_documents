#include <stdio.h>
#define MAX_VEX 100
int creatcost(int cost[][MAX_VEX])    /*cost数组表示带权图的邻接矩阵*/           
{
    int vexnum,arcnum,i,j,k,v1,v2;      /*输入图的顶点数和边数(或弧数)*/
    printf("\n请输入顶点数和边数(输入格式为:顶点数,边数):");
    scanf("%d,%d",&vexnum,&arcnum); 
    for(i=1;i<=vexnum;i++)             /*初始化带权图的邻接矩阵*/
        for(j=1;j<=vexnum;j++)
            cost[i][j]=0;             /*0表示无穷大*/
    for(k=0;k<arcnum;k++) 
    {
        printf("v1,v2= ");
        scanf("%d,%d,%d",&v1,&v2);  /*输入所有边(或弧)的一对顶点V1,V2*/
        cost[v1][v2]=1;
        /*cost[v2][v1]=1;*/      /*若建立无向图的邻接矩阵则应加上此句*/
    } 
    return(vexnum);
}

main()
{
 int i,j,vexnum;
 int cost[MAX_VEX][MAX_VEX]; 
 vexnum=creatcost(cost);
 printf("所建图的邻接矩阵为:\n");
 for(i=1;i<=vexnum;i++)
 {
   for(j=1;j<=vexnum;j++)
   printf("%3d",cost[i][j]);
   printf("\n");
 }
}

程序运行结果（以图7.9中的有向图为例）：
请输入顶点数和边数(输入格式为:顶点数,边数): 4，4（回车）
v1,v2=1，2（回车）
v1,v2=1，3（回车）
v1,v2=3，4（回车）
v1,v2=4，1（回车）
所建图的邻接矩阵为:
0  1  1  0
0  0  0  0
0  0  0  1
1  0  0  0
