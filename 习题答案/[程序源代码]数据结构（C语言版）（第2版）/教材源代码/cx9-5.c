#include <stdio.h>
typedef struct
{
	int key;     /* ����ؼ��ֵ���������Ϊ����*/ 
	int data;    /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void  BubbleSort(Record r[], int length )
/*�Լ�¼����r��ð������lengthΪ����ĳ���*/
{
	int n,i,j;
	int mark;
	Record temp;
	n=length;  
	for (i=1;i<=n-1;++i ) 
	{
	  mark=0;
	  for (j=1;j<=n-i;++j) 
	  if (r[j].key>r[j+1].key )  
	  {
	   temp=r[j];
	   r[j]=r[j+1];
	   r[j+1]=temp;
	   mark=1;
	  } 
	  if(mark==0)break;		  
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
	BubbleSort(r,len);
	printf("�Ľ��㷨��ð���������\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");
}

�������н����
����������¼�ĳ��ȣ�9���س���
����9����¼�Ĺؼ���ֵ(����֮���ÿո����):
12  62  50  16  24  78  30  6  56���س���
�Ľ��㷨���ð�����������
6  12  16  24  30  50  56  62  78

