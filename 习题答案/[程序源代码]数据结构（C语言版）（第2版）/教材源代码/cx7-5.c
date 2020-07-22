#include<stdio.h>
#define MAX_VEX 50
int creatcost(int cost[][MAX_VEX])       /*cost�����ʾ��Ȩͼ���ڽӾ���*/           
{
    int vexnum,arcnum,i,j,k,v1,v2,w;     /*����ͼ�Ķ������ͱ���(����)*/
    printf("\n�����붥�����ͱ���(�����ʽΪ:������,����): ");
    scanf("%d,%d",&vexnum,&arcnum); 
    for(i=1;i<=vexnum;i++)             /*��ʼ����Ȩͼ���ڽӾ���*/
        for(j=0;j<=vexnum;j++)
            cost[i][j]=32767;          /*32767��ʾ�����*/
    for(k=1;k<=arcnum;k++) 
    {
        printf("v1,v2,w = ");
        scanf("%d,%d,%d",&v1,&v2,&w); /*�������б�(��)��һ�Զ���V1,V2��Ȩֵ*/
        cost[v1][v2]=w;
        cost[v2][v1]=w; 
    } 
    return(vexnum);
}

void prime(int cost[][MAX_VEX],int vexnum)  
 /*Prime�㷨�����Ӷ���V1 ��ʼ����С������*/
{
    int lowcost[MAX_VEX],closevert[MAX_VEX],i,j,k,min; 
    for(i=1;i<=vexnum;i++) 
    {
        lowcost[i]=cost[1][i];           /*��ʼ��*/
        closevert[i]=1;                 /*��ʼ��*/
    }
    closevert[1]= -1;                    /*V1ѡ��U*/
    for(i=2;i<=vexnum;i++)             /*��U֮������U��ĳһ��������Ķ���*/
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
            {                          /*����߼���Ȩֵ*/
                printf("(%d,%d)%2d\n",closevert[k],k,lowcost[k]); 
                closevert[k]=-1;          /*kѡ��U*/
                for(j=2;j<=vexnum;j++)
                    if(closevert[j]!=-1&&cost[k][j]<lowcost[j])
                    {
                        lowcost[j]=cost[k][j];  /*��k�ļ���,�޸�lowcost����*/
                        closevert[j]=k;          /*k���뵽U��*/
                    }
            }
    }
}

main()    /*������*/
{
    int vexnum;
    int cost[MAX_VEX][MAX_VEX];
    vexnum=creatcost(cost);                     /*����ͼ���ڽӾ���*/ 
    printf("Prim�㷨�������С�������ı߼���Ȩֵ: \n");
    prime(cost,vexnum);
}

�������н������ͼ7.23�е�AͼΪ������
�����붥�����ͱ���(�����ʽΪ:������,����): 6,10���س���
v1,v2,w =1��2��6���س���
v1,v2,w =1��3��1���س���
v1,v2,w =1��4��5���س���
v1,v2,w =2��3��5���س���
v1,v2,w =2��5��3���س���
v1,v2,w =3��4��5���س���
v1,v2,w =3��5��6���س���
v1,v2,w =3��6��4���س���
v1,v2,w =4��6��2���س���
v1,v2,w =5��6��6���س���
Prim�㷨�������С�������ı߼���Ȩֵ: 
(1��3) 1
(3��6) 4
(6��4) 2
(3��2) 5
(2��5) 3
