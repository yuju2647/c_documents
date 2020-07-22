#include<stdio.h>
#define MAX_VEX 50
int creatcost(int cost[][MAX_VEX])       /*cost数组表示带权图的邻接矩阵*/           
{
    int vexnum,arcnum,i,j,k,v1,v2,w;     /*输入图的顶点数和边数(或弧数)*/
    printf("\n请输入顶点数和边数(输入格式为:顶点数,边数): ");
    scanf("%d,%d",&vexnum,&arcnum); 
    for(i=1;i<=vexnum;i++)             /*初始化带权图的邻接矩阵*/
        for(j=0;j<=vexnum;j++)
            cost[i][j]=32767;          /*32767表示无穷大*/
    for(k=1;k<=arcnum;k++) 
    {
        printf("v1,v2,w = ");
        scanf("%d,%d,%d",&v1,&v2,&w); /*输入所有边(或弧)的一对顶点V1,V2和权值*/
        cost[v1][v2]=w;
        cost[v2][v1]=w; 
    } 
    return(vexnum);
}

void prime(int cost[][MAX_VEX],int vexnum)  
 /*Prime算法产生从顶点V1 开始的最小生成树*/
{
    int lowcost[MAX_VEX],closevert[MAX_VEX],i,j,k,min; 
    for(i=1;i<=vexnum;i++) 
    {
        lowcost[i]=cost[1][i];           /*初始化*/
        closevert[i]=1;                 /*初始化*/
    }
    closevert[1]= -1;                    /*V1选入U*/
    for(i=2;i<=vexnum;i++)             /*从U之外求离U中某一顶点最近的顶点*/
    {
        min=32767;
        k=0;
        for(j=1;j<=vexnum;j++)
            if(closevert[j]!=-1&&lowcost[j]<min)
            { 
                min=lowcost[j];
                k=j;
            }
            if(k)
            {                          /*输出边及其权值*/
                printf("(%d,%d)%2d\n",closevert[k],k,lowcost[k]); 
                closevert[k]=-1;          /*k选入U*/
                for(j=2;j<=vexnum;j++)
                    if(closevert[j]!=-1&&cost[k][j]<lowcost[j])
                    {
                        lowcost[j]=cost[k][j];  /*由k的加入,修改lowcost数组*/
                        closevert[j]=k;          /*k加入到U中*/
                    }
            }
    }
}

main()    /*主程序*/
{
    int vexnum;
    int cost[MAX_VEX][MAX_VEX];
    vexnum=creatcost(cost);                     /*建立图的邻接矩阵*/ 
    printf("Prim算法构造的最小生成树的边及其权值: \n");
    prime(cost,vexnum);
}

程序运行结果（以图7.23中的A图为例）：
请输入顶点数和边数(输入格式为:顶点数,边数): 6,10（回车）
v1,v2,w =1，2，6（回车）
v1,v2,w =1，3，1（回车）
v1,v2,w =1，4，5（回车）
v1,v2,w =2，3，5（回车）
v1,v2,w =2，5，3（回车）
v1,v2,w =3，4，5（回车）
v1,v2,w =3，5，6（回车）
v1,v2,w =3，6，4（回车）
v1,v2,w =4，6，2（回车）
v1,v2,w =5，6，6（回车）
Prim算法构造的最小生成树的边及其权值: 
(1，3) 1
(3，6) 4
(6，4) 2
(3，2) 5
(2，5) 3
