#include<malloc.h>
#include<stdio.h>
#define MAX_VEX 50
typedef struct arcnode        /*�������*/
{ 
    int adjvex;
    struct arcnode *next;
}ARCNODE;
typedef struct vexnode        /*����ͷ���*/
{ 
    int vertex;
    ARCNODE *firstarc;
}VEXNODE;

VEXNODE adjlist[MAX_VEX];     /*�����ͷ����adjlist*/
int creatadjlist()            /*�����ڽӱ�*/
{
    ARCNODE *ptr;
    int arcnum,vexnum,k,v1,v2;
    printf("\n�����붥�����ͱ���(�����ʽΪ:������,����):");
    scanf("%d,%d",&vexnum,&arcnum);    /*����ͼ�Ķ������ͻ���(�����)*/
    for(k=1;k<=vexnum;k++)
    {
        adjlist[k].firstarc=NULL;  /*�ڽ������adjlist�����Ԫ�ص����򸳳�ֵ*/
        adjlist[k].vertex=0;        /*���������ȸ���ֵ0*/
    }
    for(k=1;k<=arcnum;k++)       /*Ϊadjlist����ĸ�Ԫ�طֱ������Ե�����*/ 
    { 
        printf("v1,v2 = ");
        scanf("%d,%d",&v1,&v2);        /*���뻡<V1,V2 >*/
        ptr=(ARCNODE*)malloc(sizeof(ARCNODE)); 
/*�����V1 �����ڽ��V2 �����ڴ�ռ�*/     
        ptr->adjvex=v2;
        ptr->next=adjlist[v1].firstarc;
        adjlist[v1].firstarc=ptr;              /*�����ڽ��V2�����ͷ���V1֮��*/
        adjlist[v2].vertex++;                    /*����V2����ȼ�1*/
    }
    return(vexnum);
}

toposort(int n)                  /*���������㷨,nΪͼ�ж���ĸ���*/
{
   int queue[MAX_VEX];
   int front=0,rear=0; 
   int v,w,n1;
   ARCNODE *p; 
   n1=0;
   for(v=1;v<=n;v++)              /*ѭ��������Ϊ0�Ķ��㲢���*/
   if(adjlist[v].vertex==0)  
   {
       rear=(rear+1)%MAX_VEX;
       queue[rear]=v;
   }
   printf("��������Ľ��: \n");
   while(front!=rear)
   {
       front=(front+1)%MAX_VEX;
       v=queue[front];
       printf("%d ",v);            /*������Ϊ0�Ķ��㲢����*/
       n1++;
       p=adjlist[v].firstarc;
       while(p!=NULL)              /*ɾ���ɶ���V���������еĻ�*/
       {
           w=p->adjvex;
           adjlist[w].vertex--;           /*���ڽ��ڶ���V�Ķ������ȼ�1*/
           if(adjlist[w].vertex==0)       /*�����Ϊ0�Ķ������*/
           {
               rear=(rear+1)%MAX_VEX;
               queue[rear]=w;
           }
           p=p->next;                   /*pָ����һ���ڽ��ڶ���V�Ķ���*/
       }
   }
   if(n1<n)           /*����Ķ������С��ͼ�Ķ������������������ʧ��*/
       printf("Not a set of partial order. \n");
}

main()                /*������*/
{ 
   int n;
   n=creatadjlist();  /*�����ڽӱ����ض���ĸ���*/
   toposort(n);       /*���ھ���n�������ͼ������������*/
}
//
//�������н������ͼ7.27��a���е�AOV��Ϊ������
//�����붥�����ͱ���(�����ʽΪ:������,����):7,9���س���
//v1,v2 =1��3���س���
//v1,v2 =1��4���س���
//v1,v2 =2��3���س���
//v1,v2 =2��5���س���
//v1,v2 =3��5���س���
//v1,v2 =4��5���س���
//v1,v2 =4��6���س���
//v1,v2 =5��6���س���
//v1,v2 =5��7���س���
//��������Ľ��:
//1	2	4	3	5	7	6
