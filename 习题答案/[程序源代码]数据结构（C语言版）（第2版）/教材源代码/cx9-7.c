#include <stdio.h>
typedef struct
{
	int key;    /* 假设关键字的数据类型为整型*/ 
	int data;   /* 假设记录的信息域的数据类型为字符型*/
}Record;

void  SelectSort(Record r[], int length)
/*对记录数组r做简单选择排序，length为数组的长度*/
{
	int i,j,k;
	int n;
	Record temp;
    n=length;
	for (i=1;i<=n-1;++i)  
	{
		k=i;
		for (j=i+1;j<=n;++j) 
		 if (r[j].key<r[k].key ) 
		   k=j;
		  if (k!=i) 
		  { 
			temp=r[i]; 
			r[i]=r[k];
			r[k]=temp;
		  }
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
	SelectSort(r,len);
	printf("简单选择排序输出：\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");
}

程序运行结果：
输入待排序记录的长度：8（回车）
输入8个记录的关键字值(数据之间用空格隔开):
53  36  48  36  60  7  18  41（回车）
简单选择排序输出：
7  18  36  36  41  48  53	60
