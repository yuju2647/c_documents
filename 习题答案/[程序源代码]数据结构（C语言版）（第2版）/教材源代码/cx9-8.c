#include <stdio.h>
typedef struct
{
	int key;    /* ����ؼ��ֵ���������Ϊ����*/ 
	int data;   /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void   sift(Record r[],int k, int m)
/* ����r[k..m]����r[k]Ϊ������ȫ���������ҷֱ���r[2k]��r[2k+1]Ϊ
����������С���ѣ�����r[k]��ʹ��������r[k..m]����ѵ����� */
{
	Record t;
	int i,j;
	int x;
	int finished;
	t= r[k];   /* �ݴ�"��"��¼r[k] */ 
	x=r[k].key;
	i=k;
	j=2*i;
	finished=0;
		while(j<=m&&!finished  ) 
		{     
		if(j<m&&r[j].key>r[j+1].key ) 
		j=j+1;  /* �������������������������Ĺؼ���С�������ҷ�֧"ɸѡ" */
		if (x<=r[j].key)
		 finished=1;       /*  ɸѡ���  */ 
		else 
		{
			r[i] = r[j];
			i=j;
			j=2*i;
		}               /* ����ɸѡ */ 
		}
		r[i] =t; /* r[k]���뵽ǡ����λ�� */ 
}  

void   creatheap(Record r[], int length )
/*�Լ�¼����r���ѣ�lengthΪ����ĳ���*/
{
	int i,n;
    n=length;
	for(i=n/2;i>=1;--i)   /* �Ե�[n/2]����¼��ʼ����ɸѡ���� */ 
	sift(r,i,n);
}

void  HeapSort(Record  r[],int length)
/* ��r[1..n]���ж�����ִ�б��㷨��r�м�¼���ؼ����ɴ�С�������� */ 
{
	int i,n;
	Record b;
	creatheap(r, length);
	n=length;
	for (i=n;i>=2;--i) 
	{
		b=r[i];              /* ���Ѷ���¼�Ͷ��е����һ����¼���� */ 
		r[i]= r[1];
		r[1]=b; 
		sift(r,1,i-1);  /* ���е�����ʹr[1..i-1]��ɶ� */ 
	}
}

void main()
{
	int i,j;
	Record r[20];
	int len;
	printf("����������¼�ĳ���:");
	scanf("%d",&len);
    printf("����%d����¼�Ĺؼ���ֵ(����֮���ÿո����):\n",len);
	for(i=1;i<=len;i++)
	{
		scanf(" %d",&j);
		r[i].key=j;
	}
	HeapSort(r,len);
	printf("�����������\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");	
}

�������н����
����������¼�ĳ��ȣ�8���س���
����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
53  36  48  36  60  7  18  41���س���
�����������
60  53  48  	41  36  36  18  7
