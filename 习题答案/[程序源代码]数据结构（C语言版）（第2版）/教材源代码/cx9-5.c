#include <stdio.h>
typedef struct
{
	int key;     /* 假设关键字的数据类型为整型*/ 
	int data;    /* 假设记录的信息域的数据类型为字符型*/
}Record;

void  BubbleSort(Record r[], int length )
/*对记录数组r做冒泡排序，length为数组的长度*/
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
	printf("输入待排序记录的长度:");
	scanf("%d",&len);
	printf("输入%d个记录的关键字值(数据之间用空格隔开):\n",len);
	for(i=1;i<=len;i++)
	{
	  scanf(" %d",&j);
	  r[i].key=j;
	}
	BubbleSort(r,len);
	printf("改进算法的冒泡排序输出\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");
}

程序运行结果：
输入待排序记录的长度：9（回车）
输入9个记录的关键字值(数据之间用空格隔开):
12  62  50  16  24  78  30  6  56（回车）
改进算法后的冒泡排序输出：
6  12  16  24  30  50  56  62  78

