#include <stdio.h>
typedef struct
{
	int key;    /* ����ؼ��ֵ���������Ϊ����*/ 
	int data;   /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void  SelectSort(Record r[], int length)
/*�Լ�¼����r����ѡ������lengthΪ����ĳ���*/
{
	int i,j,k;
	int n;
	Record temp;
    n=length;
	for (i=1;i<=n-1;++i)  
	{
		k=i;
		for (j=i+1;j<=n;++j) 
		 if (r[j].key<r[k].key ) 
		   k=j;
		  if (k!=i) 
		  { 
			temp=r[i]; 
			r[i]=r[k];
			r[k]=temp;
		  }
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
	SelectSort(r,len);
	printf("��ѡ�����������\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");
}

�������н����
����������¼�ĳ��ȣ�8���س���
����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
53  36  48  36  60  7  18  41���س���
��ѡ�����������
7  18  36  36  41  48  53	60
