#include <stdio.h>
typedef struct
{
	 int key;     /* ����ؼ��ֵ���������Ϊ����*/ 
	 int data;    /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void  ShellInsert(Record r[], int length,  int  d)
/*�Լ�¼����r��һ��ϣ����������lengthΪ����ĳ���,dΪ����*/
{
	  int i,j;
	  for(i=1+d;i<= length; i++)  /* 1+dΪ��һ�������еĵڶ���Ԫ�ص��±� */
		if(r[i].key < r[i-d].key)
		{
			r[0]= r[i];           /*  ����r[i]  (����������) */
				for(j=i-d; j>0 &&r[0].key < r[j].key; j-=d)
					r[j+d]= r[j];
					r[j+d]= r[0];
		}
}

void  ShellSort(Record r[], int length, int d[], int n)
/*�Լ�¼����r��ϣ������lengthΪ����r�ĳ��ȣ�d Ϊ�������飬nΪd[]�ĳ��� */
{ 
	  int i;
	  for(i=0 ;  i<=n-1;  ++i)
	  ShellInsert(r, length, d[i]);
}

void main()
{
	  int i,j;
	  Record r[20];
	  int len,d[3]={5,3,1};
	  printf("����������¼�ĳ���:");
	  scanf("%d",&len);
	  printf("����%d����¼�Ĺؼ���ֵ(����֮���ÿո����):\n",len);
	  for(i=1;i<=len;i++)
	  {
		scanf(" %d",&j);
		r[i].key = j;
	  }
	  ShellSort(r,len,d,3);
	  printf("ϣ���������\n");
	  for(i=1;i<=len;i++)
	  printf("%d  ",r[i].key);
	  printf("\n");
}

�������н����
����������¼�ĳ��ȣ�10���س���
����10����¼�Ĺؼ���ֵ(����֮���ÿո����):
38  18  50  80  75  6  15  45  18���س���
ϣ�����������
5  10  20  30  40  40  50  60  70  80
