#include <stdio.h>
#define MAX_VEX 100
int creatcost(int cost[][MAX_VEX])    /*cost�����ʾ��Ȩͼ���ڽӾ���*/           
{
    int vexnum,arcnum,i,j,k,v1,v2;      /*����ͼ�Ķ������ͱ���(����)*/
    printf("\n�����붥�����ͱ���(�����ʽΪ:������,����):");
    scanf("%d,%d",&vexnum,&arcnum); 
    for(i=1;i<=vexnum;i++)             /*��ʼ����Ȩͼ���ڽӾ���*/
        for(j=1;j<=vexnum;j++)
            cost[i][j]=0;             /*0��ʾ�����*/
    for(k=0;k<arcnum;k++) 
    {
        printf("v1,v2= ");
        scanf("%d,%d,%d",&v1,&v2);  /*�������б�(��)��һ�Զ���V1,V2*/
        cost[v1][v2]=1;
        /*cost[v2][v1]=1;*/      /*����������ͼ���ڽӾ�����Ӧ���ϴ˾�*/
    } 
    return(vexnum);
}

main()
{
 int i,j,vexnum;
 int cost[MAX_VEX][MAX_VEX]; 
 vexnum=creatcost(cost);
 printf("����ͼ���ڽӾ���Ϊ:\n");
 for(i=1;i<=vexnum;i++)
 {
   for(j=1;j<=vexnum;j++)
   printf("%3d",cost[i][j]);
   printf("\n");
 }
}

�������н������ͼ7.9�е�����ͼΪ������
�����붥�����ͱ���(�����ʽΪ:������,����): 4��4���س���
v1,v2=1��2���س���
v1,v2=1��3���س���
v1,v2=3��4���س���
v1,v2=4��1���س���
����ͼ���ڽӾ���Ϊ:
0  1  1  0
0  0  0  0
0  0  0  1
1  0  0  0
