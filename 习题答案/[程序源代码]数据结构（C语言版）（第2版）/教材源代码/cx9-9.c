#include <stdio.h>
typedef struct
{
	int key;      /* 设关键字的数据类型为整型*/ 
	char data;   /* 设记录的信息域的数据类型为字符型*/
}Record;

void Merge(Record r1[], int low, int mid, int high,Record r2[])
/* 已知r1[low..mid]和r1[mid+1..high]分别按关键字有序排列，
将它们合并成一个有序序列，存放在r2[low..high] */
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
/* r1[low..high]经过排序后放在r3[low..high]中，r2[low..high]为辅助空间 */ 
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
/* 对记录数组r[1..n]做归并排序 */ 
{
	MSort (r,1,n,r);
}

void main()
{
	int i,j;
	Record r[20];
	int len;
	printf("输入待排序记录的长度:");
	scanf("%d",&len);
    printf("输入%d个记录的关键字值(数据之间用空格隔开):\n",len);
	for(i=1;i<=len;i++)
	{
		scanf(" %d",&j);
		r[i].key=j;
	}
	MergeSort(r,len);
	printf("二路归并排序输出：\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");
}

//程序运行结果：
//输入待排序记录的长度：8（回车）
//输入8个记录的关键字值(数据之间用空格隔开):
//36 28 43  65  56，5  18  12（回车）
//归并排序输出：
//5   12   18   28   36   43   56   65
