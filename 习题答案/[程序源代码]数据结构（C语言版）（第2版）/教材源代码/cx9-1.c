#include <stdio.h>
typedef struct
{
	 int key;    /* ����ؼ��ֵ���������Ϊ����*/ 
	 int data;   /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void   insertSort(Record  r[],  int length)
/* �Լ�¼����r��ֱ�Ӳ�������lengthΪ�����д������¼����Ŀ*/
{ 
	  int i,j;
	  for (i=2;  i<=length;  i++) 
	  {
		r[0]=r[i];      /*���������¼��ŵ�������r[0]��*/
		j=i-1;	         
		while (r[0].key< r[j].key )     /* Ѱ�Ҳ���λ�� */
		{
			r[j+1]= r[j]; 
			j=j-1;
		}
		r[j+1]=r[0];		         /*���������¼���뵽�������������*/
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
	  insertSort(r,len);
	  printf("ֱ�Ӳ������������\n");
	  for(i=1;i<=len;i++)
	  printf("%d  ",r[i].key);
	  printf("\n");
}

�������н����
����������¼�ĳ��ȣ�9���س���
����9����¼�Ĺؼ���ֵ(����֮���ÿո����):
38  18  50  80  75  6  15  45  18���س���
�������������
6  15  18  18  38  45  50  75  80

