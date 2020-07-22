#include <stdio.h>
typedef struct
{
	  int key;     /* ����ؼ��ֵ���������Ϊ����*/ 
	  int data;    /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void BinsertSort (Record  r[],  int length)
/*�Լ�¼����r�����۰��������lengthΪ����ĳ���*/
{
	 int i,j;
	 Record x;
	 int low,high,mid;
	 for ( i=2; i<=length ; ++i ) 
	 {
		x= r[i];
		low=1;  high=i-1;
		while (low<=high )   /* ȷ������λ��*/ 
		{
			mid=(low+high) / 2;
			if (  x.key< r[mid].key   )    
			 high=mid-1;
			else 
			 low=mid+1;
		}
		for (j=i-1;j>=low;--j )   
		 r[j+1]= r[j];       /*  ��¼��������ƶ� */ 
		r[low]=x;     /* �����¼ */ 
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
		r[i].key = j;
	  }
	  BinsertSort(r,len);
	  printf("���ֲ������������\n");
	  for(i=1;i<=len;i++)
	  printf("%d  ",r[i].key);
	  printf("\n");
}

�������н����
����������¼�ĳ��ȣ�8���س���
����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
6   17   8  53  27  98  60  80  ���س���
���ֲ������������
6  8  17   27  53  60  80  98
