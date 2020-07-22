#define MAX_VEX  100   // ��󶥵���Ϊ100
#include <stdio.h> 
#include<malloc.h>
typedef struct node       // �������
{  
  int adjvex;            // �ڽӶ�����
  struct node *next;      // ָ����һ���ڽӶ����ָ����
  /*char   info;*/      //��Ϊ��ͼ��Ҫ��ʾ������Ϣ����Ӧ����һ��������info
 }ARCNODE; 
       
typedef struct vexnode    // ����ͷ���
{  
  int vertex;           // ������
  ARCNODE *firstarc;   // �߱�ͷָ��
}VEXNODE;            // VEXNODE�����ڽӱ�ʽ�洢��ͼ����

VEXNODE adjlist[MAX_VEX];   /*����ͷ�������*/  
int creatadjlist()                 /*�����ڽӱ�*/
{      
    ARCNODE *ptr;
    int arcnum,vexnum,k,v1,v2;
    printf("�����붥�����ͱ���(�����ʽΪ:������,����):");
    scanf("%d,%d",&vexnum,&arcnum);   /*����ͼ�Ķ������ͱ�����������*/
    for(k=1;k<=vexnum;k++)
    adjlist[k].firstarc=0;          /*Ϊ�ڽ������adjlist�����Ԫ�ص����򸳳�ֵ*/
    for(k=0;k<arcnum;k++)        /*Ϊadjlist����ĸ�Ԫ�طֱ������Ե�����*/
    {
     printf("v1,v2=");
     scanf("%d,%d",&v1,&v2);
     ptr=(ARCNODE*)malloc(sizeof(ARCNODE));
/*�����V1 �����ڽӽ��V2 �����ڴ�ռ�*/
     ptr->adjvex=v2;    /*������v2���뵽�����У�ʹ�ý������������Ȼ����*/
     ptr->next=adjlist[v1].firstarc;
     adjlist[v1].firstarc=ptr; /*���ڽӵ�V2 �����ͷ���V1 ֮��*/
	                                      /*��������ͼ�����������������Ҫɾ��*/   
     ptr=(ARCNODE*)malloc(sizeof(ARCNODE));  
/*�����V2 �����ڽӽ��V1 �����ڴ�ռ�*/
     ptr->adjvex=v1;    /*������v1���뵽�����У�ʹ�ý������������Ȼ����*/
     ptr->next=adjlist[v2].firstarc;
     adjlist[v2].firstarc=ptr;    /*���ڽӵ�V1 �����ͷ���V2֮��*/
  }
  return(vexnum);
}

void dfs(int v)
{
int w;
ARCNODE *p;
p= adjlist[v].firstarc;
printf("%d   ",v);  /*������ʶ���*/
adjlist[v].vertex=1;  /*�����־����1�������Ѿ����ʹ�*/
while(p!=NULL)
{
w=p->adjvex;   /*ȡ������V��ĳ�ڽӵ�����*/
if(adjlist[w].vertex==0)
dfs(w);   /*����ö���δ���ʹ���ݹ���ã��Ӹö���������������ĸ��ڽӵ���������*/
  p=p->next;
 }
}

main()                    /*������*/
{
 int i,n,v;
 ARCNODE *p;
 n=creatadjlist();           /*�����ڽӱ����ض������*/
 printf("����ͼ���ڽӱ�Ϊ:\n");
 for(i=1;i<=n;i++)          /*����ڽӱ��и��������Ϣ*/
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
 printf("�����������������ʼ����v:");
 scanf("%d",&v);
 printf("ͼ�����������������DFS :");
 dfs(v);
}

�������н������ͼ7.17��a���е�����ͼΪ������
�����붥�����ͱ���(�����ʽΪ:������,����): 8��9���س���
v1,v2=1��2���س���
v1,v2=1��3���س���
v1,v2=2��4���س���
v1,v2=2��5���س���
v1,v2=3��6���س���
v1,v2=3��7���س���
v1,v2=6��7���س���
v1,v2=4��8���س���
v1,v2=5��8���س���
����ͼ���ڽӱ�Ϊ:
1==>---->3---->2
2==>---->5---->4---->1
3==>---->7---->6---->1
4==>---->8---->2
5==>---->8---->2
6==>---->7---->3
7==>---->6---->3
8==>---->5---->4
�����������������ʼ����v: 1���س���
ͼ�����������������DFS :1  3  7  6  2  5  8  4
