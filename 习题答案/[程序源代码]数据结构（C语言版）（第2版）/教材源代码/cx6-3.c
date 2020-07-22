#include <stdio.h>
#define MAXLEN 100
typedef struct                         	// ����ṹ��
{	int weight;                      	// ����һ������Ȩֵ����
		int lchild,rchild,parent;     	// �������Һ��Ӽ�˫��ָ��
}HTNode;
typedef HTNode HFMT [MAXLEN];     	// ��������
int n;
void InitHFMT (HFMT  T)             	// ��ʼ��  
{	int i;
		printf ("\n\t\t�����빲�ж��ٸ�Ȩֵ (С��100)��");
		scanf ("%d",&n);getchar();
		for (i=0; i<2*n-1; i++)
		{	T[i].weight=0;
			T[i].lchild=-1;
			T[i].rchild=-1;
			T[i].parent=-1;
		}
}
void InputWeight(HFMT T)           	// ����Ȩֵ
{	int w;
		int i;
		for (i=0; i<n;i++)
		{	printf ("\n\t\t�����%d��Ȩֵ:",i+1);
			scanf ("%d",&w);getchar();
			T[i].weight=w;  }
}
void SelectMin (HFMT T, int i, int *p1,int *p2)  // ѡ�����������С�Ľ��
{	long min1=999999;           		// Ԥ������ֵ����ʹ�����ڿ��ܳ��ֵ����Ȩֵ
		long min2=999999;           
		int j;
		for (j=0;j<=i;j++)
		{  if (T[j].parent==-1)
			{ if (min1>T[j].weight)
				{	min1=T[j].weight;  	// �ҳ���С��Ȩֵ
					*p1=j;            	// ͨ��*p1�������
				}
			}
		}
		for (j=0;j<=i;j++)
		{ if (T[j].parent==-1)
			{ if (min2>T[j].weight&&j!=(*p1))
				{ min2=T[j].weight;     	// �ҳ�����С��Ȩֵ
					*p2=j;	          	// ͨ��*p2�������
				}
			}
		}
}                                      	// ѡ�����

void CreatHFMT (HFMT T)       		// �������������T[2*n-1]Ϊ������
{	int i,p1,p2;
		InitHFMT (T);
		InputWeight (T);
		for  (i=n;i<2*n-1;i++)
		{	SelectMin (T,i-1,&p1,&p2);
			T[p1].parent=T[p2].parent=i;
			T[i].lchild=T[p1].weight;
			T[i].rchild=T[p2].weight;
			T[i].weight=T[p1].weight+T[p2].weight;
		}
}

void PrintHFMT (HFMT T)            	// �������״̬��
{	
     printf("\n\t\t���������ĸ�����ʾ��");
int i,k=0;
		for (i=0; i<2*n-1; i++)
while (T[i].lchild!=-1)
			{   if (!(k%2))
	printf ("\n");				 
printf("\t\t(%d,%d),(%d,%d)",
T[i].weight,T[i].lchild,T[i].weight,T[i].rchild);
				k++;break;
			}
     printf("\n\n");
}

void hfnode (HFMT T,int i,int j)
{	j=T[i].parent;
		if (T[j].rchild==T[i].weight) 
			printf("1");
		else               
			printf("0");
		if(T[j].parent!= -1) 
			i=j,hfnode (T,i,j);
}
void huffmannode (HFMT T)            	// �����������
{ 	
printf("\t\t�����Ȩֵ�Ķ�Ӧ���������룺");
int i,j,a,k=0;
		for (i=0;i<n;i++)
		{	j=0;
			a=i;
			if (!(k%2))
				printf ("\n");
 		printf("\t\t%i: ",T[i].weight);k++;
			hfnode(T,i,j);
			i=a;
		}
}

void main()                        		// ������
{	HFMT HT;
		CreatHFMT(HT);
		PrintHFMT(HT);
huffmannode(HT);
		printf("\n	");
}
