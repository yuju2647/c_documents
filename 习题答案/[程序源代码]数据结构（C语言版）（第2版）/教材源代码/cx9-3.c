#include <stdio.h>
typedef struct
{
	 int key;     /* 假设关键字的数据类型为整型*/ 
	 int data;    /* 假设记录的信息域的数据类型为字符型*/
}Record;

void  ShellInsert(Record r[], int length,  int  d)
/*对记录数组r做一趟希尔插入排序，length为数组的长度,d为增量*/
{
	  int i,j;
	  for(i=1+d;i<= length; i++)  /* 1+d为第一个子序列的第二个元素的下标 */
		if(r[i].key < r[i-d].key)
		{
			r[0]= r[i];           /*  备份r[i]  (不做监视哨) */
				for(j=i-d; j>0 &&r[0].key < r[j].key; j-=d)
					r[j+d]= r[j];
					r[j+d]= r[0];
		}
}

void  ShellSort(Record r[], int length, int d[], int n)
/*对记录数组r做希尔排序，length为数组r的长度，d 为增量数组，n为d[]的长度 */
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
	  printf("输入待排序记录的长度:");
	  scanf("%d",&len);
	  printf("输入%d个记录的关键字值(数据之间用空格隔开):\n",len);
	  for(i=1;i<=len;i++)
	  {
		scanf(" %d",&j);
		r[i].key = j;
	  }
	  ShellSort(r,len,d,3);
	  printf("希尔排序输出\n");
	  for(i=1;i<=len;i++)
	  printf("%d  ",r[i].key);
	  printf("\n");
}

程序运行结果：
输入待排序记录的长度：10（回车）
输入10个记录的关键字值(数据之间用空格隔开):
38  18  50  80  75  6  15  45  18（回车）
希尔排序输出：
5  10  20  30  40  40  50  60  70  80
