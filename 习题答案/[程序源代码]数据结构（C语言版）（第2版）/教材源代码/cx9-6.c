#include <stdio.h>
typedef struct
{
int key;     /* 假设记录的关键字域的数据类型为整型*/ 
char data;    /* 假设记录的信息域的数据类型为字符型*/
}Record;

int Partition(Record r[],int left,int right) 
/*对记录数组r中的r[left]至r[right]部分进行一趟快速排序，并得到枢轴的位置，排序后的结果满足其之后（前）的记录的关键字均不小于（大于）于枢轴记录*/
{ 
	Record temp;
	int low,high;
	temp=r[left];             /* 选择枢轴记录*/ 
	low=left;  
	 high=right;
	 while ( low<high )
	 {
	   while (low< high && r[high].key>=temp.key )
/* high从右到左找小于temp.key的记录*/
		high--;
	   if ( low <high ) /*找到小于temp.key的记录，则进行交换*/ 
	   { 
		 r[low]= r[high];
		 low++;
	   } 
	  while (low<high && r[low].key<temp.key )
/*low从左到右找大于temp.key的记录*/
	  low++; 
	  if (low<high)/* 找到大于temp.key的记录，则交换*/
	  { 
		 r[high]= r[low];
		 high--; 
	  } 
	 }
	 r[low]=temp;    /*将枢轴记录保存到low=high的位置*/
	 return low;      /*返回枢轴记录的位置*/
} 

void quicksort(Record r[],int low, int high )
/*对记录数组r[low..high]用快速排序算法进行排序*/
{
	int pos;
	 if(low<high)
	 {
	  pos=Partition(r, low, high);/*调用一趟快速排序，将枢轴元素为界划分两个子表*/
	  quicksort(r, low, pos-1);     /*对左部子表快速排序*/
	  quicksort(r, pos+1, high); /*对右部子表快速排序*/
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
	quicksort(r,1,len);
	printf("快速排序输出：\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");	
}


程序运行结果：
输入待排序记录的长度：8（回车）
输入8个记录的关键字值(数据之间用空格隔开):
72   75   60   27   92   15   12   48（回车）
快速排序输出：
12  15  27  48  60  72   75   92
