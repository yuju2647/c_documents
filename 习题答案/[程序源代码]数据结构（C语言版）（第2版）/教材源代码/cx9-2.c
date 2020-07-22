#include <stdio.h>
typedef struct
{
	  int key;     /* 假设关键字的数据类型为整型*/ 
	  int data;    /* 假设记录的信息域的数据类型为字符型*/
}Record;

void BinsertSort (Record  r[],  int length)
/*对记录数组r进行折半插入排序，length为数组的长度*/
{
	 int i,j;
	 Record x;
	 int low,high,mid;
	 for ( i=2; i<=length ; ++i ) 
	 {
		x= r[i];
		low=1;  high=i-1;
		while (low<=high )   /* 确定插入位置*/ 
		{
			mid=(low+high) / 2;
			if (  x.key< r[mid].key   )    
			 high=mid-1;
			else 
			 low=mid+1;
		}
		for (j=i-1;j>=low;--j )   
		 r[j+1]= r[j];       /*  记录依次向后移动 */ 
		r[low]=x;     /* 插入记录 */ 
	 }
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
		r[i].key = j;
	  }
	  BinsertSort(r,len);
	  printf("二分插入排序输出：\n");
	  for(i=1;i<=len;i++)
	  printf("%d  ",r[i].key);
	  printf("\n");
}

程序运行结果：
输入待排序记录的长度：8（回车）
输入8个记录的关键字值(数据之间用空格隔开):
6   17   8  53  27  98  60  80  （回车）
二分插入排序输出：
6  8  17   27  53  60  80  98
