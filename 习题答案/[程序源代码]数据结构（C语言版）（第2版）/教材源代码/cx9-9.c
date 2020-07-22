#include <stdio.h>
typedef struct
{
	int key;      /* ��ؼ��ֵ���������Ϊ����*/ 
	char data;   /* ���¼����Ϣ�����������Ϊ�ַ���*/
}Record;

void Merge(Record r1[], int low, int mid, int high,Record r2[])
/* ��֪r1[low..mid]��r1[mid+1..high]�ֱ𰴹ؼ����������У�
�����Ǻϲ���һ���������У������r2[low..high] */
{ 
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while ( (i<=mid)&&(j<=high)  )
	{
		if ( r1[i].key<=r1[j].key )
		{
			r2[k]=r1[i];
			++i;
		}
		else 
		{
			r2[k]=r1[j];
			++j;
		}
		++k;
	}
	while( i<=mid )
	{
		r2[k]=r1[i];
		k++;
		i++;
	}
	while( j<=high)
	{
		r2[k]=r1[j];
		k++;
		j++;
	}
} /* Merge */ 

void   MSort(Record  r1[],  int  low,  int  high,  Record  r3[])
/* r1[low..high]������������r3[low..high]�У�r2[low..high]Ϊ�����ռ� */ 
{
	int mid;
	Record  r2[20];
	if ( low==high ) 
		r3[low]=r1[low];
	else
	{
		mid=(low+high)/2;
        MSort(r1,low, mid, r2);
        MSort(r1,mid+1,high, r2);
        Merge (r2,low,mid,high, r3);
	}
} 

void   MergeSort ( Record  r[],  int  n )
/* �Լ�¼����r[1..n]���鲢���� */ 
{
	MSort (r,1,n,r);
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
	MergeSort(r,len);
	printf("��·�鲢���������\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");
}

//�������н����
//����������¼�ĳ��ȣ�8���س���
//����8����¼�Ĺؼ���ֵ(����֮���ÿո����):
//36 28 43  65  56��5  18  12���س���
//�鲢���������
//5   12   18   28   36   43   56   65
