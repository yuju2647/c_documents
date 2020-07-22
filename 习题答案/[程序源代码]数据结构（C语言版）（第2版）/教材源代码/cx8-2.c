#include <stdio.h>
#define max_len 20 
typedef struct
{
	int  key;     /* ����ؼ��ֵ���������Ϊ����*/ 
	char data;     /*��¼����Ϣ���� */
}Record;
typedef struct
{
	Record r[max_len+1];  /* r[0]Ϊ������Ԫ */
	int length;
}seqTable;

int BinarySearch(seqTable sq,  int k)
/*�������sq���۰������ؼ��ֵ���k��Ԫ�أ�
���ҵ�������ֵΪ��Ԫ���ڱ��е�λ��*/
{
	int low,high,mid;
	low=1;  
	high=sq.length;   /*���ó�ʼ��������*/
	while(low<=high)
	{
		mid=(low+high)/2;
		if(sq.r[mid].key<k)  
		  low=mid+1;     /*�������Ұ�������в���*/
		else
		{ 
         if(sq.r[mid].key>k) 
	       high=mid-1;   /*δ�ҵ�������������������в���*/
	     else            /*���ڴ���Ĺؼ��֣����ҽ���*/
		   break;   
		}	
	}
   if(low>high)  
    return (0);  /*���Ҳ��ɹ�������0��Ϊ������־*/
   else
	return (mid);
}

void main()
{
	seqTable sq;
	int rec,k,i,len,ch;
	printf("������ұ�ĳ���:");
	scanf("%d",&len);
	sq.length = len;
	printf("������ұ�ĵ�%d����¼:\n",len);
	for(i=1;i<=len;i++)
	{
		scanf(" %d",&ch);
		sq.r[i].key=ch;
	}
	printf("������Ҫ���ҵ�Ԫ��:");
	scanf("%d",&k);
	rec=BinarySearch(sq,k);
	if(rec==0)
      printf("�ò��ұ���û��������¼!\n");
	else
      printf("�ü�¼�ڱ��е�λ��Ϊ%d\n",rec);
	}

�������н����
������ұ�ĳ��ȣ�8���س���
����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
5  12  16  20  24  28  31  35  36  42  46  50  58���س���
����Ҫ���ҵ�Ԫ�أ�24���س���
��Ԫ���ڱ��е�λ��Ϊ��5
������Ҫ���ҵ�Ԫ��Ϊ32�������ʾ�ò��ұ���û��������¼��
