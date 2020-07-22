#include <stdio.h>
#define max_len 20 
typedef struct
{
	int  key;     /* ����ؼ��ֵ���������Ϊ����*/ 
	char data;     /*��¼����Ϣ���� */
}Record;

typedef struct
{
	Record  r[max_len+1];  /* r[0]δ��ż�¼ */
	int length;
}seqTable;

int SeqSearch(seqTable  st,  int  k)
/*��˳���st��˳�������ؼ��ֵ���k��Ԫ��,
���ҵ�,����ֵΪ��Ԫ���ڱ��е�λ��,����Ϊ0*/
{
	int i;
	st.r[0].key=k; 
	i=st.length;
	while (st.r[i].key!=k) i- -;
	return(i);
}

void main()
{
	seqTable st;
	int rec,k,i,len,ch;	
	printf("������ұ�ĳ���:");
	scanf("%d",&len);
	st.length=len;
printf("����%d����¼�Ĺؼ���ֵ(�ÿո����):\n",len);
	for(i=1; i<=len; i++)
	{
		scanf(" %d",&ch);
		st.r[i].key = ch;
	}
	printf("����Ҫ���ҵ�Ԫ��:");
	scanf(" %d",&k);
rec=SeqSearch(st,k);
	if(rec==0)
	 printf("��Ԫ�ز�����!\n");
	else
	 printf("��Ԫ���ڱ��е�λ��Ϊ��%d\n",rec);
}

�������н����
������ұ�ĳ��ȣ�8���س���
����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
6   17   8  53  27  98  60  80  ���س���
����Ҫ���ҵ�Ԫ�أ�53���س���
��Ԫ���ڱ��е�λ��Ϊ��4
������Ҫ���ҵ�Ԫ��Ϊ5�������ʾ��Ԫ�ز����ڡ�
