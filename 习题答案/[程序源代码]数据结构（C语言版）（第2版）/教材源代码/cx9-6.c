#include <stdio.h>
typedef struct
{
int key;     /* �����¼�Ĺؼ��������������Ϊ����*/ 
char data;    /* �����¼����Ϣ�����������Ϊ�ַ���*/
}Record;

int Partition(Record r[],int left,int right) 
/*�Լ�¼����r�е�r[left]��r[right]���ֽ���һ�˿������򣬲��õ������λ�ã������Ľ��������֮��ǰ���ļ�¼�Ĺؼ��־���С�ڣ����ڣ��������¼*/
{ 
	Record temp;
	int low,high;
	temp=r[left];             /* ѡ�������¼*/ 
	low=left;  
	 high=right;
	 while ( low<high )
	 {
	   while (low< high && r[high].key>=temp.key )
/* high���ҵ�����С��temp.key�ļ�¼*/
		high--;
	   if ( low <high ) /*�ҵ�С��temp.key�ļ�¼������н���*/ 
	   { 
		 r[low]= r[high];
		 low++;
	   } 
	  while (low<high && r[low].key<temp.key )
/*low�������Ҵ���temp.key�ļ�¼*/
	  low++; 
	  if (low<high)/* �ҵ�����temp.key�ļ�¼���򽻻�*/
	  { 
		 r[high]= r[low];
		 high--; 
	  } 
	 }
	 r[low]=temp;    /*�������¼���浽low=high��λ��*/
	 return low;      /*���������¼��λ��*/
} 

void quicksort(Record r[],int low, int high )
/*�Լ�¼����r[low..high]�ÿ��������㷨��������*/
{
	int pos;
	 if(low<high)
	 {
	  pos=Partition(r, low, high);/*����һ�˿������򣬽�����Ԫ��Ϊ�绮�������ӱ�*/
	  quicksort(r, low, pos-1);     /*�����ӱ��������*/
	  quicksort(r, pos+1, high); /*���Ҳ��ӱ��������*/
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
	quicksort(r,1,len);
	printf("�������������\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");	
}


�������н����
����������¼�ĳ��ȣ�8���س���
����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
72   75   60   27   92   15   12   48���س���
�������������
12  15  27  48  60  72   75   92
