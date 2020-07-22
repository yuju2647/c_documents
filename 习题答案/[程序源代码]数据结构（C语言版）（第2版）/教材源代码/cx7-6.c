#include <stdio.h>
#define MAX_VEX 50
typedef struct edges        /*����߼�����Ԫ�ؽṹ*/
{ 
    int bv,ev,w;
}EDGES;
EDGES edgeset[MAX_VEX];     /*����߼�����,���ڴ洢ͼ�ĸ�����*/

int createdgeset()             /*�����߼����麯��*/
{
    int arcnum,i;
    printf("\n�����������ı���: ");
    scanf("%d",&arcnum);       /*����ͼ�еı���*/
    for(i=1;i<=arcnum;i++)
    {
      printf("bv,ev,w = ");     /*����ÿ���ߵ����յ㼰���ϵ�Ȩֵ*/
      scanf("%d,%d,%d",&edgeset[i].bv,&edgeset[i].ev,&edgeset[i].w);
    }
    return(arcnum);            /*����ͼ�еı���*/
}

sort(int n)  /*�Ա߼����鰴Ȩֵ��������,����nΪ����Ԫ�صĸ���,��ͼ�ı���*/
{
    int i,j;
    EDGES t;
    for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
         if(edgeset[i].w>edgeset[j].w)
         { 
          t=edgeset[i];
          edgeset[i]=edgeset[j];
          edgeset[j]=t;
         }
}

int seeks(int set[],int v)     /*ȷ������V���ڵ���ͨ�����ĸ����*/
{ 
    int i=v;
    while(set[i]>0)
    i=set[i];
    return(i); 
}

kruskal(int e) /*Kruskal�㷨����С������,����eΪ�߼������еı���*/
{
    int set[MAX_VEX],v1,v2,i;
    printf("Kruskal�㷨�������С������: \n"); 
    for(i=1;i<=MAX_VEX;i++)
     set[i]=0;      /*set����ĳ�ֵΪ0,��ʾÿһ�������Գ�һ������*/
    i=0;               /*i��ʾ����ȡ���������еı��ڱ߼������е��±�*/
    while(i<e)
    {
        v1=seeks(set,edgeset[i].bv);  /*ȷ���ߵ���ʼ�������ڵ���ͨ�����ĸ����*/
        v2=seeks(set,edgeset[i].ev);  /*ȷ���ߵ���ֹ�������ڵ���ͨ�����ĸ����*/
        if(v1!=v2)  /*�������������������㲻��ͬһ��ͨ����ʱ,���ñ߼���������*/
        {
            printf("(%d,%d) %d\n",edgeset[i].bv,edgeset[i].ev,edgeset[i].w);
            set[v1]=v2;           /*��v1,v2 ��Ϊ��ͬһ��ͨ������*/ 
        }
        i++;
    }
}

main()                             /*������*/
{
   int i,arcnum;
   arcnum=createdgeset();          /*����ͼ�ı߼�����,���������еı���*/
   sort(arcnum);                   /*�Ա߼����鰴Ȩֵ��������*/
   printf("��Ȩֵ��С�����������Ϣ: "); 
   printf("\nbv   ev   w \n");
   for(i=1;i<=arcnum;i++)           /*��������ı߼�����*/
   printf("%d    %d    %d\n",edgeset[i].bv,edgeset[i].ev,edgeset[i].w);
   kruskal(arcnum);                /*���ÿ�³˹�����㷨��ͼ����С������*/
}

�������н������ͼ7.24�е�AͼΪ������
�����������ı���: 10���س���
bv,ev,w =1��2��6���س���
bv,ev,w =1��3��5���س���
bv,ev,w =1��6��1���س���
bv,ev,w =2��4��3���س���
bv,ev,w =2��6��5���س���
bv,ev,w =3��5��2���س���
bv,ev,w =3��6��5���س���
bv,ev,w =4��5��6���س���
bv,ev,w =4��6��6���س���
bv,ev,w =5��6��4���س���
��Ȩֵ��С�����������Ϣ:
bv   ev   w
1    6    1
3    5    2
2    4    3
5    6    4
1    3    5
3    6    5
2    6    5
4    5    6
4    6    6
1    2    6
Kruskal�㷨�������С������:
(1��6)  1
(3��5)  2
(2��4)  3
(5��6)  4
(2��6)  5
