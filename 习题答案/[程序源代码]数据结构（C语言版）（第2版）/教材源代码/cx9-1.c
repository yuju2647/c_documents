#include <stdio.h>
typedef struct
{
	 int key;    /* 假设关键字的数据类型为整型*/ 
	 int data;   /* 假设记录的信息域的数据类型为字符型*/
}Record;

void   insertSort(Record  r[],  int length)
/* 对记录数组r做直接插入排序，length为数组中待排序记录的数目*/
{ 
	  int i,j;
	  for (i=2;  i<=length;  i++) 
	  {
		r[0]=r[i];      /*将待插入记录存放到监视哨r[0]中*/
		j=i-1;	         
		while (r[0].key< r[j].key )     /* 寻找插入位置 */
		{
			r[j+1]= r[j]; 
			j=j-1;
		}
		r[j+1]=r[0];		         /*将待插入记录插入到已排序的序列中*/
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
		r[i].key=j;
	  }
	  insertSort(r,len);
	  printf("直接插入排序输出：\n");
	  for(i=1;i<=len;i++)
	  printf("%d  ",r[i].key);
	  printf("\n");
}

程序运行结果：
输入待排序记录的长度：9（回车）
输入9个记录的关键字值(数据之间用空格隔开):
38  18  50  80  75  6  15  45  18（回车）
快速排序输出：
6  15  18  18  38  45  50  75  80

